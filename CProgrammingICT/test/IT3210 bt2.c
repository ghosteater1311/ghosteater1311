#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 80
#define MAX_N 500

// Function to compare strings for sorting
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *strings[MAX_N];
    char input[MAX_STR_LEN + 1];
    int n = 0;

    // Input strings until "END" is encountered or the maximum limit is reached
    printf("Enter strings (maximum of 500, stop by entering 'END'):\n");
    while (n < MAX_N && scanf("%80s", input) == 1 && strcmp(input, "END") != 0) {
        // Allocate memory for each string and copy it
        strings[n] = malloc(strlen(input) + 1);
        strcpy(strings[n], input);
        n++;
    }

    // Sort the list of strings in lexicographical order
    qsort(strings, n, sizeof(char *), compareStrings);

    // Print the sorted list of strings
    printf("List of strings in lexicographical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]); // Free allocated memory for each string
    }

    return 0;
}

