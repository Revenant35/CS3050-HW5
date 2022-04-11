
#include <malloc.h>
#include "Queue.h"

typedef struct node_struct *Node;

struct node_struct{
    void *vertex;
    Node next;
};

struct queue_struct {
    Node front, rear;
};

Node Create_Node(void *vertex){
    Node newNode = malloc(sizeof(struct node_struct));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Queue Create_Queue(){
    Queue Q = malloc(sizeof(struct queue_struct));
    Q->front = Q->rear = NULL;
    return Q;
}

void enQueue(Queue Q, void* vertex){
    Node newNode = Create_Node(vertex);

    if(Q->rear == NULL){
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}


void *deQueue(Queue Q){
    Node oldNode;
    void *vertex;

    if(Q->front == NULL)
        return NULL;

    oldNode = Q->front;
    vertex = Q->front->vertex;

    Q->front = Q->front->next;

    if(Q->front == NULL)
        Q->rear = NULL;

    free(oldNode);

    return vertex;
}

bool isEmpty(Queue Q){
    return (Q->front == NULL && Q->rear == NULL);
}

