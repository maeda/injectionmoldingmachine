#include <Arduino.h>
#include <max6675.h>

class Sensor {
    public:
        Sensor(int cs, int so, int sck);
        double read();
    private:
        int _cs;
        int _so;
        int _sck;
        MAX6675* _ktc;
};
