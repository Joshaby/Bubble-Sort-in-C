#include "bubbleSequencial.h"

int* aleatorio1(){
  int *vetor = (int*)malloc(MAX1*sizeof(int));
  int j, aux;
  for(int i = 0; i<MAX1;i++){
    vetor[i]=i;
  }
  for(int i = MAX1-1; i>=0; i--){
    j = (rand() % (i+1));
    aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
  }
  return vetor;
}

void CreateRandomTXT1() {
  int* vetorint = aleatorio1();
  FILE *txt;
  txt = fopen("randomList.txt", "w");
  for (int i = 0; i < MAX1; i ++) {
    fprintf(txt, "%i\n", vetorint[i]);
  }
  fclose(txt);
}

void Bubble1(int *ListaSeq) {
  bool verificador = true;
  while(verificador == true){
    verificador = false;
    for (int j = 0; j < (MAX1 - 1); j ++) {
      if(ListaSeq[j] > ListaSeq[j + 1]) {
        int AUX = ListaSeq[j + 1];
        ListaSeq[j + 1] = ListaSeq[j];
        ListaSeq[j] = AUX;
        verificador = true;
      }
    }
  }
}

void TXTtoLIST1(int *ListaSeq){
  int x = 0, cont = 0;
  FILE *txt;
  txt = fopen("randomList.txt", "r");
  while(fscanf(txt, "%i", &x) != EOF) {
    ListaSeq[cont] = x;
    cont ++;
  }
  fclose(txt);
}
void LISTtoTXT1(int *ListaSeq) {
  int i;
  FILE *txt;
  txt = fopen("bubble.txt", "w");
  for (i = 0; i < MAX1; i ++) {
    fprintf(txt, "%i\n", ListaSeq[i]);
  }
  fclose(txt);
}
