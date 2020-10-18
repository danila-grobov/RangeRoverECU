#include <SeatSensor.h>
#include <Arduino.h>

SeatSensor::SeatSensor(int id) {
    this->id = id;
    wasHit = 0;
    hitCount = 0;
}

void SeatSensor::update() {
    if(isHit()) {
        hitCount++;
        wasHit = 1;
    } else { 
        wasHit = 0;
        hitCount = 0;
    }
}

bool SeatSensor::sensorActive() {
    return hitCount == 5;
}

bool SeatSensor::isHit() {
    int pinCombo[4][3] = {
            {0,0,0},
            {0,0,1},
            {0,1,0},
            {0,1,1}
    };

    digitalWrite(A0, pinCombo[id][0]);
    digitalWrite(A1, pinCombo[id][1]);
    digitalWrite(A2, pinCombo[id][2]);

    return !digitalRead(A3);
}