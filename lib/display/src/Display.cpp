#include <stdlib.h>
#include <LiquidCrystal_I2C.h>
#include <Display.h>

Display::Display(){
    Serial.println("Initializing Display");
    _lcd = new LiquidCrystal_I2C(0x27,2,1,0,4,5,6,7,3, POSITIVE);
    _lcd->begin (16,2);
    _lcd->setBacklight(HIGH);
}

void Display::print(temperature data) {
    _lcd->setCursor(0,0);
    _lcd->print("Tmp at.: ");
    _lcd->print(data.current);
    _lcd->print("c");
    _lcd->setCursor(0,1);
    _lcd->print("Tmp mx.: ");
    _lcd->print(data.max);
    _lcd->print("c");
}
