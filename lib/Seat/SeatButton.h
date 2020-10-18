#ifndef SBUTTON
#define SBUTTON

class SeatButton {
    private:
        int id;
        bool pressed;
        int dir;
        bool pinCombos[4][3] = {
            {1,0,1},
            {1,1,1},
            {0,1,1},
            {1,1,0}
        };
        void switchGRND();
        void switchToButton();
    public: 
        SeatButton();
        void setId(int id);
        void updateState();
        bool isPressed() { return pressed; }
        int getDir() { return dir; }
};

#endif