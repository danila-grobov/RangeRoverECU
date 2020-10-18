#ifndef MBUTTON
#define MBUTTON

class MemoryButton {
    private:
        int id;
        bool pressed;
        bool clicked;
        bool pinCombos[3][3] = {
            {1,0,0},
            {0,1,1},
            {1,0,1}
        };
        unsigned long lastClickTime = 0;
    public: 
        MemoryButton();
        void setId(int id);
        void updateState();
        bool wasClicked() { return clicked; }
};

#endif