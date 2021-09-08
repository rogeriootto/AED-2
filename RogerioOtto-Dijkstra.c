#include <stdio.h>
#include <stdlib.h>

int main () {

    int sel = 0, aresta1 = 0, aresta2 = 0, peso = 0, tamanho = 0, flag = 0, i, j, inicio, chegada;
    int infinito = 2147483647;

    printf("Escolha o numero de vertices de 1 a 20: ");
    do {
        scanf("%d", &tamanho);
        if(tamanho > 20 || tamanho <= 0) {
            printf("Digite um valor valido.\n");
        }
        
    }while(tamanho > 20 || tamanho <= 0);

    int grafo[tamanho][tamanho];
    int dist[tamanho], anterior[tamanho], visitado[tamanho];
    int contaVertices = 0, menorDist, menorVertice; 

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            grafo[i][j] = infinito;
        }
    }
    
    do {

        printf("\n--Menu do programa--\n");
        printf("1- Adicionar a aresta;\n");
        printf("2- Listar o grafo;\n");
        printf("3- Menor caminho (Algoritmo de Dijkstra)\n");
        printf("4- Sair;\n");
        printf("Escolha: ");
        scanf("%d", &sel);
        getchar();

        switch (sel){
            case 1: //Adicionar aresta
                printf("Insira o numero do primeiro vertice da ligacao.\n");
                scanf("%d", &aresta1);
                getchar();

                if(aresta1 > tamanho || aresta1 <= 0) { //teste pra n matar tudo
                    printf("Numero do vertice nao eh valido.\n");
                    aresta1 = 0;
                    break;
                }

                printf("Insira o numero do segundo vertice da ligacao.\n");
                scanf("%d", &aresta2);
                getchar();

                if(aresta2 > tamanho || aresta2 <= 0) { //teste pra n matar tudo
                    printf("Numero do vertice nao eh valido.\n");
                    aresta2 = 0;
                    break;
                }

                if (grafo[aresta1-1][aresta2-1] != infinito || grafo[aresta2-1][aresta1-1] != infinito) {
                    printf("Esta aresta ja existe, deseja desistir da operacao ou alterar o peso?\n0- Alterar o peso || 1- Desistir\n");
                    scanf("%d", &flag);
                    getchar();
                }

                if(flag == 1) {
                    flag = 0;
                    break;
                }

                printf("Insira o peso para esta nova aresta.");
                scanf("%d", &peso);

                grafo[aresta1-1][aresta2-1] = peso;
                grafo[aresta2-1][aresta1-1] = peso;

            break;

            case 2: // Listar

                printf("\n");
                for(i = 0; i<tamanho+1; i++) {
                    printf("%d  ",i);
                }
                printf("\n");

                for (i = 0; i < tamanho; i++) {
                    printf("%d  ", i+1);
                    for (j = 0; j < tamanho; j++) {
                        if (grafo[i][j] != infinito) {
                            printf("%d  ", grafo[i][j]);
                        }
                        else {
                            printf("0  ");
                        }
                    }
                    printf("\n");
                }
            break;

            case 3:
                
                printf("Escolha o vertice de partida: \n");
                scanf("%d", &inicio);
                getchar();
                printf("Escolha o vertice de chegada: \n");
                scanf("%d", &chegada);
                getchar();

                menorVertice = chegada;

                for (i = 0; i < tamanho; i++) { // Preenche os vetorex auxiliares com dados de incialização
                    dist[i] = grafo[inicio][i];
                    anterior[i] = inicio;
                    visitado[i] = 0;
                }

                // Seta o primeiro vertice como visitado e itera o contador de vertices
                dist[inicio] = 0;
                visitado[inicio] = 1;
                contaVertices++;

                while (contaVertices < tamanho) {
                    menorDist = infinito;

                    for(i = 0; i < tamanho; i++) {
                        if (dist[i] < menorDist && visitado[i] == 0) {
                            menorDist = dist[i];
                            menorVertice = i;
                        }
                    }

                    visitado[menorVertice] = 1;

                    for (i = 0; i < tamanho; i++) {
                        if (visitado[i] == 0) {
                            if (menorDist + grafo[menorVertice][i] < dist[i]) {
                                dist[i] = menorDist + grafo[menorVertice][i];
                                anterior[i] = menorVertice;
                            }
                        }
                    }

                    contaVertices++;

                }
                printf("O Menor caminho eh: %d ", chegada);
                printf("A Distancia eh: %d\n", dist[chegada]);
                
                do {
                    chegada = anterior[chegada];
                    printf("%d ", chegada);
                } while (chegada != inicio);

                printf("\n");

            break;

            case 4: // Sair
                return 0;
            break;

            default:
                printf("Digite um numero valido.\n");
            break;

        }

    }while (sel != 4);

    return 0;
}
