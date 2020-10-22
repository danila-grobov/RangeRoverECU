#ifndef MSENSOR
#define MSENSOR
    class MirrorSensor {
        private:
            int id;
            int sensor_value;
        public:
            MirrorSensor(int id);
            int getValue();
    };
#endif