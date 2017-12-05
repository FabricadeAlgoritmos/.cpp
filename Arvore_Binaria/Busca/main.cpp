#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
using namespace std;

arvorebin* Busca(arvorebin* raiz, int chave){
  while(raiz != NULL){
    if(chave < raiz->chave){
      raiz = raiz->esquerda;
    }
    else if(chave > raiz->chave){
      raiz = raiz->direita;
    }
    else{
      return raiz;
    }
  }
  return NULL;
}

int main(){

  arvorebin* raiz = getArvore();
  cout << "\n\t";
  em_Ordem(raiz);

  int chave;
  cout << "\n\tBusca ~:> ";
  cin >> chave;

  arvorebin* no = Busca(raiz, chave);

  cout << "\n\t";
  if(no != NULL){
    cout << no->chave << " encontrado na arvore" << endl;
  }else{
    cout << "Elemento nao encontrado\n" << endl;
  }

  return 0;
}
