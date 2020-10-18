#include <MButtonAggregator.h>
#include <MemoryButton.h>
#include <CalibrationController.h>
#include <SMotorController.h>
#include <Arduino.h>
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

void MemoryButtonAggregator::handleButtonFunctions(CalibrationController cC, MotorController mC) {
    int clickedButtonId = getClickedButton();
    if(clickedButtonId != -1 && !cC.isAPartOfSequence(clickedButtonId)) {
        if(clickedButtonId == 1) {
            if(cC.inSaveMode()) {
                Serial.println("Save to position 1");
                mC.savePositions(0);
            } else {
                Serial.println("Drive to position 1");
                mC.driveToPositions(0);
            }
        }

        if(clickedButtonId == 2) {
            if(cC.inSaveMode()) {
                Serial.println("Save to position 2");
                mC.savePositions(1);
            } else {
                Serial.println("Drive to position 2");
                mC.driveToPositions(1);
            }
        }
    }
}