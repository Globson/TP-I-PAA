#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Headers/labirinto.h"
#include "Headers/menu.h"
#include "Headers/dados.h"

int main(int argc, char const *argv[]) {
  //Váriveis necessárias para criação do programa
  int i = 0, j = 0, valor, opcao;
  int linhaEstudante, colunaEstudante;
  int  linhaArq, colunaArq, quantChaveArq;
  char valorAux, arquivo[30];
  strcpy(arquivo, "\0"); //colocamos vazio em arquivo para impedir que o usuario acesse a opcao 2 antes de digitar o nome do arquivo
  FILE *arq;
  int ** labirinto;
  TipoItem itens;
  TipoDados dados;
  while(1){
    system("clear");
    menu_de_entradas(); //chamada do menu que mostra as opções ao usuário.
    scanf("%d", &opcao);
    system("clear");
    switch (opcao) {
      case 1:
        printf("Por favor digite o nome do arquivo: ");
        scanf("%s", arquivo);
        arq = fopen(arquivo, "r");
        while (!arq){
          printf("Erro ao ler o arquivo! \n");
          printf("Por favor digite o nome do arquivo: ");
          scanf("%s", arquivo);
          arq = fopen(arquivo, "r");
        }

          // lemos a primeira linha e armazenamos os valores das linhas colunas e  a quantidade de chaves que o estudante tem
          fscanf(arq,"%d %d %d\n", &linhaArq, &colunaArq, &quantChaveArq);

          labirinto = IniciarLabirinto(linhaArq, colunaArq, &itens, quantChaveArq); // criamos uma matriz com o tamanho passado pelo arquivo

          while(!feof(arq) && !ferror(arq)){// enquanto não for fim do arquivo e não for erro de leitura, continuamos lendo
            valorAux = fgetc(arq); //valorAux recebe um caracter
            valor = valorAux-48; //esse caracter é convertido para int e passado para valor
            if(valor == EOF){ //se esse valor for o final da leitura, encerramos o while
              break;
            }
            /*sempre que o valorAux for uma quebra de linha, aumentamos a linha e zeramos a coluna
            exemplo:
            012 <- quando chegar aqui, o i vai passar a valer 1 e a coluna que era 3 voltara para 0
            345
            678
            */
            if(valorAux == '\n'){
              i++;
              j = 0;
            }else{
              InserirPosicao(labirinto, i, j, valor);
              j++;
            }
          }
          printf("Arquivo carregado com sucesso!!\n");
          system("read -p 'Pressione Enter para continuar...' var");
          fclose(arq);
        break;
      case 2:
        printf("%s\n", arquivo);
        if(strlen(arquivo) == 0){
          printf("Por favor carregue antes um arquivo de dados!\n");
          system("read -p 'Pressione Enter para continuar...' var");
          break;
        }
        else{
          linhaEstudante = LinhaEstudante(labirinto, linhaArq, colunaArq);
          colunaEstudante = ColunaEstudante(labirinto, linhaArq, colunaArq);
          Movimenta_Estudante(labirinto, &itens, linhaEstudante, colunaEstudante, linhaArq, colunaArq, &dados);
          ImprimirLabirinto(labirinto, linhaArq, colunaArq);
          ImprimirDados(dados);
          system("read -p 'Pressione Enter para continuar...' var");
          system("clear");
        }
        strcpy(arquivo, "\0");

        break;
      default:
        menu_de_saida();
        printf("Saindo !!\n");
        exit(0);
    }
  }

  return 0;
}
