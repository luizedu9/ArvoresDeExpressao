#ifndef ARVORE_H
#define ARVORE_H

typedef struct raiz *Raiz;

void cria_expressao(char *expressao, int saida);
Raiz cria_raiz(char item);
Raiz cria_arvore(Raiz raiz, Raiz esq, Raiz dir);
void destroi_arvore(Raiz raiz);
Raiz vincula_dir(Raiz raiz, Raiz nodo);
Raiz vincula_esq(Raiz raiz, Raiz nodo);
int operador(char op);
int operando(char op);
float calculavalor_pos(Raiz raiz);
void infixa(Raiz raiz, int saida);
void prefixa(Raiz raiz, int saida);
void escreve_arquivo(char caracter);

#endif /* ARVORE_H */

