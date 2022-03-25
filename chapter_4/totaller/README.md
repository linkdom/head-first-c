# Header files

A header file is recognized by its file ending which is ".h"  
In the header file we can define function declarations.  
Be careful to import your own header file with double quotes instead of angle brackets.  
Angle brackets tell the compiler that it should look somewhere off in the directories where the library code lives.  
The double quotes are telling the compiler to look for a local file.  
Local header files can also include directory names, but you will normally put them in the same directory as the C file.

## What directories will the compiler search
The gcc compiler knows where the standard headers are stored.  
On a Unix-style operating system, the header files are normally in places like /usr/local/include, /usr/include, and a few others.

## What is the preprocessor
Preprocessing is the first stage in converting the raw C source code into a working executable.  
Preprocessing creates a modified version of the source just before the proper compilation begins.  
In your code, the preprocessing step read the contents of the header file into the main file.

## Does the preprocessor create an actual file?
No, compilers normally just use pipes for sending the stuff through the phases of the compiler to make things more efficient.

## note
\#include is a preprocessor instruction. 

#IMPORTANT
Do not forget the semicolons in the header file otherwise the compiler will go bonkers if you try to compile the C code!!
