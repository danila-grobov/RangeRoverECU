#ifndef MIRRORMOTOR
#define MIRRORMOTOR

#include <Arduino.h>
#include <Multiplexer.h>
#include <CurrentSensor.h>
#include <MirrorSensor.h>
class MirrorMotor {
    private:
        int id;
        int state;
        MirrorSensor mS;
        int hitState;
        CurrentSensor* cS;
        int getDataPos(int memoryPosition);
    public: 
        MirrorMotor(int id, CurrentSensor* cS);
        MirrorMotor();
        void drive( int dir);
        bool enabled() {return state!=0;}
        void stop() {   state = 0; U2.write(id, 0); }
        void savePosition(int memoryPosition);
        void driveToSavedPos(int memoryPosition);
};

#endif