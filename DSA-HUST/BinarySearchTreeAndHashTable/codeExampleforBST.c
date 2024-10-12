#include <stdio.h>
#include <stdlib.h>

int a[100001];

typedef struct node
{
    int key;
    node* leftChild;
    node* rightChild;
} node;

node* makeNode(int k)
{
    node* p = (node*)malloc(sizeof(node));
    p->leftChild = NULL;
    p->rightChild = NULL;
    p->key = k;
    return p;
}

node* find(node* r, int k)
{
    if (r == NULL) return NULL;
    if (r->key = k) return r;
    if (r->key < k) 
    {
        return find(r->rightChild, k);
    }
    else 
    {
        return find(r->leftChild, k);
    }
}

node* insert(node* r, int k)
{
    if (r == NULL) return makeNode(k);
    if (r->key == k) return r;
    if (r->key < k) 
    {
        r->rightChild = insert(r->rightChild, k);
    }
    else 
    {
        r->leftChild = insert(r->leftChild, k);
    }
    return r;
}

node* removeRoot(node* r) 
{
    if (r == NULL) return NULL;
    node* tmp = r;
    if (r->rightChild == NULL) 
    {
        r = r->leftChild; 
        free(tmp); 
        return r;
    }
    node* p = r->rightChild; 
    node* pp = r;
    if (p->leftChild == NULL) 
    {
        r->key = p->key; 
        tmp = p; 
        r->rightChild = p->rightChild;
        free(tmp); 
        return r;
    }
    while (p->leftChild != NULL)
    { 
        pp = p; 
        p = p->leftChild; 
    }
    pp->leftChild = p->rightChild; 
    r->key = p->key; 
    free(p);
    return r;
}

node* remove(node* r, int k)
{
    if (r == NULL) return NULL;
    if (r->key == k) return removeRoot(r);
    if (r->key < k) r->rightChild = remove(r->rightChild, k);
    else r->leftChild = remove(r->leftChild, k);
    return r; 
}

void inOrder(node* r)
{
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%d ",r->key);
    inOrder(r->rightChild);
}

void postOrder(node* r)
{
    if(r == NULL) return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ",r->key);
}

node* BuildBST(int k[], int L, int R)
{
    if (L > R) return NULL;
    node* r = makeNode(k[L]); // tạo nút gốc
    int i = L + 1;
    while ((i <= R) && (a[i] < a[L]))
    { 
        i = i + 1; 
    }
    i = i - 1;
    for (int j = i + 1; j < R; j++) 
    if (a[j] < a[L]) 
    {
        int ok = 0; // biến tổng thể
        return NULL; // T không tồn tại
    }
    r->leftChild = BuildBST(k, 2, i);
    r->rightChild = BuildBST(k, i + 1, R);
    return r;
}

