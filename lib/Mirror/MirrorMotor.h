#ifndef MIRRORMOTOR
#define MIRRORMOTOR

#include <Arduino.h>
class MirrorMotor {
    private:
        int id;
        int state;
    public: 
        MirrorMotor(int id);
        MirrorMotor();
        void drive( int dir);
        bool enabled() {return state!=0;}
        void stop() {   state = 0; digitalWrite(7,0); }
};

#endif