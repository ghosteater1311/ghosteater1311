#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct 
{
    char* date;
    int count;
    int occupied;
} HashEntry;

typedef struct 
{
    HashEntry* entries;
    size_t size;
    size_t capacity;
} HashTable;

#define INITIAL_CAPACITY 1024
#define MAX_LOAD_FACTOR 0.7

unsigned long hash(const char* str) 
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

HashTable* create_table(size_t capacity) 
{
    HashTable* table = malloc(sizeof(HashTable));
    table->entries = calloc(capacity, sizeof(HashEntry));
    table->size = 0;
    table->capacity = capacity;
    return table;
}

void free_table(HashTable* table) 
{
    for (size_t i = 0; i < table->capacity; i++) 
    {
        if (table->entries[i].occupied) 
        {
            free(table->entries[i].date);
        }
    }
    free(table->entries);
    free(table);
}

void resize_table(HashTable* table, size_t new_capacity) 
{
    HashEntry* old_entries = table->entries;
    size_t old_capacity = table->capacity;
    
    table->entries = calloc(new_capacity, sizeof(HashEntry));
    table->capacity = new_capacity;
    table->size = 0;

    for (size_t i = 0; i < old_capacity; i++) 
    {
        if (old_entries[i].occupied) 
        {
            unsigned long h = hash(old_entries[i].date) % new_capacity;
            while (table->entries[h].occupied) 
            {
                h = (h + 1) % new_capacity;
            }
            table->entries[h] = old_entries[i];
            table->size++;
        }
    }
    
    free(old_entries);
}

void insert_or_update(HashTable* table, const char* date) 
{
    if ((double)table->size / table->capacity > MAX_LOAD_FACTOR) 
    {
        resize_table(table, table->capacity * 2);
    }

    unsigned long h = hash(date) % table->capacity;
    while (table->entries[h].occupied) 
    {
        if (strcmp(table->entries[h].date, date) == 0) 
        {
            table->entries[h].count++;
            return;
        }
        h = (h + 1) % table->capacity;
    }

    table->entries[h].date = strdup(date);
    table->entries[h].count = 1;
    table->entries[h].occupied = 1;
    table->size++;
}

int compare_dates(const void* a, const void* b) 
{
    const HashEntry* ea = (const HashEntry*)a;
    const HashEntry* eb = (const HashEntry*)b;
    return strcmp(ea->date, eb->date);
}

int main() 
{
    HashTable* table = create_table(INITIAL_CAPACITY);
    char line[100];

    while (fgets(line, sizeof(line), stdin)) 
    {
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n')
            line[len-1] = '\0';

        if (strcmp(line, "*") == 0)
            break;

        char date[100];
        if (sscanf(line, "%99s", date) == 1) 
        {
            insert_or_update(table, date);
        }
    }

    HashEntry* entries = malloc(table->size * sizeof(HashEntry));
    size_t count = 0;
    for (size_t i = 0; i < table->capacity; i++) 
    {
        if (table->entries[i].occupied) 
        {
            entries[count++] = table->entries[i];
        }
    }

    qsort(entries, count, sizeof(HashEntry), compare_dates);

    for (size_t i = 0; i < count; i++) 
    {
        printf("%s %d\n", entries[i].date, entries[i].count);
    }

    free(entries);
    free_table(table);
    return 0;
}
