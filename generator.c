#include <stdlib.h>


/*

Generator

Your generator program writes randomly generated integers to standard output (by default), or to a file (if specified by the
user). The integers themselves should be preceded by the number of integers that will follow, should appear one integer
per output line, separated only by a single newline character (‘\n’). This specification is intended to match the input
format that the sorter program expects. The number of integers and the range within which they fall are specified on the
command line (see below), or with default values (also specified below). Your generator program should be compatible
with your sorter program in the sense that your sorter should successfully read and sort integers produced by your
generator. 

Interface, Options, and Parameters

Your programs should support the following interfaces:

prog1sorter [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>]
[-i <input-file-name>] [-o <output-file-name>] [-c <count-file-name>]

prog1generator [-u] [-n <num-integers>] [-m <min-int>] [-M <max-int>]
[-s <seed>] [-o <output-file-name>]

Brackets indicate that all the arguments are optional; your program should support a replaceable default for each, as
specified and described below. The user may specify options in any order. The meaning of each argument follows:

-u
	Print a usage string for your program on stderr and then exit. If –u appears anywhere on the command line, the
	program should ignore all other arguments, print the usage string, and exit.

-n <num-integers>
	Your generator program should generate <num-integers> random integers.

	Your sorter program should read (at most) the first <num-integers> values from the input file (or
	from standard input), sort them, and write them out to the output file (or standard output).
	If the input file (or stdin) contains more than <num-integers> values, your program should simply
	ignore the rest.

	For both programs, the minimum value for <num-integers> is 0. The default value for <numintegers> is 100. There is no maximum value for <num-integers>. If the user specifies a negative
	value for <num-integers>, the program should print an informative error message to stderr and
	exit immediately.

-m <min-int>
	Your generator program should generate integers no smaller than <min-int>.

	Your sorter program should check for integers in the input that have a value less than <min-int>, and
	halt with an informative error message as soon as the first one appears.

	The default and minimum acceptable value for <min-int> is 1.

-M <max-int>
	Your generator program should generate integers no larger than <max-int>.

	Your sorter program should check for integers in the input have a value greater than <max-int>, and
	halt with an informative error message as soon as the first one appears.

	The default value for <max-int> is 255. The maximum value for <max-int> is 1,000,000. <maxint> must not be less than <min-int>.

-s <seed>
	By default, your generator program should seed the random number generator with a value derived from
	reading the system clock. If the user specifies the –s option, then your program should instead seed the
	random number generator with <seed>. You may assume that <seed> is an unsigned long (and pass it
	directly to srand()). (When writing code that produces pseudo-random values for testing, seeding the
	random number generator with a time value is good practice. When debugging your code, you often want
	the same random values to be produced for every run, so that the same behavior occurs each run. This
	option allows you to select whether the numbers are pseudo-random or deterministic, on the command
	line.)

	Note that the –s option is not allowed for the sorter program.

-i <input-file-name>
	By default, your sorter program should read input from stdin. If –i is specified on the command line, it
	should instead read input from the file named <input-file-name>.

	Note that the –i option is not supported by the generator program.

-o <output-file-name>
	By default, your programs should write output to stdout. If – o is specified on the command line, it
	should instead write output to the file named <output-file-name>. Your programs should
	overwrite the contents of <output-file-name> if it exists when your program is invoked.

-c <count-file-name>
	As described above, your sorter should write the ASCII value and a count of the number of instances of
	each letter in the Unix username of the person running the program. (Do not hardcode your own userid
	into your program!) By default, your sorter program should write these values and counts to stdout. If
	the user specifies the –c option, then your program should write the counts to <count-file-name>.
	
	Note that the generator program does not support the –c option.

If the user specifies an option that your program does not support (-z for example), your program should print the
usage string to standard error (stderr), and exit. If the user does not specify an argument where one is expected,
the program should likewise report the problem, print the usage string to stderr, and then exit. You may assume
that file names do not begin with a dash, and that the user specifies no negative numbers on the command line.
Thus, you may assume that every command line option that begins with a dash (‘-‘) corresponds to an option to
your program. 

*/

int main(int argc, char **argv)
{
	char *p=getenv("USER");
    if(p==NULL) return EXIT_FAILURE;
    printf("%s\n",p);
    return 0;
}
