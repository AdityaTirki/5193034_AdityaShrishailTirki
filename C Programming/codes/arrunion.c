/*
1.Array of Unions 
An array can store elements of any data type, including unions. 

With unions, it is important to keep in mind that only one member of the union can store data for each array element.

After declaring an array of unions, an element is accessible with the index number. The dot operator is then used to access members of the union, as in the program:

*/
#include <stdio.h>

union val {
    int int_num;
    float fl_num;
    char str[20];
};

int main() {
    union val nums[10];
    int k;

    /* create an array of ints */
    for (k = 0; k < 10; k++) {
        nums[k].int_num = k;
    }

    /* display array values */
    for (k = 0; k < 10; k++) {
        printf("%d ", nums[k].int_num);
    }

    return 0;
}
/*
An array is a data structure that stores collection values that are all the same type. Arrays of unions allow storing values of different types
*/