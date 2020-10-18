#ifndef CURRSENSOR
#define CURRSENSOR
class CurrentSensor{
    private:
        double currentArr[80] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int currArrPos;
    public: 
        CurrentSensor();
        double getCurrent();
        void update();
        void reset() { for(int i=0;i<80;i++){currentArr[i] = 0;}};
};
#endif