#ifndef MIRRORBUTTON
#define MIRRORBUTTON

class MirrorButton {
    private:
        int id;
        bool pressed;
        int dir;
        bool pinCombos[2][3] = {
            {1,0,0},
            {0,1,0}
        };
        void switchGRND();
        int getAdjustedId();
    public: 
        MirrorButton();
        void setId(int id);
        void updateState();
        bool isPressed() { return pressed; }
        int getDir() { return dir; }
        int selectedMirrorId();
};

#endif