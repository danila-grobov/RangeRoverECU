#ifndef MIRRORMOTOR
#define MIRRORMOTOR

#include <Arduino.h>
#include <Multiplexer.h>

class MirrorMotor {
    private:
        int id;
        int state;
    public: 
        MirrorMotor(int id);
        MirrorMotor();
        void drive( int dir);
        bool enabled() {return state!=0;}
        void stop() {   state = 0; U2.write(id, 0); }
};

#endif