#include <stdio.h>
#include <stdlib.h>
#include "cidades.h"
#include "cidades.c"

int main() {
    
    const char *arquivo = "teste01.txt";
    
    Estrada *estrada = getEstrada(arquivo);
    
    calcularMenorVizinhanca(arquivo);
    
    cidadeMenorVizinhanca(arquivo);
    
//    printf("%d\n", estrada->T);
//    printf("%d\n", estrada->N); 
    
    
//    for(int i = 0; i < estrada->N; i++){
//    	printf("%d ", estrada->C[i].Posicao);
//    	printf("%s\n", estrada->C[i].Nome);
//	}
	
	return 0;
    
}
