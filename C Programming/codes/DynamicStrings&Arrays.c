/*
When allocating memory for a string pointer, you may want to use string length rather than the sizeof operator for calculating bytes. 
Consider the following program:
This approach is better memory management because you aren’t allocating more space than is needed to a pointer. When using strlen to determine the number of bytes needed for a string, be sure to include one extra byte for the NULL character '\0'.

A char is always one byte, so there is no need to multiply the memory requirements by sizeof(char).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str20[20];
    char *str = NULL;

    strcpy(str20, "12345");
    printf("str20 size: %ld\n", sizeof(str20));
    printf("str20 length: %ld\n", strlen(str20));
    str = malloc(strlen(str20)+1); /* make room for \0 */
    strcpy(str, str20);
    printf("%s", str);

    return 0;
}