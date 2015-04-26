#include"Pilas.h"
#include"Tokens.h"
#include"Estructura.h"

//ExpMath	POSTFIJA
int ipa=0;
char *ExpMath(char *postfija){
	char subs[100];
	subs[0] = 0;
	int i=0;
	tipopila salida = NULL, aux = NULL;
	char par[5][5];
	
	par[0][0] = 42; par[0][1] = 0; // * 
	par[1][0] = 47; par[1][1] = 0; // /
	par[2][0] = 40; par[2][1] = 0; // (
	par[3][0] = 41; par[3][1] = 0; // )
	
	// Error
	//Falta agregar el token de las funciones
	if(k->token != 15 && k->token != 14 && k->token != 4 && k->token != 306 && k->token != 36 && k->token != 309){

		goto ERR;
	}
	
	
	
		
	while(k->token != 9 && k->token != 1 && k->token != 2 && k->token != 3 && k->token != 5){ 					
		start:

		if(k->token == 306 || k->token == 309){  		        // Si es # || $var
			if(k->token == 309){
				meterpila(&salida, k->dato);                    // Metemos $
				k=k->sig;
			}
			meterpila(&salida, k->dato);                        // Lo metemos a la salida # o var	
			
		}
		else							//De lo contrario
			if(k->token == 14 || k->token == 15 || k->token == 16 || k->token == 17 || k->token == 4 || k->token == 5){//if is op(+ - / *)	
				
				
				switch(k->token){
					case 14:						// Sum 
					case 15:						// Rest
						meterpila(&aux, k->dato);	           // Withdraw in aux
						break;	
					case 16:					   // Multiplication
					case 17:		      		   // te amo gatito <3.<3 Divicion
				 
						if(aux == NULL){					   // If aux is NULL
							meterpila(&aux, k->dato);		   // Lo metemos directo a la pila
							
						}else{								   // De lo contrario
										
							while(aux != NULL){				   // Sacamos los valores de la pila aux y los metemos a la salida hasta que encuentre un * / ( o este vacia aux 
							 if(strcmp(aux->info, par[0]) == 0 || strcmp(aux->info, par[1]) == 0 || strcmp(aux->info, par[2]) == 0) //Si es '*' '/' '('
							 {goto next;}               	   // Al encontrar un * / ( en la pila saldra del ciclo y se ira a la etiqueta next	
							
								strcpy(subs, sacarpila(&aux)); // Le asignamos a la variable 'subs' el valor primer valor de la pila aux y lo borramos de la pila
								meterpila(&salida, subs);	   // Lo metemos a la salida
								subs[0] = 0;				   // Limpiamos la variable subs
							 	
							 }
							 
							next:								// label next
							meterpila(&aux, k->dato); 			// Metemos el dato a la pila aux ya sea / o *
							subs[0] = 0;	 					// Limpiamos la variable subs
						}
						
						break;
					
					case 4:						// parentecis (
						meterpila(&aux, k->dato);			    // Lo metemos directo a la pila auxiliar
						
						break;
					case 5:					    // Parentecis )
						
						while(strcmp(aux->info, par[2]) != 0){ // Comparamos si es un (
							if(aux == NULL)					   // Si no se encuentra el ( y la pila auz esta vacia ya, no llevara a la etiqueta ERR (error)
								goto ERR;					
										
							subs[0] = 0;					   // Limpiamos la variable subs
							strcpy(subs, sacarpila(&aux));	   // Le asignamos a la variable 'subs' el valor primer valor de la pila aux y lo borramos de la pila
							meterpila(&salida, subs);          // Lo metemos a la salida
							
							if(strcmp(aux->info, par[2]) == 0){// Si el primer valor de la pila aux es igual a ( entonces
								sacarpila(&aux);			   // Lo sacamos y eliminamos de la pila
							break;							   // Terminamos el caso '5'
							}
						}
						
						break;
						
					default:
						break;
					
				}														
			}
				
			else{
				
				system("cls");
				ERR: 											// Etiqueta para los errores dentro del switch
				printf("Error en la lineDa %d cerca de %s\n", k->renglon, k->dato);
				goto END;											// Termina el programa
				
			}
	
	k=k->sig;									// Avanzamos al siguiente dato
		if(k->token == 5){
			k=k->sig;	
			if(k->token == 14 || k->token == 15 || k->token == 16 || k->token == 17 || k->token == 4 || k->token == 5){
				k=k->ant;
				goto start;
			}
				

			k=k->ant;
		}
			
	
	}	
	ipa++; subs[0] = 0;
		while(aux){							    // Sacamos todos los valores que se encuentren en la pila aux 	
			strcpy(subs, sacarpila(&aux));		// Le asignamos a la variable 'subs' el valor primer valor de la pila aux y lo borramos de la pila
			meterpila(&salida, subs);			// Lo metemos a la salida
			subs[0] = 0;						// Limpiamos la variable subs
							 	
		}
	
	
	
	char mi[100]; mi[0]=0;
	while(salida){
		strcpy(mi, sacarpila(&salida));
		strcat(postfija, mi);
		i++;
	}
	
	return postfija;
	END:
	return NULL;
}	
