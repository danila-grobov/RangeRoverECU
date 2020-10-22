#include <MirrorButtonAggregator.h>
#include <MirrorMotor.h>

#ifndef MIRRORMOTORCONT
#define MIRRORMOTORCONT

class MirrorMotorController{
    private:
        MirrorButtonAggregator* mirrBA;
        MirrorMotor* motors;
        void stopMotors();
        int buttonToMotorId(int buttonId);
    public: 
        MirrorMotorController( MirrorButtonAggregator* mirrorBA);
        bool otherMotorsOFF(int ignoreId);
        void update();
        void savePositions(int memoryPosition);
        void driveToPositions(int memoryPosition);
};

#endif