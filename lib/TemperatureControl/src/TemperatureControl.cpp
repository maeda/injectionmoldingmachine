#include <stdlib.h>
#include <Arduino.h>
#include <TemperatureControl.h>

TemperatureControl::TemperatureControl(int increasePort, int decreasePort, int initialTemperature, int min, int max){
    Serial.println("Initializing TemperatureControl");
    _increasePort = increasePort;
    _decreasePort = decreasePort;
    _initialTemperature = initialTemperature;
    _max = max;
    _min = min;
    pinMode(_increasePort, INPUT);
    pinMode(_decreasePort, INPUT);
};

int TemperatureControl::read(){
    increaseButton(_increasePort);
    decreaseButton(_decreasePort);
    return _initialTemperature;
};

void TemperatureControl::increaseButton(int input) {
    if(digitalRead(input) == HIGH && _initialTemperature < _max) {
        _initialTemperature = _initialTemperature + 1;
    }
}

void TemperatureControl::decreaseButton(int input) {
    if(digitalRead(input) == HIGH && _initialTemperature > _min) {
        _initialTemperature = _initialTemperature - 1;
    }
}
