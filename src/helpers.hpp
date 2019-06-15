#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <string>

using namespace std;

int* gerarVetor(int tipo, int tamanho);
int* gerarVetorCrescente(int tamanho);
int* gerarVetorDecrescente(int tamanho);
int* gerarVetorAleatorio(int tamanho);
void imprimirVetor(int* vetor, int n);
void definirTipo(string tipoString, int* tipoInt);
int calculaMediana(int i, int meio, int j);
void insercao(int *vetor, int esquerda, int direita, double *numeroComparacoes, double *numeroTrocas);
string vetorPraString(int *vetor, int tamanhoVetor);

#endif

