#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
using namespace std;


int main(){

  arvorebin* raiz = getArvore();
  cout << "\n\t";
  em_Ordem(raiz);

  int valor;

  while(raiz != NULL){

    cout << "\n\tExcluir Chave ~:> ";
    cin >> valor;

    arvorebin *p = raiz;
    arvorebin *q = NULL;

    while(p != NULL && p->chave != valor){
      q = p;
      p = (valor < p->chave)? p->esquerda : p->direita;
    }//fim while

    if(p == NULL){
      cout << "\n\tElemento nao encontrado...\n";
      continue;
    }

    arvorebin* rp;
    if(p->esquerda == NULL){
      rp = p->direita;
    }
    else if(p->direita == NULL){
      rp = p->esquerda;
    }
    else{

      arvorebin* f = p;
      rp = p->direita;
      arvorebin* s = rp->esquerda;

      while(s != NULL){
        f = rp;
        rp = s;
        s = rp->esquerda;
      }

      if(f != p){
        f->esquerda = rp->direita;
        rp->direita = p->direita;
      }
      rp->esquerda = p->esquerda;
    }

    if(q == NULL){
      raiz = rp;
    }else{
      if(p == q->esquerda){
        q->esquerda = rp;
      }else{
        q->direita = rp;
      }
      free(p);
    }
    system("cls");
    cout << "\t";
    em_Ordem(raiz);
    cout << "\n";
  }

  cout << "\n\tArvore vazia!" << endl;

  return 0;

}
