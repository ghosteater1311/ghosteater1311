#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define TIMES 10
#define MAX 1000
#define SIZE 5

void generate_sentence(char* articles[], char* nouns[], char* verbs[], char* prepositions[])
{
    int a1 = rand() % 5;
    int n1 = rand() % 5;
    int v = rand() % 5;
    int p = rand() % 5;
    int a2 = rand() % 5;
    int n2 = rand() % 5;

    char sentence[MAX];

    sprintf(sentence, "%s %s %s %s %s %s.", articles[a1], nouns[n1], verbs[v], prepositions[p], articles[a2], nouns[n2]);

    sentence[0] = toupper(sentence[0]);

    printf("%s\n", sentence);
}

int main()
{
    char* articles[] = {"the", "a", "one", "some", "any"};
    char* nouns[] = {"boy", "girl", "dog", "town", "car"};
    char* verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char* prepositions[] = {"to", "from", "over", "under", "on"};

    for (int i = 0; i < TIMES; i++)
    {
        generate_sentence(articles, nouns, verbs, prepositions);
    }

    return 0;
}