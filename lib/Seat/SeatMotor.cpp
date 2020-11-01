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
    EEPROM.get(id*sizeof(int),position);
    state = 0;
}
void SeatMotor::drive( int dir ) {
    sS.update();
    cS->update();

    if(cS->getCurrent() < 9) {
        if(this->hitState != dir){
            if(sS.sensorActive()) {
                position += dir;
                EEPROM.put(id*sizeof(int),position);    
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
    EEPROM.put(getDataPos(memoryPosition), position);
}

int SeatMotor::getDataPos(int memoryPosition) {
    if(memoryPosition == 0) {
        return (id+4) * sizeof(int);
    } else {
        return (id + 12) * sizeof(int);
    }
}

void SeatMotor::driveToSavedPos(int memoryPosition) {
    
    int desitination;
    EEPROM.get(getDataPos(memoryPosition), desitination);
    
    cS->reset();
    if(position < desitination) {
        while(position < desitination && hitState != 1){
            drive(1);
        }
    }
    if(position > desitination) {
        while(position > desitination && hitState != -1) {
            drive(-1);
        }
    }    
    stop();
}