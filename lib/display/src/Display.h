// #include <Arduino.h>
#include <custom_struct.h>
#include <SPI.h>
#include <Wire.h>
#include <SSD1306Wire.h>

class Display {
    public:
        Display();
        void print(temperature data);
    private:
        SSD1306Wire* _lcd;
};
