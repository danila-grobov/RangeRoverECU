#include <SeatButton.h>

#ifndef SBUTTONAGG
#define SBUTTONAGG
class SeatButtonAggregator{
    private:
        SeatButton buttons[8];
    public: 
        SeatButtonAggregator();
        int getPressedButton();
        SeatButton getButtonById(int id) { return buttons[id]; }
};

#endif