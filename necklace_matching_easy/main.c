#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR_LEN		(128)
#define NUM_ARGS		(3) //cmd parent sample

bool cyclic_perm_detector(char* parent, char* sample);

int main(int argc, char* argv[])
{
	//only accept two arguments
	if(argc != NUM_ARGS)
	{
		printf("Limit of 2 arguments only");
		return 0;
	}

	//now test the two arguments against eachother
    if( cyclic_perm_detector(argv[1], argv[2]) )
    {
    	printf("It's GOOOD!\n");
    }
    else
    {
    	printf("NOOOOOOPE\n");
    }
    return 0;
}


//I'm looking to see if a given string is a cyclic permutation of the parent string
//first check that the parent and given string are of the same length
//take in two strings, copy the parent string to a new varaible twice (e.g. abc -> abcabc)
//search through this new varaible for the first character in the coppied parent string
//compare the two strings
//if they are not the same keep looking for the first character, it may not be the only instance of that character

bool cyclic_perm_detector(char* parent, char* sample)
{
	//first lets get the string length of these two inputs
	//if they do not match then return false
	uint8_t length;
	if(strlen(parent) == strlen(sample))
	{
		length = strlen(parent);
	}
	else
	{
		printf("The two are not the same length.\n");
		return false;
	}

	//double up the parent so that i can search for all cyclic permutations
	//e.g. all permutation of foo can be found in foofoo
	char double_parent[2 * MAX_STR_LEN];
	sprintf(double_parent, "%s%s", parent, parent);

	//sanity check
	printf("original: \t%i\ndoubled: \t%i\n", length, strlen(double_parent));

	//go through double parent looking for the first character in sample
	//then compare the two strings
	//keep looking until you run our of characters or you find a match, it may not be the only instance of that chacter
	bool result = false;
	for(int i = 0; i <= length; i++)
	{
		//compare chars
		if(double_parent[i] == sample[0])
		{
			//pass the appropriate pointer to strncmp and compare only the correct number of chars
			int val = strncmp(double_parent + i, sample, length);
			if(val == 0)
			{
				//FOUND IT!
				//break out of the loop
				result = true;
				break;
			}
			//else keep looking
		}

	}

	return result;
}