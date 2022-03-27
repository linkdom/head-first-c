# Summary
A struct is a data type made from a sequence of other data types.  
structs are fixed in length  
struct fields are accessed by name, using the struct.field_name syntax (aka dot notation)  
struct fields are stored in memory in the same order they appear in the code.  
You can nest structs.  
typedef creates an alias for a data type.  
If you use typedef with a struct, then you can skip giving the struct a name.  

***If you pass a struct into a function it gets copied so if you modify it in that function remember that you only modify the copy!***  
***If we actually want to modify it we need to pass the pointer and then manipulate it***

## (*t).age vs. *t.age

If you wrap the pointer with parentheses you will get the item Itself while if you don't you will get the memory location of the struct.  
So *t.age would be the same as *(t.age) which will return the contents of the memory location but t.age isn't a memory location.  

### (*t).age is exactly the same as t->age
So we might aswell use the "->" since it is way more readable imo.
