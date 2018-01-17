#include <Arduino.h>
#include <custom_struct.h>
#include <custom_struct.h>

class Relay {
    public:
        Relay(int port);
        Relay(int port, double delay);
        void trigger(temperature data);
    private:
        int _port;
        double _delay;
        void on();
        void off();
};
