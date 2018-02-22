#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#define ROBOT_NUM 14                       // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
int main ()
{
rlink.initialise(ROBOT_NUM);
cout << "Connected to robot" << endl;
rlink.command(WRITE_PORT_7, 64+2);
return 0;
}
