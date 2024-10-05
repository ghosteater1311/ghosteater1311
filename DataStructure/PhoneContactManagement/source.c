#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contact_t
{
    char name[20];
    char tel[11];
    char email[25];
} contact; //contact is the type for INFOR field

struct list_el
{
    contact el;
    struct list_el *next;
};

typedef struct list_el node;

node *root, *cur;
node *prev;
//Create New Contact 
node* makeNewNode(contact temp)
{
    node* new_p = (node*)malloc(sizeof(node));
    new_p->el = temp;
    new_p->next = NULL;
    return new_p;
}
//Input Contact
contact readNode()
{
    contact temp;
    printf("Input the full name: ");
    fgets(temp.name, sizeof(temp.name), stdin);
    printf("Input the contact number: ");
    fgets(temp.tel, sizeof(temp.tel), stdin);
    printf("Input the email: ");
    fgets(temp.email, sizeof(temp.email), stdin);
    return temp;
}
//Display Function
void displayNode(node *p)
{
    if (p == NULL) 
    {
        printf("0x00000 NULL Pointer Error");
        return;
    }
    contact temp = p->el;
    printf("%s%s%s%p\n", temp.name, temp.tel, temp.email, p->next); 
}
//insert at head
void insertAtHead(contact temp)
{
    node* new = makeNewNode(temp);
    new->next = root;
    root = new;
    cur = root;
}
//insert at current
void insertBeforeCurrent(contact e) 
{
    node *new = makeNewNode(e);
    if (root == NULL) 
    { /* if there is no element */
        root = new;
        cur = root;
        prev = NULL;
    } 
    else 
    {
    new->next = cur;
    if (cur == root) 
    {/* if cur pointed to first element */
        root = new; /* nut moi them vao tro thanh dau danh sach */
    }
    else prev->next = new; // assume prev pointer always point to the previous node
    cur = new;
    }
}

void insertAtTail(contact ct)
{
    node* new = makeNewNode(ct);
    if (root == NULL) 
    { 
        root = new;     
        cur = new; 
        prev = NULL; 
        return;
    }
    node* p = root;
    while (p->next != NULL) 
    p = p->next;
    p->next = new;
    cur = new; 
    prev = p;
}

node* insertLastRecursive(node* root, contact ct)
{
    if (root == NULL)
    {
        return makeNewNode(ct);
    }
    root->next = insertLastRecursive(root->next, ct);
    return root;
}

void traversingList(node *root)
{
    node * p;
    for (p = root; p != NULL; p = p->next)
        displayNode(p);
}

void deleteFirstElement()
{
    node* del = root;
    if (del == NULL) return;
    root = del->next;
    free(del);
    cur = root;
    prev = NULL;
}

void deleteCurrentElement()
{
    if (cur == NULL) return;
    if (cur == root) deleteFirstElement();
    else 
    {
        prev->next = cur->next;
        free(cur);
        cur = prev->next; // or cur = root;
    }
}

node* removeNodeRecursive(Node* root, contact e)
{
    if (root == NULL) return NULL;
    if (root->el == e)
    {
        node* tmp = root; root = root->next; free(tmp);
        return root;
    }
    root->next = removeNodeRecursive(root->next, e);
    return root;
}

node* list_reverse(node* root)
{
    node *cur, *prev;
    cur = prev = NULL;
    while (root != NULL) 
    {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

