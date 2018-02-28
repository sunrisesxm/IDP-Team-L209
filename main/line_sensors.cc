using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "line_sensors.h"

// Line sensors methods
// Updates current line sensor readings
bool LineSensors::update_all()
{
    int reading = rlink.request(READ_PORT_0); // Line sensor pcb connected at address 0
    bool s1 = reading bitand 0x01; // Line sensor 1
    bool s2 = reading bitand 0x02; // Line sensor 2
    bool s3 = reading bitand 0x04; // Line sensor 3
    bool s4 = reading bitand 0x08; // Line sensor 4
}
