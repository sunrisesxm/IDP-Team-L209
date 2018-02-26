#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>

#define ROBOT_NUM 14
robot_link rlink;

bool set_driving_motors(int v1, int v2) {
	return (rlink.command(MOTOR_1_GO, v1+128) and rlink.command(MOTOR_2_GO, v2));
}

// Returns an integer corresponding to a particular line following case
int get_line_position(int last_line_reading) {
    int byte = rlink.request(READ_PORT_0);
    bool val0 = byte bitand 0x01; // Line sensor 1
    bool val1 = byte bitand 0x02; // Line sensor 2
    bool val2 = byte bitand 0x04; // Line sensor 3
    
    // Calculate position case:
    // Case 1 and 7: If entirely off line, work out from last reading in which direction it has veered
    if ((val0 == 0) and (val1 == 0) and (val2 == 0)) {
        if (last_line_reading < 4) return 1;
        else if (last_line_reading > 4) return 7;
    }
    // Case 2
    if ((val0 == 0) and (val1 == 0) and (val2 == 1)) {
        return 2;
    }
     // Case 3
    else if ((val0 == 0) and (val1 == 1) and (val2 == 1)) {
        return 3;
    }
    // Case 4
    else if ((val0 == 0) and (val1 == 1) and (val2 == 0)) {
        return 4;
    }
    // Case 5
    else if ((val0 == 1) and (val1 == 1) and (val2 == 0)) {
        return 5;
    }
    // Case 6
    else if ((val0 == 1) and (val1 == 0) and (val2 == 0)) {
        return 6;
    }
    else {return 4;}
}

// Start main program
int main() {
rlink.initialise();
rlink.command (RAMP_TIME,0);
// Go forward in a straight line
int current_line_position = 4;
while (true) {
    current_line_position = get_line_position(current_line_position);
    if (current_line_position == 1) {
        set_driving_motors(120, 0);
    }
    else if (current_line_position == 2) {
        set_driving_motors(120, 40);
    }
    else if (current_line_position == 3) {
        set_driving_motors(120, 80);
    }
    else if (current_line_position == 4) {
        set_driving_motors(120, 120);
    }
    else if (current_line_position == 5) {
        set_driving_motors(80, 120);
    }
    else if (current_line_position == 6) {
        set_driving_motors(40, 120);
    }
    else if (current_line_position == 7) {
        set_driving_motors(0, 120);
    }
    int speed1 = rlink.request(MOTOR_1);
    int speed2 = rlink.request(MOTOR_2);
    cout << speed1 << speed2 << endl;
    delay(100);
}
return 0;
}
