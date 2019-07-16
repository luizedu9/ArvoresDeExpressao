/* 
	ALUNO: LUIZ EDUARDO PEREIRA
	MATRICULA: 0021619
	15/11/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "arvore.h"

struct raiz {
    char x;
    struct raiz *dir;
    struct raiz *esq;
};

void cria_expressao(char *expressao, int saida) {
    Pilha pilha;
    Raiz raiz, esq, dir;
    int i;
    float resultado;
    pilha = cria_pilha();
    for (i = 0; i < strlen(expressao); i++) {
        if (operando(expressao[i])) {
            raiz = cria_raiz(expressao[i]);
            insere_pilha(pilha, raiz);
        }
        if (operador(expressao[i])) {
            raiz = cria_raiz(expressao[i]);
            dir = retira_pilha(pilha);
            esq = retira_pilha(pilha);
            raiz = cria_arvore(raiz, esq, dir);
            insere_pilha(pilha, raiz);
        }
    }
    destroi_pilha(pilha); 
    resultado = calculavalor_pos(raiz);
    if (saida) {
        FILE *arquivo;
        arquivo = fopen("Resultado.txt", "a");
        fprintf(arquivo, "\n  Resultado: %f          \n", resultado);         
        infixa(raiz, saida);
        prefixa(raiz, saida);
        fclose(arquivo);
        destroi_arvore(raiz);
        return;
    }
    printf("\nResultado da expreção: %f\n", resultado);
    printf("\nPósFixa: \n%s", expressao);
    printf("\nInFixa: \n");        
    infixa(raiz, saida);
    printf("\nPréFixa: \n");
    prefixa(raiz, saida);
    destroi_arvore(raiz);
    return;
}

Raiz cria_raiz(char item) {
    Raiz raiz;
    raiz = (Raiz) malloc(sizeof(struct raiz));
    raiz->x = item;
    raiz->dir = NULL;
    raiz->esq = NULL;
    return(raiz);
}

Raiz cria_arvore(Raiz raiz, Raiz esq, Raiz dir) {
    raiz->esq = esq;
    raiz->dir = dir;
    return(raiz);
}

void destroi_arvore(Raiz raiz) {
    if (raiz->dir != NULL) {
        destroi_arvore(raiz->dir);
    }
    if (raiz->esq != NULL) {
        destroi_arvore(raiz->esq);
    }
    free(raiz);
    return;
}

Raiz vincula_dir(Raiz raiz, Raiz nodo) {
    raiz->dir = nodo;
    return(raiz);
}

Raiz vincula_esq(Raiz raiz, Raiz nodo) {
    raiz->esq = nodo;
    return(raiz);
}

int operador(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/') {
        return(1);
    }
    return(0);
}

int operando(char op) {
    int i, verificador = 0;
    for (i = 48; i < 58; i++) { 
        if (op == i) {
            verificador = 1;
        }       
    }
    return(verificador);
}

float calculavalor_pos(Raiz raiz) {
    if (raiz->esq == NULL) { /*Se esquerda == NULL, direita tambem será NULL*/
        return(((int)raiz->x) - 48);
    }
    if (raiz != NULL) {
        if (raiz->x == '+') {
            return(calculavalor_pos(raiz->esq) + calculavalor_pos(raiz->dir));
        }
        if (raiz->x == '-') {
            return(calculavalor_pos(raiz->esq) - calculavalor_pos(raiz->dir));
        }
        if (raiz->x == '*') {
            return(calculavalor_pos(raiz->esq) * calculavalor_pos(raiz->dir));
        }
        if (raiz->x == '/') {
            return(calculavalor_pos(raiz->esq) / calculavalor_pos(raiz->dir));
        }
    }
    return(0);
}

void infixa(Raiz raiz, int saida) {
    if (raiz != NULL) {
        if (saida) {
            escreve_arquivo('(');
        }
        else {
            printf("(");
        }
        infixa(raiz->esq, saida);
        if (saida) {
            escreve_arquivo(raiz->x);
        }
        else {
            printf("%c", raiz->x);
        }    
        infixa(raiz->dir, saida);
        if (saida) {
            escreve_arquivo(')');
        }
        else {
            printf(")");
        }
    }
}

void prefixa(Raiz raiz, int saida) {
    if (raiz != NULL) {
        if (saida) {
            escreve_arquivo(raiz->x);
        }
        else {
            printf("%c", raiz->x);
        }
        prefixa(raiz->esq, saida);
        prefixa(raiz->dir, saida);
    }
}

void escreve_arquivo(char caracter) {
    FILE *arquivo;
    arquivo = fopen("Resultado.txt", "a");
    fprintf(arquivo, "%c", caracter);
    fclose(arquivo);
}