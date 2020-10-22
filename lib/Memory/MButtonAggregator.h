#ifndef MBUTTONAGG
#define MBUTTONAGG

#include <MemoryButton.h>
#include <CalibrationController.h>
#include <MirrorMotorController.h>

class MemoryButtonAggregator{
    private:
        MemoryButton buttons[3];
    public: 
        MemoryButtonAggregator();
        int getClickedButton();
        void update();
        void handleButtonFunctions(CalibrationController cC, MotorController mC, MirrorMotorController mMC);
};

#endif