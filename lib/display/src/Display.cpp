#include <stdlib.h>
#include <SPI.h>
#include <Wire.h>
#include <Display.h>
#include <SSD1306Wire.h>
#include <font.h>

Display::Display(){
    Serial.println("Initializing Display");
    _lcd = new SSD1306Wire(0x3c, 4, 5, GEOMETRY_128_32);
    _lcd->init();
    _lcd->displayOn();
    _lcd->flipScreenVertically();
    _lcd->resetDisplay();
}

void Display::print(temperature data) {
    _lcd->clear();
    _lcd->setTextAlignment(TEXT_ALIGN_RIGHT);
    _lcd->setFont(Dialog_plain_16);
    _lcd->drawString(110, 0, String(data.current) + "°C");
    _lcd->setFont(Dialog_plain_12);
    _lcd->drawString(120, 16, String(data.max) + "°C");  

    _lcd->drawHorizontalLine(65, 22, 5);
    _lcd->drawLine(65, 22, 67, 20);
    _lcd->drawLine(67, 20, 70, 22);
    
    _lcd->drawHorizontalLine(65, 24, 5);
    _lcd->drawLine(65, 24, 67, 26);
    _lcd->drawLine(67, 26, 70, 24);
    _lcd->display();

}