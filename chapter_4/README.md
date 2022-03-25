# Data Types

## char
Each character is stored in the computer's memory as a character code.  
And That's just a number. So when the computer sees A, to the computer it's the same as seeing the literal number 65.
(65 is the ASCII code for A.)

## int
If you need to store a whole number, you can generally just use an int.  
The exact maximum size of an int can vary, but it's guaranteed to be at least 16 bits.  
In general, an int can store numbers up to a few million.

## short
But sometimes you want to save a little memory.  
Why use an int if you just want to store numbers up to few hundreds or thousands?  
That's what a short is for,  
A short number usually takes up about half the space of an int.

## long
Yes, but what if you want to store a really large count?  
That's what the long data type was invented for.  
On some machines, the long data type takes up *twice* the memory of an int, and it can hold numbers up in the billions.  
But because most computers can deal with really large ints, on a lot of machines, the long data type is *exactly* the same size as an int.  
The maximum size of a long is guaranteed to be at least 32 bits.

## float
float is the basic data type for storing floating-point numbers.  
For most everyday floating-point numbers - like the amount of fluid in your orange mocha frappuccino - you can use a float.

## double
Yes, but what if you want to get really precise?  
If you want to perform calculations that are accurate to a large numer of decimal places, then you might want to use a double.  
A double takes up twice the memory of a float, and it uses that extra space to store numbers that are larger and more precise.