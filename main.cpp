// Inclusao das Bibliotecas Padrao
#include <iostream>
#include <string>
#include <time.h>

// Inclusão de .H
#include "algoritmos.hpp"
#include "helpers.hpp"

using namespace std;


int main(int argc, char* argv[]){
    string tipoVetorString;
    int tipoVetorInt;
    int tamanhoVetor;

    // Perguntas
    //cout << "Digite o tipo de vetor que você deseja: ";
    //cin >> tipoVetorString;
    //cout << "Digite o tamanho do vetor que você deseja: ";
    //cin >> tamanhoVetor;

    tipoVetorString = argv[2];
    tamanhoVetor = argv[3];
    

    definirTipo(tipoVetorString, &tipoVetorInt);

    //tipo = definirTipo(tipoVetorString, tipo);
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