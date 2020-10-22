#include <MirrorSensor.h>
#include <Arduino.h>
#include <Multiplexer.h>
MirrorSensor::MirrorSensor(int id) {
    this->id = id;
    this->sensor_value = 0;
}

int MirrorSensor::getValue() {
    if(id == 0) {
        U1.write(0,0);
        U4.write(6,1);

        return U3.aRead(0);
    }

    if(id == 1) {
        U1.write(1,0);
        U3.write(0,1);

        return U4.aRead(6);
    }

    if(id == 2) {
        U1.write(2,0);
        U4.write(6,1);

        return U3.aRead(0);
    }
    
    if(id == 3) {
        U1.write(7,0);
        U3.write(0,1);

        return U4.aRead(6);
    }
   

    return 0;
}