// Inclusao das Bibliotecas Padrao
// Makefile C:\MinGW\bin\mingw32-make.exe
#include <iostream>
#include <string>
#include <time.h>

// Inclusão de .H
#include "helpers.hpp"
//#include "controller.hpp"
#include "qc.hpp"


using namespace std;


int main(int argc, char* argv[]){
    // Declaração De Tipos Primitivos
    string variacaoQuicksort, tipoVetorString, aux;
    int tipoVetorInt, tamanhoVetor;
    bool exibirVetores = false;
    double numeroComparacoes = 0, numeroTrocas = 0;

    // Define as Preferencias do Usuario
    variacaoQuicksort = argv[1];
    tipoVetorString = argv[2];
    tamanhoVetor = atoi(argv[3]);
    
    // Verifico se existe um parametro 4
    if (argv[4]) {
        aux = argv[4];
    } else {
        aux = " ";
    }
    // Se existir eu defino que os vetores devem ser impressos
    exibirVetores = !aux.compare("-p");

    // Converto o tipo do vetor de string pra numero, a fim de facilitar a geracao dele
    definirTipo(tipoVetorString, &tipoVetorInt);

    // Gero o Vetor
    int *vetor = gerarVetor(tipoVetorInt,tamanhoVetor);
    
    quicksortClassico(vetor,tamanhoVetor, &numeroComparacoes, &numeroTrocas);
    // Taca-lhe Pau Marcio
    //iniciaPrograma(variacaoQuicksort,vetor, tamanhoVetor, tipoVetorInt, exibirVetores, &numeroComparacoes, &numeroTrocas);
    cout << endl << "Numero de Trocas: "<< numeroTrocas <<endl;
    cout << "Numero de Comparacoes: "<< numeroComparacoes <<endl;

    if(exibirVetores)
        imprimirVetor(vetor,tamanhoVetor);

    free(vetor);
	return 0;
}