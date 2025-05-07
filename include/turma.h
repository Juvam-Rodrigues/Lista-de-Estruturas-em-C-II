#ifndef TURMA_H
#define TURMA_H
#include "aluno.h"

typedef struct{
    Aluno *listaAlunos;
    int numeroAlunos;
     
} Turma;

int tamanho(Turma *turma);
int buscar(Turma *turma, char chave[20], int inicio, int maiorPosicao);
void reinicializar(Turma *turma);
void exibirLista(Turma *turma);
int inserir(Turma *turma, Aluno aluno);
int remover(Turma *turma, char matricula[20]);
#endif