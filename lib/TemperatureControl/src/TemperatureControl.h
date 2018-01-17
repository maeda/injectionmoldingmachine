#include <Arduino.h>

class TemperatureControl {
    public:
        TemperatureControl(int increasePort, int decreasePort, int initialTemperature);
        int read(){
            increaseButton(digitalRead(_increasePort));
            decreaseButton(digitalRead(_decreasePort));
            return _initialTemperature;
        };
    private:
        int _increasePort;
        int _decreasePort;
        int _initialTemperature;
        void increaseButton(int input);
        void decreaseButton(int input);
};
