using namespace std;

#include "colour_sensor.h"
#include "sorting_motor.h"
#include "actuators.h"
#include "ir_receiver.h"
#include "ir_transmitter.h"

class Actions {
public:
    ColourSensor colour_sensor;
    SortingMotor sorting_motor;
    Actuators actuator1, actuator2;
    IRReceiver ir_receiver;
    IRTransmitter ir_transmitter;
    
private:
    
};

