#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

typedef struct
{
  int  codigo;
  char nome[20];
  char senha[20];
  int  tipo;
  int  status;
} usuario;

main()
{
  FILE *arquivo;
  FILE *arquivocadastrado;
  FILE *arquivoresposta;

  usuario dados;

  char caractere, usuarioLogin[20]="", senhaLogin[20]="",
       chave[11]="", key[11]="";
  int  i = 0;

  char usuarioLogado = '1';

  strcpy(chave,"PR0J3T0A3D");

  do
  {
    arquivo=fopen("arquivo.txt","rt");
    if (arquivo == NULL)
        printf("Aguardando login...\n");
  } while (arquivo == NULL);

  Sleep(1000);
  while (!feof(arquivo))
  {
         // Recuperando o valor do campo "usuario"
         i = 0;
         do
         {
            caractere = fgetc(arquivo);
            if (caractere != '=' && !feof(arquivo))
            {
                usuarioLogin[i] = caractere; i++;
            }
         } while (caractere != '=' && !feof(arquivo));

         // Recuperando o valor do campo "senha"
         i = 0;
         do
         {
            caractere = fgetc(arquivo);
            if (caractere != ';' && !feof(arquivo))
            {
                senhaLogin[i] = caractere; i++;
            }
         } while (caractere != ';' && !feof(arquivo));

         i = 0;
         do
         {
            caractere = fgetc(arquivo);
            if (caractere != '#' && !feof(arquivo))
            {
                key[i] = caractere; i++;
            }
         } while (caractere != '#' && !feof(arquivo));
  }

  if  (strcmp(key,chave) == 0)
       {
           printf("\n\nInformacoes recuperadas: \nusuario = %s \nsenha = %s", usuarioLogin, senhaLogin);
           printf("\n\nConsultando usuarios cadastrados...\n\n");
       }
  else
       printf("\nChave nao autorizada...");

  fclose(arquivo);
  remove("arquivo.txt");

  arquivoresposta = fopen("respostadocadastro.txt", "wt");
  if(arquivoresposta == NULL)
  {
      printf("Nao foi possivel retornar a resposta...\n");
  }

  arquivocadastrado = fopen("dados.dad","rb");
  if(arquivocadastrado == NULL)
  {
      printf("\nArquivo de usuarios nao existe...");
  }

  fseek(arquivocadastrado, 0*sizeof(usuario), SEEK_SET);

        do
        {
        fread(&dados,sizeof(usuario),1,arquivocadastrado);
        if (strcmp(dados.nome, usuarioLogin) == 0 && strcmp(dados.senha, senhaLogin) == 0 && !feof(arquivocadastrado) && dados.status == 1)
            {
                printf("Usuario encontrado:");
                printf("\n\nFazendo login...\n");
                fputc(usuarioLogado, arquivoresposta);
            }
        } while(!feof(arquivocadastrado));

        fclose(arquivocadastrado);
        fclose(arquivoresposta);
}
