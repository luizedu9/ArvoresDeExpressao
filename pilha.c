/* 
	ALUNO: LUIZ EDUARDO PEREIRA
	MATRICULA: 0021619
	15/11/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "arvore.h"

struct pilha {
    int tamanho;
    struct nodo *ultimo;
};

struct nodo {
    Raiz raiz;
    struct nodo *anterior; 
};
typedef struct nodo Nodo;

Pilha cria_pilha() {
    Pilha pilha;
    pilha = (Pilha) malloc(sizeof(struct pilha));
    pilha->tamanho = 0;
    pilha->ultimo = NULL;
    return(pilha);
}

void destroi_pilha(Pilha pilha) {
    free(pilha);
    return;
}

int vazia_pilha(Pilha pilha) {
    if (pilha->tamanho == 0) {
        return(1);
    }
    return(0);
}

void insere_pilha(Pilha pilha, Raiz raiz) {
    Nodo *nodo;
    nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->raiz = raiz;
    pilha->tamanho++;  
    if (pilha->tamanho == 1) { /*pilha vazia*/
        pilha->ultimo = nodo;
        nodo->anterior = NULL;
        return;
    }
    nodo->anterior = pilha->ultimo;
    pilha->ultimo = nodo;
    return;
}

Raiz retira_pilha(Pilha pilha) {
    Raiz retorno = pilha->ultimo->raiz;
    Nodo *aux;
    pilha->tamanho--;
    if (pilha->tamanho == 0) {
        free(pilha->ultimo);
        pilha->ultimo = NULL;
        return(retorno);
    }
    aux = pilha->ultimo->anterior;
    free(pilha->ultimo);
    pilha->ultimo = aux;
    return(retorno);
}