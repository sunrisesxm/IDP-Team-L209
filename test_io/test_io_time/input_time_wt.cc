#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#define ROBOT_NUM 14                       // The id number (see below)
robot_link  rlink;                            // datatype for the robot link
int main ()
{
stopwatch watch;
watch.start();
rlink.initialise(ROBOT_NUM);
rlink.command(WRITE_PORT_7, 255);
int v=rlink.request(READ_PORT_7);
cout << "Connected to robot" << endl;
for (int i=1; i<50; i++){
	
	

	
	rlink.command(WRITE_PORT_7, 255);
	v=rlink.request(READ_PORT_7);
	cout << "Value="  <<v << endl;
	
	}
int etime=watch.stop();
cout << etime <<endl;
}
