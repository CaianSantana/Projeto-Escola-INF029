
struct dis
{
  char Nome[50];
  int Codigo;
  int Semestre;
  char Professor[50];
  int Matricula_alunos;
  int Vagas;
  int VagasTotais;
  int contaluno;
  int matriculas[];
} Disciplina[4];

int CadastrarDisciplina (int qtd);
void InserirAluno (int qtd, int qtdAluno, int mat[]);
void listarDisciplinas (int qtd);
void listarDisciplinasGeral (int qtd, int qtdAluno,int mat[], char nomes[][qtd]);
int RemoverDisciplinas (int qtd);
int RemoverAlunoDisciplina (int qtd,int qtdAluno);
void ListaDiscMaiorVagas (int qtd);