#include "stdio.h"
#include "stdlib.h"
#define Vertex int
#define graph digraph
#define Graph Digraph
#define GRAPHinit DIGRAPHinit
#define GRAPHshow DIGRAPHshow
#define maxV 100

static int lbl[maxV], parnt[maxV][maxV];
typedef struct digraph *Digraph; // Objeto do tipo Digraph que contém o endereço de um digraph
typedef struct node *link;

struct digraph {  // Digrafo
    int V;        // Número de vértices
    int A;        // Número de arestas
    link *adj;    // Ponteiro para a lista de adjacência (são ou não vizinhos)
};

struct node{
  Vertex w;
  link next;
};

link NEW (Vertex w, link next);
Digraph DIGRAPHinit (int V);
void DIGRAPHinsertA (Digraph G, Vertex v, Vertex w);
void DIGRAPHshow (Digraph G);
void GRAPHinsertE (Graph G, Vertex v, Vertex w);

link NEW (Vertex w, link next){
  link x = malloc(sizeof*x);
  x->w = w;
  x->next = next;
  return x;
}

Digraph DIGRAPHinit (int V){
  Vertex v;
  Digraph G = malloc(sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = malloc(V * sizeof(link));
  for (v = 0; v < V; v++)
    G->adj[v] = NULL;
  return G;
}

void DIGRAPHinsertA (Digraph G, Vertex v, Vertex w){
  link p;
  if (v == w) return;
  for (p = G->adj[v]; p!=NULL; p = p->next)
    if (p->w== w) return;
  G->adj[v]= NEW(w, G->adj[v]);
  G->A++;
}

GRAPHdeg(Digraph G, Vertex v){
  int x = 0;
  link p;
  for (p = G->adj[v]; p == G->adj[v]; p = p->next)
    x++;
  return x;
}

void GRAPHinsertE (Graph G, Vertex v, Vertex w){
  DIGRAPHinsertA(G,v,w);
  DIGRAPHinsertA(G,w,v);
}

void DIGRAPHshow (Digraph G){
  Vertex v;
  link p;
  for (v =0; v < G->V; v++){
    printf("%2d:", v);
    for (p = G->adj[v]; p != NULL; p = p->next)
      printf("%2d", p->w);
    printf("\n");
  }
}

/*void GRAPHremoveE(Digraph G, Vertex v, Vertex w){
  link p, p2;

  for(p = G->adj[v]; p != NULL; p = p->next){
    if(p->next == w)
      p2 = p->next;
      p->next = p2->next;
      printf("\n\n%d %d\n\n",p2,p2->next);
  }
}*/

void pathR (Digraph G, Vertex v){
  link p;
  lbl[v] = 0;
  for (p=G->adj[v]; p != NULL; p=p->next)
    if (lbl[p->w] == -1) {
      parnt[v][p->w] = 1;
      pathR(G,p->w);
    }
}


int DIGRAPHpath (Digraph G,Vertex s,Vertex t){
  Vertex v, y;
  for (v = 0; v < G->V; v++) {
    lbl[v] = -1;
    for(y = 0; y < G->V; y++){
      parnt[v][y] = 0;
    }
  }
  parnt[s][s] = 1;
  pathR(G,s);
  if (lbl[t] != -1)
    return 1;
  else
    return 0;
}


main(){
  link next;
  Digraph g;
  int qtd, n, i, gral, y, a, b;

  printf("Informe a quantidade de vertices: ");
  scanf("%d", &n);
  printf("\n");

  while (n <= 0) {
    printf("Erro: informe outra quantidade ");
    scanf("%d", &n);
  }

  g = DIGRAPHinit(n);
  printf("\n# Inserindo Arcos\n");

  printf("\nQuantos arcos deseja inserir: ");
  scanf("%d", &qtd);
  printf("\n");

  while ((qtd <= 0) || (qtd > (n * (n - 1)))) {
    printf("Errado! Digite outro: ");
    scanf("%d", &qtd);
  }

  Vertex v, w;
  for (i = 0; i < qtd; i++) {

    printf("\nArco %d\n", i + 1);
    printf("Informe o arco na forma v-w: ");
    scanf("%d-%d", &v, &next);
    DIGRAPHinsertA(g, v, next);
  }



  printf("\ndigite o caminho para verificar a existencia(v-w): ");
  scanf("%d-%d", &v, &w);
  y = DIGRAPHpath(g, v, w);

  if(y)
    printf("\nexiste caminho!\n");
  else
    printf("\nnao existe caminho!\n");


  printf("\nDigrafo formado:\n");
  DIGRAPHshow(g);

  /*printf("\n\ninforme o vertece q deseja excluir(v-w)");
  scanf("%d-%d",&v, &w);
  GRAPHremoveE(g, v, w );*/

  for(a = 0; a < n; a++){
    printf(" %d ",lbl[a]);
  }
  printf("\n\n");
  for(a = 0; a < n; a++){
    for( b = 0; b < n; b++){
      printf(" %d ",parnt[a][b]);
      }
    printf("\n");
  }

  /*
  printf("\nDigrafo formado com aresta apagada:\n");
  DIGRAPHshow(g);*/

  system("pause");

}
