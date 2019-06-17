#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVERTICES 100

void dijkstra(int vertices,int origem,int destino,int *custos)
{
    int i,v,    /* vari�veis auxiliares */
    ant[MAXVERTICES],   /* vetor dos antecessores */
    z[MAXVERTICES];     /* v�rtices para os quais se conhece o caminho m�nimo */
    double min, /* vari�vel auxiliar */
    dist[MAXVERTICES]; /* vetor com os custos dos caminhos */

    /* Inicializa��o */

    for (i=0; i<vertices; i++) /* inicializo o grafo*/
    {
        if (custos[(origem-1)*vertices+i]!=-1) /* vertices N de vertices*/
        {
            ant[i]=origem-1;
            dist[i]=custos[(origem-1)*vertices+i]; /*custo de menor caminho recebe*/
        }
        else
        {
            ant[i]=-1; /*verifica se h� caminho de i para j, retorna -1 se n�o existe */
            dist[i]=HUGE_VAL;
        }
        z[i]=0;/*fecha vertice i*/
    }
    z[origem-1]=1;/* indica o conjunto de v�rtices para os quais j� se conhece um caminho de custo m�nimo partindo da "origem".*/
    dist[origem-1]=0; /*distancia do vetor(origem) a  origem = 0*/

    /* La�o principal */

    do
    {

        /* Encontrando o v�rtice que deve entrar em z */

        min=HUGE_VAL;
        for (i=0; i<vertices; i++) /*novo minimo */
            if (!z[i])
                if (dist[i]>=0 && dist[i]<min) /*  dist � o custo do menor caminho da "origem" ao v�rtice i.*/
                {
                    min=dist[i]; /*compara com infinito e substitui pelo valor do dist*/
                    v=i;
                }

        /* Calculando as dist�ncias dos novos vizinhos de z */

        if (min!=HUGE_VAL && v!=destino-1) /*calcula pontos do vetor z (vizinho)*/
        {
            z[v]=1;
            for (i=0; i<vertices; i++)
                if (!z[i])
                {
                    if (custos[v*vertices+i]!=-1 && dist[v]+custos[v*vertices+i]<dist[i])
                    {
                        dist[i]=dist[v]+custos[v*vertices+i]; /* se ainda nao ha custo entre os vertices dist recebe a distancia entre eles*/
                        ant[i]=v;
                    }
                }
        }
    }
    while (v!=destino-1 && min!=HUGE_VAL);

    /* Imprimindo o resultado  */

    if (min==HUGE_VAL)
        printf("\nNo digrafo dado nao existe caminho entre os vertices %d e %d !!\n",origem,destino);
    else
    {
        printf("\nO caminho de custo minimo entre os vertices %d e %d  e (na ordem reversa):\n",
               origem,destino);
        i=destino;
        printf("%d",i);
        i=ant[i-1];
        while (i!=-1)
        {
            printf("<-%d",i+1);/*+1 porque o programa come�a os vertices com 0*/
            i=ant[i];
        }
        printf("\nO custo deste caminho e: %d\n",(int) dist[destino-1]);
    }

} /* dijsktra */


main(int argc, char **argv) /*argc valor inteiro(quantidade de argumentos passados)*/ /* vetor de char que cont�m os argumentos*//*ponteiro para ponteiro*/
{

    char opcao,lixo[50];   /* vari�veis auxiliares */
    int i,custo,           /* vari�veis auxiliares */
    vertices=0,        /* n�mero de v�rtices do grafo */
             origem,            /* v�rtice origem */
             destino,           /* v�rtice destino */
             *custos=NULL;      /* matriz de incid�ncia */

    do
    {

        /* Menu principal */

        printf("\n      Trabalho feito por Carlos Henrique Penna e Felipe Calle Riccio \n\n");
        printf("\n      Caminho de custo minimo em grafos\n");
        printf("        (Algoritmo de Dijkstra)\n\n");
        printf("Escolha sua opcao:\n");
        printf("     1. Adicionar um grafo\n");
        printf("     2. Procura os menores caminhos no grafo\n");
        printf("     3. Sair do programa\n\n");
        printf("Opcao: ");
        gets(&opcao);

        /* Digitar novo grafo */

        if (opcao==49) /* opcao 1 */
        {
            do
            {
                printf("\nNumero de vertices (entre 2 e %d): ",MAXVERTICES);
                scanf("%d",&vertices);
            }
            while (vertices<2 || vertices>MAXVERTICES); /* repita enquanto nao digitar algo entre 2 e 100*/

            if (!custos) /* se nao tiver matriz fa�a*/
                free(custos);
            custos=(int *) malloc(sizeof(int)*vertices*vertices);
            for (i=0; i<=vertices*vertices; i++) custos[i]=-1;
            printf("Digite as arestas\n");
            do
            {

                do
                {
                    printf("Origem da aresta (entre 1 e %d ou 0 para sair): ",vertices);
                    scanf("%d",&origem);
                }
                while (origem<0 || origem>vertices);

                if (origem)
                {

                    do
                    {
                        printf("Destino da aresta (entre 1 e %d, menos %d): ",vertices,origem);
                        scanf("%d",&destino);
                    }
                    while (destino<1 || destino>vertices || destino==origem);

                    do
                    {
                        printf("Custo (positivo) da aresta do vertice %d para o vertice %d: ",origem,destino);
                        scanf("%d",&custo);
                    }
                    while (custo<0);
                    custos[(origem-1)*vertices+destino-1]=custo;
                }

            }
            while (origem);
            gets(lixo);
        }

        /* Achar caminho m�nimo entre 2 v�rtices */

        if (opcao==50 && vertices>0)/* opcao 2 */
        {
            printf("\nDigite os vertices origem e destino do caminho\n");
            do
            {
                printf("Vertice origem (entre 1 e %d): ",vertices);
                scanf("%d",&origem);
            }
            while (origem<1 || origem>vertices);

            do
            {
                printf("Vertice destino (entre 1 e %d, menos %d): ",vertices,origem);
                scanf("%d",&destino);
            }
            while (destino<1 || destino>vertices || destino==origem);

            dijkstra(vertices,origem,destino,custos);
            gets(lixo);
        }

    }
    while (opcao!=51); /* opcao 3 */

    printf("\nAte a proxima...\n\n");

} /* Fim do programa */
