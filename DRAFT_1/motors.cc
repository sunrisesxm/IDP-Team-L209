using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "motors.h"

// Motors methods
// Move forwards
bool Motors::forward(int speed)
{
    return set_motor_speeds(speed, speed);
}

// Reverse
bool Motors::reverse(int speed)
{
    return set_motor_speeds(-1*speed, -1*speed); // Reverse
}

// Set a differential speed
bool Motors::differential_speed(int left, int right)
{
    return set_motor_speeds(left, right);
}

// Turn clockwise
bool Motors::turn_clockwise(int speed)
{
    return set_motor_speeds(speed, -1*speed);
}

// Turn anti-clockwise
bool Motors::turn_anti_clockwise(int speed)
{
    return set_motor_speeds(-1*speed, speed);
}

// Stop
bool Motors::stop()
{
    return set_motor_speeds(0, 0);
}

// Converts speed from Motors class convention to hardware convention
int Motors::convert_speed_for_hardware(int speed, int motor)
{
    if (motor == 1) { // Left motor
        if (speed == 0) return 0; // If stop, return 0
        else if (speed > 0) return (speed+128); // If forward, return 129 to 255 (left motor is reversed)
        else return speed; // If reverse, return 1 to 127
    }
    else if (motor == 2) { // Right motor
        if (speed == 0) return 0; // If stop, return 0
        else if (speed < 0) return ((-1*speed)+128); // If reverse, return 129 to 255
        else return speed; // If forward, return 1 to 127
    }
}

// Sets motor speeds
bool Motors::set_motor_speeds(int left, int right)
{
    speed_left = left;
    speed_right = right;
    hardware_speed_left = convert_speed_for_hardware(left, 1);
    hardware_speed_right = convert_speed_for_hardware(right, 2);
    return (rlink.command(MOTOR_1_GO, hardware_speed_left) and rlink.command(MOTOR_2_GO, hardware_speed_right));
}
