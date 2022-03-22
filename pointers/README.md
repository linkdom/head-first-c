#Pointer Overview

###Stack
This is the section of memory used for **local variable storage**.
Every time you call a function, all of the function's local variables get created on the stack.
It's calles the *stack* because it's like a stack of plates: variables get added to the stack when you enter a function, and get taken off the stack when you leave.
Weird thing is, the stack actually works upside down.
It starts at the top of memory and **grows downward**.

###Heap
The heap is for **dynamic memory:** pieces of data that get created when the program is running and then hang around a long time.

###Globals
A global variable is a variable that lives outside all of the functions and is visible to all of them. Globals get created when the program fist runs, and you can update them freely. 
But that's unlike...

###Constants
Constants are also created when the program first runs, but they are stored in **read-only** memory.
Constants are things like *string literals* that you will need when the program is running, but you'll never want them to change.

###Code
Finally, the code segment.
A lot of operating systems place the code right down in the lowest memory addresses.
The code segment is also read-only.
This is the part of the memory where the actual assembled code gets loaded.
