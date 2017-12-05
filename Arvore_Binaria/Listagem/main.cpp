#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
using namespace std;

void em_Ordem(arvorebin *raiz){
  if(raiz != NULL){
    em_Ordem(raiz->esquerda);
    printf("%d ", raiz->chave);
    em_Ordem(raiz->direita);
    /* Para mostrar em ordem descrescente troque a esquerda coma a direita */
  }
}

void pos_Ordem(arvorebin *raiz){
  if(raiz != NULL){
    em_Ordem(raiz->esquerda);
    em_Ordem(raiz->direita);
    printf("%d ", raiz->chave);
  }
}

void pre_Ordem(arvorebin *raiz){
  if(raiz != NULL){
    printf("%d ", raiz->chave);
    em_Ordem(raiz->esquerda);
    em_Ordem(raiz->direita);

  }
}

arvorebin* getArvore();

int main(){

  arvorebin* raiz = getArvore();

  cout << "\n\tMetodos de Listar a Arvore Binaria de Busca \n" << endl;

  cout << "\tMetodo EMD: ";
  em_Ordem(raiz);

  cout << "\n\tMedoto EDM: ";
  pos_Ordem(raiz);

  cout << "\n\tMetodo MED: ";
  pre_Ordem(raiz);

  cout << "\n" << endl;

  return 0;
}
