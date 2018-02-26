using namespace std;

// Motors class
class Motors { // Convention: Speed 0 is stop, 1 to 127 is forward, -1 to -127 is reverse
public:
    int speed_left; // Current speed of left motor
    int speed_right; // Current speed of right motor
    bool forward(int); // Forwards
    bool reverse(int); // Reverse
    bool differential_speed(int, int); // Set a differential speed
    bool turn_clockwise(int); // Turn clockwise
    bool turn_anti_clockwise(int); // Turn anti-clockwise
    bool stop(); // Stop
private:
    // Converts speed from Motors class convention to hardware convention
    int convert_speed_for_hardware(int,int);
    // Sets motor speeds
    bool set_motor_speeds(int, int);
};
