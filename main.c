#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


void quickTest()
{
    size_t V = 5;
    Graph* graph = createGraph(V);
    for(size_t i = 0; i < V; i++){
        addNode(graph, i);
    }
    addEdge(graph, graph->nodes[0], graph->nodes[1]);
    addEdge(graph, graph->nodes[0], graph->nodes[4]);
    addEdge(graph, graph->nodes[1], graph->nodes[2]);
    addEdge(graph, graph->nodes[1], graph->nodes[3]);
    addEdge(graph, graph->nodes[1], graph->nodes[4]);
    addEdge(graph, graph->nodes[2], graph->nodes[3]);
    addEdge(graph, graph->nodes[3], graph->nodes[4]);
    printGraph(graph);
    printf("Graph has max Clique of size %ld\n", getMaxClique(graph));
    freeGraph(graph);
    return;
}


int main()
{
    quickTest();
    return 0;
}