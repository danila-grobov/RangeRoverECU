#include <MButtonAggregator.h>
#include <MemoryButton.h>
#include <CalibrationController.h>
#include <SMotorController.h>
#include <Arduino.h>
#include <MirrorMotorController.h>
MemoryButtonAggregator::MemoryButtonAggregator() {
    for( int i = 0;i<3;i++) {
        buttons[i].setId(i);
    }
}

int MemoryButtonAggregator::getClickedButton() {
    for( int i = 0;i<3;i++) {
        if(buttons[i].wasClicked()) {
            return i;
        };
    }
    return -1;
}

void MemoryButtonAggregator::update() {
    for( int i = 0;i<3;i++) {
        buttons[i].updateState();
    }
}

void MemoryButtonAggregator::handleButtonFunctions(CalibrationController cC, MotorController mC, MirrorMotorController mMC) {
    int clickedButtonId = getClickedButton();
    if(clickedButtonId != -1 && !cC.isAPartOfSequence(clickedButtonId)) {
        if(clickedButtonId == 1) {
            if(cC.inSaveMode()) {
                mC.savePositions(0);
            } else {
                mC.driveToPositions(0);
            }
        }

        if(clickedButtonId == 2) {
            if(cC.inSaveMode()) {
                mC.savePositions(1);
            } else {
                mC.driveToPositions(1);
            }
        }
    }
}