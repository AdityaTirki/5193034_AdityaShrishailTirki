/*
1.A pointer to a union points to the memory location allocated to the union.
A union pointer is declared by using the keyword union and the union tag along with * and the pointer name. 
For example, consider the following statements
*/
/*#include <stdio.h>
#include <string.h>

union val {
    int int_num;
    float fl_num;
    char str[20];
};

int main() {
    union val info;
    union val *ptr = NULL;
    ptr = &info;
    ptr->int_num = 10;
    printf("info.int_num is %d", info.int_num);
    return 0;
}
/*
When you want to access the union members through a pointer, the -> operator is required.
(*ptr).int_num is the same as ptr->int_num.
*/

/*
2.Unions as Function Parameters 
A function can have union parameters that accept arguments by value when a copy of the union variable is all that is needed. 
For a function to change the actual value in a union memory location, pointer parameters are required. 
For example:
*/
#include <stdio.h>
#include <string.h>

union id {
    int id_num;
    char name[20];
};

void set_id(union id *item);
void show_id(union id item);

int main() {
    union id item;
    set_id(&item);
    show_id(item);
    return 0;
}

void set_id(union id *item) {
    item->id_num = 42;
}

void show_id(union id item) {
    printf("ID is %d", item.id_num);
}