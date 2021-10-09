#include <stdio.h>

struct Aluno
{
    char nome[100];
    int RA;
    int P1;
    int P2;
    int T;
    int PO;
};

void cadastrarAluno(Aluno alunos[], int &n)
{
    scanf("%[^\n]", alunos[n].nome);
    scanf("%d", &alunos[n].RA);
    scanf("%d", &alunos[n].P1);
    scanf("%d", &alunos[n].P2);
    scanf("%d", &alunos[n].T);
    scanf("%d", &alunos[n].PO);
    n++;
}

int main()
{
    while(true)
    {
        printf("--- MENU ---\n");

        int option;
        printf("1. Cadastrar novo aluno\n");
        printf("2. Buscar aluno\n");
        printf("3. Ler arquivo com listagem de alunos\n");
        printf("4. Gerar arquivo com dados dos alunos aprovados\n");
        printf("5. Gerar arquivo com dados dos alunos reprovados\n");
        printf("6. Fechar programa\n");
        printf("Option: ");
        scanf("%d", &option);

        if(option == 6)
            break;
        
    }
}