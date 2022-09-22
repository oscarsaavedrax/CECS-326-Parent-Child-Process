/**********************************************************************
 * Programmer	: Oscar Saavedra
 * Class	: CECS 326-01
 * Due Date	: September 22, 2022
 * Description	: This child program takes in an integer, a gender, and
 * 	a name through command line arguments and displays them back.
 **********************************************************************/
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{	
	//Print child number, gender, and name
	cout << "Child # " << argv[0] 
	     << ": I am a " << argv[1] 
	     << ", and my name is " << argv[2] 
	     <<"." << endl;
	return 0;
}
