#ifndef QM3_HPP
#define QM3_HPP

#include <iostream>
#include "helpers.hpp"

void particionaMediana(int esquerda, int direita, int *i, int *j, int *vetor, double *numeroComparacoes, double *numeroTrocas){
    int pivo,meio, aux;
    *i = esquerda; *j = direita;
    meio = vetor[(*i + *j)/2];
    
    if (calculaMediana(*i,meio,*j) == 1)
        pivo = vetor[*i];
    else if (calculaMediana(*i,meio,*j) == 2)
        pivo = vetor[meio];
    else
        pivo = vetor[*j];
    
    do{
        while (pivo > vetor[*i]){ 
            (*i)++;
            *numeroComparacoes+=1;
        }

        while (pivo < vetor[*j]){ 
            (*j)--;
            *numeroComparacoes+=1;
        }
            
        *numeroComparacoes+=1;
            if (*i <= *j){
             *numeroComparacoes+=1;
                if(*i  < *j){
                    aux= vetor[*i];
                    vetor[*i] = vetor[*j];
                    vetor[*j] = aux;
                    *numeroTrocas+=1;
                }
                (*i)++; 
                (*j)--;
            }
            *numeroComparacoes+=1;   
    } while (*i <= *j);
}

void ordenaMediana(int esquerda, int direita, int* vetor, double *numeroComparacoes, double *numeroTrocas){ 
    int i,j;
    
    particionaMediana(esquerda, direita, &i, &j, vetor,numeroComparacoes,numeroTrocas);

    if (esquerda < j)
        ordenaMediana(esquerda, j, vetor, numeroComparacoes,numeroTrocas);
    
    *numeroComparacoes+=1;
    if (i < direita){
        *numeroComparacoes+=1; 
        ordenaMediana(i, direita, vetor,numeroComparacoes,numeroTrocas);
    }
    *numeroComparacoes+=1;    
}

void quickSortMedianaTres(int *vetor, int tamanhoVetor, double *numeroComparacoes, double *numeroTrocas){
    ordenaMediana(0, tamanhoVetor-1, vetor, numeroComparacoes, numeroTrocas);
}

#endif

// Easter EGG: É até engraçado. Eu estava lendo um livro de Clean Code, e o autor propoe que os nomes das funcoes devem ser autoexplicativas,
// por exemplo, a funcão "quickSortMedianaTres" já deve te explicar completamente o que ela faz somente pelo nome dela, e nao por causa de um
// comentário acima dela, o autor apresenta que comentários podem ser mentirosos, não por má indole, mas suponhamos que eu adicionasse o seguinte
// comentário "executa completamente o quicksort". Esse comentário seria mentiroso, porque aquela função sozinha não executa completamente o
// quicksort, na realidade ela chama outra função que chama outras duas funcoes e ai sim executa o quicksort. Legal né? esse tal de Clean Code.