#include "bubbleEncadeada.h"

void CriarLista(CEnc Cabeca){ 
  Cabeca->inicio = NULL;
}

int* aleatorio(){
  int *vetor = (int*)malloc(MAX*sizeof(int));
  int j, aux;
  for(int i = 0; i<MAX;i++){
    vetor[i]=i;
  }
  for(int i = MAX-1; i>=0; i--){
    j = (rand() % (i+1));
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
  }
  return vetor;
}


void InserirLista(CEnc Cabeca,int valor){
  node *novo = (node*) malloc(sizeof(node));
  novo->Dado = valor;
  novo->prox = NULL;
  if(Cabeca->inicio == NULL){
    Cabeca->fim = Cabeca->inicio = novo;
  }
  else{
    (Cabeca->fim)->prox = novo;
    Cabeca->fim = novo;
  }
}

void CreateRandomTXT() {
  int *vetorint = aleatorio();
  FILE *txt;
  txt = fopen("randomList.txt", "w");
  for (int i = 0; i < MAX; i ++) {
    fprintf(txt, "%i\n", vetorint[i]);
  }
  fclose(txt);
}

void TXTtoLIST(CEnc P){
  int x = 0;
  FILE *txt;
  txt = fopen("randomList.txt", "r");
  while(fscanf(txt, "%i", &x) != EOF) {
    InserirLista(P, x);
  }
  fclose(txt);
}

void BubbleSort(CEnc P) {
  _Bool i = true;
  int AUX1 = 0;
  while(i == true){
    ListaEnc AUX = P->inicio;
    i = false;
    for (; AUX->prox != NULL; AUX = AUX->prox) {
        if (AUX->Dado >= (AUX->prox)->Dado) {
            i = true;
            AUX1 = AUX->Dado;
            AUX->Dado = AUX->prox->Dado;
            AUX->prox->Dado = AUX1;
        }
    }
  }
}

void LISTtoTXT(CEnc P) {
  node *aux;
  FILE *txt;
  txt = fopen("bubble.txt", "w");
  while((P->inicio) != NULL){
    fprintf(txt, "%i\n", (P->inicio)->Dado);
    aux = P->inicio;
    P->inicio = (P->inicio)->prox;
    free(aux);
  }
  fclose(txt);
}
