#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct 
{
    char *date;
    int count;
} DateCount;

int compare_dates(const void *a, const void *b) 
{
    const DateCount *da = (const DateCount *)a;
    const DateCount *db = (const DateCount *)b;
    return strcmp(da->date, db->date);
}

int main() 
{
    DateCount *entries = NULL;
    size_t num_entries = 0;
    size_t capacity = 0;
    char line[100];

    while (fgets(line, sizeof(line), stdin)) 
    {
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') 
        {
            line[len-1] = '\0';
        }

        if (strcmp(line, "*") == 0) 
        {
            break;
        }

        char date[100];
        if (sscanf(line, "%99s", date) != 1) 
        {
            continue; 
        }

        int found = 0;
        for (size_t i = 0; i < num_entries; i++) 
        {
            if (strcmp(entries[i].date, date) == 0) 
            {
                entries[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) 
        {
            if (num_entries >= capacity) 
            {
                size_t new_capacity = capacity == 0 ? 4 : capacity * 2;
                DateCount *new_entries = realloc(entries, new_capacity * sizeof(DateCount));
                if (!new_entries) 
                {
                    perror("Memory allocation failed");
                    exit(EXIT_FAILURE);
                }
                entries = new_entries;
                capacity = new_capacity;
            }

            entries[num_entries].date = strdup(date);
            if (!entries[num_entries].date) 
            {
                perror("Memory allocation failed");
                exit(EXIT_FAILURE);
            }
            entries[num_entries].count = 1;
            num_entries++;
        }
    }

    qsort(entries, num_entries, sizeof(DateCount), compare_dates);

    for (size_t i = 0; i < num_entries; i++) 
    {
        printf("%s %d\n", entries[i].date, entries[i].count);
    }

    for (size_t i = 0; i < num_entries; i++) 
    {
        free(entries[i].date);
    }
    free(entries);

    return 0;
}