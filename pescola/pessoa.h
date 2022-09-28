#include <string.h>
typedef struct {
  int dia;
  int mes;
  int ano;
} DataNascimento; // formato DD/MM/AAAA

typedef struct {
  unsigned int Matricula;
  char Nome[51];
  char Sexo[2];
  char CPF[15];
  DataNascimento datanascimento;
  int Tipo;
  int NumMat;
} Pessoa; // Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF, Tipo(0-aluno/1-professor), NumMat(Número de matérias matriculadas))

void DadosPessoas(Pessoa pessoas[], int TAM);

void listarPessoas(int alternativa, int tipo, int TAM, Pessoa pessoas[]);
int cadastraPessoa(int tipo, int TAM, Pessoa pessoas[]);
void alterarCadastro(int alternativa, int tipo, Pessoa pessoas[], int TAM);
void pesquisarPessoas(Pessoa pessoas[], int TAM);
void buscarAniversariantes(Pessoa p[], int TAM);

DataNascimento recebeData(char d[]);
void recebeNome(char nome[]);
void recebeSexo();
void recebeCPF(char cpf[]);
int Excluir(Pessoa p[],int TAM);