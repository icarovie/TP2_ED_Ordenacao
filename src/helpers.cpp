#include "helpers.hpp"

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <sstream>

using namespace std;

int* gerarVetor(int tipo, int tamanho) {
    if(tipo == 1)
            return gerarVetorAleatorio(tamanho);
    if(tipo == 2)
            return gerarVetorCrescente(tamanho);
    if(tipo == 3)
            return gerarVetorDecrescente(tamanho);
    return 0;
}

int* gerarVetorAleatorio(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));
    srand(time(NULL));
    for (int i=0; i<tamanho; i++) {
        vetor[i] = rand();
    }
    return vetor;
}

int* gerarVetorCrescente(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=0; i<tamanho; i++) {
        vetor[i] = i;
    }
    return vetor;
}

int* gerarVetorDecrescente(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=tamanho, j=0; i>0; i--, j++) {
        vetor[j] = i;
    }

    return vetor;
}

void imprimirVetor(int *vetor, int n){
    cout<<"inicio imprimir"<<endl;
    for (int i = 0; i < n; ++i)
        cout << vetor[i] << " ";
}

void definirTipo(string tipoString, int *tipoInt){
    if(tipoString == "Ale")
        *tipoInt = 1;
    if(tipoString == "OrdC")
        *tipoInt = 2;
    if(tipoString == "OrdD")
        *tipoInt = 3;
}

int calculaMediana(int i, int meio, int j){
    // Se o meu prieiro elemento for menos que o meu ultimo elemento
	if (i < j){
        // E o meu elemento do meio for menor que o meu primeiro elemento
		if (meio < i)
            // Então o meu primeiro elemento é a mediana
			return 1;

		else if (j < meio) 
			return 3;

		else
			return 2;
	}

    // Se o meu ultimo for maior que o meu elemento do meio
	else if (meio < j)
        // O Meu ultimo é a mediana
		return 3;

    // Se o meu primeiro elemento for menor que o meu elemento do meio
	else if (i < meio)
        // Meu primeiro elemento é a mediana
		return 1;
        
	else
		return 2;
}


void insercao(int *vetor, int esquerda, int direita, double *numeroComparacoes, double *numeroTrocas){
	int i, j, aux;
    
	for (i = esquerda; i < direita; i++){
		aux = vetor[i];
		j = i;
        // Se a direita for maior que Zero, e o meu elemento for menor, entao eu insiro
		while ((j>=0)&&(aux<vetor[j])){
			*numeroComparacoes+=1;
			*numeroTrocas+=1;
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
}

string vetorPraString(int *vetor, int tamanhoVetor) {
    stringstream ss;
    for (int i=0; i<tamanhoVetor; i++) {
        ss << vetor[i] << " ";
    }
    ss << "\n";
    return ss.str();
}

