#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check = true;

typedef struct node
{
    int val;
    struct node*left, *right;
} node;

node* makeNode(int val) 
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* BuildBST(int a[], int left, int right) 
{
    if (left > right) return NULL;
    node* root = makeNode(a[left]);
    int i = left+1;
    while (i <= right && a[i] < a[left]) i++;
    i = i - 1;
    for (int j = i + 1; j <= right; j++) 
    {
        if(a[j] < a[left]) 
        {
            check = false;
            return NULL;
        }
    }
    root->left = BuildBST(a, left + 1, i);
    root->right = BuildBST(a, i + 1, right);
    return root;
}
void postOrder(node*root) 
{
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}
int main () 
{
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    node* root = NULL;
    root = BuildBST(a, 1, n);
    if (!check) printf("NULL");
    else postOrder(root);
    return 0;
}