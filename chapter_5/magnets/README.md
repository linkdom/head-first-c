# Bitfields
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
