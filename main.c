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
void inserir(NO *raiz, int numero);
void imprimir(NO *raiz);
NO* esvaziar(NO *raiz);
int altura(NO *raiz);
void pre_ordem(NO *raiz);
void ordem(NO *raiz);
void pos_ordem(NO *raiz);

int main(void) {
  
  NO *raiz;
	bool criada = false;
  int n;

  do{

    printf("---------------------\n");
    printf("Criar:              1\n");
    printf("Inserir:            2\n");
    printf("Imprimir:           3\n");
    printf("");
    printf("Sair                9\n");
    printf("---------------------\n");
    scanf("%d", &n);
    
    switch(n){

      case 1:
          raiz = criar(raiz,criada);
          criada = true;
        break;

      case 2:
        {
          int numero;
          printf("Escreva seu numero: \n");
          scanf("%d", &numero );
          inserir(raiz,numero);
        break;
          }
      case 3:
        imprimir(raiz);
        break;

      case 4:
        
        break;

      case 5:
        
        break;

      default:

        break;

      
    }
    
  }while(n != 9);
  
  return 0;
}

NO* criar(NO *raiz, bool criada){
	
	if(!criada){
    printf("Criação da Raiz da Arvore\n");
		return NULL;
	}
	
	printf("Raiz da arvore ja criada\n");
	
	return raiz;
	
}

 void inserir(NO *raiz , int numero){
if (raiz == NULL)
{
  raiz=(NO *)malloc(sizeof(NO));
  raiz->esquerda=NULL;
  raiz->direita=NULL;
  raiz->num = numero;
  }
  else{
    if (numero < raiz->num){
        inserir(raiz->direita, numero);
    }else{
        inserir(raiz->esquerda, numero);     
    }
  }
}
void imprimir(NO *raiz){
  int x;
  printf("\n---------------------------------\n");
  printf("1 - Para imprimir em Pré-Ordem\n");
  printf("2 - Para imprimir em Ordem\n");
  printf("3 - Para imprimir em Pós-Ordem\n");
  printf("Digite qualquer outro numero para voltar\n");
  printf("---------------------------------\n");
  scanf("%d", &x);
  switch(x){
    case 1:
      pre_ordem(raiz);
    break;
    case 2:
      ordem(raiz);
    break;
    case 3:
      pos_ordem(raiz);
    break;
    default:
      printf("Voltando...");
    break;
    }
}

NO* esvaziar(NO *raiz){

  
}

int altura(NO *raiz){

  return 0;
}

void pre_ordem(NO *raiz){
  if(raiz != NULL){
    printf("%d", raiz->num);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
  }
}

void ordem(NO *raiz){
  if(raiz != NULL){
    ordem(raiz->esquerda);
    printf("%d", raiz->num);
    ordem(raiz->direita);
  }
}

void pos_ordem(NO *raiz){
  if(raiz != NULL){
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d", raiz->num);
  }
}