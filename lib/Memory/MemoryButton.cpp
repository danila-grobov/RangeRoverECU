#include <MemoryButton.h>
#include <Arduino.h>
MemoryButton::MemoryButton() {
    pressed = 0;
    clicked = 0;
}

void MemoryButton::setId(int id) {
    this->id = id;
}

void MemoryButton::updateState() {
    pinMode(8, INPUT_PULLUP);

    digitalWrite(A4, pinCombos[id][0]);
    digitalWrite(A5, pinCombos[id][1]);
    digitalWrite(9, pinCombos[id][2]);

    digitalWrite(2, 0);

    if(!digitalRead(8) == 0) {
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