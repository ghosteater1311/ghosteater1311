#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[50];
    struct node* leftMostChild;
    struct node* rightSibling;
    struct node* parent;
} node;

int n;
node* nodes[104];

node* makeNode(char* name)
{
    node* p = (node*)malloc(sizeof(node));\
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    p->parent = NULL;
    return p;
}

node* findNode(char* name)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(nodes[i]->name, name) == 0)
        {
            return nodes[i];
        }
    }
    return NULL;
}

void addChild(node* child, node* parent)
{
    child->parent = parent;
    if (parent->leftMostChild == NULL)
    {
        parent->leftMostChild = child;
    }
    else 
    {
        node* p = parent->leftMostChild;
        while (p->rightSibling != NULL)
        {
            p = p->rightSibling;
        }
        p->rightSibling = child;
    }
}

int countNode(node* nod)
{
    if (nod == NULL) return 0;
    node* p = nod->leftMostChild;
    int count = 1;
    while (p != NULL)
    {
        count += countNode(p);
        p = p->rightSibling;
    }
    return count;
}

int height(node* nod)
{
    if (nod == NULL) return 0;
    int maxHeight = 0;
    node* p = nod->leftMostChild;
    while (p != NULL)
    {
        int h = height(p);
        if (h > maxHeight) maxHeight = h;
        p = p->rightSibling;
    }
    return maxHeight + 1;
}    

void solve()
{
    while (1)
    {
        char name1[50], name2[50];
        scanf("%s", name1);
        if (strcmp(name1, "***") == 0) break;
        scanf("%s", name2);
        node* n1 = findNode(name1);
        if (n1 == NULL)
        {
            n++;
            nodes[n - 1] = makeNode(name1);
            n1 = nodes[n - 1];
        }
        node* n2 = findNode(name2);
        if (n2 == NULL)
        {
            n++;
            nodes[n - 1] = makeNode(name2);
            n2 = nodes[n - 1];
        }
        addChild(n1, n2);
    }
    while (1)
    {
        char cmd[50];
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) break;
        if (strcmp(cmd, "descendants") == 0)
        {
            char param[50];
            scanf("%s", param);
            node* nod = findNode(param);
            int ans = countNode(nod);
            printf("%d\n", ans - 1);
        }
        else if (strcmp(cmd, "generation") == 0)
        {
            char param[50];
            scanf("%s", param);
            node* nod = findNode(param);
            int ans = height(nod);
            printf("%d\n", ans - 1);
        }
    }
}

int main()
{
    solve();
}