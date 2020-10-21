#include <SeatButton.h>
#include <Arduino.h>
#include <Multiplexer.h>
SeatButton::SeatButton() {
    pressed = 0;
    dir = 0;
}

void SeatButton::updateState() {
    switchGRND();
    int adjustedId = getAdjustedId();
    if (U3.read(adjustedId+4, 1) == 0) {
        pressed = 1;
    } else {
        pressed = 0;
    }
}


void SeatButton::setId(int id) {
    if(id % 2 == 0 ) {
        dir = 1;
    } else {
        dir = -1;
    }
    this->id = id;
}

void SeatButton::switchGRND() {
    if(this->id < 4) {
        U1.write(0,0);
    } else {
        U1.write(1,0);
    }
}

int SeatButton::getAdjustedId() {
    if(id < 4) {
        return id;
    } else {
        return id - 4;
    }
}