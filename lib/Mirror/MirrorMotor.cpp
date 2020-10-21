#include <Arduino.h>
#include <MirrorMotor.h>
#include <Multiplexer.h>

MirrorMotor::MirrorMotor(int id) {
    this->id = id;
    state = 0;
}
MirrorMotor::MirrorMotor() {
    state = 0;
}
void MirrorMotor::drive( int dir ) {
    if (dir == -1) {
        digitalWrite(A2,1);
        state = -1;
    } else {
        digitalWrite(A2,0);
        state = 1;
    }
    U2.write(id, 1);
}