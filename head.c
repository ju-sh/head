#include<stdio.h>
#include<stdlib.h>		//for EXIT_FAILURE
#include<getopt.h>

#define DEBUG 1

/*

If verbose and quiet options are opposites of each other, we could use the same flag variable with two values.

Come to think of it! We could even get away with a single variable with different values for the entire set of flags.

*/

// long option only flag variables
static int help_flag, version_flag; 		//default val is 0 as the variables are static.

// short and long options' flag variables for options
static int c_flag, n_flag, q_flag, v_flag, z_flag; 		//default val is 0 as the variables are static.


int main(int argc, char **argv)
{
	// variable to store return value of `getopt_long()`
	int c;

	// option_index variable to hold the index in `long_options` of the long option currently being processed.
	int option_index = 0;

	static struct option long_options[] = {
		{"bytes", required_argument, 0, 'c'},
		{"lines", required_argument, 0, 'n'},
		{"quiet", no_argument, 0, 'q'},
		{"silent", no_argument, 0, 'q'},
		{"verbose", no_argument, 0, 'v'},
		{"zero-terminated", no_argument, 0, 'z'},
		{"help", no_argument, &help_flag, 1},
		{"version", no_argument, &version_flag, 1}	
	};

	while( (c=getopt_long(argc, argv, "c:n:qvz", long_options, &option_index))!=-1 )
	{
		switch(c)
		{
		case 'c':
			break;
		case 'n':
			break;
		case 'q':
			break;
		case 'v':
			break;
		case 'z':
			break;
		case '?':
			if(optopt=='c' || optopt=='n')
			{
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			}
			return EXIT_FAILURE;
		}	
	}
	return 0;
}


/*
To-do
=====
 - default 10 lines without any option
 - mulitple input files
 - no input file => input=stdin
 - k,m, etc multiplier
 - zero terminated
*/
