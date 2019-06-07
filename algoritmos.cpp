#include <iostream>

void trocar(int *vetor, int i, int j){
    int aux;

    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

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
