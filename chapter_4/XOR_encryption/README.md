# Shared code
If we want to share code between programs we need to create a header file in addition to the C file.  
Then we need to include the header file in our program. We can call the functions from the header file
(because we have defined the functions there. (we can also define variables we want to share with the export command. e.g.: export int some-name))  
This allows us to create large programs since we can break the code down into simpler files.  
The bigger the program gets the longer it will take to compile the code because with every compilation the compiler needs to:
 - preprocess
 - compile
 - assemble
 - link

This can be avoided by saving copies of the object code for every file.  
The compiler then compiles this one file and links it to the executable which saves a lot of time.  

## How do we compile the source into object files?
By calling: ***gcc -c \*.c***  
This will compile the code but doesn't link it.
The *.c will match every C file in the current directory, and the -c will tell the compiler that you want to create an object
file for each source file, but you don't want to link them together into a full executable program.

## So how do we link them together?

By calling: ***gcc \*.o -o launch***  
The compiler is smart enough to recognize the files as object files, rather than source files, so it will skip most of the compilation
steps and just link them together into an executable program called launch.  

***So if we now want to change a single file we only need to call gcc -c thruster.c and gcc \*.o -o launch***  
This will result in compile times up to 95% faster.

## make
make is a tool that can run the compile command for you.  
The make tool will check the timestamps of the source files and the generated files, and then will only
recompile the files if things have gotten out of date.
But before it can do all these things, you need to tell make about your source code.  
It needs to know the details of which files depend on which files.  
And it also needs to be told exactly how you want to build the code.
For every target, make needs to be told two things:
 - The depenedencies  
   Which files the target is going to be generated from.
 - The recipe  
   The set of instructions it needs to run to generate the file.  

Together, the dependencies and the recipe form a rule.  
A rule tells make all it needs to know to create the target file.

All the recipe lines MUST begin with a tab character.  
If you just try to indent the recipe lines with spaces, the build won't work.


