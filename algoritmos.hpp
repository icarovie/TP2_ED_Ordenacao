#ifndef METODOS_HPP
#define METODOS_HPP

void trocar(int *a, int *b);
void quicksort(int *vetor, int esq, int dir);

// Quicksort Mediana de 3
int particao(int *vetor, int inicio, int fim);
void quicksortMedianaDeTres(int *vetor, int inicio, int fim);

#endif