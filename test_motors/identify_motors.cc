#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#define ROBOT_NUM 14						// The id number (see below)
robot_link  rlink;							// datatype for the robot link
int main ()
{
#ifdef __arm__
	rlink.initialise ();					//setup for local hardware
#else
	rlink.initialise(ROBOT_NUM);			//setup the link
#endif

rlink.command(WRITE_PORT_7, 255);

rlink.command (RAMP_TIME,200);

rlink.command (MOTOR_1_GO,100);
rlink.command(WRITE_PORT_7, 1);
delay(2000);
int speed=rlink.request(MOTOR_1);
cout << speed << endl;
rlink.command (MOTOR_1_GO,0);


rlink.command (MOTOR_2_GO,100);
rlink.command(WRITE_PORT_7, 2);
delay(2000);
int speed2=rlink.request(MOTOR_2);
cout << speed2 << endl;
rlink.command (MOTOR_2_GO,0);


rlink.command (MOTOR_3_GO,100);
rlink.command(WRITE_PORT_7, 3);
int speed3=rlink.request(MOTOR_3);
delay(2000);
cout << speed3 << endl;
rlink.command (MOTOR_3_GO,0);


rlink.command (MOTOR_4_GO,100);
rlink.command(WRITE_PORT_7, 4);
int speed4=rlink.request(MOTOR_4);
delay(2000);
cout << speed4 << endl;


rlink.command (MOTOR_4_GO,0);

rlink.command(WRITE_PORT_7, 255);
return 0;
}
