#include <Arduino.h>
#include <MirrorMotor.h>
#include <Multiplexer.h>
#include <EEPROM.h>

MirrorMotor::MirrorMotor(int id):mS(id) {
    this->id = id;
    state = 0;
}
void MirrorMotor::drive( int dir ) {
    if (dir == -1) {
        digitalWrite(A2,1);
        state = -1;
    } else {
        digitalWrite(A2,0);
        state = 1;
    }
    U2.write(id, 1);
}

void MirrorMotor::savePosition(int memoryPosition) {
    int position = mS.getValue();
    EEPROM.put(getDataPos(memoryPosition), position);
}

int MirrorMotor::getDataPos(int memoryPosition) {
    if(memoryPosition == 0) {
        return (id+8) * sizeof(int);
    } else {
        return (id + 16) * sizeof(int);
    }
}

void MirrorMotor::driveToSavedPos(int memoryPosition) {
    int position = mS.getValue();
    int desitination;
    EEPROM.get(getDataPos(memoryPosition), desitination);
    
    if(position < desitination) {
        while(position < desitination){
            drive(1);
        }
    }
    if(position > desitination) {
        while(position > desitination) {
            drive(-1);
        }
    }    
    stop();
}