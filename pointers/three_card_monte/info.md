###char *cards
The reason why we get a segmentation fault is that this gets put into read-only memory because it is a constant (also known as literal)!  
####It is good practice to use const char *cards because this lets the compiler throw an error if we try to change it.  
If we want to shuffle the cards we need to use
###char cards [ ]

