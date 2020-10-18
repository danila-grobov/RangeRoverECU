#include <CalibrationController.h>
#include <SMotorController.h>
#include <MButtonAggregator.h>
#include <Arduino.h>

void CalibrationController::update(MemoryButtonAggregator mBA, MotorController mC) {
    int memoryButtondId = mBA.getClickedButton();
    if(memoryButtondId != -1) {
        updateSeq(memoryButtondId);
    }
    if(shouldCalibrate()) {
        mC.calibrate();
        resetButtonSeq();
    }
}

void CalibrationController::resetButtonSeq() {
    for(int i = 0; i < 9; i++) {
        buttonSeq[i] = -1;
    }
}

void CalibrationController::updateSeq(int id)  {
    for(int i = 0;i < 8; i++) {
        buttonSeq[i] = buttonSeq[i+1];
    }
    buttonSeq[8] = id;
}
bool CalibrationController::shouldCalibrate() {
    for(int i = 0; i < 9; i++) {
        if(buttonSeq[i] != calibrationSeq[i]) {
            return 0;
        }
    }
    return 1;
}

bool CalibrationController::isAPartOfSequence( int id ) {
    for(int i = 8; i>=0; i--) {
        if(calibrationSeq[i] == id) {
            bool verified = 1;
            for(int j = i-1; j >= 0; j--) {
                int bSeqPos = 8-(i-j-1);
                if( buttonSeq[bSeqPos] != calibrationSeq[j] ) {
                    verified = 0;
                }
            }
            if(verified) return 1;
        }
    }
    return 0;
}