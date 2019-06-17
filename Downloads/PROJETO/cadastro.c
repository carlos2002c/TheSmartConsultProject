#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  FILE     *arquivo, *arquivotemporario;
  usuario  dados;
  int      opcao, codigoconsulta;
  char nomeCadastrado[20],
       senhaCadastrada[20],
       senhaAdm[10];

  char adm1[10] = "J0ao",
       adm2[10] = "F3lipe",
       adm3[10] = "C4rlos",
       adm4[10] = "L3on4rdo";

  arquivo = fopen("dados.dad", "rb+");
  if (arquivo == NULL)
  {
     printf("Arquivo ainda nao existe e sera criado neste momento...\n\n");
     arquivo = fopen("dados.dad", "wb+");
  }

  do
  {
     printf("\n[1] Inclui Registro");
     printf("\n[2] Consulta Registro");
     printf("\n[3] Altera Registro");
     printf("\n[4] Exclui Registro Fisicamente (Somente ADM)");
     printf("\n[5] Exclui Registro Logicamente");
     printf("\n[6] Listagem de Registros (Somente ADM)");
     printf("\n[7] Encerra");
     printf("\n[Menu] Informe a Opcao Desejada = ");
     scanf("%d", &opcao);

     switch(opcao)
     {
      case 1: printf("\n\nInserindo um novo registro no arquivo...");
              printf("\n\nInforme o codigo do usuario = ");
              scanf("%d", &dados.codigo);
              getchar();
              printf("\nInforme o nome do usuario = ");
              scanf("%[A-Z a-z]", &dados.nome);
              getchar();
              printf("\nInforme o senha do usuario = ");
              scanf("%s", &dados.senha);
              getchar();
              printf("\nInforme o tipo da conta [1 - Padrao | 2 - Premium] = ");
              scanf("%d", &dados.tipo);
              dados.status = 1;
              fflush(stdin);

              fseek(arquivo,0*sizeof(usuario), SEEK_END);
              fwrite(&dados,sizeof(usuario),1,arquivo);

              break;


      case 2: printf("\n\nConsultando um registro gravado...");
              printf("\nInforme o codigo do usuario para consulta = ");
              scanf("%d", &codigoconsulta);
              printf("\nInforme a senha do usuario para consulta = ");
              scanf("%s", &senhaCadastrada);

              //rewind(arquivo);
              fseek(arquivo, 0*sizeof(usuario), SEEK_SET);
              do
              {
                fread(&dados,sizeof(usuario),1,arquivo);
                if (dados.codigo == codigoconsulta && strcmp(dados.senha, senhaCadastrada) == 0 && !feof(arquivo) && dados.status == 1)
                {
                   printf("\nCodigo encontrado");
                   printf("\nCodigo de Acesso = %d  Nome = %s  Tipo = %d \n\n", dados.codigo, dados.nome, dados.tipo);
                   break;
                }
              } while (!feof(arquivo));

              if (feof(arquivo))
                  printf("\nCodigo inexistente...\n\n");

              break;


      case 3: printf("\n\nAlterando valores de um registro gravado...");
              printf("\nInforme o nome do usuario para consulta e alteracao = ");
              scanf("%s", &nomeCadastrado);
              printf("\nInforme a senha do usuario para consulta e alteracao = ");
              scanf("%s", &senhaCadastrada);
              getchar();

              //rewind(arquivo);
              fseek(arquivo, 0*sizeof(usuario), SEEK_SET);
              do
              {
                fread(&dados,sizeof(usuario),1,arquivo);
                if (strcmp(dados.nome, nomeCadastrado) == 0 && strcmp(dados.senha, senhaCadastrada) == 0 && !feof(arquivo) && dados.status == 1)
                {
                   printf("\nCodigo encontrado");
                   printf("\n Codigo de Acesso = %d  Nome = %s  Senha = %s  Tipo = %d \n\n", dados.codigo, dados.nome, dados.senha, dados.tipo);
                   printf("\n\nInforme os novos dados para alteracao\n\n");

                   printf("\nInforme o NOVO valor do nome do usuario = ");
                   scanf("%[A-Z a-z]",dados.nome);
                   getchar();

                   printf("\nInforme o NOVO valor da senha do usuario = ");
                   scanf("%[A-Z a-z]",dados.senha);
                   getchar();

                   printf("\nInforme o NOVO valor do tipo [1 - Padrao | 2 - Premium] = ");
                   scanf("%d", &dados.tipo);
                   getchar();
                   fflush(stdin);

                   fseek(arquivo,-1*sizeof(usuario),SEEK_CUR);
                   fwrite(&dados,sizeof(usuario),1,arquivo);
                   break;
                }
              } while (!feof(arquivo));

              if (feof(arquivo))
                  printf("\nCodigo inexistente...\n");

              break;

      case 4: printf("\n\nDigite a senha de administrador: ");
              scanf("%s", &senhaAdm);

              if(strcmp(senhaAdm, adm1) != 0 && strcmp(senhaAdm, adm2) != 0 && strcmp(senhaAdm, adm3) != 0 && strcmp(senhaAdm, adm4) != 0)
                 {
                     printf("\n\nSenha nao autorizada...\n");
                     break;
                 }

              printf("\n\nExcluindo um registro fisicamente...");
              printf("\nInforme o valor do codigo do usuario para consulta e exclusao = ");
              scanf("%d", &codigoconsulta);

              arquivotemporario = fopen("temporario.dad", "wb");

              //rewind(arquivo);
              fseek(arquivo, 0*sizeof(usuario), SEEK_SET);

              do
              {
                fread(&dados,sizeof(usuario),1,arquivo);
                if (dados.codigo != codigoconsulta && !feof(arquivo) && dados.status == 1)
                {
                   fwrite(&dados,sizeof(usuario),1,arquivotemporario);
                }
              } while (!feof(arquivo));

              fclose(arquivo); fclose(arquivotemporario);

              remove("dados.dad");
              rename("temporario.dad", "dados.dad");

              arquivo = fopen("dados.dad", "rb+");
              printf("\nRegistro excluido com sucesso...");
              printf("\nArquivo de dados original reaberto com sucesso...\n");

              break;

      case 5: printf("\n\nExcluindo um registro logicamente...");
              printf("\nInforme o valor do codigo do usuario para consulta e exclusao = ");
              scanf("%d", &codigoconsulta);

              printf("\nInforme o valor do nome do usuario para consulta e exclusao = ");
              scanf("%s", &nomeCadastrado);

              printf("\nInforme o valor da senha do usuario para consulta e exclusao = ");
              scanf("%s", &senhaCadastrada);

              fseek(arquivo, 0*sizeof(usuario), SEEK_SET);

              while(!feof(arquivo))
              {
                  fread(&dados,sizeof(usuario),1,arquivo);
                  if(dados.codigo == codigoconsulta && strcmp(nomeCadastrado, dados.nome) == 0 && strcmp(senhaCadastrada, dados.senha) == 0 && !feof(arquivo) && dados.status == 1)
                  {
                       dados.status = 0;
                       fseek(arquivo, -1*sizeof(usuario), SEEK_CUR);
                       fwrite(&dados, sizeof(usuario),1,arquivo);
                       printf("\nRegistro excluido com sucesso...");
                       break;
                  }

              }

              if(feof(arquivo))
                printf("\n\nCodigo inexistente...\n\n");
            break;

      case 6: printf("\n\nDigite a senha de administrador: ");
              scanf("%s", &senhaAdm);

              if(strcmp(senhaAdm, adm1) != 0 && strcmp(senhaAdm, adm2) != 0 && strcmp(senhaAdm, adm3) != 0 && strcmp(senhaAdm, adm4) != 0)
                 {
                     printf("\n\nSenha nao autorizada...\n");
                     break;
                 }

              printf("\nListando todos os registros...\n\n");
              fseek(arquivo,0*sizeof(usuario), SEEK_SET);
              while(!feof(arquivo))
              {
                  fread(&dados, sizeof(usuario),1,arquivo);
                  if(!feof(arquivo) && dados.status == 1)
                  printf("Codigo = %d  Nome = %s  Senha = %s  Tipo da Conta = %d  Status = %d\n",
                         dados.codigo, dados.nome,
                         dados.senha, dados.tipo, dados.status);
              }
    }
  } while (opcao != 7);

  if (arquivo != NULL)
     fclose(arquivo);

  printf("\n\n*** Fim do Programa ***");
  getchar();
 }
