# Enums

Sometimes you don't want to store a number or a piece of text.  
Instead, you want to store something from a list of **symbols**.  
If you want to record a day of the week, you only want to store MONDAY, TUESDAY, WEDNESDAY, etc.  
You don't need to store the text, because there are only ever going to be seven different values to choose from.  
**That's why enums were invented.**  
`enum colors {RED, GREEN, PUCE};`  
Any variable that is defined with a type of enum colors can then only be set to one of the keywords in the list,
and the enum will just store a number.  
But you don't need to worry about what the numbers are; your C code can just refer to the symbols.  
That'll make your code easier to read, and it will prevent storing values like REB or PUSE.

***This will not compile:***  
`enum colors favorite = PUSE;`