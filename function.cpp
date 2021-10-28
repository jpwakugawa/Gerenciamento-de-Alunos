#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define NOME 50
FILE *lista;

// Minor functions

double calcularMedia(Aluno aluno)
{
    double media;

    if(aluno.P1 < aluno.P2)
    {
        if(aluno.P1 < aluno.PO)
        {
            media = aluno.PO * 0.35 + aluno.P2 * 0.35 + 0.3 * aluno.T;
            return media;
        }
        else
        {
            media = aluno.P1 * 0.35 + aluno.P2 * 0.35 + 0.3 * aluno.T;
            return media;
        }
    }
    else
    {
        if(aluno.P2 < aluno.PO)
        {
            media = aluno.PO * 0.35 + aluno.P1 * 0.35 + 0.3 * aluno.T;
            return media;
        }
        else
        {
            media = aluno.P2 * 0.35 + aluno.P1 * 0.35 + 0.3 * aluno.T;
            return media;
        }
    }
}

int aprovado(Aluno aluno)
{
    int media = calcularMedia(aluno);

    if(media >= 6)
        return 1;
    else
        return 0;
}

// Main functions

// 1
void cadastrarAluno()
{
    Aluno aluno;
    lista = fopen("lista.txt", "a");

    if(lista == NULL)
        printf("Erro na abertura do arquivo");
    else
    {
        printf("Nome: "); scanf("%s", aluno.nome);
        while((getchar()) != '\n');
        printf("RA: "); scanf("%d", &aluno.RA);
        while((getchar()) != '\n');
        printf("P1: "); scanf("%lf", &aluno.P1);
        while((getchar()) != '\n');
        printf("P2: "); scanf("%lf", &aluno.P2);
        while((getchar()) != '\n');
        printf("T: "); scanf("%lf", &aluno.T);
        while((getchar()) != '\n');
        printf("PO: "); scanf("%lf", &aluno.PO);
        while((getchar()) != '\n');

        fprintf(lista, "%s %d %0.1lf %0.1lf %0.1lf %0.1lf\n", aluno.nome, aluno.RA, aluno.P1, aluno.P2, aluno.T, aluno.PO);
    }

    fclose(lista);
}

// 2
void buscarAluno()
{
    Aluno listaAlunos[10];
    char procurado[NOME];
    printf("Digite o nome procurado: "); scanf("%s", procurado);

    lista = fopen("lista.txt", "r");

    if(lista == NULL)
        printf("Erro na abertura do arquivo");
    else
    {
        // ...
    }




    fclose(lista);
}