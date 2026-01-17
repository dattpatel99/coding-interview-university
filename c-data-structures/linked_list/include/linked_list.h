#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct LinkedList {
    Node *head;
    int size;
} LinkedList;


LinkedList *create_linked_list();
int size(LinkedList *list);
bool empty(LinkedList *list);
int value_at(LinkedList *list, int index);
void push_front(LinkedList *list, int value);
int pop_front(LinkedList *list);
void push_back(LinkedList *list, int value);
int pop_back(LinkedList *list);
int front(LinkedList *list);
int back(LinkedList *list);
void insert(LinkedList *list, int index, int value);
void erase(LinkedList *list, int index);
int value_n_from_end(LinkedList *list, int n);
void reverse(LinkedList *list);
void remove_value(LinkedList *list, int value);
void display_list(LinkedList *list);

#endif // LINKED_LIST_H

