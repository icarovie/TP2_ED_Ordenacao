#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <string>
using namespace std;

void ordena(string tipo, int esquerda, int direita, int *vetor, int originaltamanho, double *numeroComparacoes, double *numeroTrocas);
void particao(string variacaoQuicksort, int esquerda, int direita, int *i, int *j, int *vetor, double *numeroComparacoes, double *numeroTrocas);
void insercao(int *vetor, int esquerda, int direita, double *numeroComparacoes, double *numeroTrocas);

#endif