#include <stdlib.h>
#include <Storage.h>
#include <EEPROMAnything.h>

Storage::Storage(){
    _currentMaxTemperature = read();
}

void Storage::save(int maxTemperature){
    if (_currentMaxTemperature == maxTemperature) {
        return;
    }
    _currentMaxTemperature = maxTemperature;
    EEPROM_writeAnything(0, _currentMaxTemperature);
}

int Storage::read() {
    int maxTemperature;
    EEPROM_readAnything(0, maxTemperature);
    return maxTemperature;
}