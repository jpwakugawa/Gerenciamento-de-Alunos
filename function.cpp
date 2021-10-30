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
        scanf(" %[^0-9] %d %lf %lf %lf %lf", aluno.nome, &aluno.RA, &aluno.P1, &aluno.P2, &aluno.T, &aluno.PO);
        fprintf(lista, "%s %d %0.1lf %0.1lf %0.1lf %0.1lf\n", aluno.nome, aluno.RA, aluno.P1, aluno.P2, aluno.T, aluno.PO);
        while((getchar()) != '\n');
    }

    fclose(lista);
}

// 2
void buscarAluno()
{
    Aluno listaAlunos[10], alunosIguais[10], atual;
    char procurado[NOME];
    printf("Procurado: "); scanf("%s", procurado);

    lista = fopen("lista.txt", "r");

    if(lista == NULL)
        printf("Erro na abertura do arquivo");
    else
    {
        int count = 0, countIguais = 0;

        while(feof(lista) == 0)
        {
            fscanf(lista, "%[^0-9] %d %lf %lf %lf %lf\n", atual.nome, &atual.RA, &atual.P1, &atual.P2, &atual.T, &atual.PO);
            listaAlunos[count] = atual;
            count++;

            if(strstr(atual.nome, procurado) != NULL)
            {
                alunosIguais[countIguais] = atual;
                countIguais++;
            }
        }
        
        Aluno inside;
        for(int i=0; i<countIguais; i++)
        {
            inside = alunosIguais[i];
            printf("%s %d %0.1lf %0.1lf %0.1lf %0.1lf ", inside.nome, inside.RA, inside.P1, inside.P2, inside.T, inside.PO);

            if(aprovado(inside))
                printf("Aprovado\n");
            else
                printf("Reprovado\n");
        }

        printf("Total: %d\n", countIguais);
    }

    fclose(lista);
}

// 3
void lerArquivo(char arquivo[NOME])
{
    int cont = 0;
    Aluno aluno;
    lista = fopen(arquivo, "r");

    if(lista == NULL)
        printf("Erro na abertura do arquivo!");
    else
    {
        while(feof(lista) == 0)
        {
            cont++;
            fscanf(lista, "%s %d %lf %lf %lf %lf\n", aluno.nome, &aluno.RA, &aluno.P1, &aluno.P2, &aluno.T, &aluno.PO);
        }
    }

    fclose(lista);
}