#include <iostream>
#include <string>
#include "helpers.hpp"
#include "quicksort.hpp"

using namespace std;

void iniciaPrograma(string variacaoQuicksort, int tamanhoVetor, int tipoVetor, bool exibirVetores, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas){
    int *vetor = gerarVetor(tipoVetor,tamanhoVetor);
    cout << "Gerei o Vetor" <<endl;

    if(variacaoQuicksort == "QC"){
        cout << "Chamei o Ordena" << endl;
        ordena("QC", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    } 

    if(variacaoQuicksort == "QM3")
        ordena("QM3", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
        
    if(variacaoQuicksort == "QPE")
        ordena("QPE", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    
    if(variacaoQuicksort == "QI1")
        ordena("QI1", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);
    
    if(variacaoQuicksort == "QI5")
        ordena("QI5", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);

    if(variacaoQuicksort == "QI10")
        ordena("QI10", 0, tamanhoVetor-1, vetor, tamanhoVetor, numeroComparacoes, numeroTrocas);

    if(exibirVetores)
        imprimirVetor(vetor,tamanhoVetor);

    free(vetor);
}