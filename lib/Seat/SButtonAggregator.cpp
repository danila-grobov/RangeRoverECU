#include <SButtonAggregator.h>
#include <SeatButton.h>
#include <CurrentSensor.h>

SeatButtonAggregator::SeatButtonAggregator() {
    for( int i = 0;i<8;i++) {
        buttons[i].setId(i);
    }
}

int SeatButtonAggregator::getPressedButton() {
    for( int i = 0;i<8;i++) {
        buttons[i].updateState();
        if(buttons[i].isPressed()) {
            return i;
        };
    }
    return -1;
}