#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main()
{
    FILE *arq;

	char nome[1000];
	printf("Digite o nome do arquivo:\n");
	scanf("%s", nome);
	arq = fopen(nome, "r");

	if(arq == NULL)
    {
		printf("Arquivo não encontrado!\n");
		exit(1);
    }
    int k = 0, i = 0, resposta, tamanho, cont = 0, analise;
    fscanf(arq, "%i\n", &tamanho);
    RPN rpn;
    rpn.indice_resultado = 0, rpn.indice_expressao = 0;
    do
    {
        fgets(rpn.expressao, MAX, arq);
        rpn.indice_expressao = strlen(rpn.expressao);
        analise = analises(&rpn);
        if(analise != 0)
        {
            printf("ERRO!\n");
            goto saida;
        }
        printf("\n");
        for(k = 0; k < rpn.indice_expressao; k++)printf("%c", rpn.expressao[k]);
        polonesa(&rpn);
        printf("\nResultado:");
        for(i = i; i < rpn.indice_resultado; i++)printf("\n%c", rpn.resultado[i]);
        printf("\n");
        resposta = resultado(&rpn);
        printf("RESPOSTA %i\n", resposta);
        saida:
        cont++;
    }while(cont < tamanho);
        return 0;
}
