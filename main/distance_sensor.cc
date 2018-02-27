using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "distance_sensor.h"

// Distance sensor methods
bool DistanceSensor::update();
{
    int byte = rlink.request(ADC0);
    int ref = rlink.request(ADC1);
    voltage = (double(byte)/double(ref))*reference; // Actual reference is 3.1V
    distance = convert_voltage_to_distance(voltage);
    
}

double DistanceSensor::convert_voltage_to_distance()
{
    // Calibration required to get the distance corresponding to voltage
}
