#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#define ROBOT_NUM 14                       // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
int main ()
{
#ifdef __arm__
	rlink.initialise ();      //setup for local hardware
#else
	rlink.initialise(ROBOT_NUM);       //setup the link
#endif
stopwatch watch;
watch.start();

rlink.command(WRITE_PORT_7, 64+16);
cout << "Connected to robot" << endl;
for (int i=1; i<100; i++){
	
	
	
	rlink.command(WRITE_PORT_7, i);
	
	}
int etime=watch.stop();
cout << etime <<endl;
}
