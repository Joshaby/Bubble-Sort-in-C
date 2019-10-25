#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Quantidade de N elementos, que sera realizado o algoritimo.
#define MAX1 30000

//Cria uma lista aleatoria de tamanho N.
int* aleatorio1();

//Salva a lista aleatoria em um arquivo do tipo .txt.
void CreateRandomTXT1();

//Realiza o algoritimo da bolha.
void Bubble1(int listaSeq[]);

//Salva o resultado do algoritimo em um arquivo do tipo .txt.
void LISTtoTXT1(int ListaSeq[]);

//Cria a lista sequencial, com base no .txt(aleatorio) salvo.
void TXTtoLIST1(int *ListaSeq);
