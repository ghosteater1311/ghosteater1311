#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int id;
    struct node* leftMostChild;
    struct node* rightSibling;
    struct node* parent;
} node;

node* makeNode(int u)
{
    node* p = (node*)malloc(sizeof(node));
    p->id = u;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
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
    q->parent = p;  
    if (p->leftMostChild == NULL)
    {
        p->leftMostChild = q;
    }
    else
    {
        node* h = p->leftMostChild;
        while (h->rightSibling != NULL)
        {
            h = h->rightSibling;
        }
        h->rightSibling = q;
    }
}

int depth(node* r)
{
    node* p = r;
    int d = 0;
    while (p != NULL)
    {
        d = d + 1;
        p = p->parent;
    }
    return d;  
}

int height(node* r)
{
    int maxH = 0;
    if (r == NULL) return 0;
    node* p = r->leftMostChild;
    while (p != NULL)
    {
        int h = height(p);
        if (h > maxH) maxH = h;
        p = p->rightSibling;  
    }
    return maxH + 1;
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
        else if (strcmp(cmd, "Height") == 0)
        {
            int id;
            scanf("%d", &id);
            node* p = find(root, id);
            if (p != NULL)
            {
                printf("%d\n", height(p));
            }
        }
        else if (strcmp(cmd, "Depth") == 0)
        {
            int id;
            scanf("%d", &id);
            node* p = find(root, id);
            if (p != NULL)
            {
                int ans = depth(p);
                printf("%d\n", ans);
            }
        }
    }
    freeTree(root);
}

int main()
{
    solve();
}
