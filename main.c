#include <stdio.h>
#include "Graph.h"

Graph createGraphFromEdges(Edge edges, int n){
    Graph graph = Create_Graph(n);
    for(int i = 0; i < n; i++){
        Add_Edge(graph, edges[i].src, edges[i].dest);
    }
    return graph;
}

int main() {
    struct edge_struct edges[] = {
            {'A'-65, 'B'-65},
            {'A'-65, 'D'-65},
            {'B'-65, 'C'-65},
            {'B'-65, 'E'-65},
            {'B'-65, 'G'-65},
            {'C'-65, 'A'-65},
            {'D'-65, 'C'-65},
            {'E'-65, 'H'-65},
            {'G'-65, 'F'-65},
            {'H'-65, 'F'-65},
            {'H'-65, 'G'-65}};
    int n = sizeof(edges)/sizeof(edges[0]);
    Graph graph = createGraphFromEdges(edges, n);
    printGraph(graph);

    Breadth_First_Print(graph, 0);
}
