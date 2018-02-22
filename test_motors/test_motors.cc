#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#define ROBOT_NUM 14                       // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
int main ()
{
rlink.initialise(ROBOT_NUM);
rlink.command (MOTOR_1_GO,100);
rlink.command (MOTOR_2_GO,100);
rlink.command (MOTOR_3_GO,100);
rlink.command (MOTOR_4_GO,100);
delay(2000);
int speed=rlink.request(MOTOR_1);
int speed2=rlink.request(MOTOR_2);
int speed3=rlink.request(MOTOR_3);
int speed4=rlink.request(MOTOR_4);
delay(2000);
rlink.command (MOTOR_1_GO,0);
rlink.command (MOTOR_2_GO,0);
rlink.command (MOTOR_3_GO,0);
rlink.command (MOTOR_4_GO,0);
cout << speed << endl;
cout << speed2 << endl;
cout << speed3 << endl;
cout << speed4 << endl;

return 0;
}
