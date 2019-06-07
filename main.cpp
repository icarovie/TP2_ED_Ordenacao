// Inclusao das Bibliotecas Padrao
#include <iostream>
#include <string>
#include <time.h>

// Inclusão de .H
#include "algoritmos.hpp"
#include "helpers.hpp"

using namespace std;


int main(int argc, char *argv[]){
    string tipoString;
    int tipo;
    int tamanhoVetor;

    tamanhoVetor = 20;

    //tipo = definirTipo(tipoString, tipo);
    int *vetor = gerarVetor(1,tamanhoVetor);
    cout << "Antes Do Quicksort" <<endl;
    imprimirVetor(vetor,tamanhoVetor);
    cout <<endl;
    quicksort(vetor,0,tamanhoVetor);
    cout << " Depois Do Quicksort" <<endl;
    imprimirVetor(vetor,tamanhoVetor);
    delete vetor;
	return 0;
}