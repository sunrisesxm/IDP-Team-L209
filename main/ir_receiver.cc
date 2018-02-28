using namespace std;

#include <iostream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <vector>

extern robot_link rlink;

#include "ir_receiver.h"

// IR receiver methods
int IRReveiver::get_code()
{
    vector<int> recorded_counters;
    bool code_confirmed = false;
    bool non_zero_obtained = false;
    bool reading = false;
    int counter, last_counter;
    int prev_counter = 0;
    while (!code_confirmed) {
        delay(50); // Wait 50ms
        counter = get_counter();
        if (counter != 0 and !non_zero_obtained) { // First wait til we obtain a non-zero counter
            non_zero_obtained = true;
        }
        else if (counter == 0 and non_zero_obtained) { // Start reading when the counter reaches 0 after non-zero is obtained
            reading = true;
        }
        while (reading) {
            delay(50); // Wait 50ms
            last_counter = counter;
            counter = get_counter();
            if (counter < last_counter) { // If counter goes back down to 0, record last_counter
                if (last_counter == prev_counter) { // If the new result matches the previous result, recording is confirmed
                    reading = false;
                    code_confirmed = true;
                }
                else { // If result does not match previous result, update previous result and start next reading cycle
                    prev_counter = last_counter;
                }
            }
            else { continue; }
        }
    }
    return prev_counter;
}

int IRReveiver::get_counter()
{
    int byte, counter;
    byte = rlink.request(READ_PORT_0);
    byte = byte bitand (128+64+32+16);
    counter = byte >> 4;
    return counter;
}
