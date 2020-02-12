#include <Arduino.h>
#include <custom_struct.h>
#include <custom_struct.h>

class Storage {
    public:
        Storage();
        void save(int maxTemperature);
        int read();
    private:
        int _currentMaxTemperature;
};
