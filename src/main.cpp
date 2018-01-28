#include <Wire.h>
#include <max6675.h>
#include <custom_struct.h>
#include <Display.h>
#include <TemperatureControl.h>
#include <Relay.h>
#include <Sensor.h>

Display *display;
TemperatureControl *temperatureControl;
Relay *relay;
Sensor *sensor;

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting...");
    temperatureControl = new TemperatureControl(2, 3, 200);
    relay = new Relay(8, 0.05);
    sensor = new Sensor(10, 12, 13, 500);
    display = new Display();
    Serial.println("Initialized");
}

void loop()
{
    temperature data;
    data.current = sensor->read();
    data.max = temperatureControl->read();

    display->print(data);
    relay->trigger(data);

    delay(100);
}
