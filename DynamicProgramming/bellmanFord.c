#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct edge{
    int source;
    int destination;
    int weight;
};

struct graph{
    int v;
    int e;
    struct edge * edges;
};

struct graph * createGraph(int v, int e){
    struct graph * g;
    g = (struct graph *)malloc(sizeof(struct graph));
    g->v = v;
    g->e = e;
    g->edges = (struct edge *)malloc(e * sizeof(struct edge));
    return g;
}

void display(int * distance, int v, int flag){
    if(flag){
        printf("\nVertex\tDistance from source vertex\n");
        for(int vertex = 0; vertex < v; vertex++) printf("\n%d\t\t%d", vertex + 1, distance[vertex]);
    }
    else printf("\nNegative edge cycle is there!");
}

void bellmanFord(struct graph * g, int source){
    int * distance = (int *)malloc(g->v * sizeof(int));
    int flag = 1;
    for(int vertex = 0; vertex < g->v; vertex++) distance[vertex] = INT_MAX;
    distance[source] = 0;
    for(int loop = 0; loop < g->v - 1; loop++){
        for(int edge = 0; edge < g->e; edge++){
            int s = g->edges[edge].source;
            int d = g->edges[edge].destination;
            int w = g->edges[edge].weight;
            if(distance[s] + w < distance[d]) distance[d] = distance[s] + w;
        }
    }
    for(int edge = 0; edge < g->e; edge++){
        int s = g->edges[edge].source;
        int d = g->edges[edge].destination;
        int w = g->edges[edge].weight;
        if(distance[s] + w < distance[d]){
            flag = 0;
            break;
        }
    }
    display(distance, g->v, flag);
}

int main(){
    int v, e;
    struct graph * g;
    printf("\nEnter the no of vertices:");
    scanf("%d", &v);
    printf("\nEnter the no of edges:");
    scanf("%d", &e);
    g = createGraph(v, e);
    for(int edge = 0; edge < e; edge++){
        printf("\nEnter the source, distance and weight of the edge %d: ", edge + 1);
        scanf("%d %d %d", &g->edges[edge].source, &g->edges[edge].destination, &g->edges[edge].weight);
    }
    bellmanFord(g, 0);
    return 0;
}