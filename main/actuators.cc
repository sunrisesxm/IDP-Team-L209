using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "actuators.h"

// Actuators methods
void Actuators::activate()
{
    int byte;
    if (type == SCRAPER) {
        byte = 64;
    }
    else if (type == OFFLOADER) {
        byte = 128;
    }
    else {
        // Error handling
    }
    rlink.command(WRITE_PORT_1, byte);
}
