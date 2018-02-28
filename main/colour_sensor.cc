using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>

extern robot_link rlink;

#include "colour_sensor.h"

// Colour sensor methods
void ColourSensor::update()
{
    int reading_1 = rlink.request(ADC2);
    int reading_2 = rlink.request(ADC3);
    int ref = rlink.request(ADC4)
    voltage_1 = (double(reading_1)/double(ref))*reference; // Actual reference is 3.3V
    voltage_2 = (double(reading_2)/double(ref))*reference;
}

void ColourSensor::get_egg_type()
{
    update(); // Update voltages
    // Compare voltaged to work out and then update EggType egg
