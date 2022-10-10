
// A C program to demonstrate linked list based
// implementation of queue
#include <stdio.h>
#include <stdlib.h>

// A linked list (LL) node to store a queue entry
struct QNode {
    struct node* tempNode;
	struct QNode* next;
};


// insert and delete operations.
struct QNode* newNode(struct node* param);
struct Queue* createQueue();
void enQueue(struct Queue* q, struct node* param);
void deQueue(struct Queue* q);
