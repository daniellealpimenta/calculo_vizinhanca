#include <stdio.h>
#include <stdlib.h>
#include "cidades.h"

Estrada *getEstrada(const char *nomeArquivo) {
	Estrada *estrada = (Estrada*)malloc(sizeof(Estrada));
	
	if (estrada == NULL) {
	    perror("Erro ao alocar memória para a Estrada");
	    exit(1);
	}
	
	estrada->C = (Cidade*)malloc(sizeof(Cidade));
	
	if (estrada->C == NULL) {
	    perror("Erro ao alocar memória para o array da lista");
	    free(estrada);
    	exit(1);
	}
	
	FILE *arquivo = fopen(nomeArquivo, "r");
		if(arquivo == NULL) {
			perror("ERRO!\n");
			exit(1);
		}
	
	fscanf(arquivo,"%d", &estrada->T);
	fscanf(arquivo,"%d", &estrada->N);
	

	for(int i = 0; i <= estrada->N; i++) {	
		fscanf(arquivo,"%d %50[^\n]", &estrada->C[i].Posicao, estrada->C[i].Nome);
	}

	return estrada;
	
	fclose(arquivo);
	
	free(estrada->C);
	free(estrada);
}

double menor_vizinhanca;
int cidade_menor_vizinhanca = 0;

double calcularMenorVizinhanca(const char *nomeArquivo){
	
	Estrada *estrada = getEstrada(nomeArquivo);
	
	int tamanho_fronteira = (estrada->N) - 1;
	int tamanho_vizinhanca = estrada->N;
	
	float fronteira[tamanho_fronteira];
	
	for(int i = 0; i < estrada->N - 1; i++) {
		fronteira[i] = (estrada->C[i].Posicao + estrada->C[i + 1].Posicao) / 2.0;
		
		printf("fronteira da cidade %d|%d : %.2f \n", i+1, i+2, fronteira[i]);
	}
	
	printf("\n");
	
	double vizinhanca[tamanho_vizinhanca];
	
	vizinhanca[0] = fronteira[0];
	vizinhanca[tamanho_vizinhanca - 1] = (estrada->T - fronteira[tamanho_fronteira - 1]);
	
	if(estrada->N > 2){
		for(int i = 1; i < tamanho_fronteira; i++){
		vizinhanca[i] = (fronteira[i] - fronteira[i - 1]);
		}
	}
	
	menor_vizinhanca = vizinhanca[0];
    
    for (int i = 0; i < tamanho_vizinhanca; i++) {
        printf("vizinhanca da cidade %d: %.2lf \n", i+1, vizinhanca[i]);
        
        for (int j = 0; j < tamanho_vizinhanca; j++) {
            if (vizinhanca[j] < menor_vizinhanca) {
                menor_vizinhanca = vizinhanca[j];
                cidade_menor_vizinhanca = j;
            }
        }
    }
    
    return cidade_menor_vizinhanca;
	
}

char *cidadeMenorVizinhanca(const char *nomeArquivo){
	
	Estrada *estrada = getEstrada(nomeArquivo);
	
	printf("\n");
	
	printf("Menor vizinhanca: %.2lf\n", menor_vizinhanca);
	printf("Cidade com menor vizinhanca: %s\n", estrada->C[cidade_menor_vizinhanca].Nome);
	
	return estrada->C[cidade_menor_vizinhanca].Nome;
}