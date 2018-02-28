using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "leds.h"

// Line sensors methods
// Updates current line sensor readings
void LEDs::update(NestType nest_type, Composition composition)
{
    int output;
    switch (nest_type) {
        case EMPTY:
            output = 0;
            rlink.command(WRITE_PORT_1, output); // and so on
            break;
        case A:
            switch (composition) {
                case S:
                    output = 1;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case B:
                    output = 4;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SS:
                    output = 1+2;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case BB:
                    output = 4+8;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SB:
                    output = 1+4;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SSB:
                    output = 1+2+4;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SBB:
                    output = 1+4+8;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SSBB:
                    output = 1+2+4+8;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                default:
                    break;
            }
        case B:
            switch (composition) {
                case S:
                    output = 16+1;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case B:
                    output = 16+4;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SS:
                    output = 16+1+2;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case BB:
                    output = 16+4+8;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SB:
                    output = 16+1+4;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SSB:
                    output = 16+1+2+4;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SBB:
                    output = 16+1+4+8;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                case SSBB:
                    output = 16+1+2+4+8;
                    rlink.command(WRITE_PORT_1, output); // and so on
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

