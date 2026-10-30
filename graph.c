#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


Node* createNode(size_t id)
{

    Node* new_node = malloc(sizeof(Node));
    new_node->id = id;
    new_node->neighbours = NULL;
    return new_node;
}

Graph* createGraph(size_t v)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->V = v;
    graph->nodes = malloc(v * sizeof(Node));
    return graph;
}

void addNode(Graph* graph, size_t id)
{
    Node* node = createNode(id);
    node->neighbours= malloc(graph->V *  sizeof(size_t));
    for(size_t i = 0; i < graph->V; i++ ){
        node->neighbours[i] = 0;
    }
    graph->nodes[id] = node;
}
void addEdge(Graph* graph, size_t u, size_t v)
{
    graph->nodes[u]->neighbours[v] = 1;
    graph->nodes[v]->neighbours[u] = 1;
}
void printGraph(Graph* graph)
{
    for(size_t i = 0;i < graph->V; i++){
        printf("%ld: ", i);
        for(size_t j = 0; j< graph->V;j++){
            printf(" %ld", graph->nodes[i]->neighbours[j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph* graph){

    for(size_t i = 0;i < graph->V; i++){
        free(graph->nodes[i]->neighbours);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}