// #include <Arduino.h>
#include <custom_struct.h>
#include <LiquidCrystal_I2C.h>

class Display {
    public:
        Display();
        void print(temperature data);
    private:
        LiquidCrystal_I2C* _lcd;
};
