#ifndef QI_HPP
#define QI_HPP

#include <iostream>
#include "helpers.hpp"

void insercao(int *v, int tamanho, double *numeroComparacoes, double *numeroTrocas) {
    int i,j;
    int aux[tamanho];
    for (i = 1; i < tamanho; i++) {
        aux[i] = v[i]; 
        j = i - 1; 
        while (( j >= 0 ) && (aux[i] < v[j])) {  
            (*numeroComparacoes)++;                            
            (*numeroTrocas)++;                            
            v[j + 1] = v[j];                     
            j--;                                    
            v[j + 1] = aux[i];                    
        }
    }
}

void particaoQuicksortInsercao(int esquerda, int direita, int *i, int *j, int vetor[], double *numeroComparacoes, double *numeroTrocas){
    *i = esquerda; *j = direita;
    int aux;
    int meio = (esquerda + direita) / 2;
    int a = vetor[esquerda], b = vetor[meio], c = vetor[direita];
    int medianaIndice; 
    //define o pivo de acordo com a especificação do trabalho para o quicksort 
    //verifica qual é o indice da mediana
    (*numeroComparacoes)++;
    if (a < b) {
        (*numeroComparacoes)++;
        if (b < c) {
            medianaIndice = meio;
        } else {
            (*numeroComparacoes)++;
            if (a < c) {
                medianaIndice = direita;
            } else {
                medianaIndice = esquerda;
            }
        }
    } else {
        (*numeroComparacoes)++;
        if (c < b) {
            medianaIndice = meio;
        } else {
            (*numeroComparacoes)++;
            if (c < a) {
                medianaIndice = direita;
            } else {
                medianaIndice = esquerda;
            }
        }
    }
    
    int pivo = vetor[medianaIndice];
    
    do{ 
        // Indentifico do lado esquerdo qual é o primeiro elemento maior que o meu pivô
        while (pivo > vetor[*i]){
            (*numeroComparacoes)++;
            (*i)++; 
        } 
        
        // Identifico do lado direito o primeiro elemento menor que o meu pivô
        while (pivo < vetor[*j]){
            (*numeroComparacoes)++; 
            (*j)--;
        } 
        
        (*numeroComparacoes)++; 
        // Caso os indices não tenham ferido o principio de que os indices I e J não se cruzaram, eu troco o A e o B de lugar
        if (*i <= *j){
            if(*i < *j)(*numeroTrocas)++; 
            aux = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = aux;

            (*i)++; (*j)--;
        }
    // Faço isso enquanto o I não se cruzar com o J
    } while (*i <= *j);
}

void quicksortInsercao(int esquerda, int direita, int vetor[], int tamanho, float porcentagem, double *numeroComparacoes, double *numeroTrocas){ 
    int i, j;
    int tamanhoPart = (direita-esquerda) + 1;
    static int tamanhoInicial; 
    
    // Trato o caso especial
    if (tamanhoPart == tamanho){
        tamanhoInicial = tamanho;
    }

    if(tamanhoPart > porcentagem * tamanhoInicial){
        particaoQuicksortInsercao(esquerda, direita, &i, &j, vetor, numeroComparacoes, numeroTrocas);
    
        if(esquerda < j)
            quicksortInsercao(esquerda, j, vetor,tamanho, porcentagem, numeroComparacoes, numeroTrocas);
        if(i < direita)
            quicksortInsercao(i, direita, vetor, tamanho, porcentagem, numeroComparacoes, numeroTrocas);
    } 
    else {
        insercao(&vetor[esquerda], tamanhoPart, numeroComparacoes, numeroTrocas);
    }
} 

#endif