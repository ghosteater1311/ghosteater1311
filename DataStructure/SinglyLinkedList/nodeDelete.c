#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node* next;
} node;

node* deleteNode(node* *head, node* del)
{
    if (*head == del)
    {
        *head == del->next;
        free(del);
    }
    else 
    {
        node* prev = *head;
        while (prev->next != del) prev = prev->next;
        prev->next = del->next;
        free(del);
    }
    return *head;
}

void deleteAllNode(node* head)
{
    node* del = head;
    while (del != NULL)
    {
        head = head->next;
        free(del);
        del = head;
    }
}