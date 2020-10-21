#include <Multiplexer.h>
#include <Arduino.h>

MPlexer::MPlexer(uint8_t A_pin, uint8_t B_pin,uint8_t C_pin,uint8_t IO_pin) {
    this->A_pin = A_pin;
    this->B_pin = B_pin;
    this->C_pin = C_pin;
    this->IO_pin = IO_pin;
}

void MPlexer::write(int pos, int bit) {
    pinMode(IO_pin,OUTPUT);
    switchPin(pos);
    digitalWrite(IO_pin, bit);
}

void MPlexer::switchPin(int pos) {
    digitalWrite(A_pin,combos[pos][0]);
    digitalWrite(B_pin,combos[pos][1]);
    digitalWrite(C_pin,combos[pos][2]);
}

bool MPlexer::read(int pos, bool pullUp) {
    if(pullUp)
        pinMode(IO_pin,INPUT_PULLUP);
    else 
        pinMode(IO_pin,INPUT);
        
    switchPin(pos);
    return digitalRead(IO_pin);
}