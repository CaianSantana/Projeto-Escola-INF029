#include "disciplinas.h"
#include "pessoa.h"
#include <stdio.h>
#include <string.h>

// int
// MenuDisciplina ()
// {
//   int opcao;
//   printf ("\nDigite a opC'C#o\n");
//   printf ("0. Voltar para o Menu\n");
//   printf ("1. Cadastrar Disciplina\n");
//   printf ("2. Inserir Aluno\n");
//   printf ("3. Excluir Disciplina\n");
//   printf ("4. Listar Disciplinas\n");
//   printf ("5. Listar uma Disciplinas \n");
//   printf ("6. Excluir aluno de uma disciplina \n");
//   printf ("7. Listar Disciplinas com mais de 40 vagas \n");
//   scanf ("%d", &opcao);
//   getchar ();
//   return opcao;
// }

// int mainDisciplina (int qtdDisciplina, int qtdAluno, Pessoa p[])
// {
//   int opcao = 1;
//   while (opcao != 0)
//     {
//       opcao = MenuDisciplina ();
//       switch (opcao)
// 	{
// 	case 1:
// 	  qtdDisciplina = CadastrarDisciplina (qtdDisciplina);
// 	  break;
// 	case 2:
// 	  InserirAluno (qtdDisciplina, qtdAluno, p);
// 	  break;
// 	case 3:
// 	  qtdDisciplina = RemoverDisciplinas (qtdDisciplina);
// 	  break;
// 	case 4:
// 	  listarDisciplinas (qtdDisciplina);
// 	  break;
// 	case 5:
// 	  listarDisciplinasGeral (qtdDisciplina, qtdAluno, p);
// 	  break;
// 	case 6:
// 	  RemoverAlunoDisciplina (qtdDisciplina,qtdAluno);
// 	  break;
// 	case 7:
// 	  ListaDiscMaiorVagas (qtdDisciplina);
// 	  break;
// 	}
//     }
//   return qtdDisciplina;
// }

int CadastrarDisciplina (int qtd)
{

  fflush(stdin);
  getchar();
  printf ("Nome da disciplina: ");
  fgets (Disciplina[qtd].Nome, 49, stdin);
  
  printf ("Codigo da disciplina: ");
  scanf (" %d", &Disciplina[qtd].Codigo);
  while(Disciplina[qtd].Semestre<1){
      printf ("Semestre da disciplina: ");
      scanf (" %d", &Disciplina[qtd].Semestre);
      getchar ();
      if(Disciplina[qtd].Semestre <1)
        printf("Semestre não pode ser menor que 1.\n");
  }
  printf ("Nome do Professor da Disciplina: ");
  fgets (Disciplina[qtd].Professor, 49, stdin);
  printf ("Quantidade de vagas: ");
  scanf (" %d", &Disciplina[qtd].Vagas);
  getchar ();
  Disciplina[qtd].VagasTotais = Disciplina[qtd].Vagas;
  Disciplina[qtd].matriculas[Disciplina[qtd].Vagas];
  Disciplina[qtd].contaluno = 0;
  qtd++;
  return qtd;
}


void InserirAluno (int qtd, int qtdAluno, int mat[])
{
  int i, j, codigo;
  printf ("Digite o codigo da disciplina que deseja adicionar o aluno: ");
  scanf (" %d", &codigo);
  getchar ();
  for (i = 0; (Disciplina[i].Codigo != codigo) && (i < qtd); i++)
    {
    }
  // i armazena a posição da disciplina
  printf ("\nDigite a matricula do Aluno: ");
  scanf ("%d", &Disciplina[i].Matricula_alunos);
  Disciplina[i].Vagas--;
  Disciplina[i].Vagas = Disciplina[i].Vagas;
  printf ("%d", Disciplina[i].Vagas);
  for (int j = 0; j < qtdAluno; j++)
    {
      if (Disciplina[i].Matricula_alunos == mat[j])
	{
	  Disciplina[i].matriculas[Disciplina[i].contaluno] = Disciplina[i].Matricula_alunos;	//adiciona aluno na matC)ria
	  Disciplina[i].contaluno++;
	  printf ("contaluno %d\n", Disciplina[i].contaluno++);
	}
    }				//armazena alunos vC!lidos
  printf ("matricula %d\n", Disciplina[i].matriculas[0]);
}

void listarDisciplinas (int qtd)
{
  for (int i = 0; i < qtd; i++)
    {
      printf ("Disciplina:");
      printf ("%s", Disciplina[i].Nome);
      printf ("Codigo:");
      printf ("%d", Disciplina[i].Codigo);
      printf ("\nSemestre:");
      printf ("%d", Disciplina[i].Semestre);
      printf ("\nProfessor:");
      puts (Disciplina[i].Professor);
    }
}

void listarDisciplinasGeral (int qtd, int qtdAluno,int mat[], char nomes[][qtd]){
  int codigo, i;
  printf ("Que disciplina deseja mostrar: ");
  scanf (" %d", &codigo);
  for (i = 0; (Disciplina[i].Codigo != codigo) && (i < qtd); i++)
    {
    }
  if (i < qtd)
    {
      printf ("Disciplina: ");
      printf ("%s", Disciplina[i].Nome);
      printf ("Codigo: ");
      printf ("%d", Disciplina[i].Codigo);
      printf ("\nSemestre: ");
      printf ("%d", Disciplina[i].Semestre);
      printf ("\nProfessor: ");
      puts (Disciplina[i].Professor);
      printf ("\nAlunos: ");
      for (int j = 0; j < Disciplina[i].contaluno; j++)
	{
	  for (int k = 0; k < qtdAluno; k++)
	    {
	      if (Disciplina[i].matriculas[j] == mat[k])
		{
		  puts (nomes[k]);
		}
	    }
	}
    }
  else
    {
      printf ("Nao há disciplinas com esse codigo");
    }
}

int RemoverDisciplinas (int qtd)
{
  int i, j, codigo;
  printf ("Digite o codigo da disciplina que deseja excluir: ");
  scanf ("%d", &codigo);
  getchar ();

  for (i = 0; (Disciplina[i].Codigo != codigo) && (i < qtd); i++)
    {
    }
  if (i < qtd)
    {
      printf ("%d", i);
      for (; i < qtd; i++)
	{
	  Disciplina[i] = Disciplina[i + 1];
	  Disciplina[i].Codigo = Disciplina[i + 1].Codigo;
	  Disciplina[i].Semestre = Disciplina[i + 1].Semestre;
	  strcpy (Disciplina[i].Nome, Disciplina[i + 1].Nome);
	  strcpy (Disciplina[i].Professor, Disciplina[i + 1].Professor);
	}
      printf ("Disciplina excluida do sistema com sucesso!");
      qtd -= 1;
    }
  else
    {
      printf ("nao existe disciplina com esse codigo");
    }
  return qtd;
}

int
RemoverAlunoDisciplina (int qtd,int qtdAluno)
{
  int i, j, matriculaExc,codigo;
  printf ("\nDigite a matricula do Aluno que deseja remover: ");
  scanf ("%d", &matriculaExc);
  getchar ();
  printf ("\nDigite o codigo da Disciplina do Aluno que deseja remover: ");
  scanf ("%d", &codigo);
  getchar ();
  for (j = 0; (Disciplina[j].Codigo != codigo) && (j < qtd); j++)
    {
    }
    codigo = j;
  for (i = 0; (Disciplina[codigo].matriculas[i] != matriculaExc) && (i < qtdAluno); i++)
    {
    }
    printf("\n%d %d %d",i, qtdAluno, j);
    
  if (i <= qtdAluno)
    {
      printf ("%d", i);
      for (i= i-1; i < qtdAluno; i++)
	{
	  printf("\n%d",Disciplina[codigo].matriculas[i]);
	  Disciplina[codigo].matriculas[i] =Disciplina[codigo].matriculas[i+1] ;
    printf("funciona");
    printf("\n%d",Disciplina[codigo].matriculas[i]);
	}
      printf ("Aluno excluido do sistema com sucesso!");
      Disciplina[codigo].contaluno--;
      Disciplina[codigo].Vagas++;
    }
  else
    {
      printf ("Nao existe aluno com essa matricula");
    }
  return qtdAluno;
}

void
ListaDiscMaiorVagas (int qtd)
{
  for (int i = 0; i < qtd; i++)
    {
      if (Disciplina[i].VagasTotais > 40)
	{
	  printf ("Disciplina que estrapolam 40 vagas:");
	  printf ("\n %s", Disciplina[i].Nome);
	  printf ("\nProfessor:");
	  puts (Disciplina[i].Professor);
	}
    }
}
