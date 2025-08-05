/*
The calloc() function allocates memory based on the size of a specific item, such as a structure.
The program below uses calloc to allocate memory for a structure and malloc to allocate memory for the string within the structure:
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char *info;
} record;

int main() {
    record *recs;
    int num_recs = 2;
    int k;
    char str[] = "This is information";

    recs = calloc(num_recs, sizeof(record));
    if (recs != NULL) {
        for (k = 0; k < num_recs; k++) {
            (recs+k)->num = k;
            (recs+k)->info = malloc(sizeof(str));
            strcpy((recs+k)->info, str);
        }
    }

    for (k = 0; k < num_recs; k++) {
        printf("%d\t%s\n", (recs+k)->num, (recs+k)->info);
    }

    return 0;
}
/*
calloc allocates blocks of memory within a contiguous block of memory for an array of structure elements. You can navigate from one structure to the next with pointer arithmetic.

After allocating room for a structure, memory must be allocated for the string within the structure. Using a pointer for the info member allows any length string to be stored.

Dynamically allocated structures are the basis of linked lists and binary trees as well as other data structures.
*/
/*
2.The realloc() function expands a current block to include additional memory.
realloc leaves the original content in memory and expands the block to allow for more storage.

Ru
For example:
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = malloc(10*sizeof(*ptr)); /* a block of 10 ints */
    if (ptr != NULL) {
        *(ptr+2) = 50; /* assign 50 to third int */
    }
    ptr = realloc(ptr, 100*sizeof(*ptr)); /* 100 ints */
    *(ptr+30) = 75;
    printf("%d %d", *(ptr+2), *(ptr+30));
    return 0;
}