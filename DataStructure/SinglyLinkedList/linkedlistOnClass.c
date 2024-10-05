#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* nalloc(int v)
{
    node* p = (node*)malloc(sizeof(node));
    if (p != NULL)
    {    
        p->data = v; 
        p->next = NULL;
    }
    return p;
}

node* addFront(node* head, int data)
{
    node* p = nalloc(data);
    if (p == NULL) return head;
    p->next = head;
    return p;
}

void PrintList(node* head)
{
    node* cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main()
{
    int n, j;
    scanf("%d", &n);
    node* head;
    if (n >= 1)
    {
        head = nalloc(1);
        node* cur = head;
        j = 1;
        for (int i = 2; i <= n; i++)
        {
            cur->next = nalloc(2 *  i - 1);
            cur = cur->next;
        }
    }
    else head = NULL;
    PrintList(head);
}