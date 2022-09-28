#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "main.h"

Pessoa SetPessoa(unsigned int Matricula, char Nome[], char Sexo[], char CPF[],
               DataNascimento datanascimento, int Tipo, int NumMat) {
  Pessoa p;
  p.Matricula = Matricula;
  strcpy(p.Nome, Nome);
  strcpy(p.Sexo, Sexo);
  strcpy(p.CPF, CPF);
  p.datanascimento = datanascimento;
  p.Tipo = Tipo;
  p.NumMat = NumMat;
  return p;
}

DataNascimento SetDataNascimento(int dia, int mes, int ano) {
  DataNascimento DN;
  DN.dia = dia;
  DN.mes = mes;
  DN.ano = ano;
  return DN;
}

void DadosPessoas(Pessoa pessoas[], int TAM) {
    pessoas[0] = SetPessoa(1, "Johnny", "M", "00000000000",
                                SetDataNascimento(23, 9, 2002), 1, 0);
    pessoas[1] = SetPessoa(2, "Maria", "F", "00000000000",
                                SetDataNascimento(24, 9, 2002), 1, 0);
    pessoas[2] = SetPessoa(3, "Julia", "F", "00000000000",
                                SetDataNascimento(25, 9, 2002), 1, 0);
    pessoas[3] = SetPessoa(4, "Jonas", "M", "00000000000",
                                SetDataNascimento(22, 9, 2002), 1, 0);
    pessoas[4] = SetPessoa(6, "James", "M", "00000000000", SetDataNascimento(15, 11, 1967), 0, 6);
    pessoas[5] = SetPessoa(7, "Mary", "F", "00000000000",
                       SetDataNascimento(23, 9, 2002), 0, 6);
    pessoas[6] = SetPessoa(5, "Evelyn", "F", "00000000000",
                       SetDataNascimento(1, 5, 2002), 0, 6);
    pessoas[7] = SetPessoa(8, "Justin", "M", "00000000000",
                       SetDataNascimento(22, 3, 1975), 0, 6);
}

//funções de formatação
DataNascimento formataData(char data[]) {
  // Transforma Data de string para int e depois para formato de data
  int dia, mes, ano, i, j;
  for (i = 0; i < 11; i++)
    if (data[i] == '/')
      for (j = i; j < 11; j++)
        data[j] = data[j + 1];
  for (i = 0; i < 8; i++)
    data[i] -= 48;
  dia = (data[0] * 10) + data[1];
  mes = (data[2] * 10) + data[3];
  ano = (data[4] * 1000) + (data[5] * 100) + (data[6] * 10) + data[7];
  DataNascimento DataFormatada = SetDataNascimento(dia, mes, ano);
  return DataFormatada;
}
int calculaAnoBissexto(int ano) {

  // 1-Se o ano for uniformemente divisível por 4, vá para a etapa 2. Caso
  // contrário, vá para a etapa 5. 2-Se o ano for uniformemente divisível por
  // 100, vá para a etapa 3. Caso         contrário, vá para a etapa 4. 3-Se o
  // ano for uniformemente divisível por 400, vá para a etapa 4. Caso contrário,
  // vá para a etapa 5. 4-O ano é bissexto (tem 366 dias). 5-O ano não é um ano
  // bissexto (tem 365 dias)
  if (ano % 4 == 0) {
    if (ano % 100 == 0) {
      if (ano % 400 == 0)
        return 0;
      else
        return 1;
    } else {
      return 0;
    }
  } else
    return 1;
}

// Funções de ordenação
void OrdenarPessoaPorDataNasc(Pessoa p[],int tipo, int TAM) {
    Pessoa aux;
    int i, j,k=0,menor, idade[TAM];
    for(i=0;i<TAM;i++){
        if(p[i].Tipo == tipo){
            idade[k] = 2021 - p[i].datanascimento.ano;
            k++;
            if((p[i].datanascimento.mes = 9 && p[i].datanascimento.dia  >= 27)||(p[i].datanascimento.mes > 9)){
                idade[k]+=1;
            }
            printf("idade[%d]: %d\t%d\n", i, idade[k], p[i].datanascimento.ano);
        }
    }
    for (i = 0; i < k-1; i++){
        menor=i;
        if(p[i].Tipo == tipo){
            for (j = i+1 ; j < k; j++)
                if (idade[i]>idade[j]){
                    menor = j;
                }
            aux = p[i];
            p[i] = p[menor];
            p[menor] = aux;
        }
    }
}

void OrdenarPessoaPorNome(Pessoa p[], int TAM) {
  Pessoa auxiliar;
  int i, j,k, menor;
  for (i = 0; i < TAM; i++){
        menor = i;
        k=0;
    for (j = i + 1; j < TAM; j++)
        if (p[j].Nome[0] < p[menor].Nome[0]  && strlen(p[j].Nome)<=strlen(p[j].Nome)){
            menor = j;
        }
        auxiliar = p[i];
        p[i] = p[menor];
        p[menor] = auxiliar;
    }
  }

//funções de input
DataNascimento recebeData(char d[]) {

  char data[11];
  DataNascimento DataFormatada;
  printf("informe a Data de Nascimento(DD/MM/AAAA): \n");
  fgets(data, 12, stdin);
  fflush(stdin);
  removerBarraN(data);
  strcpy(d, data);
  DataFormatada = formataData(data);
  return DataFormatada;
}
void recebeNome(char nome[]) {
    printf(
      "informe o nome completo sem acentos ou caracteres especiais: \n"); // Modificar
                                                                          // depois
                                                                          // para
                                                                          // aceitar
                                                                          // acentos
    fgets(nome, 51, stdin);
    fflush(stdin);
    removerBarraN(nome);
}
void recebeSexo( char sexo[]) {
    printf("informe o sexo(M/F):\n"); // Modificar depois para aceitar acentos
    fgets(sexo, 3, stdin);
    fflush(stdin);
    removerBarraN(sexo);
}
void recebeCPF(char cpf[]){
    printf("informe o CPF(somente números): \n"); // Modificar depois para aceitar acentos
    fgets(cpf, 13, stdin);
    fflush(stdin);
    removerBarraN(cpf);
  //formataCPF(cpf);
}


//funções de validação
int validaData(DataNascimento data, char d[]) {
  int i;
  if (strlen(d) < 10) {
    printf("Formato de data inválido.\n");
    return 1;
  }
  if (data.ano > 2022 || data.ano < 1920) {
    printf("Ano inválido.\n");
    return 1;
  }
  for (i = 1; i <= 12; i++) {
    if (data.mes == i && data.dia > 31 || data.dia < 1) {
      printf("Este mês possui apenas 31 dias. Dia inválido.\n");
      return 1;
    }
    if (i == 7)
      i--;
    i++;
  }
  for (i = 4; i <= 11; i++) {
    if (data.mes == i && data.dia > 30 || data.dia < 1) {
      printf("Este mês possui apenas 30 dias. Dia inválido.\n");
      return 1;
    }
    if (i == 6)
      i++;
    i++;
  }
  if (calculaAnoBissexto(data.ano) == 0) {
    if (data.mes == 2 && data.dia > 29 || data.dia < 1) {
      printf("Fevereiro em anos bissextos possui apenas 29 dias."
             " Dia inválido.\n");
      return 1;
    }
  } else {
    if (data.mes == 2 && data.dia > 28 || data.dia < 1) {
      printf("Fevereiro em anos comuns possui apenas 28 dias."
             " Dia inválido.\n");
      return 1;
    }
  }
  return 0;
}
int validaNome(char nome[]) {
  int i;
  if (strlen(nome) < 2) {
    printf("Nome inválido.\n");
    return 1;
  }
  for (i = 0; i < strlen(nome); i++) {
    if (nome[i] == 32) {
      continue;
    } else if (nome[i] < 65 || nome[i] > 122) {
      printf("Carácter %c é inválido.", nome[i]);
      return 1;
    }
  }
  return 0;
}
int validaSexo(char sexo[]) {
  if (sexo[0] == 109 || sexo[0] == 77 || sexo[0] == 102 || sexo[0] == 70) {
    return 0;
  } else {
    printf("Sexo inválido.\n");
    return 1;
  }
}
int validaCPF(char cpf[]){
  int i, j, verificador1, verificador2, resto, calc=0, cpfinteiro[11];
  verificador1 = cpf[9] - 48;
  verificador2 = cpf[10] - 48;
  for (i = 0; i < 11; i++)
  {  
    cpfinteiro[i] = cpf[i] - 48; // converte o valor absoluto do char em inteiro//
  }
  for (i = 0; i < 9; i++)
  {
    calc = calc + (cpfinteiro[i] * (10 - i));
  }
  resto = ((calc * 10) % 11);
  calc=0;
  if (resto != verificador1)
  {
    printf("\nDigito verificador 1 errado");
    return 1;
  }
  for (i = 0; i < 10; i++)
  {
    calc = calc + (cpfinteiro[i] * (11 - i));
  }
  resto = ((calc * 10) % 11);
  if (resto != verificador2)
  {
    printf("Digito verificador 2 errado");
    return 1;
  }
  return 0;
}

//funções de administração
void listarPessoas(int alternativa, int tipo, int TAM, Pessoa pessoas[]) {
  int i, j;
  char sexo;
    switch (alternativa) {
        case 1:
            printf("Listando todos:\n\n");
            for (i = 0; i < TAM; i++){
                if(pessoas[i].Tipo == tipo)
                    printf("Matrícula: %d\nNome: %s\nSexo: %c\nData de Nascimento: "
                     "%i/%i/%i\nCPF: %s\n\n",
                     pessoas[i].Matricula, pessoas[i].Nome, pessoas[i].Sexo[0],
                     pessoas[i].datanascimento.dia, pessoas[i].datanascimento.mes,
                     pessoas[i].datanascimento.ano, pessoas[i].CPF);
                }
            getchar();
            break;
        case 2:
            OrdenarPessoaPorNome(pessoas, TAM);
            printf("Listando por ordem alfabética:\n\n");
            for (i = 0; i < TAM; i++)
                if(pessoas[i].Tipo == tipo)
                    printf("Matrícula: %d\nNome: %s\nSexo: %c\nData de Nascimento: "
                     "%i/%i/%i\nCPF: %s\n\n",
                     pessoas[i].Matricula, pessoas[i].Nome, pessoas[i].Sexo[0],
                     pessoas[i].datanascimento.dia, pessoas[i].datanascimento.mes,
                     pessoas[i].datanascimento.ano, pessoas[i].CPF);
            getchar();
            break;
        case 3:
            getchar();
            printf("Escolha o sexo(M/F):\n");
            scanf(" %c", &sexo);
            printf("\e[1;1H\e[2J");
            if (sexo == 77 || sexo == 109) {
                printf("Listando homens:\n\n");
                for (i = 0; i < TAM; i++)
                    if(pessoas[i].Tipo == tipo)
                        if (strcmp(pessoas[i].Sexo, "M") == 0 || strcmp(pessoas[i].Sexo, "m") == 0)
                            printf("Matrícula: %d\nNome: %s\nData de Nascimento: "
                                    "%i/%i/%i\nCPF: %s\n\n",
                                    pessoas[i].Matricula, pessoas[i].Nome,
                                    pessoas[i].datanascimento.dia, pessoas[i].datanascimento.mes,
                                    pessoas[i].datanascimento.ano, pessoas[i].CPF);
            } else if (sexo == 70 || sexo == 102) {
                printf("Listando mulheres:\n\n");
                    for (i = 0; i < TAM; i++)
                        if(pessoas[i].Tipo == tipo)
                            if (strcmp(pessoas[i].Sexo, "F") == 0 || strcmp(pessoas[i].Sexo, "f") == 0)
                                printf("Matrícula: %d\nNome: %s\nData de Nascimento: "
                                        "%i/%i/%i\nCPF: %s\n\n",
                                        pessoas[i].Matricula, pessoas[i].Nome,
                                        pessoas[i].datanascimento.dia, pessoas[i].datanascimento.mes,
                                        pessoas[i].datanascimento.ano, pessoas[i].CPF);
            } else
                printf("Dígito inválido.");
            getchar();
            break;
        case 4:
            OrdenarPessoaPorDataNasc(pessoas, tipo, TAM);
            printf("Listando por idade:\n\n");
            for (i = 0; i < TAM; i++)
                if(pessoas[i].Tipo == tipo)
                    printf("Matrícula: %d\nNome: %s\nSexo: %c\nData de Nascimento: "
                     "%i/%i/%i\nCPF: %s\n\n",
                     pessoas[i].Matricula, pessoas[i].Nome, pessoas[i].Sexo,
                     pessoas[i].datanascimento.dia, pessoas[i].datanascimento.mes,
                     pessoas[i].datanascimento.ano, pessoas[i].CPF);
            getchar();
            break;
    }
}
int cadastraPessoa(int tipo, int TAM, Pessoa pessoas[]) {
    char confirmacao;
    char nome[51], sexo[3], cpf[15], d[11];
    DataNascimento data;
    getchar();
    while(0==0){
        recebeNome(nome);
        if(validaNome(nome)==0)
            break;
    }
    while(0==0){
        recebeCPF(cpf);
        if(validaCPF(cpf)==0)
            break;
    }
    while(0==0){
        data = recebeData(d);
        if(validaData(data, d)==0)
            break;
    }
    while (0 == 0) {
        recebeSexo(sexo);
        if (validaSexo(sexo) == 0)
            break;
    }
    fflush(stdin);
    TAM++;
    pessoas[TAM-1] = SetPessoa(TAM, nome, sexo, cpf, data, tipo, 0);
    printf( "\e[1;1H\e[2J\e[1;1H\e[2J"    
            "Matrícula: %d\nNome: %s\nSexo: %s\nData de Nascimento: "
            "%i/%i/%i\nCPF: %s\n\n"
            "Cadastro realizado com sucesso!\n\n",
                     pessoas[TAM-1].Matricula, pessoas[TAM-1].Nome, pessoas[TAM-1].Sexo,
                     pessoas[TAM-1].datanascimento.dia, pessoas[TAM-1].datanascimento.mes,
                     pessoas[TAM-1].datanascimento.ano, pessoas[TAM-1].CPF);
    printf("Deseja realizar outro cadastro?(S/N)\n");
    scanf(" %c", &confirmacao);
    fflush(stdin);
    if (confirmacao == 83 || confirmacao == 115) {
        printf("\e[1;1H\e[2J");
        cadastraPessoa(1, TAM, pessoas);
        }
    return TAM;
}
void alterarCadastro(int alternativa, int tipo, Pessoa pessoas[], int TAM){
    int matricula, i,  posicao=0;
    char nome[51], cpf[15], d[11], sexo;
    DataNascimento data;
    while(0==0){
        printf("Digite a matricula:");
        scanf(" %d", &matricula);
        getchar();
        fflush(stdin);
        printf("\e[1;1H\e[2J");
        for(i=0;i<TAM;i++){
            if(pessoas[i].Matricula == matricula && pessoas[i].Tipo == tipo){
                posicao = i;
                break;
            }
        }
        if(posicao!=0){
            break;
        }else{
            printf("Matrícula inválida. Digite Enter para tentar novamente.\n");
            getchar();
        }
    }
    switch(alternativa){
        case 1:
            while(0==0){
                recebeNome(nome);
                if(validaNome(nome)==0){
                    pessoas[posicao] = SetPessoa(pessoas[posicao].Matricula, nome, pessoas[posicao].Sexo, pessoas[posicao].CPF,
                                                pessoas[posicao].datanascimento, pessoas[posicao].Tipo, pessoas[posicao].NumMat);
                    break;
                }
            }
            printf("Cadastro Atualizado com Sucesso!\n");
            break;
        case 2:
            while(0==0){
                recebeCPF(cpf);
                if(validaCPF(cpf)==0){
                    pessoas[posicao] = SetPessoa(pessoas[posicao].Matricula, pessoas[posicao].Nome, pessoas[posicao].Sexo, cpf,
                                                pessoas[posicao].datanascimento, pessoas[posicao].Tipo, pessoas[posicao].NumMat);
                    break;
                }
            }
            printf("Cadastro Atualizado com Sucesso!\n");
            break;
        case 3:
            while(0==0){
                recebeSexo(sexo);
                if(validaSexo(sexo)==0){
                    pessoas[posicao] = SetPessoa(pessoas[posicao].Matricula, pessoas[posicao].Nome, sexo,  pessoas[posicao].CPF,
                                                pessoas[posicao].datanascimento, pessoas[posicao].Tipo, pessoas[posicao].NumMat);
                    break;
                }
            }
            printf("Cadastro Atualizado com Sucesso!\n");
            break;
        case 4:
            while(0==0){
                data = recebeData(d);
                if(validaData(data, d)==0){
                    pessoas[posicao] = SetPessoa(pessoas[posicao].Matricula, pessoas[posicao].Nome, pessoas[posicao].Sexo,  pessoas[posicao].CPF,
                                                data, pessoas[posicao].Tipo, pessoas[posicao].NumMat);
                    break;
                }
            }
            printf("Cadastro Atualizado com Sucesso!\n");
            break;
        case 5:
            while(0==0){
                recebeNome(nome);
                if(validaNome(nome)==0){
                    strcpy(pessoas[posicao].Nome, nome);
                    break;
                }
            }
            while(0==0){
                recebeCPF(cpf);
                if(validaCPF(cpf)==0){
                    strcpy(pessoas[posicao].CPF, cpf);
                    break;
                }
            }
            while(0==0){
                recebeSexo(sexo);
                if(validaSexo(sexo)==0){
                    strcpy(pessoas[posicao].Sexo, sexo);
                    break;
                }
            }
            while(0==0){
                data = recebeData(d);
                if(validaData(data, d)==0){
                    pessoas[posicao].datanascimento = data;
                    break;
                }
            }
            pessoas[posicao] = SetPessoa(pessoas[posicao].Matricula, nome, sexo, cpf, data, pessoas[posicao].Tipo, pessoas[posicao].NumMat);
            //pessoas[TAM-1] = SetPessoa(TAM, nome, sexo, cpf, data, tipo, 0);
            printf("Cadastro Atualizado com Sucesso!\n");
            fflush(stdin);
            break;
    }
}
void pesquisarPessoas(Pessoa pessoas[], int TAM){
    char procurado[51];
    Pessoa encontradas[TAM];
    int i, j, k, x=0, contador, contmenos;
    printf("\e[1;1H\e[2J");
    recebeNome(procurado);
    contmenos = strlen(procurado);
    contador = contmenos;
    for(i=0;i<TAM;i++){
        k=0;
        for(j=0;j<contador;j++){
                if(pessoas[i].Nome[j] == procurado[k]){
                    k++;
                    contmenos--;
                    if(contmenos <=0)
                        break;
                }
        }
        if(k == contador){
            encontradas[x] = pessoas[i];
            x++;
        }
        contmenos = strlen(procurado);
    }
    if(x != 0 ){
        for(i = 0; i<x; i++)
            printf("Matrícula: %d\nNome: %s\nSexo: %c\nData de Nascimento: "
                     "%i/%i/%i\nCPF: %s\n\n",
                     encontradas[i].Matricula, encontradas[i].Nome, encontradas[i].Sexo[0],
                     encontradas[i].datanascimento.dia, encontradas[i].datanascimento.mes,
                     encontradas[i].datanascimento.ano, encontradas[i].CPF);
    }else
        printf("Pessoa não encontrada.");
}
void buscarAniversariantes(Pessoa p[], int TAM){
    int mes=0, i, j=0, k=0;
    while(mes < 1 || mes >12){
        printf("Digite o mês:\n");
        scanf("%d",&mes);
        getchar();
        if(mes<1 || mes>12){
            printf("Mês inválido.");
            getchar();
        }
    }
    for(i=0;i<TAM;i++){
        if(p[i].datanascimento.mes == mes && k==0){
            printf("\e[1;1H\e[2J");
            printf("Feliz aniversário para:\n");
            k++;
        }
        if(p[i].datanascimento.mes == mes){
            printf("Nome: %s\nSexo: %c\nData de Nascimento: %i/%i/%i\n\n",
                     p[i].Nome, p[i].Sexo[0], p[i].datanascimento.dia, p[i].datanascimento.mes, p[i].datanascimento.ano);
            j++;
        }
    }
    if(j==0){
        printf("Não há aniversariantes no mês inserido!");
    }
}
int excluirPessoa(Pessoa p[],int TAM){
    int MatriculaE, i;
    printf("digite a Matricula: ");
    scanf(" %d", & MatriculaE);
    getchar();
    for(i = 0; p[i].Matricula != MatriculaE && i<TAM;i++){
    }
    if(i < TAM){
        for(;i<TAM;i++){
            p[i] = p[i+1];
        }
    }
    
}