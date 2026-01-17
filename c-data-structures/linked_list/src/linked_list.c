#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

// Forward declarations
Node* make_new_node(int value);
void throw_error(const char *message);

// Implementation will go here

LinkedList *create_linked_list() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int size(LinkedList *list) {
    return list->size;
}

bool empty(LinkedList *list) {
    return list->size == 0;
}

Node* node_at(LinkedList *list, int index) {
    if (index >= 0 && index < list->size) {
        Node* curr = list->head;
        for(int counter = 0; counter < index; counter++) {
            if (curr != NULL) {
                curr = curr->next;
            } else {
                return NULL;
            }
        }
        return curr;
    }

    return NULL;
}

int value_at(LinkedList *list, int index) {
    Node *result = node_at(list, index);
    if (result == NULL) {
        throw_error("No node found at index");
    }

    return result->data;
}


void push_front(LinkedList *list, int value) {
    insert(list, list->size+1, value);
}

int pop_front(LinkedList *list) {
    Node *newTail = node_at(list, list->size - 1);
    if (newTail == NULL) {
        Node *curTail = newTail->next;
        newTail->next = NULL;
        return curTail->data;
    }
    
    throw_error("No node found at tail of the list");
    return -1;
}

void push_back(LinkedList *list, int value) {
    insert(list, 0, value);
}

int pop_back(LinkedList *list) {
    Node* curHead = list->head;
    if (curHead != NULL) {
        list->head = curHead->next;
        return curHead->data;
    } 

    throw_error("No node found at back of list");
    return -1;
}

int front(LinkedList *list) {
    return value_at(list, 0);
}

int back(LinkedList *list) {
    return value_at(list, list->size);
}

void insert(LinkedList *list, int index, int value) {
    int curPosition = 0;
    Node *curr = list->head;
    Node *insertNode = make_new_node(value);

    if (index == 0) {
        insertNode->next = curr;
        list->head = insertNode;
        return;
    }
    
    while (curPosition < index-1) {
        if (curr == NULL) {
            curr = make_new_node(-1);
            list->size = list->size + 1;
        }
        curr = curr->next;
        curPosition = curPosition + 1;
    }

    if (curr == NULL) {
        curr = make_new_node(-1);
    }

    Node *temp = curr->next;
    curr->next = insertNode;
    insertNode->next = temp;
    list->size = list->size + 1;
}

void erase(LinkedList *list, int index) {
    throw_error("Not yet ready");
}

int value_n_from_end(LinkedList *list, int n) {
    return value_at(list, list->size - n);
}

void reverse(LinkedList *list) {
    throw_error("Not yet ready");
}

void remove_value(LinkedList *list, int value) {
    throw_error("Not yet ready");
}

void display_list(LinkedList *list) {
    Node *node = list->head;
    int curPosition = 0;
    while (node != NULL) {
        printf("Position: %d, Value: %d ", curPosition, node->data);
        printf("\n");
        node = node->next;
        curPosition = curPosition + 1;
    }
}

Node* make_new_node(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        throw_error("Error: Out of memory allocating new node\n");
    }
    newNode->data= value;
    newNode->next=NULL; 
    return newNode;
}

void throw_error(const char *message) {
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}
