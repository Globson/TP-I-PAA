#include "../Headers/labirinto.h"
#include "../Headers/dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int ** IniciarLabirinto(int linha, int coluna, TipoItem *itens,int quantChave){
    int **labirintof;

    labirintof = (int**)calloc((linha+1),sizeof(int*));
    for(int i = 0; i <= linha; i++){
        labirintof[i] = (int*)calloc((coluna+1),sizeof(int));
    }
    itens->quantChave = quantChave;

    return labirintof;
}
void InserirPosicao(int ** labirinto, int linha, int coluna, int valor){
    if(valor == 0){ // posição inicial do estudante
        labirinto[linha][coluna] = 0;
    }else if(valor == 1){ // posição livre
        labirinto[linha][coluna] = 1;
    }else if(valor == 2){ //posição com parede
        labirinto[linha][coluna] = 2;
    }else{ // posição acessivel com chave
        labirinto[linha][coluna] = 3;
    }
}
void ImprimirLabirinto(int ** labirinto, int linha, int coluna){
    for(int i = 0; i < linha; i++){
      for(int j = 0; j < coluna; j++){
        if(labirinto[i][j] == 4){ // trocamos  a posição do estudandte por E pra mostrar que ele passou ali
          printf("E ");
        }else{
          printf("%d ",labirinto[i][j]);
        }
      }
    printf("\n");
  }
}
void MarcarPosicao(int ** labirinto, int linha, int coluna){
  labirinto[linha][coluna] = 4;
}

int EstudantePassou(int ** labirinto, int linha, int coluna){
  if(labirinto[linha][coluna] == 4){
    return 1;
  }
  return 0;
}

int EstudanteEsta(int ** labirinto, int linha, int coluna){
  if(labirinto[linha][coluna] == 0){
    return 1;
  }
  return 0;
}

int EhParede(int ** labirinto, int linha, int coluna){
  if(labirinto[linha][coluna] == 2){
    return 1;
  }
  return 0;
}
void EhPortaAberta(int ** labirinto, int linha, int coluna){
  labirinto[linha][coluna] = 1;
}
int EhPortaFechada(int **labirinto, int linha, int coluna){
  if(labirinto[linha][coluna] == 3){
    //if(!EhPortaAberta(labirinto, chaves, linha, coluna))
      return 1;
  }
  return 0;
}
int LinhaEstudante(int ** labirinto, int linha, int coluna){
  for(int i = 0; i < linha; i ++){
    for(int j = 0; j < coluna; j ++){
      if(labirinto[i][j] == 0){
        return i;
      }
    }
  }
  return -1;
}
int ColunaEstudante(int ** labirinto, int linha, int coluna){
  for(int i = 0; i < linha; i ++){
    for(int j = 0; j < coluna; j ++){
      if(labirinto[i][j] == 0){
        return j;
      }
    }
  }
  return -1;
}
int Movimenta_Estudante(int ** labirinto, TipoItem *itens, int i, int j, int linha, int coluna, TipoDados * dados,long long int* NUM){
    *NUM = *NUM + 1;
    if(i <= 0 && !EhParede(labirinto, i, j)){ //chegou ao final do labirinto e a posi��o � v�lida
        dados->ultimaColuna = j;
        dados->temSaida = 1;
        dados->quantMovimentacao++;
        //itens->quantChave--;
        //printf("itens %d\n", itens->quantChave);
        MarcarPosicao(labirinto, i, j);
        printf("Linha: %d Coluna: %d\n", i, j);
        return 1;
    }
    if(j >= coluna || j < 0 || i >= linha){ // ultrapassou os limites do labirinto
        dados->temSaida = 0;
        return 0;
    }
    if(!EhParede(labirinto, i, j) && !EhPortaFechada(labirinto, i, j)){
        dados->quantMovimentacao++;  //Incrementa o movimento do estudante
        printf("Linha: %d Coluna: %d\n", i, j);
    }
    if(EhPortaFechada(labirinto, i, j) && itens->quantChave > 0){
      dados->quantMovimentacao++;
      printf("Linha: %d Coluna: %d\n", i, j);
      itens->quantChave--;
      EhPortaAberta(labirinto, i, j);
    }
    if(!EhParede(labirinto, i, j) && !EstudantePassou(labirinto, i, j) && !EhPortaFechada(labirinto, i, j)){
        MarcarPosicao(labirinto, i, j);
        //itens->quantChave--;
        if(Movimenta_Estudante(labirinto, itens,i - 1, j, linha, coluna,dados,NUM)); // para cima
        else{
            if(Movimenta_Estudante(labirinto, itens, i, j + 1, linha, coluna,dados,NUM)); // para a direita
            else{
                if(Movimenta_Estudante(labirinto, itens, i, j - 1, linha, coluna,dados,NUM)); // para a esquerda
                else{
                    if(Movimenta_Estudante(labirinto, itens, i + 1, j, linha, coluna,dados,NUM)); //para baixo
                    else{
                        return 0;
                    }
                }
            }
        }
    }else{
      return 0;
    }
    return 0; //PUS PARA TIRA WARNING 
}
