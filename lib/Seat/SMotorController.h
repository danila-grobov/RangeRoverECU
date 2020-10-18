#include <SButtonAggregator.h>
#include <CurrentSensor.h>
#include <SeatMotor.h>

#ifndef SMOTORCONT
#define SMOTORCONT
class MotorController{
    private:
        int activeMotorId;
        SeatButtonAggregator sBA;
        CurrentSensor* cSensor;
        SeatMotor* motors;
        void stopMotors();
        int buttonToMotorId(int buttonId);
    public: 
        MotorController( SeatButtonAggregator sBA, CurrentSensor* cSensor );
        bool otherMotorsOFF(int ignoreId);
        void update();
        void calibrate();
        void savePositions( int memoryPosition);
        void driveToPositions( int memoryPosition);
};

#endif