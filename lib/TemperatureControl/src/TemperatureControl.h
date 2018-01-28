#include <Arduino.h>

class TemperatureControl {
    public:
        TemperatureControl(int increasePort, int decreasePort, int initialTemperature, int min, int max);
        int read();
    private:
        int _increasePort;
        int _decreasePort;
        int _initialTemperature;
        int _min;
        int _max;
        void increaseButton(int input);
        void decreaseButton(int input);
};
