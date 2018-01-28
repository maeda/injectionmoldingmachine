#include <Arduino.h>

class TemperatureControl {
    public:
        TemperatureControl(int increasePort, int decreasePort, int initialTemperature);
        int read();
    private:
        int _increasePort;
        int _decreasePort;
        int _initialTemperature;
        void increaseButton(int input);
        void decreaseButton(int input);
};
