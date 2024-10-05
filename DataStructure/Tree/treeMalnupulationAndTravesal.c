#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int id;
    struct node* leftMostChild;
    struct node* rightSibling;
} node;

node* makeNode(int u)
{
    node* p = (node*)malloc(sizeof(node));
    p->id = u;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

node* find(node* r, int u)
{
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    node* p = r->leftMostChild;
    while (p != NULL)
    {
        node* q = find(p, u);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

void insert(node* r, int u, int v)
{
    node* p = find(r, v);
    if (p == NULL) return;
    node* q = makeNode(u);
    if (p->leftMostChild == NULL)
    {
        p->leftMostChild = q;
        return;
    }
    node* h = p->leftMostChild;
    while (h->rightSibling != NULL)
    {
        h = h->rightSibling;
    }
    h->rightSibling = q;
}

void preOrder(node* r)
{
    if (r == NULL) return;
    printf("%d ", r->id);
    node* p = r->leftMostChild;
    while (p != NULL)
    {
        preOrder(p);
        p = p->rightSibling;
    }
}

void inOrder(node* r)
{
    if (r == NULL) return;
    if (r->leftMostChild != NULL)
    {
        inOrder(r->leftMostChild);
    }
    printf("%d ", r->id);
    node* p = r->leftMostChild;
    if (p != NULL) 
    {
        p = p->rightSibling;
    }
    while (p != NULL)
    {
        inOrder(p);
        p = p->rightSibling;
    }
}

void postOrder(node* r)
{
    if (r == NULL) return;
    node* p = r->leftMostChild;
    while (p != NULL)
    {
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ", r->id);
}

void freeTree(node* r)
{
    if (r == NULL) return;
    node* p = r->leftMostChild;
    while (p != NULL)
    {
        node* np = p->rightSibling;
        freeTree(p); 
        p = np;
    }
    free(r);
}

void solve()
{
    node* root = NULL;
    char cmd[50];
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0)
        {
            break;
        }
        else if (strcmp(cmd, "MakeRoot") == 0)
        {
            int id;
            scanf("%d", &id);
            root = makeNode(id);
        }
        else if (strcmp(cmd, "Insert") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            insert(root, u, v);
        }
        else if (strcmp(cmd, "InOrder") == 0)
        {
            inOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PreOrder") == 0)
        {
            preOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PostOrder") == 0)
        {
            postOrder(root);
            printf("\n");
        }
    }
    freeTree(root);
}

int main()
{
    solve();
}