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

//Hashing Function
/*
int hash(s[1..k], m) 
{
    //Hash a string
    code = 0
    for i = 1 to k do
    code = (code * 256 + s[i]) mod m;
    return code;
}

node* FindBST(node* r, int k)
{
    if r = NULL then return NULL;
    if r.key = k then return r;
    if r.key < k then return FindBST(r.rightChild, k);
    else return FindBST(r.leftChild, k);
}

int Find(int k)
{
    i = h(k);// tính mã băm
    node = FindBST(T[i], k); // tìm k trên BST gốc T[i]
    if node = NULL then return 0; 
    else return 1;
}

node* InsertBST(node* r, int k)
{
    if r = NULL then return Node(k);
    if r.key < k then r.rightChild = InsertBST(r.rightChild, k);
    else r.leftChild = InsertBST(r.leftChild, k);
    return r;
}

int Insert(k){
    i = h(k);
    if FindBST(T[i], k) != NULL then return 0;// k already existed
    T[i] = InsertBST(T[i], k);// k does not exist
    return 1;
}
*/

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
