// Inclusao das Bibliotecas Padrao
#include <iostream>
#include <string>
#include <time.h>

// Inclusão de .H
#include "helpers.hpp"
#include "controller.hpp"

using namespace std;


int main(int argc, char* argv[]){
    // Declaração De Tipos Primitivos
    string variacaoQuicksort, tipoVetorString, aux;
    int tipoVetorInt, tamanhoVetor;
    bool exibirVetores = false;
    unsigned long long int numeroComparacoes = 0, numeroTrocas = 0;

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
    cout << "Passei da Definicao do Tipo" <<endl;
    // Taca-lhe Pau Marcio
    iniciaPrograma(variacaoQuicksort, tamanhoVetor, tipoVetorInt, exibirVetores, &numeroComparacoes, &numeroTrocas);


    cout << endl << "Numero de Trocas: "<< numeroTrocas <<endl;
    cout << "Numero de Comparacoes: "<< numeroComparacoes <<endl;

	return 0;
}