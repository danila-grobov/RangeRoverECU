#ifndef SMOTOR
#define SMOTOR

#include <Arduino.h>
#include <CurrentSensor.h>
#include <SeatSensor.h>
#include <Multiplexer.h>
class SeatMotor{
    private:
        int id;
        int position;
        int state;
        int hitState;
        CurrentSensor* cS;
        SeatSensor sS;
    public: 
        SeatMotor(int id, CurrentSensor* cS);
        SeatMotor();
        void drive( int dir);
        void setHitState(int state) {
            hitState = state;
        }
        int getHitState() {return hitState;}
        bool enabled() {return state!=0;}
        void stop() {   state = 0; U2.write(id+4,0); }
        void calibrate();
        void savePosition(int memoryPosition);
        void driveToSavedPos(int memoryPosition);
};

#endif