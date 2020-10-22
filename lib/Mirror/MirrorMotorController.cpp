#include <MirrorButtonAggregator.h>
#include <MirrorMotorController.h>
#include <MirrorButton.h>
#include <MirrorMotor.h>
#include <Arduino.h>

MirrorMotorController::MirrorMotorController( MirrorButtonAggregator* mirrBA) {
    this->mirrBA = mirrBA;
    motors = new MirrorMotor[4]{
        {0},
        {1},
        {2},
        {3}
    };
}

void MirrorMotorController::update() {    
    int pressedButtonId = mirrBA->getPressedButton();
    if(pressedButtonId != -1) {
        int motorId = buttonToMotorId(pressedButtonId);
        MirrorButton button = mirrBA->getButtonById(pressedButtonId);
        int dir = button.getDir();
        int selectedMirrorId = button.selectedMirrorId();
        if(otherMotorsOFF(motorId) && selectedMirrorId != -1){
            motors[motorId + 2*selectedMirrorId].drive(dir);
        }
    }  else {
        stopMotors();
    }
    
}

void MirrorMotorController::stopMotors() {
    for(int i=0;i<4;i++) {
        motors[i].stop();
    }
}

bool MirrorMotorController::otherMotorsOFF( int ignoreId ) {
    for(int i=0;i<2;i++){
        if(i != ignoreId && motors[i].enabled()) {
            return 0;
        }
    }
    return 1;
}

int MirrorMotorController::buttonToMotorId(int buttonId) {
    if(buttonId == 0 || buttonId == 1) return 0;
    if(buttonId == 2 || buttonId == 3) return 1;
    return -1;
}

void MirrorMotorController::savePositions( int memoryPosition) {
    for(int i=0;i<4;i++) {
        motors[i].savePosition(memoryPosition);
    }
}
void MirrorMotorController::driveToPositions( int memoryPosition) {
     for(int i=0;i<4;i++) {
        motors[i].driveToSavedPos(memoryPosition);
    }
}