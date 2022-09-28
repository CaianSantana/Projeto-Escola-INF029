#include <stdio.h>
#include "pessoa.h"
static int escolha;
static int parar = 0;
void menu(int retornos[]);
void menuAluno(int retornos[]);
void menuProfessor(int retornos[]);
void menuDisciplina(int retornos[]);
void menuListar(int retornos[]);
void menuAlterar(int retornos[]);
void menuAlterarDisciplina(int retornos[]);
void menuGerenciarDisciplina(int retornos[]);
void menuListarDisciplina(int retornos[]);
void menuExtras(int retornos[]);
void menu(int retornos[]){
  
  do {
    printf("|----------- Sistema Escola -----------|\n"
           "| O que deseja acessar?                |\n"
           "| 1 - alunos                           |\n"
           "| 2 - professores                      |\n"
           "| 3 - disciplinas                      |\n"
           "| 4 - extras                           |\n"
           "| 0 - sair                             |\n"
           "|--------------------------------------|\n\n");
    scanf(" %d", &escolha);
    getchar();
    printf("\e[1;1H\e[2J");
    switch (escolha) {
    case 0:
        retornos[0] = -1;
        parar = 1;
        break;
    case 1:
        retornos[0] = 0;
        menuAluno(retornos);
        break;
    case 2:
        retornos[0] = 1;
        menuProfessor(retornos);
        break;
    case 3:
        retornos[0] = 2;
        menuDisciplina(retornos);
        break;
    case 4:
        retornos[0] = 3;
        menuExtras(retornos);
        break;
    default:
      printf("Dígito inválido. Pressione Enter para retornar para o ínicio.\n");
      getchar();
      printf("\e[1;1H\e[2J");
      continue;
    }
  } while (parar == 0);
}
void menuAluno(int retornos[]){
        printf("\n\n|----------- Sistema Escola -----------|\n"
                 "| Você escolheu alunos.                |\n"
                 "| O que deseja fazer?                  |\n"
                 "| 1 - Cadastrar aluno                  |\n"
                 "| 2 - Listar alunos                    |\n" 
                 "| 3 - Alterar cadastro                 |\n"
                 "| 4 - Excluir                          |\n"
                 "| 0 - retornar ao menu principal       |\n"
                 "|--------------------------------------|\n\n");
        scanf(" %d", &escolha);
        printf("\e[1;1H\e[2J");
        switch (escolha) {
            case 1:
                retornos[1] = 0;
                parar = 1;
                break;
            case 2:
                retornos[1] = 1;
                menuListar(retornos);
                break;
            case 3:
                retornos[1] = 2;
                menuAlterar(retornos);
                break;
            case 4:
                retornos[1] = 3;
                parar =1;
                break;
        }
}
void menuProfessor(int retornos[]){
        printf("\n\n|----------- Sistema Escola -----------|\n"
             "| Você escolheu professores.           |\n"
             "| O que deseja fazer?                  |\n"
             "| 1 - Cadastrar Professor              |\n"
             "| 2 - Listar professores               |\n" 
             "| 3 - Alterar cadastro                 |\n"
             "| 4 - Excluir                          |\n"
             "| 0 - retornar ao menu principal       |\n"
             "|--------------------------------------|\n\n");
        scanf(" %d", &escolha);
        printf("\e[1;1H\e[2J");
        switch (escolha) {
            case 1:
                retornos[1] = 0;
                parar = 1;
                break;
            case 2:
                retornos[1] = 1;
                menuListar(retornos);
                break;
            case 3:
                retornos[1] = 2;
                menuAlterar(retornos);
                break;
            case 4:
                retornos[1] = 3;
                parar =1;
                break;
        }
}
void menuDisciplina(int retornos[]){
    printf("\n\n|----------- Sistema Escola -----------|\n"
                 "| Você escolheu disciplinas.           |\n"
                 "| O que deseja fazer?                  |\n"
                 "| 1 - Cadastrar disciplina             |\n"
                 "| 2 - Listar disciplina                |\n" 
                 "| 3 - excluir disciplina               |\n"
                 "| 4 - Gerenciar disciplina             |\n"
                 "| 0 - retornar ao menu principal       |\n"
                 "|--------------------------------------|\n\n");
        scanf(" %d", &escolha);
        printf("\e[1;1H\e[2J");
        switch (escolha) {
            case 1:
                retornos[1] = 0;
                parar = 1;
                break;
            case 2:
                retornos[1] = 1;
                menuListarDisciplina(retornos);
                break;
            case 3:
                retornos[1] = 2;
                break;
            case 4:
                retornos[1] = 3;
                menuGerenciarDisciplina(retornos);
                break;
        }
}
void menuListar(int retornos[]){
    printf("\n\n|----------- Sistema Escola -----------|\n"
                    "| Você escolheu listar.                |\n"
                    "| Como deseja fazer isso?              |\n"
                    "| 1 - Listar todos                     |\n"
                    "| 2 - Ordenar por nome                 |\n"
                    "| 3 - Listar por sexo                  |\n"
                    "| 4 - Ordenar por data de nascimento   |\n"
                    "| 0 - retornar ao menu principal       |\n"
                    "|--------------------------------------|\n\n");
                scanf(" %d", &escolha);
                printf("\e[1;1H\e[2J");
                switch (escolha) {
                    case 1:
                        retornos[2] = 1;
                        parar = 1;
                        break;
                    case 2:
                        retornos[2] = 2;
                        parar = 1;
                        break;
                    case 3:
                        retornos[2] = 3;
                        parar = 1;
                        break;
                    case 4:
                        retornos[2] = 4;
                        parar = 1;
                        break;
                }
}
void menuAlterar(int retornos[]){
    printf("\n\n|----------- Sistema Escola -----------|\n"
                "| Você escolheu alterar cadastro.      |\n"
                "| O que deseja fazer?                  |\n"
                "| 1 - Alterar Nome                     |\n"
                "| 2 - Alterar CPF                      |\n"
                "| 3 - Alterar Sexo                     |\n"
                "| 4 - Alterar Data de Nascimento       |\n"
                "| 5 - Alterar tudo                     |\n"
                "| 6 - Apagar dados                     |\n"
                "| 0 - retornar ao menu principal       |\n"
                "|--------------------------------------|\n\n");
                scanf(" %d", &escolha);
                getchar();
                printf("\e[1;1H\e[2J");
                switch (escolha) {
                    case 1:
                        retornos[2] = 1;
                        parar = 1;
                        break;
                    case 2:
                        retornos[2] = 2;
                        parar = 1;
                        break;
                    case 3:
                        retornos[2] = 3;
                        parar = 1;
                        break;
                    case 4:
                        retornos[2] = 4;
                        parar = 1;
                        break;
                    case 5:
                        retornos[2] = 5;
                        parar = 1;
                        break;
                    case 6:
                        retornos[1] = 3;
                        parar = 1;
                        break;
                }
}

void menuGerenciarDisciplina(int retornos[]){
    printf("\n\n|----------- Sistema Escola -----------|\n"
                 "| Você escolheu gerenciar disciplinas. |\n"
                 "| O que deseja fazer?                  |\n"
                 "| 1 - Inserir Aluno                    |\n"
                 "| 2 - Excluir aluno de uma disciplina  |\n"
                 "| 0 - retornar ao menu principal       |\n"
                 "|--------------------------------------|\n\n");
        scanf(" %d", &escolha);
        printf("\e[1;1H\e[2J");
        switch (escolha) {
            case 1:
                retornos[2] = 0;
                parar = 1;
                break;
            case 2:
                retornos[2] = 1;
                parar = 1;
                break;
        }
}
void menuListarDisciplina(int retornos[]){
    printf("\n\n|----------- Sistema Escola -----------|\n"
                 "| Você escolheu listar disciplinas.    |\n"
                 "| O que deseja listar?                 |\n"
                 "| 1 - Uma Disciplina                   |\n"
                 "| 2 - todas Disciplinas                |\n" 
                 "| 3 - Disciplinas com mais de 40 vagas |\n"
                 "| 0 - retornar ao menu principal       |\n"
                 "|--------------------------------------|\n\n");
        scanf(" %d", &escolha);
        printf("\e[1;1H\e[2J");
        switch (escolha) {
            case 1:
                retornos[2] = 0;
                parar = 1;
                break;
            case 2:
                retornos[2] = 1;
                parar = 1;
                break;
            case 3:
                retornos[2] = 2;
                parar = 1;
                break;
        }
}

void menuExtras(int retornos[]){
    printf("\n\n|----------- Sistema Escola -----------|\n"
                 "| Você escolheu extras.                |\n"
                 "| O que deseja fazer?                  |\n"
                 "| 1 - pesquisar pessoas                |\n"
                 "| 2 - aniversariantes do mês           |\n" 
                 "| 0 - retornar ao menu principal       |\n"
                 "|--------------------------------------|\n\n");
    scanf(" %d", &escolha);
    printf("\e[1;1H\e[2J");
    switch (escolha) {
            case 1:
                retornos[1] = 0;
                parar = 1;
                break;
            case 2:
                retornos[1] = 1;
                parar = 1;
                break;
    }
}