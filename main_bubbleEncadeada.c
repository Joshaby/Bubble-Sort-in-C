#include "bubbleEncadeada.h"

int main() {
  nocab P;
  CriarLista(&P);
  CreateRandomTXT();
  TXTtoLIST(&P);
  BubbleSort(&P);
  LISTtoTXT(&P);
  return 0;
}
