#include <SeatButton.h>
#include <Arduino.h>

SeatButton::SeatButton() {
    pressed = 0;
    dir = 0;
}

void SeatButton::updateState() {
    switchGRND();
    switchToButton();
    digitalWrite(2,1);
    if (digitalRead(13) == 0) {
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
    pinMode(8,OUTPUT);

    if(this->id < 4) {
        digitalWrite(A4, 1);
        digitalWrite(A5, 1);
        digitalWrite(9, 1);
    } else {
        digitalWrite(A4, 1);
        digitalWrite(A5, 1);
        digitalWrite(9, 0);
    }

    digitalWrite(8, 0);
}

void SeatButton::switchToButton() {
    int adjustedId;

    if(id < 4) {
        adjustedId = id;
    } else {
        adjustedId = id - 4;
    }

    digitalWrite(10, pinCombos[adjustedId][0]);
    digitalWrite(11, pinCombos[adjustedId][1]);
    digitalWrite(12, pinCombos[adjustedId][2]);
}