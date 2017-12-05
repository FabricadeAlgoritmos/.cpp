
/*
  Na Árvore Binária de Busca
  os valores maiores sempre ficam
  a direita da raiz
  e os menores a esquerda,
  o mesmo vale para as sub-árvores
*/

struct arvorebin {
    int chave;
    arvorebin* esquerda;
    arvorebin* direita;
};

void em_Ordem(arvorebin *raiz){
  if(raiz != NULL){
    em_Ordem(raiz->esquerda);
    printf("%d ", raiz->chave);
    em_Ordem(raiz->direita);
    /* Para mostrar em ordem descrescente troque a esquerda coma a direita */
  }
}

arvorebin* getArvore(){
  arvorebin* raiz = (arvorebin*) malloc(sizeof(arvorebin));
  raiz->chave = 10;
  raiz->esquerda = NULL;
  raiz->direita = NULL;

  /* filho a esquerda da raiz */
  arvorebin* no1 = (arvorebin*) malloc(sizeof(arvorebin));
  no1->chave = 5;
  no1->esquerda = NULL;
  no1->direita = NULL;
  raiz->esquerda = no1;

  /* filho a direita da raiz */
  arvorebin* no2 = (arvorebin*) malloc(sizeof(arvorebin));
  no2->chave = 15;
  no2->esquerda = NULL;
  no2->direita = NULL;
  raiz->direita = no2;

  /* filho a esquerda do no1 */
  arvorebin* no3 = (arvorebin*) malloc(sizeof(arvorebin));
  no3->chave = 1;
  no3->esquerda = NULL;
  no3->direita = NULL;
  no1->esquerda = no3;

  /* filho a direita do no1 */
  arvorebin* no4 = (arvorebin*) malloc(sizeof(arvorebin));
  no4->chave = 8;
  no4->esquerda = NULL;
  no4->direita = NULL;
  no1->direita = no4;

  /* filho a esquerda do no2 */
  arvorebin* no5 = (arvorebin*) malloc(sizeof(arvorebin));
  no5->chave = 13;
  no5->esquerda = NULL;
  no5->direita = NULL;
  no2->esquerda = no5;

  /* filho a direita do no2 */
  arvorebin* no6 = (arvorebin*) malloc(sizeof(arvorebin));
  no6->chave = 20;
  no6->esquerda = NULL;
  no6->direita = NULL;
  no2->direita = no6;

  return raiz;
}
