#Important note
Care is needed if one assigns an array to a pointer variable. We remember: Arrays are just pointers to the starting location BUT! the array pointer also holds the information about the length of the array. So when I call sizeof() on the array it will give me the size(length) of the array. If I assign that array to a pointer variable it will only return 4 (on 32-bit systems) and 8 (on 64-bit systems) since that is the size of a pointer. This is called "decay". It happens also when you pass an array into a function so it is ultimately unavoidable but it needs to be remembered otherwise bugs bugs bugs :)

###scanf()
- can be used to enter more than one field  
- cannot be used to enter strings that contain spaces  

scanf() takes an array with a fixed length (which if we remember is just a pointer to the beginning of the array) and then updates these memory addresses with the input (what a genius thing that is :D)  
Same goes with integers and floating point numbers

scanf("%i", &integerVariable)  
scanf("%31s", arrayVariable)  
scanf("%i", &floatingVariable)

####We need to be careful to always specify the same length in scanf as in the array otherwise we will get a segfault which is a security issue.

###fgets()  
 - can only receive strings
 - can take input containing spaces  

As an alternative we might want to use fgets since it takes three arguments fgets(array, sizeof(array), stdin) so it needs the length of the array to even execute which is more secure

####Again, care is needed with sizeof() since it could return the size of the pointer if we are careless
####Dont't use gets()!

###Memory
(Highest to Lowest)

- Stack
- Heap
- Globals
- Constants (Read-only section)
- Code (Read-only section)


