#include <iostream>
#include <string>
#include <time.h>
#include "helpers.hpp"

using namespace std;

int* gerarVetor(int tipo, int tamanho) {
    if(tipo == 1)
            return gerarVetorAleatorio(tamanho);
    if(tipo == 2)
            return gerarVetorCrescente(tamanho);
    if(tipo == 3)
            return gerarVetorDecrescente(tamanho);
}

int* gerarVetorAleatorio(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=0; i<tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}

int* gerarVetorCrescente(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=0; i<tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

int* gerarVetorDecrescente(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=tamanho, j=0; i>0; i--, j++) {
        vetor[j] = i;
    }

    return vetor;
}

void imprimirVetor(int *vetor, int n){
    for (int i = 0; i < n; ++i)
        cout << vetor[i] << " ";
}

void definirTipo(string tipoString, int *tipoInt){
    if(tipoString == "Ale")
        *tipoInt = 1;
    if(tipoString == "OrdC")
        *tipoInt = 2;
    if(tipoString == "OrdD")
        *tipoInt = 3;
}