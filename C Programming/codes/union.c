#include <stdio.h>
#include <string.h>
union val {
    int int_num;
    float fl_num;
    char str[20];
    /* data */
 };/*
int main (){
    union val test;
    test.int_num =42;
    printf("%d", test.int_num);
    return 0;
}
*/
  /*
  2.After declaring a union, you can declare union variables. You can even
  assign one union to another of the same type:
  */  
 /*int main() {
    union val u1;
    union val u2;
    u1.int_num = 42;
    u2 = u1;
    printf("%d", u2.int_num);
    return 0;
 }*/
/*
3.You access the members of a union variable by using the . dot operator between the variable name and the member name. 

When assignment is performed, the union memory location will be used for that member until another member assignment is performed. 

Trying to access a member that isn't occupying the memory location gives unexpected results.

The following program demonstrates accessing union members:
*/
int main () {
    union val test;
    test.int_num = 123;
    test.fl_num = 98.76;
    strcpy(test.str,"hello");

    printf("%d\n", test.int_num);
    printf("%f\n", test.fl_num);
    printf("%s\n", test.str);
    return 0;

    
}
/*
Explanation:
1. Union Behavior:
A union in C allows different data types to share the same memory location. The size of the union is determined by the size of its largest member. When you assign a value to one member of the union, it overwrites the values of the other members because they all occupy the same memory space.
2. test.int_num = 123;:
The int_num member is assigned the value 123.
3. test.fl_num = 98.76;:
The fl_num member is assigned the value 98.76. This overwrites the memory location previously holding int_num.
4. strcpy(test.str, "hello");:
The str member (a character array) is assigned the string "hello". This overwrites the memory location previously holding fl_num.
5. printf("%d\n", test.int_num);:
When test.int_num is printed, it attempts to interpret the bytes currently in the union's memory as an integer. Since the last operation was strcpy which wrote "hello" to test.str, the memory contents are now related to the string "hello". Interpreting these bytes as an integer typically results in 0 or a garbage value, depending on the system and the specific memory layout of the string. In many common scenarios, especially on systems where the string "hello" doesn't align perfectly to form a valid integer representation or when the integer part of the union is zeroed out by the string operation, the output for an integer read after a string write to a union is 0.
6. printf("%f\n", test.fl_num);:
Similarly, when test.fl_num is printed, it attempts to interpret the bytes in the union's memory as a float. Again, since the last operation was strcpy, the memory contents are related to the string "hello". Interpreting these bytes as a float typically results in 0.000000 or a garbage value.
7. printf("%s\n", test.str);:
When test.str is printed, it correctly outputs the string "hello" because strcpy successfully placed this string in the union's shared memory location
*/