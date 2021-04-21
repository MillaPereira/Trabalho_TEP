#ifndef RACIONAIS_H
#define RACIONAIS_H

typedef struct Racional_st *Racional_pt;
typedef struct Racional_st Racional_t;

Racional_pt criaNumRacional(long int numerador, long int denominador);

long int retornaDen(Racional_pt numero);

long int retornaNum(Racional_pt numero);

void destroiNum(Racional_pt numRacional);

void copiaNumRacional(Racional_pt num1, Racional_pt num2);

int comparaNumeros(Racional_pt valor1, Racional_pt valor2);

int verificaEquivalente(Racional_pt valor1, Racional_pt valor2);

int verificaDenominadorZero(Racional_pt numRacional);

int verificaNumeradorZero(Racional_pt numRacional);

int verificaAmbosZero(Racional_pt numRacional);

Racional_pt somaRacionais(Racional_pt valor1, Racional_pt valor2);

void acumulaRacional(Racional_pt valor1, Racional_pt valor2);

Racional_pt subtraiRacionais(Racional_pt valor1, Racional_pt valor2);

Racional_pt multiplicaRacionais(Racional_pt valor1, Racional_pt valor2);

void acumulaMultiplicacaoRacionais(Racional_pt valor1, Racional_pt valor2);

Racional_pt divideRacionais(Racional_pt valor1, Racional_pt valor2);

Racional_pt elevaAoQuadrado(Racional_pt valor);

Racional_pt raizQuadrada(Racional_pt numRacional);

double converteRacionalEmReal(Racional_pt numRacional);

Racional_pt converteRealEmRacional(double numReal);

int verificaRacionalConverteEmInteiro(Racional_pt numRacional);

#endif