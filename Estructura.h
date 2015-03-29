//_______________________Estructura de las palabras________________________________________________//
struct milista
{
	int renglon;
	char dato[100];
	int token;
	struct milista *sig;
	struct milista *ant;
};

typedef struct milista nodo;
typedef nodo *tipo;
tipo k=NULL;

//____________________ Insertar ___________________________//

void insertar(tipo *lista, int x, char pala[100], int token){
	tipo n, p = *lista;
	n=(nodo *)malloc(sizeof(nodo));
	n->renglon = x+1;
	n->token = token;
	strcpy(n->dato, pala);
	n->sig = NULL;
	n->ant = NULL;
		if(*lista == NULL)
		*lista = n;
	else
		{
			while(p->sig != NULL)
				p=p->sig;
				p->sig = n;
				n->ant = p;
		}		
	
}


//______________________ Imprimir ___________________________//
void imprimir(tipo *lista){
	tipo p = *lista;
	while(p != NULL){
		printf("[%s, %d, %d]\n", p->dato, p->renglon, p->token);
		p=p->sig;
	}
}
