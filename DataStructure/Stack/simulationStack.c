#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int value;
    struct node* next;
} node;

node* makeNode(int data)
{
    node* p = (node*)malloc(sizeof(node));
    p->value = data;
    return p;
}

void push(struct node** top, int data) 
{
    node* p = makeNode(data);
    p->next = *top;
    *top = p;
}

int pop(node** top)
{
    if (*top == NULL) 
    {
        return -1;
    }
    node* q = *top;
    *top = (*top)->next;
    int value = q->value;
    free(q);
    return value;
}

int main() 
{
    node* top = NULL;
    
    char cmd[10];
    int value;
    
    while (1) 
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0)
        {
            break;
        }
        else if (strcmp(cmd, "PUSH") == 0) 
        {
            scanf("%d", &value);
            push(&top, value);
        } else if (strcmp(cmd, "POP") == 0) 
        {
            int a = pop(&top);
            if (a == -1) 
            {
                printf("NULL\n");
            } else 
            {
                printf("%d\n", a);
            }
        }
    }
    
    return 0;
}