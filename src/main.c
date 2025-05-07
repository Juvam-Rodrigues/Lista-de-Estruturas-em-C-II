#include <stdio.h>
#include <stdlib.h>
#include "..\include\turma.h"
#include "..\include\aluno.h"
#include <string.h>

int main()
{
    Turma turma; 
    turma.numeroAlunos = 0;
    turma.listaAlunos = NULL;

    Aluno aluno;
    int atividade = 1;
    int resposta;
    int posicao, r, t;
    char matricula[20];

    while (atividade == 1)
    {
        printf("\nO que você deseja fazer: \n1-Inserir \n2-Deletar");
        printf("\n3-Buscar \n4-Listar \n5-Reinicializar \n6-Obter tamanho \n7-Sair\n\n");
        scanf("%d", &resposta);
        getchar();
        switch (resposta)
        {
        case 1:
            printf("Digite o nome do aluno: ");
            fgets(aluno.nome, sizeof(aluno.nome), stdin);
            aluno.nome[strcspn(aluno.nome, "\n")] = 0;
            printf("Digite a matrícula: ");
            scanf("%s", aluno.matricula);
            printf("Digite a nota: ");
            scanf("%lf", &aluno.nota);
            r = inserir(&turma, aluno);

            if (r == 1)
            {
                printf("Aluno inserido\n");
            }
            else
            {
                printf("Aluno não inserido\n");
            }
            break;

        case 2:
            printf("Digite a matrícula: ");
            scanf("%s", matricula);

            r = remover(&turma, matricula);  // Passando o endereço de 'turma'
            if (r == 1)
            {
                printf("Aluno removido\n");
            }
            else
            {
                printf("Aluno não removido\n");
            }
            break;

        case 3:
            printf("Digite a matrícula: ");
            scanf("%s", matricula);

            r = buscar(&turma, matricula, 0, tamanho(&turma) - 1);  
            if (r == -1)
            {
                printf("Aluno não encontrado.\n");
            }
            else
            {
                printf("Nome: %s\n", turma.listaAlunos[r].nome);
                printf("Matrícula: %s\n", turma.listaAlunos[r].matricula);
                printf("Nota: %.2lf\n", turma.listaAlunos[r].nota);
            }
            
            break;

        case 4:
            exibirLista(&turma);  
            break;

        case 5:
            reinicializar(&turma); 
            break;

        case 6:
            t = tamanho(&turma);  
            printf("Tamanho da turma: %d\n", t);
            break;

        case 7:
            atividade = 0;
            break;
        }
    }
    reinicializar(&turma);
    return 0;
}
