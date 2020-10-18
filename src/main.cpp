#include <SMotorController.h>
#include <SButtonAggregator.h>
#include <CurrentSensor.h>
#include <MButtonAggregator.h>
#include <CalibrationController.h>
#include <Arduino.h>
#include <MirrorMotorController.h>
#include <MirrorButtonAggregator.h>

void pinInit() {
    pinMode(9, OUTPUT);  // A
    pinMode(A5, OUTPUT); // B
    pinMode(A4, OUTPUT); // C

    pinMode(8, INPUT_PULLUP); // I/O COM

    pinMode(A0, OUTPUT); // C
    pinMode(A1, OUTPUT); // B
    pinMode(A2, OUTPUT); // A

    pinMode(A3, INPUT); // I/O COM

    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

    pinMode(10, OUTPUT); // C
    pinMode(11, OUTPUT); // B 
    pinMode(12, OUTPUT); // A 

    pinMode(13, INPUT_PULLUP); // I/O COM

    pinMode(2, OUTPUT);
}

void setup() {
    pinInit();
    Serial.begin(9600);
}


MemoryButtonAggregator mBA;
CurrentSensor cSensor;
SeatButtonAggregator sBA;
MotorController controller(sBA, &cSensor);
CalibrationController cC;
MirrorButtonAggregator mirrBA;
MirrorMotorController mirrController(&mirrBA);


void loop() {
    cSensor.update();
    controller.update();
    // mirrController.update();
    mBA.update();
    mBA.handleButtonFunctions(cC,controller);
    cC.update(mBA,controller);
// digitalWrite(6,1);
}

