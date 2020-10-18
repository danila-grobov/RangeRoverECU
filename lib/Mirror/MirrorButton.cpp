#include <MirrorButton.h>
#include <Arduino.h>

MirrorButton::MirrorButton() {
    pressed = 0;
    dir = 0;
}

void MirrorButton::updateState() {
    switchGRND();
    switchToButton();
    if (digitalRead(13) == 0) {
        pressed = 1;
    } else {
        pressed = 0;
    }
}


void MirrorButton::setId(int id) {
    if(id % 2 == 0 ) {
        dir = 1;
    } else {
        dir = -1;
    }
    this->id = id;
}

void MirrorButton::switchGRND() {
    pinMode(8,OUTPUT);

    if(this->id % 2 == 0) {
        digitalWrite(A4, 1);
        digitalWrite(A5, 1);
        digitalWrite(9, 1);
        
        digitalWrite(8, 0);
    } else {
        digitalWrite(8, 1);
    }
   
}

void MirrorButton::switchToButton() {
    int adjustedId;

    if(id < 2) {
        adjustedId = 0;
    } else {
        adjustedId = 1;
    }

    digitalWrite(10, pinCombos[adjustedId][0]);
    digitalWrite(11, pinCombos[adjustedId][1]);
    digitalWrite(12, pinCombos[adjustedId][2]);
}

int MirrorButton::selectedMirrorId() {
    if(id == 1) {
        pinMode(8,OUTPUT);
        digitalWrite(A4, 1);
        digitalWrite(A5, 1);
        digitalWrite(9, 1);
        
        digitalWrite(8, 0);
    }

    digitalWrite(10, 0);
    digitalWrite(11, 0);
    digitalWrite(12, 0);
    if(digitalRead(13) == 0) return 0;

    digitalWrite(10, 0);
    digitalWrite(11, 0);
    digitalWrite(12, 1);
    if(digitalRead(13) == 0) return 1;

    return -1;
}