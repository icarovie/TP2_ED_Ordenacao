#ifndef QNR_HPP
#define QNR_HPP

#include <iostream>
#include "simulaPilha.hpp"

void particaoquicksortNaoRecursivo(int esquerda, int direita, int* vetor, int *i, int *j, double *numeroComparacoes, double *numeroTrocas){
    *i = esquerda; *j = direita;
    int pivo = vetor[(*i + *j)/2]; 
    int aux;
    
    do{
        // Procuro no lado esquerdo um elemento que é maior que o pivo
        while (pivo > vetor[*i]){
            (*numeroComparacoes)++;
            (*i)++; 
        } 
        // Procuro do lado direito um elemento que é menor que o pivo
        while (pivo < vetor[*j]){
            (*numeroComparacoes)++; 
            (*j)--;
        } 
        
        (*numeroComparacoes)++; 
        // Como no Quicksort os I e o J não podem se cruzar, se eles ainda não se cruzaram troco A e B
        if (*i <= *j){
            if(*i < *j)(*numeroTrocas)++;
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;

            (*i)++; (*j)--;
        }
    // Vou permanecer trocando os elementos ate que o I e o J se cruzem
    } while (*i <= *j);
}

void quicksortNaoRecursivo(int esquerda, int direita, int *vetor, double *numeroComparacoes, double *numeroTrocas){
    // Como não posso utilizar recusividade, implemento uma pilha
    Pilha pilha;
    int i, j;

    // Atribuo a direita e esquerda ao ponteiro do item pra direita e pra esquerda
    struct Item item;
    struct Item auxItem;
    item.direita = direita;
    item.esquerda = esquerda;
    pilha.empilha(item);
    
    do{
        // Verifico se existe elementos dentro do vetor
        if(direita > esquerda){
            // Executo a ideia principal do quicksort, divido o vetor em um subvetor e ordeno ele
            particaoquicksortNaoRecursivo(esquerda, direita, vetor, &i, &j, numeroComparacoes, numeroTrocas);
            // Empilho a o subvetor que for maior
            if ((j-esquerda) > (direita - i)){
                item.direita = j;
                item.esquerda = esquerda;
                pilha.empilha(item);
                esquerda = i;
            }
            else{
                item.direita = direita;
                item.esquerda = i;
                pilha.empilha(item);
                direita = j;
            }
        }
        else{
            // Tiro da pilha o subvetor que ainda não foi ordenado
            pilha.desempilha(&auxItem);
            esquerda = auxItem.esquerda;
            direita = auxItem.direita;
        }
    // Realizo o procedimento até que a minha pilah esteja completamente vazia
    }while(!pilha.isVazia());
} 

#endif