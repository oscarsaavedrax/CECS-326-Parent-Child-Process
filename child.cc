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
