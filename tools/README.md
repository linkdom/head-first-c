# Summary
There is one input (stdin) and two outputs (stdout, stderr).
The error code for the stderr is 2.  
We can redirect data into the stdin by using the < operator so for example **./program < file**  
We can redirect the output too by using **./program < inputFile > outputFile**  

- The standard output goes to the display by default.
- Scanf() reads data from the Standard Input.
- The standard input reads data from the keyboard by default.
- The standard error is reserved for outputting error messages.
- The standard error can be redirected using 2>.

### printing
***printf("something: %s", something);*** is exactly the same as
***fprintf(stdout, "something: %s", something)*** but with this function we can specify if we want to send it to *stdout* or *stderr*.

 