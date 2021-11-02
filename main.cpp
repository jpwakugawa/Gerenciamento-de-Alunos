#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main()
{
    while(true)
    {
        printf("\n--- MENU ---\n");

        int option;
        printf("1. Cadastrar novo aluno.\n");
        printf("2. Buscar aluno.\n");
        printf("3. Ler arquivo com listagem de alunos.\n");
        printf("4. Gerar arquivo com dados dos alunos aprovados.\n");
        printf("5. Gerar arquivo com dados dos alunos reprovados.\n");
        printf("6. Fechar programa.\n");
        printf("| Option: ");
        scanf("%d", &option);

        char arquivo[NOME];

        if(option == 6)
            break;
        else if(option == 1)
        {
            cadastrarAluno();
        }
        else if(option == 2)
        {
            printf("| Nome do arquivo: ");
            scanf("%s", arquivo);

            printf("-------------\n");
            buscarAluno(arquivo);
        }

        else if(option == 3)
        {
            printf("| Nome do arquivo: ");
            scanf("%s", arquivo);

            printf("-------------\n");
            lerArquivo(arquivo);
        }

        else if(option == 4)
        {
            printf("| Nome do arquivo: ");
            scanf("%s", arquivo);

            printf("-------------\n");
            gerarAprovados(arquivo);
        }

        else if(option == 5)
        {
            printf("| Nome do arquivo: ");
            scanf("%s", arquivo);

            printf("-------------\n");
            gerarReprovados(arquivo);
        }
    }
}