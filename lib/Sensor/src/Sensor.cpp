#include <stdlib.h>
#include <max6675.h>
#include <Sensor.h>

Sensor::Sensor(int cs, int so, int sck, int delayMillis){
    Serial.println("Initializing Sensor");
    _ktc = new MAX6675(sck, cs, so);
    _cs = cs;
    _so = so;
    _sck = sck;
    _nextExecution = millis() + delayMillis;
    _delayMillis = delayMillis;
    Serial.println(_nextExecution);
};

double Sensor::read(){
    if(_nextExecution <= millis()) {
        _currentTemperature = _ktc->readCelsius();
        _nextExecution = millis() + _delayMillis;
    }
    return _currentTemperature;
};
