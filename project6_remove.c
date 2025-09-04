// Daniel Misherky
// U93099650
// This program will read in a file of strings and remove any duplicates in the file.
// The program will then write the strings to a new file without any duplicates.
#include <stdio.h>
#include <string.h> // needed to compare strings to chack for duplicates

int main(int argc, char *argv[]) // allows arguments to be passed in the terminal
{
	char inputs[1000][101]; // initializes 2 arrays of strings with max length of 1000 words
	char outputs[1000][101]; // and each word up to 100 characters long
	int totalcounts = 0; // initializes a counter for the actual numbers of read in the file
	int i,j; // initializes variables for the for loops
	int k = 0; // initializes a index for the output array for unique words
	if(argc != 3) // checks to see that there is an argument for ./a.out, the input file, and the output file
	{
		printf("Invalid number of arguments."); // if not prints error message
		return 1; // returns 1 to indicate an error
		
	}
	else
	{
		FILE *input = fopen(argv[1], "r"); // opens input file to read it
		if(input == NULL) // if file is not found..
		{
			printf("Error opening file \n"); // prints error message
			return 1; // breaks program
		}
		FILE *output = fopen(argv[2], "w"); // opens output file and writes to it
		if(output == NULL) // if file is not found..
		{
			printf("Error opening file \n"); // prints error message
			return 1; // breaks program
		}
		while(!feof(input) && !ferror(input) && totalcounts<1000) // while the file is not at its end and there is no error reading, and the numbers of words are less than 1000
		{
			if(fscanf(input, "%s", inputs[totalcounts])==1) // reads the words in file to inputs array, if it reads 1
			{
				totalcounts++; // increments the total counts of words
			}
		}

		for(i=0; i<totalcounts;i++) // for loop to check for duplicates
		{
			int isDuplicate = 0; // flag variable to check for duplicates
			for(j=0; j<k; j++) // for loop that to compare if the word is already in the output array
			{
				if(strcmp(inputs[i], outputs[j])==0) // if the word is already in the output array
				{
					isDuplicate = 1; // sets the flag to 1
					break; // breaks out of inner loop
				}
			}
			if(isDuplicate==0) // if the word is not in outputs
			{
				strcpy(outputs[k++], inputs[i]); // copies the word into outputs array and increments the index k
			}
		}
		
		int index = 0; // initializes index for the output array
		while(!feof(output) && !ferror(input) && index<k) // while the file is not at its end and there is no error reading, and the index is less than k
		{
			fprintf(output,"%s\n",outputs[index++]); // prints the unique words to the output file
		}
		fclose(input); // closes input file
		fclose(output); // closes output file
	}
	return 0;
}
