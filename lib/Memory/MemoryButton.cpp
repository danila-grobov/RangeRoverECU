#include <MemoryButton.h>
#include <Arduino.h>
#include <Multiplexer.h>
MemoryButton::MemoryButton() {
    pressed = 0;
    clicked = 0;
}

void MemoryButton::setId(int id) {
    this->id = id;
}

void MemoryButton::updateState() {

    U3.write(2,0);

    if(!U3.read(id+1, 1) == 0) {
        if(pressed == 1 && clicked != 1 && millis() - lastClickTime >= 100 ) {
            clicked = 1;
            lastClickTime = millis();
        } else {
            clicked = 0;
        }
        pressed = 0;
    } else {
        clicked = 0;
        pressed = 1;
    }
}