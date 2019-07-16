/* 
	ALUNO: LUIZ EDUARDO PEREIRA
	MATRICULA: 0021619
	15/11/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "arvore.h"

int main(int argc, char** argv) {
    char expressao[255], diretorio[255];
    FILE *arquivo;
    int entrada, saida;
    
    printf("Entrada de Dados: 0 = Teclado / 1 - Arquivo\n");
    scanf("%d", &entrada);
    printf("Saida de Dados: 0 = Tela / 1 - Arquivo\n");
    scanf("%d", &saida);
    if (entrada) {
        printf("Diretorio do Arquivo:\n");
        scanf("%s", diretorio);       
        arquivo = fopen(diretorio, "r");
        if (arquivo == NULL) {
            printf("Arquivo não encontrado");
            exit(0);
        }
        while (!feof(arquivo)) {
            fgets(expressao, 254, arquivo);
            cria_expressao(expressao, saida);
        }
        fclose(arquivo);
        return(0);
    }
    printf("Expreção:\n");
    scanf("%s", expressao);
    //fgets(expressao, 254, stdin);
    cria_expressao(expressao, saida);
    return(0);
}