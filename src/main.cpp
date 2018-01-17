#include <Wire.h>
#include <max6675.h>
#include <custom_struct.h>
#include <Display.h>
#include <TemperatureControl.h>
#include <Relay.h>
#include <Sensor.h>


Display *display = new Display();
TemperatureControl *temperatureControl = new TemperatureControl(2, 3, 100);
Relay *relay = new Relay(8, 0.05);
Sensor *sensor = new Sensor(10, 12, 13);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    temperature data;
    data.current = sensor->read();
    data.max = temperatureControl->read();

    display->print(data);
    relay->trigger(data);

    delay(500);
}
