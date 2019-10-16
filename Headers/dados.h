#ifndef DADOS_H
#define DADOS_H

typedef struct{
    int quantMovimentacao;
    int temSaida;
    int ultimaColuna;
}TipoDados;

#endif

void IniciarDados(TipoDados *dados);
void ImprimirDados(TipoDados dados);
