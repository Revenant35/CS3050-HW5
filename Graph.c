#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Queue.h"

#define BLACK (2)
#define GREY (1)
#define WHITE (0)

typedef struct node_struct *Node;

struct node_struct {
    int src, dest, color;
    Node next;
};


struct graph_struct{
    Node *heads;
    int size;
};

Node Create_AdjacencyList_Node(int src, int dest){
    Node newNode = malloc(sizeof(struct node_struct));
    newNode->dest = dest;
    newNode->src = src;
    newNode->color = WHITE;
    newNode->next = NULL;
    return newNode;
}



Graph Create_Graph(int n){

    Graph graph;
    int i;

    graph = malloc(sizeof(struct graph_struct));
    graph->size = n;

    graph->heads = malloc(n*sizeof(Node));

    for(i = 0; i < n; i++){
        graph->heads[i] = NULL;
    }

    return graph;
}

void Add_Edge(Graph graph, int src, int dest){
    Node cursor = NULL;
    Node newNode = Create_AdjacencyList_Node(src, dest);

    if(graph->heads[src] == NULL){
        newNode->next = graph->heads[src];
        graph->heads[src] = newNode;
    } else {
        cursor = graph->heads[src];

        while(cursor->next != NULL){
            cursor = cursor->next;
        }
        cursor->next = newNode;
    }
}

void printGraph(Graph graph){
    Node ptr;
    for(int i = 0; i < graph->size; i++){
        ptr = graph->heads[i];
        while(ptr != NULL){
            printf("(%c->%c)\t", (char)i+65, (char)ptr->dest+65);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void Breadth_First_Print(Graph graph, int src){
    Node head, child;
    Queue Q;

    Q = Create_Queue();

    if(graph->heads[src] == NULL){
        printf("Element not found\n");
        return;
    }

    enQueue(Q, graph->heads[src]);

    while(!isEmpty(Q)){
        head = deQueue(Q);
        child = head;
        while(child != NULL){
            if(child->color == WHITE){
                child->color = GREY;
                enQueue(Q, graph->heads[child->dest]);
            }
            child = child->next;
        }
        if(head && head->color != BLACK) {
            head->color = BLACK;
            printf("%c\n", head->src+65);
        }
    }
}