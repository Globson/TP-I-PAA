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
  int  linhaArq, colunaArq, quantChaveArq;
  char valorAux, arquivo[30];
  FILE *arq;
  int ** labirinto;
  TipoItem itens;
  menu_de_entradas(); //chamada do menu que mostra as opções ao usuário.
  scanf("%d", &opcao);
  switch (opcao) {
    case 1:
      printf("Por favor digite o nome do arquivo:");
      scanf("%s", arquivo);
      arq = fopen(arquivo, "r");
      while (!arq){
        printf("Erro ao ler o arquivo! \n");
        printf("Por favor digite o nome do arquivo:");
        scanf("%s", arquivo);
        arq = fopen(arquivo, "r");
      }

        // lemos a primeira linha e armazenamos os valores das linhas colunas e  a quantidade de chaves que o estudante tem
        fscanf(arq,"%d %d %d\n", &linhaArq, &colunaArq, &quantChaveArq);

        printf("linha %d\n", linhaArq);
        printf("coluna %d\n", colunaArq);
        printf("quant %d\n", quantChaveArq);

        labirinto = IniciarLabirinto(linhaArq, colunaArq, &itens, quantChaveArq); // criamos uma matriz com o tamanho passado pelo arquivo

        EhParede(labirinto, linhaArq, colunaArq);
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
        fclose(arq);
      break;
    case 2:

      break;
    default:
      printf("Saindo !!\n");
      exit(0);
  }

  ImprimirLabirinto(labirinto, linhaArq, colunaArq);

  /*
  printf("%d ", labirinto[0][0]);
  printf("%d ", labirinto[0][1]);
  printf("%d\n", labirinto[0][2]);

  printf("%d ", labirinto[1][0]);
  printf("%d ", labirinto[1][1]);
  printf("%d\n", labirinto[1][2]);

  printf("%d ", labirinto[2][0]);
  printf("%d ", labirinto[2][1]);
  printf("%d\n", labirinto[2][2]);
  */

  return 0;
}
