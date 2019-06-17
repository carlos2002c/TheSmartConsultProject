#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct
{
    int *gr, g;
    int GRAFO;
} Vertice;

typedef struct
{
    int *r, *d, *p, *ad, *aberto;
    int s, v;
}

void main()
{
    GRAFO *gr = criaGrafo(6);

    criaAresta(gr, 0, 1, 10);
    criaAresta(gr, 0, 2, 5);
    criaAresta(gr, 2, 1, 3);
    criaAresta(gr, 1, 3, 1);
    criaAresta(gr, 2, 3, 8);
    criaAresta(gr, 2, 4, 2);
    criaAresta(gr, 4, 5, 6);
    criaAresta(gr, 3, 5, 4);
    criaAresta(gr, 5, 4, 4);

    int *r = dijkstra(gr,0);

    int i;
    for(i=0; i<gr->vertices; i++)
        printf("D(v0->v%d) = %d\n", i, r[i]);
}

void inicializaD(GRAFO *g, int*d, int*p, int s)
{
    int v;
    for(v=0; v<g->vertice; v++)
    {
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0;
}

void relaxa(GRAFO *g, int *d, int *p, int v)
{
    ADJACENCIA *ad = g->adj[u].cab;
    while (ad && ad->vertices != v)
        ad= ad->prox;
    if(ad)
    {
        if(d[v] > d[u] + ad->peso)
        {
            d[v] = d[u] + ad -> peso;
            p[v] = u;
        }
    }
}

int *dijkstra(GRAFO *g, int s)
{
    int *d = (int *)
             malloc(g->vertices*sizeof(int));
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializaD(g,d, s);

    int i;
    for(i=0; i<g->vertices; i++)
        aberto[i] = true;

    while(existeAberto(g,aberto))
    {
        int u = menorDist(g,aberto,d);
        aberto[u] = false;

        ADJACENCIA *ad = g->ad[u].cab;
        while(ad)
        {
            relaxa(g, d, p, u, ad->vertices);
            ad = ad->prox;
        }
    }
    return(d);
}

bool existeAberto(GRAFO *g, int *aberto)
{
    int i;
    for(i=0; i<g->vertices; i++)
        if(aberto[i]) return(true);
    return(false);
}

int menorDist(GRAFO *g, int *aberto, int *d)
{
    int i;
    for(i=0; i<g->vertices; i++)
        if(aberto[i]) break;
    if(i==g->vertices) return (-1);
    int menor = i;
    for(i=menor+1; i<g->vertices; i++)
        if(aberto[i] && (d[menor]>d[i]))
            menor = i;
    return(menor);
}

