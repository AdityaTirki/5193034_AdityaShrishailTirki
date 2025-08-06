//The following program demonstrates writing to a file
#include <stdio.h> // Includes the standard input/output library for functions like printf, fopen, fclose, etc.

int main() {
    FILE *fptr; // Declares a file pointer to manage the file operations.
    char filename[50]; // Declares a character array to store the filename, with a maximum length of 50 characters.
    char c; // Declares a character variable to store individual characters read from the file.

    printf("Enter the filename of the file to create: "); // Prompts the user to enter a filename.
    gets(filename); // Reads the entered filename from the user. Note: `gets()` is unsafe and `fgets()` is preferred for security.

    fptr = fopen(filename, "w"); // Opens the file in "write" mode. If the file doesn't exist, it's created; if it exists, its content is truncated.

    /* write to file */ // A comment indicating the start of the file writing section.
    fprintf(fptr, "Inventory\n"); // Writes the string "Inventory" followed by a newline character to the file.
    fprintf(fptr, "%d %s %f\n", 100, "Widget", 0.29); // Writes formatted data (integer, string, float) to the file.
    fputs("End of List", fptr); // Writes the string "End of List" to the file. Note: `fputs()` does not add a newline automatically.

    fclose(fptr); // Closes the file, saving the written content.

    /* read the file contents */ // A comment indicating the start of the file reading section.
    fptr = fopen(filename, "r"); // Opens the same file in "read" mode to read its content.

    while ((c = getc(fptr)) != EOF) { // Loops through the file, reading one character at a time until the end of the file (EOF) is reached.
        printf("%c", c); // Prints each character read from the file to the console.
    }

    fclose(fptr); // Closes the file after reading.
    return 0; // Indicates successful program execution.
}