using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "navigation.h"

// Navigation methods
void Navigation::get_line_position() {
    line_sensors.update_all();
    
    // Calculate position case:
    // Case 1 and 7: OFF LINE - If entirely off line, work out from last reading in which direction it has veered
    if ((line_sensors.s1 == 0) and (line_sensors.s2 == 0) and (line_sensors.s3 == 0)) {
        if (last_line_reading < 4) line_reading = OFF_LEFT;
        else if (last_line_reading > 4) line_reading = OFF_RIGHT;
    }
    // Case 2: LARGE LEFT
    if ((line_sensors.s1 == 0) and (line_sensors.s2 == 0) and (line_sensors.s3 == 1)) {
        line_reading = LARGE_LEFT;
    }
    // Case 3: SMALL LEFT
    else if ((line_sensors.s1 == 0) and (line_sensors.s2 == 1) and (line_sensors.s3 == 1)) {
        line_reading = SMALL_LEFT;
    }
    // Case 4: ON COURSE
    else if ((line_sensors.s1 == 0) and (line_sensors.s2 == 1) and (line_sensors.s3 == 0)) {
        line_reading = ON_COURSE;
    }
    // Case 5: SMALL RIGHT
    else if ((line_sensors.s1 == 1) and (line_sensors.s2 == 1) and (line_sensors.s3 == 0)) {
        line_reading = SMALL_RIGHT;
    }
    // Case 6: LARGE RIGHT
    else if ((line_sensors.s1 == 1) and (line_sensors.s2 == 0) and (line_sensors.s3 == 0)) {
        line_reading = LARGE_RIGHT;
    }
    // Case 8: JUNCTION
    else if ((line_sensors.s1 == 1) and (line_sensors.s2 == 1) and (line_sensors.s3 == 1)) {
        line_reading = JUNCTION;
    }
    else {line_reading = ON_COURSE} // Implement error handling here
}

void Navigation::follow_line()
{
    rlink.command (RAMP_TIME,0);
    // Go forward in a straight line
    line_reading = ON_COURSE;
    bool junction_detected = false;
    bool junction_reached = false;
    while (!junction_reached) {
        line_reading = get_line_position();
        switch (line_reading) {
            case OFF_LEFT:
                motors.differential_speed(speed_max,0);
                break;
            case LARGE_LEFT:
                motors.differential_speed(speed_max,int(speed_max/3));
                break;
            case SMALL_LEFT:
                motors.differential_speed(speed_max,int(2*speed_max/3));
                break;
            case ON_COURSE:
                motors.forward(speed_max);
                break;
            case SMALL_RIGHT:
                motors.differential_speed(int(2*speed_max/3),speed_max);
                break;
            case LARGE_RIGHT:
                motors.differential_speed(int(speed_max/3),speed_max);
                break;
            case OFF_RIGHT:
                motors.differential_speed(0,speed_max);
                break;
            case JUNCTION:
                if (!junction_detected) {
                    junction_detected = true;
                    motors.forward(speed_max/2); // Slow to half speed when junction is encountered
                }
                else { continue; } // Continue straight over junction
        }
        if (junction_detected and line_sensors.s4 == 1) { // If a junction has been detected and the rear line sensor is on, junction has been reached
            junction_reached = true;
            motors.stop();
        }
        delay(20); // Wait 20ms before updating to account for sensor response time
}
}
