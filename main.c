#include <stdio.h>
#include <stdlib.h>
#include "graph.h"



int main()
{
    size_t V = 5;
    Graph* graph = createGraph(V);
    for(size_t i = 0; i < V; i++){
        addNode(graph, i);
    }
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    freeGraph(graph);
    return 0;
}