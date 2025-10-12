#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
};

struct DoublyLinkedList { 
    struct Node * head;
    struct Node * tail;
};

struct DoublyLinkedList * create_list() {
    struct DoublyLinkedList * list = malloc(sizeof(struct DoublyLinkedList));
    if (!list) return NULL;

    list->head = NULL;
    list->tail = NULL;

    return list;
}

struct Node * create_node(const char *str) {
    struct Node * node = malloc(sizeof(struct Node));
    if (!node) return NULL;

    size_t len = strlen(str);
    node->data = malloc(len+1);
    if (!node->data) {
        free(node);
        return NULL;
    }
    strcpy(node->data, str);

    node->prev = NULL;
    node->next = NULL;

    return node;
}

void append(struct DoublyLinkedList * list, const char *str) {
    struct Node * new_node = create_node(str);
    if (!list->tail) {
        list->head = list->tail = new_node;
        return;
    }

    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
}

void prepend(struct DoublyLinkedList * list, const char *str) {
    struct Node *new_node = create_node(str);
    if (!new_node) return;

    if (list->head)
        (list->head)->prev = new_node;

    new_node->next = list->head;
    list->head = new_node;
}

int main() {

    struct DoublyLinkedList list = {.head = NULL, .tail = NULL};

    append(&list, "Hello");
    append(&list, "World");
    append(&list, "List");

    struct Node * head = list.head;

    while (head) {
        printf("%s\n", head->data);
        head = head->next;
    } 
}