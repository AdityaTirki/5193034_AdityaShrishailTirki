
//The following program reads a record from a file of structures
#include <stdio.h>
#include <string.h>

// Defines a structure named 'item' to hold an integer ID and a character array for name.
typedef struct {
    int id;
    char name[20];
} item;

int main() {
    FILE *fptr; // Declares a file pointer.
    item first, second, secondf; // Declares three variables of type 'item'.

    // /* create records */
    // Initializes the 'first' and 'second' item structures with specific ID and name values.
    first.id = 10276;
    strcpy(first.name, "Widget");
    second.id = 11786;
    strcpy(second.name, "Gadget");

    // /* write records to a file */
    // Opens a binary file named "info.dat" in write mode ("wb").
    fptr = fopen("info.dat", "wb");
    // Writes the 'first' and 'second' item structures to the file.
    fwrite(&first, 1, sizeof(first), fptr);
    fwrite(&second, 1, sizeof(second), fptr);
    fclose(fptr); // Closes the file.

    // /* file contains 2 records of type item */
    // Re-opens the "info.dat" file in binary read mode ("rb").
    fptr = fopen("info.dat", "rb");

    // /* seek second record */
    // Moves the file pointer to the beginning of the second record.
    // 1 * sizeof(item) calculates the offset to skip the first 'item' record.
    // SEEK_SET indicates that the offset is from the beginning of the file.
    fseek(fptr, 1 * sizeof(item), SEEK_SET);
    // Reads the second record from the file into the 'secondf' item structure.
    fread(&secondf, 1, sizeof(item), fptr);
    // Prints the ID and name of the 'secondf' record.
    printf("%d %s\n", secondf.id, secondf.name);
    fclose(fptr); // Closes the file.

    return 0; // Indicates successful program execution.
}