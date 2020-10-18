#include <MirrorButtonAggregator.h>
#include <MirrorButton.h>
#include <CurrentSensor.h>
#include <Arduino.h>
MirrorButtonAggregator::MirrorButtonAggregator() {
    for( int i = 0;i<4;i++) {
        buttons[i].setId(i);
    }
}

int MirrorButtonAggregator::getPressedButton() {
    int buttonIds[4] = {1,3,0,2};
    for( int i = 0;i<4;i++) {
        buttons[buttonIds[i]].updateState();
        if(buttons[buttonIds[i]].isPressed()) {
            return buttonIds[i];
        };
    }
    return -1;
}