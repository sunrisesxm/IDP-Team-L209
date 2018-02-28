using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "microswitches.h"

// Microswitch methods
void MicroSwitch::read(); // Read microswitch
{
    int input;
    bool reading;
    input = rlink.request(READ_PORT_0);
    if (type == COLLECTION) {
        reading = input bitand 0x01; // Collection position microswitch is bit 0
    }
    else if (type == COLOUR_SENSOR) {
        reading = input bitand 0x02; // Colour sensor position microswitch is bit 1
    }
    else {
        // Error handling
    }
    return reading;
}

bool MicroSwitch::catch_switch() // Catch switch on over 2 seconds
{
    bool reading;
    for (int i; i < 100; i++) {
        reading = read();
        if (reading == true) {
            return true;
        }
        else {
            delay(20);
        }
    }
    return false;
}

