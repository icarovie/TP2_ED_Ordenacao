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
int quicksort(int *vetor, int esquerda, int direita){
	int i, j, numeroMovimentos = 0;
    int pivo;

	i = esquerda;
	j = direita - 1;
	pivo = vetor[(esquerda + direita) / 2];

	while(i <= j){
		while(vetor[i] < pivo && i < direita){ i++; }
		while(vetor[j] > pivo && j > esquerda){ j--; }
		if(i <= j){
            trocar(vetor,i,j);
			numeroMovimentos++;
			i++;
			j--;
		}
	}
	if(j > esquerda)
		quicksort(vetor, esquerda, j+1);
	if(i < direita)
		quicksort(vetor, i, direita);
	
	return numeroMovimentos;
}

int insertionSort(int *vetor, int esquerdauerda, int direitaeita) {
    int i, j, aux, numeroMovimentos=0;
    for (i = esquerdauerda; i < direitaeita; i++) {
        aux = vetor[i];
        j = i;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            numeroMovimentos++;
            j--;
        }
        numeroMovimentos++;
        vetor[j + 1] = aux;
    }
    return numeroMovimentos;
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