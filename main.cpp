#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME 50
FILE *lista;
int cadastrados = 0;

struct Aluno
{
    char nome[NOME];
    int RA;
    double P1;
    double P2;
    double T;
    double PO;
};

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

        fprintf(lista, "%s %d %lf %lf %lf %lf\n", aluno.nome, aluno.RA, aluno.P1, aluno.P2, aluno.T, aluno.PO);
    }

    fclose(lista);
}

void buscarAluno()
{
    char user[NOME];
    printf("Digite um nome: ");
    scanf("%s", user);
    
    for(int i=0; i<cadastrados; i++)
    {
        Aluno atual;
        fscanf(lista, "%s", atual.nome);
        printf("%s", atual.nome);

        char *ret = strstr(atual.nome, user);
        if(ret)
            printf("Encontrei!\n");
        else
            printf("Nops :(\n");
    }
}

int main()
{
    while(true)
    {
        printf("--- MENU ---\n");

        int option;
        printf("1. Cadastrar novo aluno.\n");
        printf("2. Buscar aluno.\n");
        printf("3. Ler arquivo com listagem de alunos.\n");
        printf("4. Gerar arquivo com dados dos alunos aprovados.\n");
        printf("5. Gerar arquivo com dados dos alunos reprovados.\n");
        printf("6. Fechar programa.\n");
        printf("Option: ");
        scanf("%d", &option);

        if(option == 6)
            break;
        else if(option == 1)
        {
            cadastrarAluno();
            cadastrados++;
        }
        else if(option == 2)
        {
            buscarAluno();
        }
    }
}