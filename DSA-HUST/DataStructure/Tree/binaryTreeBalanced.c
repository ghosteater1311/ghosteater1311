#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000001

typedef struct TNode
{
    int id;
    struct TNode* left;
    struct TNode* right;
} Node;

Node* root;
Node* nodes[N];

typedef struct TINFO
{
    int balanced; 
    int hl; // Depth of the left child
    int hr; // Depth of the right child
    int h;  // Depth of the tree
} INFO;

Node* makeNode(int id)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;  
    p->left = NULL; 
    p->right = NULL;
    return p;
}

int addLeft(int u, int v)
{
    if (nodes[u] != NULL || nodes[v] == NULL) return 0;
    if (nodes[v]->left != NULL) return 0;
    Node* p = makeNode(u);
    nodes[v]->left = p;
    nodes[u] = p;
    return 1;
}

int addRight(int u, int v)
{
    if(nodes[u] != NULL || nodes[v] == NULL) return 0;
    if(nodes[v]->right != NULL) return 0;
    Node* p = makeNode(u);
    nodes[v]->right = p;
    nodes[u] = p;
    return 1;
}

INFO visit(Node* r)
{
    if(r == NULL)
    {
        INFO i;
        i.balanced = 1;
        i.h = 0;
        return i;
    }
    INFO i1 = visit(r->left);
    INFO i2 = visit(r->right);
    INFO i;
    i.h = (i1.h > i2.h ? i1.h : i2.h) + 1;
    if (i1.balanced == 0)
    {
        i.balanced = 0; 
        return i;
    }
    if(i2.balanced == 0)
    {
        i.balanced = 0; return i;
    }
    if(abs(i1.h - i2.h) >= 2)
    {
        i.balanced = 0;
    }
    else i.balanced = 1;
    return i;
}

void solve()
{
    for (int i = 0; i < N; i++) nodes[i] = NULL;
    while (1)
    {
        char s[20];
        scanf("%s", s);
        if (strcmp(s, "*") == 0) break;
        if (strcmp(s, "MakeRoot") == 0)
        {
            int u; scanf("%d", &u);
            root = makeNode(u);
            nodes[u] = root;
        }
        else if (strcmp(s, "AddLeft") == 0)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            addLeft(u, v);
        }
        else if(strcmp(s, "AddRight") == 0)
        {
            int u,v;
            scanf("%d%d", &u, &v);
            addRight(u, v);
        }
    }
    INFO i = visit(root);
    printf("%d %d", i.balanced, i.h);
}

int main()
{
    solve();
}