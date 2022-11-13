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
void imprimir(NO *raiz);
NO* esvaziar(NO *raiz);
int altura(NO *raiz);
void pre_ordem(NO *raiz);
void ordem(NO *raiz);
void pos_ordem(NO *raiz);
void inserirNO(NO *raiz, int nivel);
NO* criarNO();
NO* procuraraRaiz(NO* raiz, int num);

int main(void) {
  
  NO *raiz;
	bool criada = false;
  int n;

  do{

    printf("---------------------\n");
    printf("Criar:              1\n");
    printf("Inserir:            2\n");
    printf("Imprimir:           3\n");
    printf("Esvaziar:           4\n");
    printf("Altura:             5\n");
    printf("Sair                9\n");
    printf("---------------------\n");
    scanf("%d", &n);
    
    switch(n){

      case 1:
          raiz = criar(raiz,criada);
          criada = true;
        break;

      case 2:
        raiz = inserir(raiz);
        break;
      case 3:
        imprimir(raiz);
        break;

      case 4:
        raiz = esvaziar(raiz);
        printf("Arvore vazia!\n");
        break;

      case 5:
        printf("A altura do arvore é : %d\n", altura(raiz));
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

NO* inserir(NO *raiz){
	
	int opc;
	
	if(raiz == NULL){
		raiz = criarNO();
		inserirNO(raiz, 0);
	}
	
	do{
		
		printf("Deseja inserir novo valor na arvore 1 SIM // 2 NAO: ");
		scanf("%d", &opc);
		
		if(opc == 1){
			NO *novaRaiz = criarNO();
			inserirNO(novaRaiz, -1);
			
			NO *pai = procuraraRaiz(raiz, novaRaiz->num);
			
			if(pai->num < novaRaiz->num){
				pai->direita = novaRaiz;
			}else{
				pai->esquerda = novaRaiz;
			}
			
			novaRaiz->nivel = pai->nivel+1;
			
		}
		
	}while(opc != 2);

	return raiz;
}

void inserirNO(NO *raiz, int nivel){
	
	printf("digite um numero para a arvore:  ");
	scanf("%d", &raiz->num);
	raiz->nivel = nivel;
	raiz->direita = NULL;
	raiz->esquerda = NULL;
	
}

NO* criarNO(){
	return (NO *) malloc(sizeof(NO));
}

NO* procuraraRaiz(NO* raiz, int num){
	
	NO *aux;
	
	if(raiz->num < num){
		aux = raiz->direita;	
	}else{
		aux = raiz->esquerda;	
	}	

	while(aux != NULL){
			
		raiz = aux;
		
		if(aux->num < num){
			aux = raiz->direita;
		}else{
			aux = raiz->esquerda;
		}
		
	}
	
	return raiz;
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
    }printf("\n");
}

NO* esvaziar(NO *raiz){
  if(raiz != NULL){
    esvaziar(raiz->esquerda );
    esvaziar(raiz->direita );
    free(raiz);
  }return NULL;
}

int altura(NO *raiz){
	if(raiz != NULL){
		int n = raiz->nivel;
		int aux;
		aux = altura(raiz->esquerda);
		
		if(aux > n){
			n = aux;
		}
		
		aux = altura(raiz->direita);
		
		if(aux > n){
			n = aux;
      }return n;	
    }return 0;
}

void pre_ordem(NO *raiz){
  if(raiz != NULL){
    printf("%d", raiz->num);
    printf(" | ");
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
  }
}

void ordem(NO *raiz){
  if(raiz != NULL){
    ordem(raiz->esquerda);  
    printf("%d", raiz->num);
    printf(" | ");
    ordem(raiz->direita);
  }
}

void pos_ordem(NO *raiz){
  if(raiz != NULL){
    pos_ordem(raiz->esquerda );
    pos_ordem(raiz->direita );
    printf(" %d ", raiz->num);
    printf(" | ");
  }
}