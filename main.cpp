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
    unsigned long int numeroComparacoes = 0;
    unsigned long int numeroTrocas = 0;

    variacaoQuicksort = argv[1];
    tipoVetorString = argv[2];
    tamanhoVetor = atoi(argv[3]);
    
    definirTipo(tipoVetorString, &tipoVetorInt);

    int *vetor = gerarVetor(tipoVetorInt,tamanhoVetor);

    cout << "Antes Do Quicksort" <<endl;
    imprimirVetor(vetor,tamanhoVetor);
    cout <<endl;
    //quicksort(vetor,0,tamanhoVetor, &numeroComparacoes,&numeroTrocas);
    //quicksortMedianaDeTres(vetor,0,tamanhoVetor);
    quicksortPrimeiroElemento(vetor,0,tamanhoVetor, &numeroComparacoes,&numeroTrocas);
    cout << " Depois Do Quicksort" <<endl;
    imprimirVetor(vetor,tamanhoVetor);
    cout <<endl;
    cout << "Numero De Comparacoes feitas: " << numeroComparacoes<<endl;
    cout << "Numero De Trocas Feitas: " << numeroTrocas <<endl;
    free(vetor);
	return 0;
}