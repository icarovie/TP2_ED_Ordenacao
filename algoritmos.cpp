#include <iostream>

void trocar(int *vetor, int i, int j){
    int aux;

    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

/*
 *  QUICKSORT CLASSICO 
 */
void quicksort(int *vetor, int esquerda, int direita, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas){
	int i, j;
    int pivo;
	i = esquerda;
	j = direita - 1;
	pivo = vetor[(esquerda + direita) / 2];

	while(i <= j){
        (*numeroComparacoes)++;
		while(vetor[i] < pivo && i < direita){ i++; }
        (*numeroComparacoes)++;
		while(vetor[j] > pivo && j > esquerda){ j--; }
        (*numeroComparacoes)++;
		if(i <= j){
            trocar(vetor,i,j);
            (*numeroTrocas)++;
			i++;
			j--;
		}
	}
	if(j > esquerda)
		quicksort(vetor, esquerda, j+1,numeroComparacoes,numeroTrocas);
	if(i < direita)
		quicksort(vetor, i, direita, numeroComparacoes,numeroTrocas);
	
}

/*
 * QUICKSORT MEDIANA DE 3
 */

void encontraMediana(int &medianaIndice, int a, int b, int c, int meio, int inicio, int fim){
    if(a < b && b < c)
        medianaIndice = meio;

    if(a < c && c <= b)
       medianaIndice = fim;

    if(c <= a && a < b)
        medianaIndice = inicio;
    
    if(c < b && b <= a)
        medianaIndice = meio;
    
    if(b <= c && c < a)
        medianaIndice = fim;
    
    if(b <= a && a <= c)
        medianaIndice = inicio;

}

int particao(int *vetor, int inicio, int fim) {
    int meio = (inicio + fim) / 2;
    int a = vetor[inicio];
    int b = vetor[meio];
    int c = vetor[fim];
    int medianaIndice; 

    encontraMediana(medianaIndice, a, b, c, meio, inicio, fim);
    trocar(vetor, medianaIndice, fim);
        
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i = i + 1;
            trocar(vetor, i, j);
        }
    }

    trocar(vetor, i + 1, fim);
    return i + 1; 
}

void quicksortMedianaDeTres(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int q = particao(vetor, inicio, fim);
        quicksortMedianaDeTres(vetor, inicio, q - 1);
        quicksortMedianaDeTres(vetor, q + 1, fim);
    }
}

/**
 *  QUICKSORT PIVÔ PRIMEIRO ELEMENTO
 */

void quicksortPrimeiroElemento(int *vetor, int esquerda, int direita, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas){
	int i, j;
    int pivo;
	i = esquerda;
	j = direita - 1;
	pivo = vetor[esquerda];

	while(i <= j){
        (*numeroComparacoes)++;
		while(vetor[i] < pivo && i < direita){ i++; }
        (*numeroComparacoes)++;
		while(vetor[j] > pivo && j > esquerda){ j--; }
        (*numeroComparacoes)++;
		if(i <= j){
            trocar(vetor,i,j);
            (*numeroTrocas)++;
			i++;
			j--;
		}
	}
	if(j > esquerda)
		quicksortPrimeiroElemento(vetor, esquerda, j+1,numeroComparacoes,numeroTrocas);
	if(i < direita)
		quicksortPrimeiroElemento(vetor, i, direita, numeroComparacoes,numeroTrocas);
	
}