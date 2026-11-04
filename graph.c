#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

size_t checkCliqueSize(const Graph* graph, size_t target, const Node** candidates)
{
    //TRIPLE POINTER? O_O
    
}

void updateCandidates(const Graph *graph, size_t target, Node** candidates)
{

    //check each node for a node to be apart of a clique of size n, it must have ATLEAST n - 1 edges
    for(size_t i = 0; i < graph->V; i++)
    {
        if(candidates[i] == NULL && graph->nodes[i]->n_neighbours >= target - 1){
            candidates[i] = graph->nodes[i];
        }
    }
}

size_t getMaxClique(const Graph* graph)
{
    //since we know n_neighbours can be anywhere from 0 to V - 1 we can make an array of the counts of n_neighbours
    //since l < n_neighbours < u where l = 0 and u = V - 1 
    size_t* frequencies;
    frequencies = calloc(graph->V, sizeof(size_t));
    Node** candidates;
    candidates = calloc(graph->V, sizeof(Node));
    for(size_t i = 0; i < graph->V;i++){
        frequencies[graph->nodes[i]->n_neighbours] += 1;
        printf("Node: {%ld} : n_neighbours: {%ld}\n",  i, graph->nodes[i]->n_neighbours);
    }
    //we iterate through the frequencies
    for(size_t i = 0;i < graph->V; i++){
            if(frequencies[i] != 0){
                printf("n_neighbours: {%ld} : Freq of n_neighbours: {%ld}\n",  i, frequencies[i]);
            }
    }
    //we go through the frequencies backwards // loop coniditon is just i-- 
    for(size_t i = (graph->V);i--;){
        //add all nodes that have enough connections to be apart of a clique of size i
        updateCandidates(graph, i, candidates);
        if(checkCliqueSize(graph, i, candidates) >= i)
        {
            return i;
        }
    }

    

    free(candidates);
    free(frequencies);
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