#include <Arduino.h>
#include <max6675.h>

class Sensor {
    public:
        Sensor(int cs, int so, int sck, int delayMillis);
        double read();
    private:
        int _cs;
        int _so;
        int _sck;
        int _delayMillis;
        unsigned long _nextExecution;
        double _currentTemperature;
        MAX6675* _ktc;
};
