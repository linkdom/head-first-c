###char *cards
The reason why we get a segmentation fault is that this gets put into read-only memory because it is a constant (also known as literal)!

If we want to shuffle the cards we need to use
###char cards [ ]

