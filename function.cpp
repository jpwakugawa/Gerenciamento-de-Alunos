#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#define NOME 50
#define MAX 10
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

void ordenarAlunos(Aluno listaD[MAX], int n)
{
    int min;
    for(int i=0; i<n; i++)
    {
        min = i;
        for(int j=i+1; j<n; j++)
        {
            int compare = strcmp(listaD[j].nome, listaD[min].nome);

            if(compare == 0)
            {
                if(listaD[j].RA < listaD[min].RA)
                    min = j;
            }

            else if(compare < 0)
                min = j;
        }

        Aluno temp;
        temp = listaD[i];
        listaD[i] = listaD[min];
        listaD[min] = temp;
    }
}

// Main functions

// 1
void cadastrarAluno()
{
    Aluno aluno;
    lista = fopen("atual.txt", "a");

    if(lista == NULL)
        printf("Erro na abertura do arquivo");
    else
    {
        scanf(" %[^0-9] %d %lf %lf %lf %lf", aluno.nome, &aluno.RA, &aluno.P1, &aluno.P2, &aluno.T, &aluno.PO);
        fprintf(lista, "%s %d %0.1lf %0.1lf %0.1lf %0.1lf\n", aluno.nome, aluno.RA, aluno.P1, aluno.P2, aluno.T, aluno.PO);
    }

    fclose(lista);
}

// 2
void buscarAluno()
{
    Aluno listaAlunos[10], alunosIguais[10], atual;
    char procurado[NOME];
    printf("Digite um nome: "); scanf("%s", procurado);
    lista = fopen("atual.txt", "r");

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
            fscanf(lista, "%[^0-9] %d %lf %lf %lf %lf\n", aluno.nome, &aluno.RA, &aluno.P1, &aluno.P2, &aluno.T, &aluno.PO);
            printf("%s %d %0.1lf %0.1lf %0.1lf %0.1lf\n", aluno.nome, aluno.RA, aluno.P1, aluno.P2, aluno.T, aluno.PO);
        }
        printf("Total: %d\n", cont);
    }

    fclose(lista);
}

// 4
void gerarAprovados()
{
    Aluno aluno, listaAprovados[MAX];
    int contA = 0;
    lista = fopen("atual.txt", "r");

    if(lista == NULL)
        printf("Erro na abertura do arquivo!");
    else
    {
        while(feof(lista) == 0)
        {
            fscanf(lista, "%[^0-9] %d %lf %lf %lf %lf\n", aluno.nome, &aluno.RA, &aluno.P1, &aluno.P2, &aluno.T, &aluno.PO);

            if(aprovado(aluno))
            {
                listaAprovados[contA] = aluno;
                contA++;
            }
        }

        ordenarAlunos(listaAprovados, contA);

        FILE* aprovadotxt;
        aprovadotxt = fopen("aprovados.txt", "w");

        if(aprovadotxt == NULL)
            printf("Erro na abertuda do arquivo!");
        else
        {
            for(int i=0; i<contA; i++)
            {
                aluno = listaAprovados[i];
                double media = calcularMedia(aluno);
                fprintf(aprovadotxt, "%s %d %0.1lf\n", aluno.nome, aluno.RA, media);
            }
            fprintf(aprovadotxt, "Total: %d\n", contA);
        }

        fclose(aprovadotxt);
    }

    fclose(lista);
}

// 5
void gerarReprovados()
{
    Aluno aluno, listaReprovados[MAX];
    int contR = 0;
    lista = fopen("atual.txt", "r");

    if(lista == NULL)
        printf("Erro na abertura do arquivo!");
    else
    {
        while(feof(lista) == 0)
        {
            fscanf(lista, "%[^0-9] %d %lf %lf %lf %lf\n", aluno.nome, &aluno.RA, &aluno.P1, &aluno.P2, &aluno.T, &aluno.PO);

            if(aprovado(aluno) != 1)
            {
                listaReprovados[contR] = aluno;
                contR++;
            }
        }

        ordenarAlunos(listaReprovados, contR);
        
        FILE* reprovadotxt;
        reprovadotxt = fopen("reprovados.txt", "w");

        if(reprovadotxt == NULL)
            printf("Erro na abertuda do arquivo!");
        else
        {
            for(int i=0; i<contR; i++)
            {
                aluno = listaReprovados[i];
                double media = calcularMedia(aluno);
                fprintf(reprovadotxt, "%s %d %0.1lf\n", aluno.nome, aluno.RA, media);
            }
            fprintf(reprovadotxt, "Total: %d\n", contR);
        }

        fclose(reprovadotxt);
    }

    fclose(lista);
}