#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <string>
using namespace std;

void ordena(string tipo, int esquerda, int direita, int *vetor, int originaltamanho, int &numeroComparacoes, int &numeroTrocas);
void particao(string variacaoQuicksort, int esquerda, int direita, int *i, int *j, int *vetor,int &numeroComparacoes, int &numeroTrocas);
void insercao(int *vetor, int esquerda, int direita, int &numeroTrocas, int &numeroComparacoes);

#endif