//sorter.c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*

Sorter

The sorter reads a sequence of integers from standard input or from a file and outputs three different things:
	• the sorted values, to standard output (stdout) by default, or to an output file (if one is specified by the user)
	• a report about the counts of a few of the integers in the input, written to standard output by default, or to an output
	file if one is specified by the user
	• the elapsed time of the program, written to standard error (stderr).

To sort, you should call the qsort() C library function. Read the man pages or online documentation to determine how
to prepare the data for qsort(), and how to call the function. Using new library and system call functions is
fundamentally important to becoming an effective systems programmer. Sorted values should appear one per line of
output, in text format. Duplicate values in the input should appear in the output.

Your program should count and report the number of occurrences of integers that correspond to the ASCII value of letters
in the Linux userid of the person running the program. An example report for user mlewis appears below.

m 109 5
l 108 3
e 101 6
w 119 7
i 105 2
s 115 5

The output should appear exactly as above; the userid characters (no matter whether they are lowercase letters, capital
letters, or digits) appear in the order they appear in the userid, one per line. Each character is followed on each line by the
ASCII value of the letter and then a count of the number of times that ASCII value appeared in the input. One tab
character (‘\t’) should separate the letter and the ASCII value, and one more should separate the ASCII value and the
count. Lines should contain no trailing whitespace, other than a single newline character (‘\n’). Repeated letters in the
userid should be repeated in the output. For example:

n 110 69
e 101 58
l 108 66
l 108 66
y 121 61
4 52 53

Sometimes we will build programs that check your output automatically. If it is not formatted exactly according to
specifications, then either we have to take off way too many points, or grading becomes much more difficult. Let’s get
used to specifying (me) and producing (you) precisely formatted output.

Whether the program uses files or standard input and output depends on command line options, as described in more
detail under the program command line options below.

Your program should also report the time elapsed, in seconds (with a decimal part that includes precision to the
microsecond) of your program. Timing should be done within your code, not from the shell. Start the timing after parsing
command line arguments, and stop the timing after writing the last bit of output (other than time elapsed). Report the
elapsed time on stderr, not on stdout.

The positive integers to be sorted appear as input, one per line, in text format (i.e. not binary). Text format can be read
directly by scanf() (among other functions), and written using fprintf() (among other functions).

You may assume that the input contains valid positive integers only, and ends with a Control-D, the Linux end-of-file
(EOF) character. Your program should read until EOF or the number of specified integers is reached (see -n below),
whichever comes first.

Please do not prompt the user for values; you should assume that the user knows how to use the program. You may
include instructions after printing a “usage string” in response to “prog1sort –u” if you wish.

*/

int compare(const void * a, const void * b)
{
  return (*(int*)a - *(int*)b);
};

void outputToFile(char* output, int size, int[] nums)
{
	FILE* opf;
	if((opf = fopen(outputFile, "w")) == NULL)
	{
		fprintf(stderr, "Output file failed to open\n");
		return 1;
	}
	for(int i = 0; i < size; i++)
	{
		fprintf(opf, "%d", nums[i]);
	}
};

void outputToTerminal(int size, int[] nums)
{
	for(int i = 0; i < size; i++)
	{
		fprintf(stdout, "%d", nums[i]);
	}
};

void outputUserID(int size, int[] nums)
{
	
};

int main(int argc, char **argv)
{
	int opt, numInts, minInt, maxInt;
	char* inputFile[], outputFile[], countFile[];
	bool numIntsExists = false;
	bool maxIntExists = false;
	bool minIntExists = false;
	bool inputFileExists = false;
	bool outputFileExists = false;
	bool countFileExists = false;
	while((opt = getopt(argc, argv, ":if:lrx")) != -1)  
    {  
        switch(opt)  
        {
			case 'u':
				fprintf(stderr, "prog1sorter [-u] [-n <num-integers> [-m <min-int> [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]");
				exit(0);
			case 'n':
				numInts = optarg;
				if(numInts < 0)
				{
					fprintf(stderr, "number of integers cannot be negative");
					exit(0);
				}
				numIntsExists = true;
				break;
			case 'm':
				minInt = optarg;
				if(minInt < 1)
				{
					fprintf(stderr, "min-int must be greater than or equal to 1");
					exit(0);
				}
				minIntExists = true;
				break;
			case 'M':
				maxInt = optarg;
				if(maxInt > 1000000)
				{
					fprintf(stderr, "max-int must be less than or equal to 1000000");
					exit(0);
				}
				if(minIntExists && maxInt < minInt)
				{
					fprintf(stderr, "max-int must not be less than min-int");
					exit(0);
				}
				maxIntExists = true;
				break;
			case 'i':
				inputFile = optarg;
				inputFileExists = true;
				break;
			case 'o':
				outputFile = optarg;
				outputFileExists = true;
				break;
			case 'c':
				countFile = optarg;
				countFileExists = true;
				break; 
            case ':':  
                fprintf(stderr, "prog1sorter [-u] [-n <num-integers> [-m <min-int> [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]");
                exit(0);
            case '?':  
                fprintf(stderr, "prog1sorter [-u] [-n <num-integers> [-m <min-int> [-M <max-int>] [-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]");
                exit(0); 
        }  
    }
	
    // optind is for the extra arguments 
    // which are not parsed 
    /*for(; optind < argc; optind++)
    {      
        fprintf(stderr, "extra arguments: %s\n", argv[optind]);  
    }*/
	
	if(!numIntsExists)
	{
		numInts = 100;
	}
	if(!minIntExists)
	{
		minInt = 1;
	}
	if(!maxIntExists)
	{
		maxInt = 255;
	}
    
    if(inputFileExists == true)							//input file given
    {
		FILE* ipf;
		//ipf = fopen(inputFile, "r");
		if((ipf = fopen(inputFile, "r")) == NULL)
		{
			fprintf(stderr, "Input file failed to open\n");
			return 1;
		}
		int* numList = malloc(numInts*sizeof(int));
		for(int i = 0; i < numInts; i++)
		{
			fscanf(ipf, "%d", numList[i]);
			if(numList[i] > maxInt)
			{
				fprintf(stderr, "input contains an integer greater than max-int");
				exit(0);
			}
			if(numList[i] < minInt)
			{
				fprintf(stderr, "intput contains an integer less than min-int");
				exit(0);
			}
		}
		qsort(numList, numInts, sizeof(int), compare);
		if(outputFileExists == true)				// output file given
		{
			outputToFile(outputFile, numInts, numList);
		}
		else										// no output file given
		{
			outputToTerminal(numInts, numList);
		}
		free(numList);
	}
	else												// no input file given
	{
		int* numList = malloc(numInts*sizeof(int));
		for(int i = 0; i < numInts; i++)
		{
			scanf("%d", numList[i]);
			if(numList[i] > maxInt)
			{
				fprintf(stderr, "input contains an integer greater than max-int");
				exit(0);
			}
			if(numList[i] < minInt)
			{
				fprintf(stderr, "intput contains an integer less than min-int");
				exit(0);
			}
		}
		qsort(numList, numInts, sizeof(int), compare);
		if(outputFileExists == true)				// output file given
		{
			outputToFile(outputFile, numInts, numList);
		}
		else										// no output file given
		{
			outputToTerminal(numInts, numList);
		}
		free(numList);
	}
	return 0;
}


