# Summary

### Piping
Programs can be piped together by using the | between the two program calls. E.g. (./program1 | ./program2)  
What the piping does is it gets something from the stdout of the first program and passes it into the stdin of the second  
Programs that are piped together run at the same time and not sequentially.  

### Data Streams
By default there are only 3 data streams (1 input, 2 outputs) but with the help of fopen we can create our own data streams.  
E.g.: (FILE \*input = fopen(argv[2], "w");) and as we learned if we use the fprintf function we can define where to read from/write our data to.  
There is a limit to how many you can have but it is very large (256 or something)  

Modes:
 - "r" - Read
 - "w" - Write
 - "a" - Append

### Arguments
I can define arguments by passing int argc (argument count) and char *argv\[\] (argument values) into the main function.
argv starts at 1 because the execution call itself is 0.  
E.g.: int main(int argc, char *argv[])

### Options 
I can also define options with the help of "unistd.h".  
while((ch = getopt(argc, argv, "ae:")) != EOF)  
I can define them with a switch;case statement to check for the valid options.  
afterwards i need to decrease the argc by the number of arguments read, this i can do with argc -= optind; and argv += optind;  
It is important to note that after we processed the options, the 0th argument will not be the program call itself anymore but the 1st argument  
A ":" following an option in the string means that the option takes an additional argument.

### POSIX

POSIX stands for "Portable Operating System Interface" and was an attempt to create a common set of functions for use across all popular operating systems.
