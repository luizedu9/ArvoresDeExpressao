# ArvoresDeExpressao

Instituto Federal de Educação, Ciência e Tecnologia de Minas Gerais, IFMG - Campus Formiga

Ciência da Computação

Criação e utilização de árvores de expressão para a disciplina de 'Algoritmos e Estruturas de Dados II'.

Autor: Luiz Eduardo Pereira.

# Objetivo:

Este trabalho tem como objetivo a implementação de uma estrutura de dados que utilize um tipo abstrato de dados (TAD) de criação e utilização de árvores de expressão.

# Compilação 

gcc arvore.c pilha.c main.c -o main

./main

# Funcionamento

Dado uma expressão no formato PósFixa, a arvore resolve a expressão e cria saidas no formato InFixa e PréFixa.

PósFixa: 1 2 + 5 * 7 -

InFixa: ((((1)+(2))*(5))-(7))

PréFixa: -*+1257

Resultado: 8.000000               
