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
    int n, j, a[1000];
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the number: ");
        scanf("%d", &a[i]);
    }
    node* head;
    for (int i = 1; i <= n; i++)
    {
        addFront(head, a[i]);
    }
    PrintList(head);
}