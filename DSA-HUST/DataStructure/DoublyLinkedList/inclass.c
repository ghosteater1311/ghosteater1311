#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int grade;
    char* name;
    char* id;
} student;

typedef struct node
{
    student data;
    node* next;
    node* prev;
} node;

node *head, *tail;

void deleteNode(node* p)
{
    if (head == NULL) printf("Empty List\n");
    else
    {
        if (p == head) head = head->next;
        else p->prev->next = p->next;
        if (p->next != NULL) p->next->prev = p->prev;
        else tail = p->prev;
        free(p); 
    }
}