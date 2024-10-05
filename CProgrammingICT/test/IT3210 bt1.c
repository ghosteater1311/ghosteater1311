#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 80
#define MAX_N 500

int main() {
    int n, i, j, max_len = 0;
    char strings[MAX_N][MAX_STR_LEN + 1];
    char longest[MAX_STR_LEN + 1];
    int letter_count[26] = {0};  // Assuming only uppercase Latin letters are allowed

    // Input the number of strings
    printf("Enter the number of strings (n < 500): ");
    scanf("%d", &n);

    // Input the strings
    printf("Enter %d strings (each with max length 80, no spaces, and only uppercase letters):\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%s", strings[i]);

        // Find the longest string
        int len = strlen(strings[i]);
        if (len > max_len) {
            max_len = len;
            strcpy(longest, strings[i]);
        }

        // Count occurrences of each letter
        for (j = 0; j < len; ++j) {
            if (strings[i][j] >= 'A' && strings[i][j] <= 'Z') {
                letter_count[strings[i][j] - 'A']++;
            }
        }
    }

    // Output the longest string
    printf("Longest string: %s\n", longest);

    // Output the letter occurrences in lexicographic order
    printf("Letter occurrences:\n");
    for (i = 0; i < 26; ++i) {
        if (letter_count[i] > 0) {
            printf("%c:%d ", 'A' + i, letter_count[i]);
        }
    }
    printf("\n");

    return 0;
}
