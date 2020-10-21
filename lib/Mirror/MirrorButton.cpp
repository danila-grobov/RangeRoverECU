#include <MirrorButton.h>
#include <Arduino.h>
#include <Multiplexer.h>
MirrorButton::MirrorButton() {
    pressed = 0;
    dir = 0;
}

void MirrorButton::updateState() {
    switchGRND();
    int adjustedId = getAdjustedId();
    if (U4.read(adjustedId + 4,1) == 0) {
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
    if(this->id % 2 == 0) {
        U1.write(0,0);
    } else {
        U1.write(0,1);
    }
   
}

int MirrorButton::getAdjustedId() {
    if(id < 2) {
        return 0;
    } else {
        return 1;
    }
}

int MirrorButton::selectedMirrorId() {
    if(id == 1) {
        U1.write(0,0);
    }

    if(U4.read(2,1) == 0) return 0;

    if(U4.read(3,1) == 0) return 1;

    return -1;
}