#include <SeatSensor.h>
#include <Arduino.h>
#include <Multiplexer.h>
SeatSensor::SeatSensor(int id) {
    this->id = id;
    hitCount = 0;
}

void SeatSensor::update() {
    if(U1.read(id + 3,1) == 0) {
        hitCount++;
    } else { 
        hitCount = 0;
    }
}

bool SeatSensor::sensorActive() {
    return hitCount == 5;
}