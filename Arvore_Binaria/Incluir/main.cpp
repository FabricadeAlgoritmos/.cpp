#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
using namespace std;

void Incluir(arvorebin* raiz, int valor){
  arvorebin* novo = (arvorebin*) malloc(sizeof(arvorebin));
  novo->chave = valor;
  novo->esquerda = NULL;
  novo->direita = NULL;

  arvorebin* pai = NULL;

  while(raiz != NULL){
    pai = raiz;
    if(valor > raiz->chave){
      raiz = raiz->direita;
    }else{
      raiz = raiz->esquerda;
    }
  }

  if(pai != NULL && valor > pai->chave){
    pai->direita = novo;
  }else{
    pai->esquerda = novo;
  }
}

int main(){

  arvorebin* raiz = getArvore();
  cout << "\n\t";
  em_Ordem(raiz);

  int novaChave;
  cout << "\n\tInforme a Chave ~:> ";
  cin >> novaChave;

  Incluir(raiz, novaChave);

  cout << "\n\tNovo Elemento adicionado na arvore!\n\t";
  em_Ordem(raiz);
  cout << "\n";

  return 0;
}
