#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <string>
using namespace std;

void ordena(string tipo, int esquerda, int direita, int *vetor, int originaltamanho, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas);
void particao(string variacaoQuicksort, int esquerda, int direita, int *i, int *j, int *vetor, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas);
void insercao(int *vetor, int esquerda, int direita, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas);

#endif