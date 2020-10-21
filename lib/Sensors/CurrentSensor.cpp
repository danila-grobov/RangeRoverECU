#include <CurrentSensor.h>
#include <Arduino.h>
CurrentSensor::CurrentSensor() {
    currArrPos = 0;
}

void CurrentSensor::update() {
    int sensorValue = analogRead(A5) - 510;

    currentArr[currArrPos] = abs(sensorValue) * 0.04;
    if(currArrPos < 79) {
        currArrPos++;
    } else {
        currArrPos = 0;
    }
}

double CurrentSensor::getCurrent() {
    double sum = 0;
    for(int i = 0;i<80;i++) {
        sum+=currentArr[i];
    }
    return sum / 80;
}