# Summary

## structs
A struct is a data type made from a sequence of other data types.  
structs are fixed in length  
struct fields are accessed by name, using the struct.field_name syntax (aka dot notation)  
struct fields are stored in memory in the same order they appear in the code.  
You can nest structs.  
typedef creates an alias for a data type.  
If you use typedef with a struct, then you can skip giving the struct a name.  

***If you pass a struct into a function it gets copied so if you modify it in that function remember that you only modify the copy!***  
***If we actually want to modify it we need to pass the pointer and then manipulate it***

### (*t).age vs. *t.age

If you wrap the pointer with parentheses you will get the item Itself while if you don't you will get the memory location of the struct.  
So *t.age would be the same as *(t.age) which will return the contents of the memory location but t.age isn't a memory location.  

#### (*t).age is exactly the same as t->age
So we might aswell use the "->" since it is way more readable imo.

## unions

Every time you create an instance of a struct, the computer will lay out the fields in memory one after the other.  
A union is different.  
A union will use the space for just one of the fields in its definition.  
It is always set to the size of the largest field.

Defining a union:  
``` 
typedef union {  
    short count;  
    float weight;  
    float volume;  
} quantity;  
```

Assigning a value to the fields:  

First Field: (C89 notation)  
` q = {4}; `  

All other Fields:  
` q = {.weight=1.5}; `

Or:  
` q.weight = 1.5 `  
Which I find the easiest and will probably use the most.


Why is a union always set to the size of the largest field?  
The Computer needs to make sure that a union is always the same size.  
The only way it can do that is by making sure it is large enough to contain any of the fields.  

***Remember:  
Whichever way we set the union's value, there will only ever be one piece of data stored.  
The union just fives us a way of creating a variable that supports several different data types***

### Unions are often used with structs  

Once you've created a union, you've created a new *data type*.  
That means you can use its values anywhere you would use another data type like an int or a struct.  
For example, you can combine them with structs:  
```
typedef struct {
    const char *name;
    const char *country;
    quantity amount;
} fruit_order;
```  
And you can access the values in the struct/union combination using the dor or -> notation you used before:

```
fruit_order apples = {"apples", "England", .amount.weight=4.2};
printf("This order contains %2.2f lbs of %s\n", apples.anount.weight, apples.name);    
```
