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
    switch (nest_type) {
        case A:
            switch (composition) {
                case S:
                    int comp = ;
                    rlink.command(WRITE_PORT_4, comp); // and so on
                    break;
                case B:
                    break;
                case SS:
                    break;
                case BB:
                    break;
                case SB:
                    break;
                case SSB:
                    break;
                case SBB:
                    break;
                case SSBB:
                    break;
                default:
                    break;
            }
        case B:
            switch (composition) {
                case S:
                    break;
                case B:
                    break;
                case SS:
                    break;
                case BB:
                    break;
                case SB:
                    break;
                case SSB:
                    break;
                case SBB:
                    break;
                case SSBB:
                    break;
                default:
                    break;
            }
        default:
            break;
    }
}

