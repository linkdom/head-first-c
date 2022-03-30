# Using Multiple Source Files
## Data Types

### char
Each character is stored in the computer's memory as a character code.  
And That's just a number. So when the computer sees A, to the computer it's the same as seeing the literal number 65.
(65 is the ASCII code for A.)

### int (%i)
If you need to store a whole number, you can generally just use an int.  
The exact maximum size of an int can vary, but it's guaranteed to be at least 16 bits.  
In general, an int can store numbers up to a few million.

### short (%hi)
But sometimes you want to save a little memory.  
Why use an int if you just want to store numbers up to few hundreds or thousands?  
That's what a short is for.  
A short number usually takes up about half the space of an int.

### long
Yes, but what if you want to store a really large count?  
That's what the long data type was invented for.  
On some machines, the long data type takes up *twice* the memory of an int, and it can hold numbers up in the billions.  
But because most computers can deal with really large ints, on a lot of machines, the long data type is *exactly* the same size as an int.  
The maximum size of a long is guaranteed to be at least 32 bits.

### float (%f)
float is the basic data type for storing floating-point numbers.  
For most everyday floating-point numbers - like the amount of fluid in your orange mocha frappuccino - you can use a float.

### double (%d)
Yes, but what if you want to get really precise?  
If you want to perform calculations that are accurate to a large numer of decimal places, then you might want to use a double.  
A double takes up twice the memory of a float, and it uses that extra space to store numbers that are larger and more precise.

## Header files

A header file is recognized by its file ending which is ".h"  
In the header file we can define function declarations.  
Be careful to import your own header file with double quotes instead of angle brackets.  
Angle brackets tell the compiler that it should look somewhere off in the directories where the library code lives.  
The double quotes are telling the compiler to look for a local file.  
Local header files can also include directory names, but you will normally put them in the same directory as the C file.

### What directories will the compiler search
The gcc compiler knows where the standard headers are stored.  
On a Unix-style operating system, the header files are normally in places like /usr/local/include, /usr/include, and a few others.

### What is the preprocessor
Preprocessing is the first stage in converting the raw C source code into a working executable.  
Preprocessing creates a modified version of the source just before the proper compilation begins.  
In your code, the preprocessing step read the contents of the header file into the main file.

### Does the preprocessor create an actual file?
No, compilers normally just use pipes for sending the stuff through the phases of the compiler to make things more efficient.

### note
\#include is a preprocessor instruction.

***Do not forget the semicolons in the header file otherwise the compiler will go bonkers if you try to compile the C code!!***

## Shared code
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

### How do we compile the source into object files?
By calling: ***gcc -c \*.c***  
This will compile the code but doesn't link it.
The *.c will match every C file in the current directory, and the -c will tell the compiler that you want to create an object
file for each source file, but you don't want to link them together into a full executable program.

### So how do we link them together?

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


