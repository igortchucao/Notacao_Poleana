#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char expressao[MAX];
    int indice_expressao;
    char resultado[MAX];
    int indice_resultado;
    int resposta;
}RPN;

void polonesa(RPN *rpn)
{
    int auxiliar_numerico[10];
    char refe[10];
    int j = 0, k = 0, n = 0, m = 0,indice = 0, i, cont, analise = 0;
    char ref = '#';
    for(cont = 0; cont < (*rpn).indice_expressao; cont++)
    {
        switch ((*rpn).expressao[cont])
        {
        case '(':
            (*rpn).expressao[cont] = '#';
        break;

        case ')':
            (*rpn).expressao[cont] = '#';
            (*rpn).expressao[k] = '#';
            cont = 0;
            while(n > m)
            {
                indice = auxiliar_numerico[m+1];
                (*rpn).expressao[indice] = '#';
                if(auxiliar_numerico[m] != NULL)
                {
                    (*rpn).resultado[(*rpn).indice_resultado] = auxiliar_numerico[m] + 48;
                    (*rpn).indice_resultado++;

                }
                m = m + 2;
            }
            (*rpn).resultado[(*rpn).indice_resultado] = ref;
            (*rpn).indice_resultado++;
            n = 0;
            m = 0;
        break;

        default:
            if((*rpn).expressao[cont] == '+' || (*rpn).expressao[cont] == '-' || (*rpn).expressao[cont] == '*' || (*rpn).expressao[cont] == '/')
            {
                ref = (*rpn).expressao[cont];
                k = cont;
            }
                if(isdigit((*rpn).expressao[cont]))
                {
                    auxiliar_numerico[n] = ((*rpn).expressao[cont] - 48);
                    auxiliar_numerico[n+1] = cont;
                    auxiliar_numerico[n+2] = NULL;
                    n = n + 2;
                    i = 10;
                }
                if(n == 6)
                {
                    auxiliar_numerico[0] = auxiliar_numerico[2];
                    auxiliar_numerico[1] = auxiliar_numerico[3];
                    auxiliar_numerico[2] = auxiliar_numerico[4];
                    auxiliar_numerico[3] = auxiliar_numerico[6];
                    auxiliar_numerico[4] = NULL;
                }
        }
    }
}

int resultado(RPN *rpn)
{
    int somador1, somador2, cont = 0, i = 0, k, respostas;
    char pedro;
    for(cont = 0; cont < (*rpn).indice_resultado; cont++)
    {
        switch((*rpn).resultado[cont])
        {
        case '*':
          i = cont;
            somador2 = (int)(*rpn).resultado[cont-1];
            if(isdigit((*rpn).resultado[cont-1]))somador2 = (int)(*rpn).resultado[cont-1]-48;
            (*rpn).resultado[cont-1] = NULL;
            do
            {
                somador1 = (int)(*rpn).resultado[cont-1];
                if(isdigit((*rpn).resultado[cont-1]))somador1 = (int)(*rpn).resultado[cont-1]-48;
                (*rpn).resultado[cont] = NULL;
                cont --;
                if(cont == -1)
                {
                    somador1 = (int)(*rpn).resultado[cont-1];
                    (*rpn).resultado[cont] = '0';
                }
            }while((*rpn).resultado[cont] == NULL);
            cont = i;
            (*rpn).resultado[cont-2] = NULL;
            i = (somador1 * somador2);
            respostas = i;
            (*rpn).resultado[cont] = (char)i;
            break;
        case '/':
            i = cont;
            somador2 = (int)(*rpn).resultado[cont-1];
            if(isdigit((*rpn).resultado[cont-1]))somador2 = (int)(*rpn).resultado[cont-1]-48;
            (*rpn).resultado[cont-1] = NULL;
            do
            {
                somador1 = (int)(*rpn).resultado[cont-1];
                if(isdigit((*rpn).resultado[cont-1]))somador1 = (int)(*rpn).resultado[cont-1]-48;
                (*rpn).resultado[cont] = NULL;
                cont --;
                if(cont == -1)
                {
                    somador1 = (int)(*rpn).resultado[cont-1];
                    (*rpn).resultado[cont] = '0';
                }
            }while((*rpn).resultado[cont] == NULL);
            cont = i;
            (*rpn).resultado[cont-2] = NULL;
            i = (somador1 / somador2);
            respostas = i;
            (*rpn).resultado[cont] = (char)i;
            break;
        case '+':
            i = cont;
            somador2 = (int)(*rpn).resultado[cont-1];
            if(isdigit((*rpn).resultado[cont-1]))somador2 = (int)(*rpn).resultado[cont-1]-48;
            (*rpn).resultado[cont-1] = NULL;
            do
            {
                somador1 = (int)(*rpn).resultado[cont-1];
                if(isdigit((*rpn).resultado[cont-1]))somador1 = (int)(*rpn).resultado[cont-1]-48;
                (*rpn).resultado[cont] = NULL;
                cont --;
                if(cont == -1)
                {
                    somador1 = (int)(*rpn).resultado[cont-1];
                    (*rpn).resultado[cont] = '0';
                }
            }while((*rpn).resultado[cont] == NULL);
            cont = i;
            (*rpn).resultado[cont-2] = NULL;
            i = (somador1 + somador2);
            respostas = i;
            (*rpn).resultado[cont] = (char)i;
            break;
        case '-':
            i = cont;
            somador2 = (int)(*rpn).resultado[cont-1];
            if(isdigit((*rpn).resultado[cont-1]))somador2 = (int)(*rpn).resultado[cont-1]-48;
            (*rpn).resultado[cont-1] = NULL;
            do
            {
                somador1 = (int)(*rpn).resultado[cont-1];
                if(isdigit((*rpn).resultado[cont-1]))somador1 = (int)(*rpn).resultado[cont-1]-48;
                (*rpn).resultado[cont] = NULL;
                cont --;
                if(cont == -1)
                {
                    somador1 = (int)(*rpn).resultado[cont-1];
                    (*rpn).resultado[cont] = '0';
                }
            }while((*rpn).resultado[cont] == NULL);
            cont = i;
            (*rpn).resultado[cont-2] = NULL;
            i = (somador1 - somador2);
            respostas = i;
            (*rpn).resultado[cont] = (char)i;
            break;
        }
    }
    return respostas;
}

int analises(RPN *rpn)
{
    int i = 0, analise = 0;
    for(i = 0; i < (*rpn).indice_expressao; i++)
    {
        switch((*rpn).expressao[i])
        {
            case '(':
                 analise = analise + 15;
                 break;
            case ')':
                 analise = analise - 5;
                 break;
            default:
                if((*rpn).expressao[i] == '+' || (*rpn).expressao[i] == '-' || (*rpn).expressao[i] == '*' || (*rpn).expressao[i] == '/')
                {
                    analise = analise - 10;
                }
        }
    }
    return analise;
}


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

