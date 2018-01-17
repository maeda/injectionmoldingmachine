#include <stdlib.h>
#include <max6675.h>
#include <Sensor.h>

Sensor::Sensor(int cs, int so, int sck){
    _ktc = new MAX6675(sck, cs, so);
    _cs = cs;
    _so = so;
    _sck = sck;
};

double Sensor::read(){
    return _ktc->readCelsius();
};
