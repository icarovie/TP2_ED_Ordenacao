#include <iostream>
#include <cstdlib>

#define MAX 500000

// Crio o meu nó
struct Item{
    int esquerda;
    int direita;
};

// Monto uma pilha
class Pilha{
	int cabeca;

    public:
        Pilha();
		Item vetor[MAX];

        void empilha(struct Item item);
        void desempilha(struct Item *item);
        int retornarTamanho();
        bool isVazia();
};

Pilha::Pilha(){cabeca = -1;}

int Pilha::retornarTamanho(){
	return cabeca + 1;
}

bool Pilha::isVazia(){
	return cabeca < 0;
}

void Pilha::empilha(struct Item x){
	cabeca += 1;
	vetor[cabeca].direita = x.direita;
	vetor[cabeca].esquerda = x.esquerda;
}

void Pilha::desempilha(struct Item *item){
	if(this->isVazia())
		return;

	*item = vetor[cabeca--];
	
}