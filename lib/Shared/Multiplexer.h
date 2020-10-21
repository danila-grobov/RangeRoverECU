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
#endif