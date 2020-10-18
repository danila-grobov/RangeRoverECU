#include <MirrorButtonAggregator.h>
#include <MirrorMotor.h>

#ifndef MIRRORMOTORCONT
#define MIRRORMOTORCONT

class MirrorMotorController{
    private:
        MirrorButtonAggregator* mirrBA;
        MirrorMotor* motors = new MirrorMotor[2];
        void stopMotors();
        int buttonToMotorId(int buttonId);
    public: 
        MirrorMotorController( MirrorButtonAggregator* mirrorBA);
        bool otherMotorsOFF(int ignoreId);
        void update();
};

#endif