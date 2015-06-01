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

//_______________________Estructura de los tipos de datos________________________________________________//
struct typelista
{
	int  renglon;
	char variableName[100];
	char value[100];
	int  token;
	int called;
	struct typelista *sig;
	struct typelista *ant;
};

typedef struct typelista typenodo;
typedef typenodo *typelist;
typelist types=NULL;

//____________________ Insertar ___________________________//

void insertarType(typelist *lista, int x, char name[100], int token, char value[100]){
	typelist n, p = *lista;
	n=(typenodo *)malloc(sizeof(typenodo));
	n->renglon = x+1;
	n->token = token;
	n->called = 0;
	strcpy(n->variableName, name);
	strcpy(n->value, value);
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
void imprimirTypes(typelist *lista){
	typelist p = *lista;
	while(p != NULL){
		printf("[(%d) %s = %s, %d]\n", p->token, p->variableName, p->value, p->renglon);
		p=p->sig;
	}
}

//_______________________   V   A   R   C   M   P ____________________________________________//

//This function compare the given variable's name with the rest of declared variables before. If the variable's name is already used the function will return 0, else return 1
int varcmp(char *var){
	typelist s = types;

	while(s){
		if(strcmp(var, s->variableName) == 0){		
			return 0;
		}
		s = s->sig;
	}
	return 1;
}

int vartype(char *var){
	typelist s = types;

	while(s){
		if(strcmp(var, s->variableName) == 0){		
			return s->token;
		}
		s = s->sig;
	}
	return 0;
}

int decvarcmp(char *var){
	typelist s = types;

//This functions indicate the number of variables' declared
	while(s){									//End while end of the variables list
		if(strcmp(var, s->variableName) == 0){	//Check if the variable name are in the variable list
			s->called++;						//Aument the number of calleds of variable
			if(s->called > 1)					//If called are more than 1, so the variable was declared before
				return 0;
			else 								//Else, this variable wasn't declared or are declaring
				return 1;
		}
		s = s->sig;
	}
	return 1;
}
			








