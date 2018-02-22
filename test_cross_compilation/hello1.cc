#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#define ROBOT_NUM 14                       // The id number (see below)
robot_link  rlink;                            // datatype for the robot link

int main()
{
#ifdef __arm__
	rlink.initialise ())      //setup for local hardware
#else
	rlink.initialise(ROBOT_NUM))       //setup the link
#endif
cout << "Hello world" << endl;
return 0;
}
