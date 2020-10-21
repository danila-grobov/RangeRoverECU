#include <SeatMotor.h>
#include <Arduino.h>
#include <SeatSensor.h>
#include <CurrentSensor.h>
#include <EEPROM.h>
#include <Multiplexer.h>
SeatMotor::SeatMotor(int id, CurrentSensor* cS):sS(id) {
    hitState = 0;
    this->id = id;
    this->cS = cS;
    position = EEPROM.read(8 + id);
    state = 0;
}
void SeatMotor::drive( int dir ) {
    sS.update();
    cS->update();
    if(cS->getCurrent() < 9) {
        if(this->hitState != dir){
            if(sS.sensorActive()) {
                position += dir;
                EEPROM.write(8 + id,position);    
            }
            if (dir == -1) {
                digitalWrite(A2,1);
                state = -1;
            } else {
                digitalWrite(A2,0);
                state = 1;
            }
            U2.write(id+4,1);
            this->hitState = 0;
        }
    } else {
        this->hitState = dir;
        stop();
        
    }
}

void SeatMotor::calibrate() {
    while( this->hitState != -1 ) {
        drive(-1);
    }
    stop();
    position = 0;
    cS->reset();
    delay(1000);
    while( this->hitState != 1 ) {
        drive(1);
    }
    cS->reset();
    delay(1000);
    while(!sS.sensorActive()) {
        drive(-1);
    }
    stop();
}

void SeatMotor::savePosition(int memoryPosition) {
    EEPROM.write(id+memoryPosition*4, position);
}
void SeatMotor::driveToSavedPos(int memoryPosition) {
    int desitination = EEPROM.read(id+memoryPosition*4);
    
    cS->reset();
    if(position < desitination) {
        while(position < desitination && hitState != 1){
            drive(1);
            Serial.println(position);
        }
    }
    if(position > desitination) {
        while(position > desitination && hitState != -1) {
            drive(-1);
            Serial.println(position);
        }
    }    
    stop();
}