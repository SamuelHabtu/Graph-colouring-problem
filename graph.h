#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>

//had to do this so I can set up the neighbours member within Node
typedef struct Node Node;
struct Node{
    size_t id;
    size_t n_neighbours;
    Node** neighbours;
};

typedef struct{
    size_t V;
    Node** nodes;
}Graph;

Node* createNode(size_t id);
Graph* createGraph(size_t V);
void addNode(Graph* graph, size_t id);
void addEdge(Graph* graph, Node* u, Node* v);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
size_t getMaxClique(Graph* graph);

#endif