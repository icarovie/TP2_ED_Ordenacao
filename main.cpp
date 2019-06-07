// Inclusao das Bibliotecas Padrao
#include <iostream>
#include <string>
#include <time.h>

// Inclusão de .H
#include "algoritmos.hpp"
#include "helpers.hpp"

using namespace std;


int main(int argc, char* argv[]){
    string variacaoQuicksort;
    string tipoVetorString;
    int tipoVetorInt;
    int tamanhoVetor;

    variacaoQuicksort = argv[1];
    tipoVetorString = argv[2];
    tamanhoVetor = atoi(argv[3]);
    
    definirTipo(tipoVetorString, &tipoVetorInt);

    int *vetor = gerarVetor(tipoVetorInt,tamanhoVetor);
    cout << "Antes Do Quicksort" <<endl;
    imprimirVetor(vetor,tamanhoVetor);
    cout <<endl;
    quicksort(vetor,0,tamanhoVetor);
    cout << " Depois Do Quicksort" <<endl;
    imprimirVetor(vetor,tamanhoVetor);
    delete vetor;
	return 0;
}