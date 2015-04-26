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

//_______________________Estructura de las funciones________________________________________________//
struct mifunciones
{	
	char funcion[100], vars[30][100] ;
	int renglon;
	int VarsCant;
	int token;
	struct mifunciones *sig;
	struct mifunciones *ant;
};

typedef struct mifunciones nodoF;
typedef nodoF *tipoFuncion;
tipoFuncion Funciones=NULL;
int NoF = 1000;

//____________________ Insertar ___________________________//

void insertarFuncion(tipoFuncion *lista, int renglon, char nombre[100], char variables[30][100], int cant){
	tipoFuncion n, p = *lista;
	int i;
	n=(nodoF *)malloc(sizeof(nodoF));
	n->renglon = renglon+1;
	n->token = NoF;
	n->VarsCant = cant;
	strcpy(n->funcion, nombre);
    for(i = 0;i < cant;i++){
    strcpy(n->vars[i], variables[i]);
	}
	n->sig = NULL;
	n->ant = NULL;
	NoF++;
	
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

//______________________ Imprimir Funciones___________________________//
void imprimirFunciones(tipoFuncion *lista){
	tipoFuncion p = *lista;
	int i;
	while(p != NULL){
		printf("Nombre [%s]\nCantidad de var [%d]\nVariables [", p->funcion, p->VarsCant);
		
		for(i = 0; i < p->VarsCant ;i++)
		printf("%s, ", p->vars[i]);
		
		printf("]\nToken: [%d]\n", p->token);
		p=p->sig;
	}
}











