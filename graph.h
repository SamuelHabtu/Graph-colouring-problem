#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    size_t id;
    node* edges;
}node;

typedef struct graph{
    size_t V;
    node* nodes;
}graph;