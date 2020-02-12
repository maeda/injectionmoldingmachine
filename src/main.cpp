#include <Wire.h>
#include <max6675.h>
#include <custom_struct.h>
#include <Display.h>
#include <TemperatureControl.h>
#include <Relay.h>
#include <Sensor.h>
#include <Storage.h>

Display *display;
TemperatureControl *temperatureControl;
Relay *relay;
Sensor *sensor;
Storage *storage;

void setup()
{
    Serial.begin(9600);
    Serial.println("Starting...");
    temperatureControl = new TemperatureControl(2, 3, 200, 100, 300);
    relay = new Relay(8, 0.05);
    sensor = new Sensor(10, 12, 13, 500);
    display = new Display();
    storage = new Storage();
    Serial.println("Initialized");
}

void loop()
{
    temperature data;
    data.current = sensor->read();
    data.max = temperatureControl->read();

    display->print(data);
    relay->trigger(data);
    storage->save(data.max);

    delay(100);
}
