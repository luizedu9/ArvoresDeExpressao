#ifndef PILHA_H
#define PILHA_H

#include "arvore.h"

typedef struct pilha *Pilha;    
 
Pilha cria_pilha();
void destroi_pilha(Pilha pilha);
int vazia_pilha(Pilha pilha);
void insere_pilha(Pilha pilha, Raiz nodo);
Raiz retira_pilha(Pilha pilha);

#endif /* PILHA_H */

