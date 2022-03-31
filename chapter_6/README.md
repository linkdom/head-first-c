# Data Structures and Dynamic Memory

## Linked Lists
A **linked list** is an example of an **abstract data structure.**  
It's called an *abstract* data structure because a linked list is *general*: it can be used to store a lot of different kinds of data.  
In a linked list, as long as you know where the list starts, you can travel along the list of links, from one piece of data
to the next, until you reach the end of the list.  

***Linked lists allow inserts***  
Another advantage linked lists have over arrays is that inserting data is very quick.  
If you wanted to insert a value into the middle of an *array*, you would have to shuffle all the pieces of data that follow
it along by one.  
So linked lists allow you to ***store a variable amount of data***, and they make it ***simple to add more data***.  

***Recursive structures need a name***
```
typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;
```
***This is because a linked list needs a pointer to the same type!***

## Null
**In C, NULL actually has the value 0, but it's set aside specially to set *pointers* to 0.**  

## Q&A
**What if I want to use the 700th item in a really long list? Do I have to start at the first item and then read all the way through?**  
Yes, you do.  
**So if I want a data structure that lets me insert things quickly, I need a linked list, but if I want direct access I might use an array?**  
Exactly.  
**Can a *struct* contain a whole recursive *struct* itself?**  
No.  
**Why not?**  
C needs to know the exact amount of space a struct will occupy in memory.  
If it allowed full recursive copies of the same struct, then one piece of data would be a different size than another.  

## The heap is used for dynamic storage
We can do that by using the malloc() function.  
You tell the malloc() function exactly how much memory you need, and it asks the operating system to set that much memory aside in the heap.  
The malloc() function then returns a **pointer** to the new heap space, a bit like getting a key to the locker.  
It allows you access to the memory, and it can also be used to keep track of the storage locker that's been allocated.  

### Give the memory back when you are done
The good news about heap memory is that you can keep hold of it for a really long time.  
The bad news is...you can keep hold of it for a really long time.  
When we are using the stack, we didn't need to worry about returning memory; it all happened automatically.  
Every time we leave a function, the local storage is freed from the stack.  
The heap is different. Once you've asked for space on the heap, it will never be available
for anything else until you tell the C Standard Library that you're finished with it.  
There's only so much heap memory available, so if your code keeps asking for more and more heap space, your program will quickly
start to develop memory leaks.

***Memory Leaks***  
A memory leak happens when a program asks for more and more memory without releasing the memory it no longer needs.  
Memory leaks are among the most common bugs in C programs, and they can be really hard to track down.  
***The heap has only a fixed amount of storage available, so be sure you use it wisely.***  

### Ask for memory with malloc()
malloc() takes a single parameter: the number of bytes that you need.  
Most of the time, we probably don't know exactly how much memory we need in bytes, so malloc() is almost always used with 
an operator called *sizeof*, like this:

```
#include <stdlib.h>
 
/*
* We need to include this to get 
* access to malloc() and free()
*/

malloc(sizeof(island));
```
**sizeof tells you how many bytes a particular data type occupies on your system**  
***We can free memory by using the free() function.  
The free() takes the address of the memory so in our case free(island)***

### strdup()
#### (string.h library)  
The strdup() works out how long the string is, and then calls the malloc() function to allocate the correct number of characters on the heap.  
It then copies each of the characters to the new space on the heap.  
It can't create space on the stack because that's for *local* variables, and local variables get cleared away too often.  
But because strdup() puts new strings on the heap, that means you must always remember to release their storage with the free() function.  

### Dynamic memory allocation lets you create the memory you need at RUNTIME.
### And the way you access dynamic heap memory is with malloc() and free().
## Q&A
***If the island struct had a name array rather than a character pointer, would I need to use the strdup() here?***  
No. Each island struct would store its own copy, so you wouldn't need to make your own copy.

***So why would I want to use *char* pointers rather than arrays in my data structures?***  
char pointers won't limit the amount of space you need to set aside for strings. If you use char arrays, you will need to decide in advance exactly how long your strings might need to be.

***Why is the heap called the heap?***  
Because the computer doesn't automatically organize it. It's just a big heap of data.

***What's garbage collection?***  
Some languages track when you allocate data on a heap and then, when you're no longer using the data, they free the data from the heap.  

***Why doesn't C contain garbage collection?***  
C is quite an old language; when it was invented, most languages didn't do automatic garbage collection.  

***Does *strdup()* actually call the *malloc()* function?***  
It will depend on how the C Standard Library is implemented, but most of the time, yes.  

***Do I need to free all my data before the program ends?***  
You don't have to; the operating system will clear away all of the memory when the program exits.
But it's good practice to always explicitly free anything you've created.

## Bullet Points

 - Dynamic data structures allow you to store a variable number of data items.
 - A linked list is a data structure that allows you to easily insert items.
 - Dynamic data structures are normally defined in C with recursive structs.
 - A recursive struct contains one or more pointers to a similar struct.
 - The stack is used for local variables and is managed by the computer.
 - The heap is used for long-term storage. You allocate space with malloc().
 - The sizeof operator will tell you how much space a struct needs.
 - Data will stay on the heap until you release it with free().
