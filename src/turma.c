#include "..\include\turma.h"
#include "..\include\aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(Turma *turma, int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1; // Pega a metade esquerda
    int n2 = fim - meio;        // Pega a metade direita

    Turma turma1, turma2;
    turma1.listaAlunos = malloc(n1 * sizeof(Aluno));
    turma2.listaAlunos = malloc(n2 * sizeof(Aluno));

    for (i = 0; i < n1; i++)
        turma1.listaAlunos[i] = turma->listaAlunos[inicio + i];
    for (j = 0; j < n2; j++)
        turma2.listaAlunos[j] = turma->listaAlunos[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2)
    {
        if (atoi(turma1.listaAlunos[i].matricula) <= atoi(turma2.listaAlunos[j].matricula))
        {
            turma->listaAlunos[k] = turma1.listaAlunos[i];
            i++;
        }
        else
        {
            turma->listaAlunos[k] = turma2.listaAlunos[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        turma->listaAlunos[k] = turma1.listaAlunos[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        turma->listaAlunos[k] = turma2.listaAlunos[j];
        j++;
        k++;
    }
}

void merge_sort(Turma *turma, int inicio, int fim)
{
    if (inicio < fim)
    {

        int meio = inicio + (fim - inicio) / 2;

        merge_sort(turma, inicio, meio);
        merge_sort(turma, meio + 1, fim);

        merge(turma, inicio, meio, fim);
    }
}

int tamanho(Turma *turma)
{
    return turma->numeroAlunos;
}

int buscar(Turma *turma, char chave[20], int inicio, int maiorPosicao)
{
    if (inicio > maiorPosicao)
    {
        return -1; // Elemento não encontrado
    }

    int meio = (inicio + maiorPosicao) / 2;

    if (strcmp(chave, turma->listaAlunos[meio].matricula) == 0)
    {
        return meio;
    }

    else if (atoi(chave) > atoi(turma->listaAlunos[meio].matricula))
    {
        return buscar(turma, chave, meio + 1, maiorPosicao);
    }
    else
    {
        return buscar(turma, chave, inicio, meio - 1);
    }
}


void exibirLista(Turma *turma)
{
    printf("Lista : \n");
    for (int i = 0; i < turma->numeroAlunos; i++)
    {
        printf("%s\n", turma->listaAlunos[i].matricula);
    }
}

int inserir(Turma *turma, Aluno aluno)
{
    int posicao = turma->numeroAlunos;

    if (posicao < 0 || posicao > turma->numeroAlunos)
        return -1;

    Aluno *temp = (Aluno *)realloc(turma->listaAlunos, (turma->numeroAlunos + 1) * sizeof(Aluno));

    if (temp == NULL)
    {
        return -1; // Falha na realocação
    }

    turma->listaAlunos = temp;

    for (int j = turma->numeroAlunos; j > posicao; j--)
    {
        turma->listaAlunos[j] = turma->listaAlunos[j - 1];
    }

    turma->listaAlunos[posicao] = aluno;
    turma->numeroAlunos++;

    merge_sort(turma, 0, tamanho(turma) - 1);
    return 1;
}

int remover(Turma *turma, char matricula[20])
{
    int pos = buscar(turma, matricula, 0, tamanho(turma) - 1);
    if (pos == -1)
    {
        return -1;
    }
    for (int j = pos; j < turma->numeroAlunos - 1; j++)
    {
        turma->listaAlunos[j] = turma->listaAlunos[j + 1];
    }

    turma->numeroAlunos--;

    if (turma->numeroAlunos == 0)
    {
        free(turma->listaAlunos);
        turma->listaAlunos = NULL;
    }
    else
    {
        Aluno *temp = (Aluno *)realloc(turma->listaAlunos, turma->numeroAlunos * sizeof(Aluno));
        if (temp != NULL)
        {
            turma->listaAlunos = temp;
        }
    }

    return 1;
}
void reinicializar(Turma *turma)
{
    free(turma->listaAlunos);
    turma->numeroAlunos = 0;
}
