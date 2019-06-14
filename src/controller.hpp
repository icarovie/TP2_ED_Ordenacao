#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include <iostream>
#include <string>

#include "helpers.hpp"
#include "quicksort.hpp"

using namespace std;

void iniciaPrograma(string variacaoQuicksort, int tamanhoVetor, int tipoVetor, bool exibirVetores, unsigned long long int *numeroComparacoes, unsigned long long int *numeroTrocas);

#endif