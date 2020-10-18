#include <Arduino.h>
#include <MirrorMotor.h>

MirrorMotor::MirrorMotor(int id) {
    this->id = id;
    state = 0;
}
MirrorMotor::MirrorMotor() {
    state = 0;
}
void MirrorMotor::drive( int dir ) {

    Serial.print(id);
    Serial.print(" ");
    Serial.println(dir);
    if (dir == -1) {
        digitalWrite(6,1);
        state = -1;
    } else {
        digitalWrite(6,0);
        state = 1;
    }
    digitalWrite(7,1);

}