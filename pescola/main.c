
/*#### VersC#o v01 ####
- Estrutura bC!sica para representar aluno
- Estrutura inicial de menu e switch
- Lista de alunos
- Inserir aluno
- Listar alunos */
/*Proximas mudanC'as:
- Trabalhar a parte de Disciplinas
- ManipulaC'C#o de arquivos para armazenar dados
- CriaC'C#o das funC'C5es de Cadastrosvoid OrdenarProfessorPorNome(Professor p[])
- Uso da biblioteca Time para validaC'C#o de datas
- uso de header para guardar funC'C5es em vez de manter todas no msm arquivo. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "menu.h"
#include "main.h"
#include "disciplinas.h"
#define MAXTAM 100
void
matriculaVetor (Pessoa p[], int TAM, int matvet[])
{
  int i;
  for (i = 0; i < TAM; i++)
    {
      matvet[i] = p[i].Matricula;
    }
}

void
nomeVetor (Pessoa p[], int TAM, char nomevet[][TAM])
{
  int i;
  for (i = 0; i < TAM; i++)
    {
      strcpy (nomevet[i], p[i].Nome);
    }
}

int
main ()
{
  int i, retornos[3];		//Aluno = tipo 0, Prof = 1 e Disc. = tipo 2. (tipo 3 C) pra sair)
  int TAM = 8, qtd = 0, matvet[TAM];
  char continuar, nomevet[51][TAM];
  Pessoa pessoas[MAXTAM];
  DadosPessoas (pessoas, TAM);
  do
    {

      retornos[0] = 5;
      retornos[1] = 5;
      retornos[2] = 5;
      menu (retornos, TAM);
      switch (retornos[0])
	{
	case 0:
	  switch (retornos[1])
	    {
	    case 0:
	      TAM = cadastraPessoa (0, TAM, pessoas);
	      break;
	    case 1:
	      listarPessoas (retornos[2], 0, TAM, pessoas);
	      break;
	    case 2:
	      alterarCadastro (retornos[2], 0, pessoas, TAM);
	      break;
	    case 3:
	      excluirPessoa (pessoas, TAM);
	      break;
	    }
	  break;
	case 1:
	  switch (retornos[1])
	    {
	    case 0:
	      TAM = cadastraPessoa (1, TAM, pessoas);
	      break;
	    case 1:
	      listarPessoas (retornos[2], 1, TAM, pessoas);
	      break;
	    case 2:
	      alterarCadastro (retornos[2], 1, pessoas, TAM);
	      break;
	    case 3:
	      excluirPessoa (pessoas, TAM);
	      break;

	    }
	  break;
	case 2:
	  switch (retornos[1])
	    {
	    case 0:
	      qtd = CadastrarDisciplina (qtd);
	      break;
	    case 1:
	      switch (retornos[2])
		{
		case 0:
		  matriculaVetor (pessoas, TAM, matvet);
		  nomeVetor (pessoas, TAM, nomevet);
		  listarDisciplinasGeral (qtd, TAM, matvet, nomevet);
		  break;
		case 1:
		  listarDisciplinas (qtd);
		  break;
		case 2:
		  ListaDiscMaiorVagas (qtd);
		  break;
		}
	      break;
	    case 2:
	      RemoverDisciplinas (qtd);
	      break;
	    case 3:
    	  switch (retornos[2])
    	    {
    	    case 0:
    	      matriculaVetor (pessoas, TAM, matvet);
    	      InserirAluno (qtd, TAM, matvet);
    	      break;
    	    case 1:
    	      RemoverAlunoDisciplina (qtd, TAM);
    	      break;
    	    }
	        break;
	    }
	  break;
	case 3:
	  switch (retornos[1])
	    {
	    case 0:
	      pesquisarPessoas (pessoas, TAM);
	      break;
	    case 1:
	      buscarAniversariantes (pessoas, TAM);
	      break;
	    }
	  break;
	case -1:
	  printf ("\e[1;1H\e[2J Programa encerrado.\n");
	  exit (0);
	}
      printf ("\nDigite Enter para retornar ao inicio.\n");
      getchar ();
    }
  while (1 == 1);
}
