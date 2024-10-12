#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int exists(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void addLast(Node** head, int data) {
    if (exists(*head, data)) return;

    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void addFirst(Node** head, int data) {
    if (exists(*head, data)) return;

    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void addAfter(Node* head, int newData, int afterData) {
    if (!exists(head, afterData) || exists(head, newData)) return;

    Node* current = head;
    while (current != NULL && current->data != afterData) {
        current = current->next;
    }

    if (current != NULL) {
        Node* newNode = createNode(newData);
        newNode->next = current->next;
        current->next = newNode;
    }
}

void addBefore(Node** head, int newData, int beforeData) {
    if (!exists(*head, beforeData) || exists(*head, newData)) return;

    Node* newNode = createNode(newData);

    if ((*head)->data == beforeData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != beforeData) {
        current = current->next;
    }

    if (current->next != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void removeNode(Node** head, int data) {
    if (*head == NULL) return;

    Node* temp = *head;
    if ((*head)->data == data) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        int value;
        scanf("%d", &value);
        addLast(&head, value);
    }

    char command[20];
    int x, y;
    while (1) {
        scanf("%s", command);
        if (command[0] == '#') break;

        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &x);
            addLast(&head, x);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &x);
            addFirst(&head, x);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d %d", &x, &y);
            addAfter(head, x, y);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d %d", &x, &y);
            addBefore(&head, x, y);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &x);
            removeNode(&head, x);
        } else if (strcmp(command, "reverse") == 0) {
            reverseList(&head);
        }
    }

    printList(head);

    return 0;
}
