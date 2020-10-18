#ifndef SSENSOR
#define SSENSOR
    class SeatSensor {
        private:
            int id;
            bool wasHit;
            bool isHit();
            int hitCount = 0;
        public:
            SeatSensor(int id);
            bool sensorActive();
            void update();
    };
#endif