#include "Quicksort.hpp"
//#include "Stack.hpp"
#include <iostream>
#include <string>

//using std::pair;

// Quicksort não recursivo feito tendo como base o algoritmo disponível nas transparências de sala
/*
void nonRecursive(int *vetor, int size) {
    Stack<std::pair<int,int>> *stack = new Stack<std::pair<int,int>>();
    int esquerda = 0, direita = size - 1, i, j;
    std::pair<int,int> item;
    item.first = esquerda;
    item.second = direita;
    stack->insert(item);
    do {
        numeroComparacoes++;
        if (direita > esquerda) {
            numeroComparacoes++;
            particao("QNR",esquerda,direita,&i, &j, vetor);
            if ((j-esquerda) > (direita-i)) {
                item.second = j;
                item.first = esquerda;
                stack->insert(item);
                esquerda = i;
            }
            else {
                std::pair<int,int> item;
                item.first = i;
                item.second = direita;
                stack->insert(item);
                direita = j;
            }
        }
        else {
            item = stack->remove();
            direita = item.second;
            esquerda = item.first;
        }
    }while (!stack->isEmpty());
    delete stack;
}
*/

void ordena(string variacaoQuicksort, int esquerda, int direita, int *vetor, int tamanho, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas) {
    int i,j; // Índices que serão usados posteriormente
    bool precisaInserir = false; // Variável para definir se é preciso chamar o método de inserção ou não

    // Avalia se é necessário chamar o método de inserção
    if (variacaoQuicksort == "QI1" || variacaoQuicksort == "QI5" || variacaoQuicksort == "QI10") {
        double porcentagem; // Porcentagem a partir da qual devemos chamar o inserção
        int quantidadeChaves = direita - esquerda + 1; // Calcula o número de chaves que estamos cobrindo nesta chamada
        // Define a porcentagem
        if (variacaoQuicksort == "QI1") {
            porcentagem = 0.01;
        } else  if (variacaoQuicksort == "QI5") {
            porcentagem = 0.05;
        } else {
            porcentagem = 0.10;
        }
        // Caso tenhamos menos chaves que 1%, 5% ou 10% do total de chaves define que é necessário chamar o insertion
        if (quantidadeChaves <= tamanho * porcentagem) {
            precisaInserir = true;
        }
    }

    // Caso não precise de inserção
    if (!precisaInserir) {
        // Realiza o quicksort normalmente
        particao(variacaoQuicksort, esquerda, direita, &i, &j, vetor, numeroComparacoes, numeroTrocas);
        (numeroComparacoes)++;
        if (esquerda < j) {
            ordena(variacaoQuicksort, esquerda, j, vetor, tamanho, numeroComparacoes, numeroTrocas);
        }
        (numeroComparacoes)++;
        if (direita > i) {
            ordena(variacaoQuicksort, i, direita, vetor, tamanho, numeroComparacoes,numeroTrocas);
        }
    } else {
        // Caso precise, chama o método de inserção
        insercao(vetor,esquerda,direita, numeroComparacoes, numeroTrocas); // Ordena o subvetor com o inserção
    }
}

void particao(string variacaoQuicksort, int esquerda, int direita, int *i, int *j, int *vetor, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas) {
    int pivo, aux;
    *i = esquerda; *j = direita;

    // Escolhe o pivo com base no tipo do Quicksort
    if (variacaoQuicksort == "QC"  || variacaoQuicksort == "QNR") {
        // Clássico e Não-recursivo tem como pivo o elemento central
        pivo = vetor[(*i + *j)/2];
    } else if (variacaoQuicksort == "QPE") {
        // Primeiro elemento tem como pivo o primeiro elemento do vetor
        pivo = vetor[*i];
    } else {
        // Os demais tem como pivo o valor médio entre primeiro, central e último
        int meio = (*i + *j)/2; // Calcula a posição central
        // Sequencia de ifs para saber qual o elemento central
        // Poderia ter colocado os tres elementos num vetor e ordenado eles, mas preferi fazer assim
        if (vetor[esquerda] <= vetor[direita]) {
            if (vetor[meio] <= vetor[esquerda]) {
                pivo = vetor[esquerda];
            } else if (vetor[meio] >= vetor[direita]) {
                pivo = vetor[direita];
            } else {
                pivo = vetor[meio];
            }
        } else {
            if (vetor[meio] >= vetor[esquerda]) {
                pivo = vetor[esquerda];
            } else if (vetor[meio] <= vetor[direita]) {
                pivo = vetor[direita];
            } else {
                pivo = vetor[meio];
            }
        }
    }

    // Faz as chamadas recursivas enquanto for necessário
    while (*i <= *j) {
        while (pivo > vetor[*i]) {
            (*numeroComparacoes)++;
            (*i)++;
        }
        while (pivo < vetor[*j]) {
            (*numeroComparacoes)++;
            (*j)--;
        }
        (*numeroComparacoes)++;
        if (*i <= *j) {
            (*numeroComparacoes)++;
            if (*i < *j) {
                (*numeroTrocas)++;
                //Troco os Elementos de Lugar
                aux= vetor[*i];
                vetor[*i] = vetor[*j]; 
                vetor[*j] = aux;
            }
            (*i)++; (*j)--;
        }
        (*numeroComparacoes)++;
    }
}

void insercao(int *vetor, int esquerda, int direita, unsigned long long int *numeroTrocas, unsigned long long int *numeroComparacoes) {
    int i, j, aux;
    // Percorre o vetor da posição esquerda até a posição direita e ordena essa parte do vetor
    for (i = esquerda; i < direita; i++) {
        aux = vetor[i];
        j = i;
        while (j >= 0 && vetor[j] > aux) {
            (*numeroComparacoes)++;
            (*numeroTrocas)++;
            vetor[j + 1] = vetor[j];
            j--;
        }
        (*numeroTrocas)++;
        vetor[j + 1] = aux;
    }
}