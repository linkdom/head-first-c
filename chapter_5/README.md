# Structs, Unions and Bitfields

## Structs
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

## Unions

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

## Enums

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

## Bitfields
### Sometimes you want control at the bit level
Lets say you need a struct that will contain a lot of yes/no values.  
You could create the struct with a series of shorts or ints:
```
typedef struct {
    short low_pass_vcf;
    short filter_coupler;
    short reverb;
    short sequential
    ...
} synth;
```
Each field will use many bits (0000000000000001).  
And that would work.  
The problem is that it will tak up a lot more space than is needed for just a single bit for **true / false**.  
That's why bitfields were created.

#### C doesn't support binary literals, but it does support hexadecimal literals.

***A bitfield lets you specify how many bits an individual field will store. For example, you could write your code like this:***
```
typedef struct {
    unsigned int low_pass_vcf:1;
    unsigned int filter_coupler:1;
    unsigned int reverb:1;
    unsigned int sequential:1;
    ...
} synth;
```
By using bitfields, you can make sure each field takes up only one bit.  
If you have a sequence of bitfields, the computer can **squash them together** to save space.  
So if you have eight single-bit bitfields, the computer can store them in a single byte.

## Q&A
#### Why do I need 4 bits to store a value up to 10?
Four bits can store values from 0 to binary 1111, which is 15.  
But 3 bits can only store values up to binary 111, which is 7.

#### So what if I try to put the value 0 into a 3-bit field?
The computer will store a value of 1 in it, because 9 is 1001 in binary, so the computer transfers 001.

#### Are bitfields really just used to save space?
No. They're important if you need to read low-level binary information.  
For example if you're reading or writing some sort of custom binary file.

### Binary table just for reiteration

**0:** 0000  
**1:** 0001  
**2:** 0010  
**3:** 0011  
**4:** 0100  
**5:** 0101  
**6:** 0110  
**7:** 0111  
**8:** 1000   
**9:** 1001   
**10:** 1010  
**11:** 1011  
**12:** 1100  
**13:** 1101  
**14:** 1110  
**15:** 1111

## Bullet Points

- A union allows you to store different data types in the same memory location.
- A designated initializer sets a field value by name.
- Designated initializers are part of the C99 standard. They are not supported in C++.
- If you declare a union with a value in {braces}, it will be stored with the type of the first field.
- The compiler will let you store one field in a union and read a completely different field. But be careful! This can cause bugs!
- enums store symbols.
- Bitfields allow you to store a field with a custom number of bits.
- Bitfields should be declared as unsigned int.
