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
  
  NO *raiz;
	bool criada = false;
  int n;

  do{

    printf("-----------------------------");

    printf("-----------------------------");
    

    switch(n){

      case 1:
          raiz = criar(raiz,criada);
          criada = true;
        break;

      case 2:
         
        
        break;

      case 3:
        
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
		return NULL;
	}
	
	printf("Raiz da arvore ja criada");
	
	return raiz;
	
}

NO* inserir(NO *raiz){
  

}

void imprimir(){

  
}

NO* esvaziar(NO *raiz){
  
}

int altura(NO *raiz){

  return 0;
}