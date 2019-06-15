#ifndef QPE_HPP
#define QPE_HPP

#include <iostream>
#include "helpers.hpp"

void particionaPrimeiroElemento(int esquerda, int direita, int *i, int *j, int *vetor,double *numeroComparacoes, double *numeroTrocas){
    // Defino os parametros iniciais para o quicksort, nesse caso o pivô é o primeiro elemento
    int pivo, aux;
    *i = esquerda; *j = direita;
    pivo = vetor[*i];
        
        do{
        // Procuro no lado esquerdo um elemento que é maior que o pivo
        while (pivo > vetor[*i]){ 
            (*i)++;
            *numeroComparacoes+=1;
        }
        // Procuro do lado direito um elemento que é menor que o pivo
        while (pivo < vetor[*j]){ 
            (*j)--;
            *numeroComparacoes+=1;
        }
            
        *numeroComparacoes+=1;
            // Como no Quicksort os I e o J não podem se cruzar, se eles ainda não se cruzaram troco A e B
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
            // Repito o processo até que os indices I e J se cruzem
    } while (*i <= *j);
        
}

void ordenaPrimeiroElemento(int esquerda, int direita, int *vetor,double *numeroComparacoes, double *numeroTrocas){ 
    int i, j; 
    
    particionaPrimeiroElemento(esquerda, direita, &i, &j, vetor, numeroComparacoes,numeroTrocas);

    *numeroComparacoes+=1;
    if (esquerda < j)
        ordenaPrimeiroElemento(esquerda, j, vetor, numeroComparacoes,numeroTrocas);
    
    *numeroComparacoes+=1; 
    if (i < direita)
        ordenaPrimeiroElemento(i, direita, vetor, numeroComparacoes,numeroTrocas);    
}

void quickSortPrimeiroElemento(int *vetor, int tamanhoVetor, double *numeroComparacoes, double *numeroTrocas){
    ordenaPrimeiroElemento(0, tamanhoVetor-1, vetor, numeroComparacoes,numeroTrocas);
}

#endif