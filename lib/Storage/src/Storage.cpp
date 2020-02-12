#include <stdlib.h>
#include <Storage.h>
#include <EEPROMAnything.h>

Storage::Storage(){
    _currentTemperature = read();
}

void Storage::save(temperature data){
    if (_currentTemperature.max == data.max) {
        return;
    }
    _currentTemperature = data;
    EEPROM_writeAnything(0, _currentTemperature);
}

temperature Storage::read() {
    temperature data;
    EEPROM_readAnything(0, data);
    return data;
}