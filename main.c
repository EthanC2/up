#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *dynpath = NULL, *cache[] = { "..", "../..", "../../..", "../../../..", "../../../../.." };
    long int up = 0;

    if (argc != 2)
    {
        fputs("usage: up INT\n", stderr);
        exit(1);
    }
    
    up = atoi(argv[1]);
    if (up <= 0)
    {
        fprintf(stderr, "\"%s\" is not a valid integer greater than 0\n", argv[1]);
        exit(2);
    }

    /*
        3 Unique cases:
        - Where n = 1: ".."
        - Where n = 2: "../.."
        - Where n > 2: "../$(repeat ".." n-2 times, join with '/')/.."
            - For the case n > 2, the number of characters required is:
                - 2*n for each ".." used go up a directory
                - n-1 for the '/' separating each pair of ".."
 
        However, since 1-5 are common, they are hardcoded to prevent unncessary allocation.
    */
    switch (up)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            puts(cache[up-1]);
            break;
        default:
            dynpath = (char*) malloc((2*up + up-1 + 1) * sizeof(char));
            int nchars = up*3;

            for(int i=0; i < nchars-3; i += 3)
            {
                dynpath[i] = '.';
                dynpath[i+1] = '.';
                dynpath[i+2] = '/';
            }

            dynpath[nchars-3] = '.';
            dynpath[nchars-2] = '.';
            dynpath[nchars-1] = '\0';
            puts(dynpath);

            free(dynpath);

    }

    return EXIT_SUCCESS;
}