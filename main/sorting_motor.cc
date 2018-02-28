using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "sorting_motor.h"

// Sorting motor methods
void SortingMotor::move(int degrees)
{
    rlink.command(RAMP_TIME, 0);
    time_delay = 5; // Some function to get from degrees rotation required to time of rotation at speed = 100 (in ms)
    if (degrees > 0) { // Go clockwise
        rlink.command(MOTOR_3_GO, 100);
    }
    else { // Go anticlockwise
        rlink.command(MOTOR_3_GO, 228);
    }
    delay(time_delay);
    rlink.command(MOTOR_3_GO, 0);
}

void SortingMotor::switch_position(Position desired_position)
{
    switch (current_position) {
        case COLLECTION:
            switch (desired_position) {
                case INTO_RECYCLING:
                    // collection to recycling
                    move(-30);
                    break;
                case COLOUR_SENSOR:
                    // collection to colour sensor
                    move(30);
                    break;
                case INTO_NEST:
                    // collection to nest
                    move(60);
            }
            break;
        case INTO_RECYCLING:
            switch (desired_position) {
                case COLLECTION:
                    // recycling to collection
                    move(30);
                    break;
            }
            break;
        case COLOUR_SENSOR:
            switch (desired_position) {
                case INTO_RECYCLING:
                    // colour sensor to recycling
                    move(-60);
                    break;
                case INTO_NEST:
                    // colour sensor to nest
                    move(30);
                    break;
            }
            break;
    }
}
