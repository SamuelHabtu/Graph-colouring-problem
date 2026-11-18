#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
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
    //check if were already neighbours B)
    if (graph->nodes[u->id]->neighbours[v->id] != NULL){
        return;
    }
    graph->nodes[u->id]->neighbours[v->id] = v;
    graph->nodes[v->id]->neighbours[u->id] = u;
    graph->nodes[u->id]->n_neighbours += 1;
    graph->nodes[v->id]->n_neighbours += 1;
    graph->E += 1;
}
void addEdges(Graph* graph, size_t target, size_t n_edges, const size_t edges[])
{
    for(size_t i = 0; i < n_edges; i++){
        addEdge(graph, graph->nodes[target], graph->nodes[edges[i]]);
    }
}
void printGraph(const Graph* graph)
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
bool isNeighbour(Node* u, Node* v){ 
    for(size_t i = 0; i <u->n_neighbours;i++){
        if(u->neighbours[i]->id == v->id){
            return true;
        }
    }
    return false;
}

bool isClique(const Graph* graph, size_t target,  Node** candidates)
{
    size_t count = 0;

    printf("HERE?");
    for(size_t i = 0; i < graph->V; i++)
    {
        for(size_t j = 0; j < graph->V; j++){
            if(candidates[i] != NULL && candidates[j] != NULL){
                if(candidates[i]->neighbours[j]->id != candidates[j]->id){
                    return false;
                }

            }
        }
    }
   return true;
}

size_t checkCliqueSize(const Graph* graph, size_t target,  Node** candidates)
{
    size_t count = 0;
    Node ** test;
    test = calloc(4, sizeof(Node));
    test[0] = candidates[0];
    test[1] = candidates[1];
    test[2] = candidates[2];
    test[5] = candidates[5];
    if(isClique(graph, 4,  test))
    {
        printf("Clique of size: %zu", 4);
    }
    free(test);
    
   return 0;
}

void updateCandidates(const Graph *graph, size_t target, Node** candidates, size_t* n_candidates)
{

    //check each node for a node to be apart of a clique of size n, it must have ATLEAST n - 1 edges
    for(size_t i = 0; i < graph->V; i++)
    {
        if(candidates[i] == NULL && graph->nodes[i]->n_neighbours >= target - 1){
            candidates[i] = graph->nodes[i];
            *n_candidates += 1;
        }
    }
}

bool findClique(const Graph* graph, Node ** candidates, size_t target, size_t n_candidates)
{

    return false;
}
size_t getMaxClique(const Graph* graph)
{
    Node** candidates = calloc(graph->V, sizeof(Node));
    size_t* frequencies = calloc(graph->V, sizeof(size_t));
    size_t n_candidates = 0;

    for(size_t i = 0; i < graph->V; i++){
        frequencies[graph->nodes[i]->n_neighbours] += 1;
    }
    for(size_t i = 0; i < graph->V;i++){
        printf(" %lu \n", frequencies[i]);
    }
    for(size_t i = graph->V;i > 2;i--){
        updateCandidates(graph, i, candidates, &n_candidates);
        if(n_candidates >= i){
            if(findClique(graph ,candidates, i, n_candidates))
                return i;
        }
    }

    free(frequencies);
    free(candidates);
    return 0;
}

void freeGraph(Graph* graph){

    for(size_t i = 0;i < graph->V; i++){
        free(graph->nodes[i]->neighbours);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
}