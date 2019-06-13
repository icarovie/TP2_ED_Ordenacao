// Inclusao das Bibliotecas Padrao
#include <iostream>
#include <string>
#include <time.h>

// Inclusão de .H
#include "algoritmos.hpp"
#include "helpers.hpp"

using namespace std;


int main(int argc, char* argv[]){
    // Declaração De Tipos Primitivos
    string variacaoQuicksort, tipoVetorString, aux;
    int tipoVetorInt, tamanhoVetor;
    bool exibirVetores = false;
    unsigned long int numeroComparacoes = 0, numeroTrocas = 0;

    // Define as Preferencias do Usuario
    variacaoQuicksort = argv[1];
    tipoVetorString = argv[2];
    tamanhoVetor = atoi(argv[3]);
    
    if (argv[4]) {
        aux = argv[4];
    } else {
        aux = " ";
    }
    exibirVetores = !aux.compare("-p");
    
    definirTipo(tipoVetorString, &tipoVetorInt);

    int *vetor = gerarVetor(tipoVetorInt,tamanhoVetor);

    if(exibirVetores){
        cout << "Antes Do Quicksort" <<endl;
        imprimirVetor(vetor,tamanhoVetor);
        cout <<endl;
    }

    //quicksort(vetor,0,tamanhoVetor, &numeroComparacoes,&numeroTrocas);
    //quicksortMedianaDeTres(vetor,0,tamanhoVetor);
    //quicksortPrimeiroElemento(vetor,0,tamanhoVetor, &numeroComparacoes,&numeroTrocas);

    if(exibirVetores){
        cout << " Depois Do Quicksort" <<endl;
        imprimirVetor(vetor,tamanhoVetor);
        cout <<endl;
    }

    cout << "Numero De Comparacoes feitas: " << numeroComparacoes<<endl;
    cout << "Numero De Trocas Feitas: " << numeroTrocas <<endl;

    free(vetor);

	return 0;
}