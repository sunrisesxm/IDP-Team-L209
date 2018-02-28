using namespace std;

#include "sensors.h"
#include "motors.h"
#include "distance_sensor.h"

enum LinePosition {OFF_LEFT,LARGE_LEFT,SMALL_LEFT,ON_COURSE,SMALL_RIGHT,LARGE_RIGHT,OFF_RIGHT,JUNCTION}
class Navigation {
public:
    LineSensors line_sensors;
    Motors motors;
    // Publicly available methods and data
private:
    // Internally used private methods and data
    int speed_max;
    void follow_line();
    void get_line_position();
    LinePosition line_reading, last_line_reading;
};
