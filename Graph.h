
#ifndef HW5_GRAPH_H
#define HW5_GRAPH_H

#define N (32)

typedef struct graph_struct *Graph;
typedef struct edge_struct *Edge;


struct edge_struct {
    int src, dest;
};

Graph Create_Graph(int n);
void Add_Edge(Graph graph, int src, int dest);
void printGraph(Graph graph);
void Breadth_First_Print(Graph G, int src);

#endif //HW5_GRAPH_H
