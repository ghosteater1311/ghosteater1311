#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tnode
{
    int data;
    Tnode* left;
    Tnode* right;
} Tnode;

Tnode* root;
 
Tnode* makeNode(int input)
{
    Tnode* newNode = NULL;
    newNode = (Tnode*)malloc(sizeof(Tnode));
    if (newNode == NULL) 
    {
        printf("Out of memory\n");
        exit(1);
    }
    else 
    {
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data = input;
    }
    return newNode;
}

int countNodes(Tnode* root)
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int depth(Tnode* root)
{
    if (root == NULL) return 0;
    return fmax(depth(root->left), depth(root->right)) + 1;
}
void freeTree(Tnode* root)
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printPreorder(Tnode* tree)
{
    printf("%d\n", tree->data);
    printPreorder(tree->left);
    printPreorder(tree->right);
}








