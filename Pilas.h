#include<stdio.h>
#include<stdlib.h>


struct nodeP{
   char info[100];
   struct nodeP *sig;    
};

typedef struct nodeP nodoP;
typedef nodoP *tipopila;

/////////////////////// M E T E R    P I L A  ///////////////

void meterpila (tipopila *A, char x[]){
	tipopila n;
				
	n=(nodoP *)malloc(sizeof(nodoP));
	strcpy(n->info, x);
    n->sig = NULL;
    
	n->sig = *A;	
	*A = n;	
}

/////////////////////// S A C A R    P I L A ////////////////

char* sacarpila (tipopila *pila){
	char x[100];
	x[0] = 0;
	tipopila p=*pila;
	
													
	strcpy(x, p->info);	
	*pila=p->sig;
	free(p);
	x[strlen(x)] = 0;
	return x;
}

/////////////////////// I M P R I M I R ///////////////////////
void imprimirpila(tipopila pila){
	tipopila p=pila;
	
	while(p)				
	{
		printf("%s, ",p->info); 
		p=p->sig;
	}

}






