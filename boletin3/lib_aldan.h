#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void encriptar(char *string, char *encriptado)
{

  encriptado[0] = string[0];

  for (int i = 1; i < strlen(string); i++)
  {
    encriptado[i] = (string[i] + string[i - 1]) % 128;
  }
  encriptado[strlen(string)] = '\0';
}

void desencriptar(char *encriptado, char *desencriptado) {

  desencriptado[0] = encriptado[0];

  for (int i = 1; i < strlen(encriptado) ; i++)
  {
    desencriptado[i] = (encriptado[i] - desencriptado[i-1] + 128) % 128;
  }
  desencriptado[strlen(encriptado)] = '\0';
}

void ler_linha(FILE *arquivo, char *cadea_destino, int lonx_cadea) {
  fgets(cadea_destino,lonx_cadea,arquivo);
  //printf("%d, %d, %d, %d ",strlen(cadea_destino), cadea_destino[strlen(cadea_destino)], cadea_destino[strlen(cadea_destino)] - 1, cadea_destino[strlen(cadea_destino)] - 2);
  for(int i = strlen(cadea_destino) - 1; (cadea_destino[i] == '\r') || (cadea_destino[i] == '\n'); i--) {
    if(cadea_destino[i] == (cadea_destino[i] == '\r') || (cadea_destino[i] == '\n'))
    cadea_destino[i] = '\0';
  }
}

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

    if (strcmp(final, ".txt") == 0 && strcmp(final, ".dat") == 0)
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