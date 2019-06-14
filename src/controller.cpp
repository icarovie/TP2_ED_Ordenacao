#include <iostream>
#include <string>
#include "helpers.hpp"
#include "quicksort.hpp"

using namespace std;

void iniciaPrograma(string variacaoQuicksort,int *vetor, int tamanhoVetor, int tipoVetor, bool exibirVetores, double *numeroComparacoes, double *numeroTrocas){
    
    if(variacaoQuicksort == "QC"){
        ordena("QC", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
        cout << "Cheguei aqui suave1"<<endl;
    }
    else if(variacaoQuicksort == "QM3")
        ordena("QM3", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    else if(variacaoQuicksort == "QPE")
        ordena("QPE", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    else if(variacaoQuicksort == "QI1")
        ordena("QI1", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    else if(variacaoQuicksort == "QI5")
        ordena("QI5", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    else if(variacaoQuicksort == "QI10")
        ordena("QI10", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    
    cout << "Cheguei aqui suave2"<<endl;
}