#include <Arduino.h>
#ifndef MPLEX
#define MPLEX
    class MPlexer {
        private:
            uint8_t A_pin;
            uint8_t B_pin;
            uint8_t C_pin;
            uint8_t IO_pin;
            int combos[8][3] = {
                {0,0,0}, {0,0,1},
                {0,1,0}, {0,1,1},
                {1,0,0}, {1,0,1},
                {1,1,0}, {1,1,1}
            };
            void switchPin(int pos);
        public:
            MPlexer(uint8_t A_pin,uint8_t B_pin,uint8_t C_pin,uint8_t IO_pin);
            void write(int pos, int bit);
            bool read(int pos, bool poolUp);
    };

    MPlexer U1(8,9,10,A0);
    MPlexer U2(11,12,13,A1);
    MPlexer U3(5,6,7,A3);
    MPlexer U4(2,3,4,A4);
#endif