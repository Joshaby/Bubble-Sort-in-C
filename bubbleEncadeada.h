#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 30000

//Estrutura do tipo no.
typedef struct Lista {
  int Dado;
  struct Lista *prox;
}node;

//Estrutura que contem apontadores para o inicio e final de uma lista encadeada.
typedef struct Cabeca {
  struct Lista *inicio;
  struct Lista *fim;
}nocab;

typedef nocab *CEnc;
typedef node *ListaEnc;

//Inicia a lista, definindo o inicil = NULL.
void CriarLista(CEnc Cabeca);

//Cria uma lista aleatoria de tamanho N.
int* aleatorio();

//Insere X inteiro na lista encadeada.
void InserirLista(CEnc Cabeca,int valor);

//Salva a lista aleatoria em um arquivo do tipo .txt.
void CreateRandomTXT();

//Cria a lista encadeada, com base no .txt(aleatorio) salvo.
void TXTtoLIST(CEnc P);

//Realiza o algoritimo da bolha.
void BubbleSort(CEnc P);

//Salva o resultado do algoritimo em um arquivo do tipo .txt.
void LISTtoTXT(CEnc P);
