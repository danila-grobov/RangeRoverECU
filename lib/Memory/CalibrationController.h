#ifndef CALCONTROLL
#define CALCONTROLL

class MotorController;
class MemoryButtonAggregator;

class CalibrationController{
    private:
        int calibrationSeq [9] = {0,0,0,0,0,2,1,1,2};
        int buttonSeq[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
        bool shouldCalibrate();
        void updateSeq( int id );
        void resetButtonSeq();
    public: 
        void update(MemoryButtonAggregator mBA, MotorController mC);
        bool isAPartOfSequence(int id);
        bool inSaveMode() {return buttonSeq[8] == 0;};
};
#endif