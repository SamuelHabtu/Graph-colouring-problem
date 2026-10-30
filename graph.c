#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


Node* createNode(size_t id)
{

    Node* new_node = malloc(sizeof(Node));
    new_node->id = id;
    new_node->neighbours = NULL;
    new_node->n_neighbours = 0;
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
    //max neighbours is n - 1
    node->neighbours= malloc((graph->V -1)*  sizeof(Node));
    for(size_t i = 0; i < graph->V; i++ ){
        node->neighbours[i] = 0;
    }
    graph->nodes[id] = node;
}
void addEdge(Graph* graph, Node* u, Node* v)
{
    graph->nodes[u->id]->neighbours[v->id] = v;
    graph->nodes[v->id]->neighbours[u->id] = u;
    graph->nodes[u->id]->n_neighbours += 1;
    graph->nodes[v->id]->n_neighbours += 1;
}
void printGraph(Graph* graph)
{
    for(size_t i = 0;i < graph->V; i++){
        printf("%ld: ", i);
        for(size_t j = 0; j< graph->V;j++){
            //check if theres actually a connection here!
            if(graph->nodes[i]->neighbours[j] != NULL){
                printf(" %ld", graph->nodes[i]->neighbours[j]->id);
            }
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