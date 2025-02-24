#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    // Read the first line which contains the number of data lines (m)
    char first_line[1024];
    if (fgets(first_line, sizeof(first_line), stdin) == NULL) 
    {
        fprintf(stderr, "Error reading the first line\n");
        return 1;
    }

    int m;
    if (sscanf(first_line, "%d", &m) != 1) 
    {
        fprintf(stderr, "Invalid first line\n");
        return 1;
    }

    // Allocate array to store data lines
    char **data_lines = (char **)malloc(m * sizeof(char *));
    if (data_lines == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read m data lines
    for (int i = 0; i < m; i++) 
    {
        char *line = NULL;
        size_t len = 0;
        size_t read = getline(&line, &len, stdin);
        if (read == -1) 
        {
            // Handle case where lines are fewer than m
            fprintf(stderr, "Unexpected end of input\n");
            // Free allocated lines so far
            for (int j = 0; j < i; j++) {
                free(data_lines[j]);
            }
            free(data_lines);
            free(line);
            return 1;
        }
        data_lines[i] = line;
    }

    // Process the query line IDs
    int k;
    while (scanf("%d", &k) == 1) 
    {
        if (k == 1) 
        {
            printf("%d\n", m);
        }

        else if (k >= 2 && k <= m + 1) 
        {
            int idx = k - 2;
            fputs(data_lines[idx], stdout);
        }
        // Ignore invalid line numbers
    }

    // Free allocated memory
    for (int i = 0; i < m; i++) 
    {
        free(data_lines[i]);
    }
    free(data_lines);

    return 0;
}