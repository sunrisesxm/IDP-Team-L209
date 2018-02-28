using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "distance_sensor.h"

// Distance sensor methods
void DistanceSensor::update();
{
    int reading = rlink.request(ADC0);
    int ref = rlink.request(ADC1);
    double voltage = (double(reading)/double(ref))*reference; // Actual reference is 3.1V
    distance = convert_voltage_to_distance(voltage);
}

void DistanceSensor::convert_voltage_to_distance()
{
    // Calibration required to get the distance corresponding to voltage
}
