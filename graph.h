#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    size_t id;
    size_t* neighbours;
}Node;

typedef struct Graph{
    size_t V;
    Node** nodes;
}Graph;

Node* createNode(size_t id);
Graph* createGraph(size_t V);
void addNode(Graph* graph, size_t id);
void addEdge(Graph* graph, size_t u, size_t v);
void printGraph(Graph* graph);
void freeGraph(Graph* graph);
#endif