#ifndef METODOS_HPP
#define METODOS_HPP

void trocar(int *a, int *b);

// Quicksort Classico
void quicksort(int *vetor, int esquerda, int direita, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas);

// Quicksort Mediana de 3
int particao(int *vetor, int inicio, int fim);
void quicksortMedianaDeTres(int *vetor, int inicio, int fim);

// Quicksort Primeiro Elemento
void quicksortPrimeiroElemento(int *vetor, int esquerda, int direita, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas);

// Quicksort 1%
void quicksortInsercaoUm(int *vetor, int esquerda, int direita, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas);

#endif