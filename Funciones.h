#include"Pilas.h"
#include"Tokens.h"
#include"Estructura.h"
//_______________________	P	a	r	e	a ________________________________________________//

int parea(int ntoken){
	if(ntoken==k->token)
		return 1;
	else
		return 0;
}

int pareas (int ntoken){
	if (ntoken==k->token){
		k=k->sig;
		return 1;
		
	}else{
		printf("Error en la linea [%d] cerca de %s\n", k->renglon, k->dato);
		//if(k-> token!=111)
		//	printf("------     token= %d \n",k->token);
	}
	return 0;
}

// ERROR
int error(char *msj){
	system("cls");
	printf("Error en la linea %d cerca de '%s' \n%s\n", k->renglon, k->dato, msj);
	return 0;
}

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
	//             +                 -                 (                var               #
	if(k->token != 13 && k->token != 16 && k->token != 4 && k->token != 87 && k->token != 89){
		goto ERR;
	}
	
	
	
    //                ;                >                 <                 =                 )  	          |                 &	              ,
	while(k->token != 9 && k->token != 30 && k->token != 28 && k->token != 26 && k->token != 5 && k->token != 32 && k->token != 37 && k->token != 10 ){ 					
		start:

		if(k->token == 89 || k->token == 87){  		        // Si es # || $var
		
			if(k->token==87){ //If the next token its variable, 
				
 				if(!varcmp(k->dato)){ //If the variables was declared
 				
					if(vartype(k->dato)!=89){ // if the variables is diferent of char type
						//Continue
						goto continues;
					}else{
						
						goto ERR;
					}
				}else{
					
					goto ERR;
				}
			}
				continues:
			meterpila(&salida, k->dato);                        // Lo metemos a la salida # o var	
		}
		else							//De lo contrario
			//             +                 -                 *                 /                 (                )
			if(k->token == 13 || k->token == 16 || k->token == 20 || k->token == 22 || k->token == 4 || k->token == 5){//if is op(+ - / *)	
				
				
				switch(k->token){
					case 13:						// Sum 
					case 16:						// Rest
						meterpila(&aux, k->dato);	           // Withdraw in aux
						break;	
					case 20:					   // Multiplication
					case 22:		      		   // te amo gatito <3.<3 Divicion
				 
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
		if(k->token == 5){						// )
			k=k->sig;							// sig dato
			if(k->token == 13 || k->token == 16 || k->token == 20 || k->token == 22 || k->token == 4 || k->token == 5){
				k=k->ant;						// if the exp math continue, return to )
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
