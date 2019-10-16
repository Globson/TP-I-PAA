#include "../Headers/dados.h"
#include <stdio.h>
#include <stdlib.h>

void IniciarDados(TipoDados *dados){
  dados->quantMovimentacao = -1; // começamos com -1 para desconsiderar a movimentação de quando ele está parado
  dados->ultimaColuna = -1;
  dados->temSaida = 0;
}
void ImprimirDados(TipoDados dados){
    printf("\nO estudante se movimentou %d vezes ", dados.quantMovimentacao);
    if(dados.temSaida == 1) {
      printf("e chegou na coluna %d da primeira linha.\n", dados.ultimaColuna);
    }
    else{
      printf("e percebeu que o labirinto nao tem saida.\n");
    }
}
