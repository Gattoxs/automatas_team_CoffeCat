// Strcatint
 char *strcatint (char *str, int x)
 {
 char z, a[2];
 		z = x;
		a[0] = z;
		a[1] = 0;
     strcat(str, a);
     return str;
 }
//______________________ Guardar ____________________//
bool ex=true;
void guardar(tipo *lista, FILE *Archivo, char res[118][20]){
	tipo n, p=*lista;
	char pala[100], a[100], z, vars[30][100];
	int x,y, i=0, s=0;
	
	
//printf("Archivo original: \n");	
//	while(!feof(Archivo)){
//		fputc(fgetc(Archivo), stdout);
//	}
//printf("\n\nSeparado en: \n");
rewind(Archivo);	
	x = fgetc(Archivo);
	pala[0] = 0;
	if(lista){
		while(!feof(Archivo))
		{ 
		back:
			
		//function
		if(AToken(pala) == 335){
			insertar(&*lista, i, pala, AToken(pala));
			pala[0] = 0;
			for(s = 0; s<30; s++) vars[s][0]='\0';
			s=0;
				if(x == 32){ // espacio despues del funcion para el nombre
					x = fgetc(Archivo);
					
					// Obtenemos el nombre de la funcion hasta encontrar espacio o (
					while(x != 32 && x != 40){  
 					strcatint(pala, x); //Concatenamos un valor INT a la cadena pala
					x = fgetc(Archivo);
					}
					
					a[0]=0;
					strcpy(a, pala);
					pala[0] = 0;
					
					//Avanzamos hasta los parametros de la funcion quitando espacios si es que hay
					while(x != 40){
						x = fgetc(Archivo); 
						if(x != 40 && x != 32){
							printf("Error en la linea %i\n", i+1, pala);
							goto END;
						}
					}
					
					//Obtenemos la cantidad de parametros de la funcion
					x = fgetc(Archivo); 
					
					while(x != 41){
						
						if(x == 36){ // si es igual a $
							while(x != 41 && x != 44){	
							
							strcatint(pala, x);	
							x = fgetc(Archivo); 
							}
							strcpy(vars[s], pala); // se une el argumento al arreglo bidimencional
							s++;
							pala[0] = 0;
							if(x == 44){	// si es igual a ,
								x = fgetc(Archivo);
								
								while(x == 32){
								x = fgetc(Archivo);
								}
								

								if(x != 36){
									printf("Error en la linea %i\n", i+1, pala);
									ex = false;
									goto END;
								}
							}
							
								
						}else{
							
							printf("Error en la linea %i\n", i+1);
							ex = false;
							goto END;
						}
						
						
					}
					
					insertarFuncion(&Funciones, i, a, vars, s);
					insertar(&*lista, i, a, NoF);
					goto next;
				}else{
					printf("Error en la linea %d cerca de function\n", i);
					goto END;
				}				
		}
		
		
		//espacio
		if(x == 32){
			if(strlen(pala) > 1)
			insertar(&*lista, i, pala, AToken(pala));
			x = fgetc(Archivo);
			pala[0] = 0;
			goto back;
		}	
				
		//Salto de linea
		if(x == 10){
			if(strlen(pala) > 1)
			insertar(&*lista, i, pala, AToken(pala));
			i = i + 1;
			x = fgetc(Archivo);
			pala[0] = 0;
			goto back;
		}			
		//Tabulacion
		if(x == 9){
			
			if(strlen(pala) > 1)
			insertar(&*lista, i, pala, AToken(pala));
			x = fgetc(Archivo);
			pala[0] = 0;
			goto back;
		}		
		
		//Parentesis
		if(x == 40 || x == 41){
		if(pala[0] != 0){
			insertar(&*lista, i, pala, AToken(pala));
		}
		pala[0] = 0;
		strcatint(pala, x);
		insertar(&*lista, i, pala, AToken(pala));
		pala[0] = 0;
		x = fgetc(Archivo);
		goto back;
		}
		
		//Numeros
		if(x >= 48 && x <= 57){
			if(strlen(pala) > 1)
			insertar(&*lista, i, pala, AToken(pala));
			pala[0] = 0;
			strcatint(pala, x);
			x = fgetc(Archivo);
			
			while(x >= 48 && x <= 57){
				
				strcatint(pala, x);
				x = fgetc(Archivo);	
			}
			
			insertar(&*lista, i, pala, 306);
			pala[0] = 0;
			goto back;
		}		
		//Comillas
		if(x == 34){
			pala[0] = 34;
			insertar(&*lista, i, pala, 34);
			pala[0] = 0;
			x = fgetc(Archivo);
			while(x != 34){
				
				strcatint(pala, x);
				x = fgetc(Archivo);
			}
			insertar(&*lista, i, pala, 308);
			pala[0] = 0;
			
			strcatint(pala, x);
			insertar(&*lista, i, pala, 34);
			x = fgetc(Archivo);
			pala[0] = 0;
			goto back;
		}
		
		
		//Variable
		if(x == 36){
			strcatint(pala, x);
			y = 0;
			insertar(&*lista, i, pala, 309);
			pala[0] = 0;
			x = fgetc(Archivo);
			z = x;
			a[0] = z;
			a[1] = 0;
			if(x == 97 | x == 98 | x == 99 | x == 100 | x == 101 | x == 102 | x == 103 | x == 104 | x == 105 | x == 106 | x == 107 | x == 108 | x == 109 | x == 110 | x == 111 | x == 112 | x == 113 | x == 114 | x == 115 | x == 116 | x == 117 | x == 118 | x == 119 | x == 120 | x == 121 | x == 122 | x == 65 |x == 66 |x == 67 |x == 68 |x == 69 |x == 70 |x == 71 |x == 72 |x == 73 |x == 74 |x == 75 |x == 76 |x == 77 |x == 78 |x == 79 |x == 80 |x == 81 |x == 82 |x == 83 |x == 84 |x == 85 |x == 86 |x == 87 |x == 89 |x == 90)
			{
			while(x != 9 && x != 32 && x != 61 && x != 45 && x != 43 && x != 47 && x != 34 && x != 59  && x != 58  && x != 123  && x != 125  && x != 91  && x != 94  && x != 40){
				strcatint(pala, x);
				x = fgetc(Archivo);
			}	
			insertar(&*lista, i, pala, 310);
			pala[0] = 0;
			}
			
			goto back;
		}
		
		// Plabras reservadas	
		
		if(x != 10 && x != 32 && x != 34 && x != 36 && x != 9 ){
		//printf("Pala: %s\nX: %c\n",pala, x);
		//system("pause");	
			strcatint(pala, x);
			y = 0;
			
		while(y < 27){
				if(strcmp(pala, res[y]) == 0){
					insertar(&*lista, i, pala, AToken(pala));
					pala[0] = 0;
					goto next;
				}

			y = y + 1;
			
		}

		next:
		x = fgetc(Archivo);
		
		}	

   		}
   	END:
   	 printf("");	
	}
}
