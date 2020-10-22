#include <SButtonAggregator.h>
#include <CurrentSensor.h>
#include <SMotorController.h>
#include <SeatButton.h>
#include <SeatMotor.h>
#include <Arduino.h>

MotorController::MotorController( SeatButtonAggregator sBA, CurrentSensor* cSensor ) {
    this->sBA = sBA;
    this->cSensor = cSensor;
    activeMotorId = -1;
    motors = new SeatMotor[4]{
        {0,cSensor},
        {1,cSensor},
        {2,cSensor},
        {3,cSensor}
    };
}

void MotorController::update() {  

    int pressedButtonId = sBA.getPressedButton();
    if(pressedButtonId != -1) {
        int motorId = buttonToMotorId(pressedButtonId);
        SeatButton button = sBA.getButtonById(pressedButtonId);
        int dir = button.getDir();
        if(otherMotorsOFF(motorId)){
            motors[motorId].drive(dir);
        }
    } else {
        stopMotors();
    }
    
}

void MotorController::stopMotors() {
    for(int i=0;i<4;i++) {
        motors[i].stop();
    }
}

bool MotorController::otherMotorsOFF( int ignoreId ) {
    for(int i=0;i<4;i++){
        if(i != ignoreId && motors[i].enabled()) {
            return 0;
        }
    }
    return 1;
}

int MotorController::buttonToMotorId(int buttonId) {
    if(buttonId == 0 || buttonId == 1) return 0;
    if(buttonId == 2 || buttonId == 3) return 1;
    if(buttonId == 4 || buttonId == 5) return 2;
    if(buttonId == 6 || buttonId == 7) return 3;
    return -1;
}

void MotorController::calibrate() {
    if(otherMotorsOFF(-1)) {
        for(int i=0;i<4;i++) {
            motors[i].calibrate();
        }
    }
}

void MotorController::savePositions( int memoryPosition) {
    for(int i=0;i<4;i++) {
        motors[i].savePosition(memoryPosition);
    }
}
void MotorController::driveToPositions( int memoryPosition) {
     for(int i=0;i<4;i++) {
        motors[i].driveToSavedPos(memoryPosition);
    }
}