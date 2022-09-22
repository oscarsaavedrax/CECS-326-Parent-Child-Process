/***********************************************************************
 * Programmer	: Oscar Saavedra
 * Class	: CECS 326-01
 * Due Date	: September 22, 2022
 * Description	: This program uses a parent process to create a user 
 * 	defined number of child processes. Each child process executes 
 * 	the child program. The parent process sends each child process 
 * 	information about the child. The parent waits for all child 
 * 	processes to complete before terminating itself.
 ***********************************************************************/
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	// Create variables
	int number_children = (argc - 1) / 2;	// Total number of children
	int gender_name_pair_index = 1;		// Tracks gender-name pairs
		
	//Print number of children
	cout << "I have " << number_children << " children." << endl;

	// Create user defined number of child processes
	for (int i = 0; i < number_children; i++)
	{
		// Fork a new child process on each iteration
		if(fork() == 0)
		{
			string child_num_str = to_string(i+1);	// Convert number to string
			char* child_num = const_cast<char*>(child_num_str.c_str());	// Holds child number
			/* Create array with child information
			 * child_num - number of child
			 * argv[gender_name_paired_index] - the gender of the child
			 * argv[gender_name_pair_index + 1] - the name of child
			 */
			char *child_info[] = {child_num,
					      argv[gender_name_pair_index],
					      argv[gender_name_pair_index + 1],
					      NULL};

			// Child processs executes child program
			execv("./child", child_info);
			exit(0);
		}
		gender_name_pair_index += 2;	// Update gender-name pair index
	}

	// Parent process waits for children and terminates at the end
	for(int i = 0; i < number_children; i++)
		wait(NULL);

	cout << "All child processes terminated. Parent exits." << endl;
	return 0;
}
