#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char** argv)
{
	// Create variables
	int number_children = (argc - 1) / 2;
	
	//Print number of children
	cout << "I have " << number_children << " children." << endl;
	
	//Print the aruments as gender-name pairs
	for (int i = 1; i < argc; i += 2)
	{
		cout << argv[i] << " " << argv[i+1] << endl;
		// Create n children processes
		if(fork() == 0)
		{
			cout << "son pid " << getpid() << endl;
			exit(0);
		}
	}
	cout << endl;

	// Parent process waits for children and terminates at the end
	for(int i = 0; i < number_children; i++)
		wait(NULL);
	cout << "All child processes terminated. Parent exits." << endl;
	return 0;
}
