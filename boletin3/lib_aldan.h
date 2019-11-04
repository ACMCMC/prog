#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

FILE* abrir_arquivo(char *modo)
{

  char nome_arquivo[20], final[5];

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

FILE *arquivo;

  if ((arquivo = fopen(nome_arquivo, modo)) == NULL)
  {
    extern int errno;
    printf("Erro: %s",strerror(errno));
    exit(1);
  }
  else
  {
    printf("Aberto: %s\n",nome_arquivo);
    return(arquivo);
  }
}