#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void abrir_arquivo(FILE *arquivo, char *modo)
{

  char nome_arquivo[20], final[4];

  scanf("%s", nome_arquivo);

  if (strlen(nome_arquivo) > 4)
  {
    for (int i = 0; i < 5; i++)
    {
      final[i] = nome_arquivo[strlen(nome_arquivo) - i - 1];
    }
    final[4] = '\0';

    if (strcmp(final, ".txt") == 0)
    {
      strcat(nome_arquivo, ".txt");
    }
  }
  else
  {
    strcat(nome_arquivo, ".txt");
  }

  FILE *arch;

  if ((arch = fopen(nome_arquivo, modo)) == NULL)
  {
    printf("Erro de apertura do arquivo.");
    exit(1);
  }
  else
  {
    printf("Aberto: %s\n",nome_arquivo);
    arquivo = arch;
  }
}