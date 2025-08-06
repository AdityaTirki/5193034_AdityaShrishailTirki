//The following program demonstrates writing to and reading from binary files:
#include <stdio.h> // Standard input-output library for functions like printf, fopen, fclose, fread, fwrite

int main() {
    FILE *fptr; // Declare a file pointer for file operations
    int arr[10]; // Declare an integer array 'arr' of size 10
    int x[10];   // Declare another integer array 'x' of size 10
    int k;       // Declare an integer variable 'k' for loop control

    /* Generate array of numbers */
    // Loop to initialize 'arr' with values from 0 to 9
    for (k = 0; k < 10; k++) {
        arr[k] = k; // Assign 'k' to the k-th element of 'arr'
    }

    /* Write array to file */
    // Open "datafile.bin" in write binary mode ("wb")
    fptr = fopen("datafile.bin", "wb");
    // Write the contents of 'arr' to the file
    // sizeof(arr[0]) is the size of one element (int)
    // sizeof(arr)/sizeof(arr[0]) calculates the number of elements in 'arr'
    fwrite(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fptr);
    fclose(fptr); // Close the file

    /* Read array from file */
    // Open "datafile.bin" in read binary mode ("rb")
    fptr = fopen("datafile.bin", "rb");
    // Read data from the file into array 'x'
    // The arguments are similar to fwrite, ensuring the correct amount of data is read
    fread(x, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fptr);
    fclose(fptr); // Close the file

    /* Print array */
    // Loop to print the elements of array 'x'
    for (k = 0; k < 10; k++) {
        printf("%d ", x[k]); // Print each element followed by a space
    }
    printf("\n"); // Print a newline character for better formatting

    return 0; // Indicate successful program execution
}