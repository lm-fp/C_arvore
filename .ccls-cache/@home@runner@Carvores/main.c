#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct NO{
	int num;
	int nivel;
	struct NO *direita;
	struct NO *esquerda;
	
} NO;

NO* criar(NO *raiz, bool criada);
NO* inserir(NO *raiz);
void imprimir();
NO* esvaziar(NO *raiz);
int altura(NO *raiz);

int main(void) {

  


  return 0;
}