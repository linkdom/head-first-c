
typedef struct {
    short count;
    float weight;
    float volume;
} fruit; //This is bad because it will have no field called quantity and so it won't be clear.

//That's where unions come into play



// So how do we assign unions?

//for the first value only we can do quantity q = {4};
//for all other fields we can do quantity q = {.weight=1.5};
//or we can do q.weight = 1.5 (which I find the easiest)
