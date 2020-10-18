#ifndef MIRRORBUTTONAGG
#define MIRRORBUTTONAGG

#include <MirrorButton.h>

class MirrorButtonAggregator {
    public:
        private:
        MirrorButton buttons[4];
    public: 
        MirrorButtonAggregator();
        int getPressedButton();
        MirrorButton getButtonById(int id) { return buttons[id]; }
};

#endif