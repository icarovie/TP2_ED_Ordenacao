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

int particao(int *vetor, int inicio, int fim) {
    //procura a mediana entre inicio, meio e fim
    int meio = (inicio + fim) / 2;
    int a = vetor[inicio];
    int b = vetor[meio];
    int c = vetor[fim];
    int medianaIndice; //índice da mediana
    //A sequência de if...else a seguir verifica qual é a mediana
    if (a < b) {
        if (b < c) {
            //a < b && b < c
            medianaIndice = meio;
        } else {
            if (a < c) {
                //a < c && c <= b
                medianaIndice = fim;
            } else {
                //c <= a && a < b
                medianaIndice = inicio;
            }
        }
    } else {
        if (c < b) {
            //c < b && b <= a
            medianaIndice = meio;
        } else {
            if (c < a) {
                //b <= c && c < a
                medianaIndice = fim;
            } else {
                //b <= a && a <= c
                medianaIndice = inicio;
            }
        }
    }
    //coloca o elemento da mediana no fim para poder usar o Quicksort de Cormen
    trocar(vetor, medianaIndice, fim);
        
    //*******************LGORITMO DE PARTIÇÃO DE CORMEN*********************
    //o pivo é o elemento final
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;
    /*
     * Este laço irá varrer os vetores da esquerda para direira
     * procurando os elementos que são menores ou iguais ao pivô.
     * Esses elementos são colocados na partição esquerda.         
     */
    for (j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i = i + 1;
            trocar(vetor, i, j);
        }
    }
    //coloca o pivô na posição de ordenação
    trocar(vetor, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}
//Quicksort mediana de três
void quicksortMedianaDeTres(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        //realiza a partição
        int q = particao(vetor, inicio, fim);
        //ordena a partição esquerda
        quicksortMedianaDeTres(vetor, inicio, q - 1);
        //ordena a partição direita
        quicksortMedianaDeTres(vetor, q + 1, fim);
    }
}