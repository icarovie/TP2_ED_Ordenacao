#include <iostream>
#include <string>

void iniciaPrograma(string variacaoQuicksort, int tamanhoVetor, int tipoVetor, int &numeroComparacoes, int &numeroTrocas, bool exibirVetores){
    int *vetor = gerarVetor(tipoVetor,tamanhoVetor);

    if(variacaoQuicksort == "QC")
        ordena("QC", 0, tamanho-1, vetor, tamanho);

    if(variacaoQuicksort == "QM3")
        ordena("QM3", 0, tamanho-1, vetor, tamanho);
        
    if(variacaoQuicksort == "QPE")
        ordena("QPE", 0, tamanho-1, vetor, tamanho);
    
    if(variacaoQuicksort == "QI1")
        ordena("QI1", 0, tamanho-1, vetor, tamanho);
    
    if(variacaoQuicksort == "QI5")
        ordena("QI5", 0, tamanho-1, vetor, tamanho);

    if(variacaoQuicksort == "QI10")
        ordena("QI10", 0, tamanho-1, vetor, tamanho);

    if(exibirVetores)
        imprimirVetor(vetor,tamanhoVetor);

    free(vetor);
}