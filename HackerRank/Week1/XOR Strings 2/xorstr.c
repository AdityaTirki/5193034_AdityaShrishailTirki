#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main() {
    char s[101], t[101];
    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == t[i])
            printf("0");
        else
            printf("1");
    }
    printf("\n");

    return 0;
}
