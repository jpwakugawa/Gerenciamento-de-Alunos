#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME 50

struct Aluno
{
    char nome[NOME];
    int RA;
    double P1;
    double P2;
    double T;
    double PO;
};

void cadastrarAluno();

void buscarAluno();

void lerArquivo();