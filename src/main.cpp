// Inclusao das Bibliotecas Padrao
// Makefile C:\MinGW\bin\mingw32-make.exe
#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include <ctime>
#include <sstream>
#include <fstream>

// Inclusão de .H
#include "helpers.hpp"
#include "qc.hpp"
#include "qm3.hpp"
#include "qpe.hpp"
#include "qi.hpp"
#include "qnr.hpp"


using namespace std;


int main(int argc, char* argv[]){
    // Declaração De Tipos Primitivos
    string variacaoQuicksort, tipoVetorString, aux;
    int tipoVetorInt, tamanhoVetor;
    bool exibirVetores = false;
    double numeroComparacoes = 0, numeroTrocas = 0;
    stringstream vetorString;

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

    // Armazena o vetor gerado em uma string, caso eu precise imprimir ele posteriormente
    vetorString << vetorPraString(vetor, tamanhoVetor) << "\n";

    // Inicio da Contagem Do Tempo
    auto cronometroInicio = std::chrono::system_clock::now();

    // Defino Qual Algoritmo do Quicksort Deve Ser Utilizado
    if(variacaoQuicksort == "QC"){
        quicksortClassico(vetor,tamanhoVetor, &numeroComparacoes, &numeroTrocas);
    } else if (variacaoQuicksort == "QM3"){
        quickSortMedianaTres(vetor,tamanhoVetor, &numeroComparacoes, &numeroTrocas);
    } else if (variacaoQuicksort == "QPE"){
        quickSortPrimeiroElemento(vetor,tamanhoVetor, &numeroComparacoes, &numeroTrocas);
    } else if (variacaoQuicksort == "QI1"){
        quicksortInsercao(0, tamanhoVetor-1, vetor, tamanhoVetor, 0.01, &numeroComparacoes, &numeroTrocas);
    } else if (variacaoQuicksort == "QI5"){
        quicksortInsercao(0, tamanhoVetor-1, vetor, tamanhoVetor, 0.05, &numeroComparacoes, &numeroTrocas);
    } else if (variacaoQuicksort == "QI10"){
        quicksortInsercao(0, tamanhoVetor-1, vetor, tamanhoVetor, 0.10, &numeroComparacoes, &numeroTrocas);
    } else if (variacaoQuicksort == "QNR") {
        quicksortNaoRecursivo(0, tamanhoVetor-1, vetor, &numeroComparacoes, &numeroTrocas);
    }

    // Fim da Contagem do Tempo
    auto cronometroFim = std::chrono::system_clock::now();

    std::chrono::duration<double> tempo = cronometroFim-cronometroInicio;
    double tempoSegundos = tempo.count();
    
    // Saida
    cout << variacaoQuicksort <<" "<< tipoVetorString<<" "<<tamanhoVetor<<" "<< numeroComparacoes<<" "<<numeroTrocas<<" "<< tempoSegundos << endl;

    if(exibirVetores)
        cout << vetorString.str() << endl;
    

    free(vetor);
	return 0;
}