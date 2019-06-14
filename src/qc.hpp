#ifndef QC_HPP
#define QC_HPP

#include <iostream>
#include "helpers.hpp"

using namespace std;


//QuickSort Clássico
void particiona(int esquerda, int direita, int *i, int *j, int *vetor, double* numeroComparacoes, double* numeroTrocas){

    int pivo, aux;
    *i = esquerda; *j = direita;
    pivo = vetor[(*i + *j)/2]; //Pivo

        do{
            while (pivo > vetor[*i]){
                *numeroComparacoes+=1;
                (*i)++;
            }
            while (pivo < vetor[*j]){
                *numeroComparacoes+=1;
                (*j)--;
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

void ordena(int esquerda, int direita, int *vetor, double *numeroComparacoes, double *numeroTrocas){ 
    int i; 
    int j;
    particiona(esquerda, direita, &i, &j, vetor,numeroComparacoes,numeroTrocas);
    
    if (esquerda < j)
        ordena(esquerda, j, vetor, numeroComparacoes, numeroTrocas); 

    *numeroComparacoes+=1;
   
    if (i < direita)
        ordena(i, direita, vetor, numeroComparacoes, numeroTrocas);

    *numeroComparacoes+=1;
}

void quicksortClassico(int *vetor, int numItens, double *numeroComparacoes, double* numeroTrocas){
    ordena(0, numItens-1, vetor, numeroComparacoes, numeroTrocas);
}

#endif
