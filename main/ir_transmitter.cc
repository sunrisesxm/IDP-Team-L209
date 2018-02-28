using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

extern robot_link rlink;

#include "ir_transmitter.h"

// IR transmitter methods
void IRTransmitter::set_turntable_postition(int position)
{
    int output_on = 0x01;
    int output_off = 0;
    switch (position) {
        case 0:
            rlink.command(WRITE_PORT_1, output_on);
            delay(50);
            rlink.command(WRITE_PORT_1, output_off);
            break;
        case 1:
            rlink.command(WRITE_PORT_1, output_on);
            delay(100);
            rlink.command(WRITE_PORT_1, output_off);
            break;
        case 2:
            rlink.command(WRITE_PORT_1, output_on);
            delay(150);
            rlink.command(WRITE_PORT_1, output_off);
            break;
        case 3:
            rrlink.command(WRITE_PORT_1, output_on);
            delay(200);
            rlink.command(WRITE_PORT_1, output_off);
            break;
        default:
            // Error handling
            break;
    }
}
