#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "dados.h"

typedef struct{
    int quantChave;
}TipoItem;

typedef int ** Labirinto;

int ** IniciarLabirinto(int linha, int coluna, TipoItem *itens,int quantChave);
void InserirPosicao(int ** labirinto, int linha, int coluna, int valor);
int EstudantePassou(int ** labirinto, int linha, int coluna);
int EstudanteEsta(int ** labirinto, int linha, int coluna);
int LinhaEstudante(int ** labirinto, int linha, int coluna);
int ColunaEstudante(int ** labirinto, int linha, int coluna);
int EhParede(int ** labirinto, int linha, int coluna);
void EhPortaAberta(int ** labirinto, int linha, int coluna);
int EhPortaFechada(int **labirinto, int linha, int coluna);
int Movimenta_Estudante(int ** labirinto,TipoItem *itens, int x, int y, int linha, int coluna, TipoDados *dados);
void ImprimirLabirinto(int ** labirinto, int linha, int coluna);

#endif
