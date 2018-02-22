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

int v=rlink.request(READ_PORT_7);
cout << "Connected to robot" << endl;
for (int i=1; i<50; i++){
	
	v=rlink.request(READ_PORT_7);
	cout << "Value="  <<v << endl;
	
	}
int etime=watch.stop();
cout << etime <<endl;
}
