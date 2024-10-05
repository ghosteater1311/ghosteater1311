#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StackNode 
{
    char data;
    struct StackNode* next;
};

struct StackNode* createStackNode(char data) 
{
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct StackNode* root) 
{
    return !root;
}

void push(struct StackNode** root, char data) 
{
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *root;
    *root = newNode;
}

char pop(struct StackNode** root) 
{
    if (isEmpty(*root)) 
    {
        return '\0';
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

char peek(struct StackNode* root) 
{
    if (isEmpty(root)) 
    {
        return '\0';
    }
    return root->data;
}

int isMatchingPair(char open, char close) 
{
    return ((open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}'));
}

int isCorrectExpression(char* s) {
    struct StackNode* stack = NULL;
    for (int i = 0; i < strlen(s); i++) 
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
        {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') 
        {
            if (isEmpty(stack) || !isMatchingPair(pop(&stack), s[i])) 
            {
                return 0; 
            }
        }
    }
    return isEmpty(stack); 
}

int main() {
    char s[1000001];
    
    if (scanf("%1000000s", s) != 1) 
    {
        printf("Input error\n");
        return 1;
    }

    if (isCorrectExpression(s)) 
    {
        printf("1\n");
    } 
    else 
    {
        printf("0\n");
    }

    return 0;
}
