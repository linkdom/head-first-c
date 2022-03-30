#include <unistd.h>

int main()
{
    while ((ch = getopt(argc, argv, "ae:")) != EOF)
        switch(ch){
        case 'e':
            engine_count= optarg;
    }

    argc -= optind;
    argv += optind;
}