#include <stdlib.h>
#include <Relay.h>

Relay::Relay(int port){
    _port = port;
    _delay = 0.0;
    pinMode(_port, OUTPUT);
}

Relay::Relay(int port, double delay){
    _port = port;
    _delay = delay;
    pinMode(_port, OUTPUT);
};

void Relay::trigger(temperature data){
    if(data.current >= data.max) {
        on();
    }
    if(data.current <= (data.max - (data.max * _delay))){
        off();
    }
};

void Relay::on() {
    digitalWrite(_port, HIGH);
};

void Relay::off() {
    digitalWrite(_port, LOW);
};
