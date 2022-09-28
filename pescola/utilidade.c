#include<string.h>
#include<stdlib.h>
#include <stdio.h>
void removerBarraN(char palavra[]) {
  int procurar = strcspn(palavra, "\n");
  palavra[procurar] = 0;
}
