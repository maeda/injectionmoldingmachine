#include <Arduino.h>
#include <custom_struct.h>
#include <custom_struct.h>

class Storage {
    public:
        Storage();
        void save(temperature data);
        temperature read();
    private:
        temperature _currentTemperature;
};
