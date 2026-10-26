
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail; // tailpointer
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->tail = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* curr = obj->head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    if (obj->size == 0) obj->tail = newNode; // First node is tail 
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if (obj->size == 0) {
        obj->head = obj->tail = newNode;
    } else {
        obj->tail->next = newNode; // O(1) speed! No traversal!
        obj->tail = newNode;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++) curr = curr->next;
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node* temp;
    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        if (obj->size == 1) obj->tail = NULL; // Empty list handle
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) curr = curr->next;
        temp = curr->next;
        curr->next = temp->next;
        if (index == obj->size - 1) obj->tail = curr; // Last node delete to update tail
    }
    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}
