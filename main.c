#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void quickTest()
{
    size_t V = 6;
    Graph* graph = createGraph(V);
    for(size_t i = 0; i < V; i++){
        addNode(graph, i);
    }
    /**/
    //sample graph -> should look like a complete graph of 4 nodes 0 1 2 and 5; then 3 is connected to 1 and 2 and 4 is connected to
    //3 and 1
    addEdges(graph, 0, 3, (size_t []){1,2,5});
    addEdges(graph, 1, 5, (size_t []){0,2,3,4,5});
    addEdges(graph, 2, 4, (size_t []){0,1,3,5});
    addEdges(graph, 3, 2, (size_t []){1,2});
    addEdges(graph, 4, 2, (size_t []){1,3});
    addEdges(graph, 5, 3, (size_t []){0,1,2});


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