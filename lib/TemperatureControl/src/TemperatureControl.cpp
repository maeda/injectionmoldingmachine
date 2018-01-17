#include <stdlib.h>
#include <TemperatureControl.h>

TemperatureControl::TemperatureControl(int increasePort, int decreasePort, int initialTemperature){
    _increasePort = increasePort;
    _decreasePort = decreasePort;
    _initialTemperature = initialTemperature;
    pinMode(_increasePort, INPUT);
    pinMode(_decreasePort, INPUT);
};

void TemperatureControl::increaseButton(int input) {
    if(digitalRead(input) == HIGH) {
        _initialTemperature = _initialTemperature + 1;
    }
}

void TemperatureControl::decreaseButton(int input) {
    if(digitalRead(input) == HIGH) {
        _initialTemperature = _initialTemperature - 1;
    }
}
