#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
    int data;
    node* next;
} node;

typedef struct queue 
{
    node* head;
    node* tail;
} queue;

node* makeNode(int data) 
{
    node* p = (node*)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

queue* makeQueue() 
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->head = q->tail = NULL;
    return q;
}

void push(queue* q, int data) 
{
    node* p = makeNode(data);
    if (q->head == NULL && q->tail == NULL) 
    {
        q->head = q->tail = p;
        return;
    }
    q->tail->next = p;
    q->tail = p;
}

int pop(queue* q) 
{
    if (q->head == NULL && q->tail == NULL) 
    {
        printf("NULL\n");
        return -1;
    }
    int v = q->head->data;
    node* temp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return v;
}

int main() 
{
    queue* q = makeQueue();
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
            push(q, value);
        } 
        else if (strcmp(cmd, "POP") == 0) 
        {
            int result = pop(q);
            if (result != -1) 
            {
                printf("%d\n", result);
            }
        }
    }
    while (q->head != NULL) 
    {
        pop(q);
    }
    free(q);

    return 0;
}