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

void guardar(tipo *lista, FILE *Archivo){
	tipo n, p=*lista;
	char pala[100], a[100], z, vars[30][100], name[100], value[100];
	int x,y, i=0, s=0, type=0, dot=0, eq=0;
	
//printf("Archivo original: \n");	
//	while(!feof(Archivo)){
//		fputc(fgetc(Archivo), stdout);
//	}
//printf("\n\nSeparado en: \n");
rewind(Archivo);	
	x = fgetc(Archivo);
	pala[0] = 0;
	
	if(lista){
		while(!feof(Archivo)){ 
		
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
			// MATH SENTENCES
			// < = > ! & % * + - / ^ [ ] { } | , . ;
			if( x == 60 || x == 61 || x == 62|| x == 33 || x == 37 || x == 38 || x == 42 || x == 43 || x == 45 || x == 47 || x == 94 || x == 91 || x == 93 || x == 123 || x == 125 || x == 124 || x == 44 || x == 46 || x == 59 ){
				if(strlen(pala))
					insertar(&*lista, i, pala, AToken(pala));
				pala[0] = 0;
				strcatint(pala, x);
				insertar(&*lista, i, pala, AToken(pala));
				pala[0] = 0;
				x = fgetc(Archivo);
				goto back;
			}
			
			//espacio
			if(x == 32){
				
				if(strlen(pala) >= 1)
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
			
			insertar(&*lista, i, pala, 89);
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
			insertar(&*lista, i, pala, 88);
			pala[0] = 0;
			
			strcatint(pala, x);
			insertar(&*lista, i, pala, 34);
			x = fgetc(Archivo);
			pala[0] = 0;
			goto back;
		}
		
			// Plabras reservadas	
			if(x != 10 && x != 32 && x != 34 && x != 9 && x != 40  && x != 41 ){
							
				strcatint(pala, x);
				y = 0;
			
			//Variable
			if(AToken(pala) == 51 || AToken(pala) == 52 || AToken(pala) == 53 || AToken(pala) == 54 ){
			
			//						          Char                       INT                       FLOAT                     DOUBLE
			switch(AToken(pala)){  case 51: type=51; break;   case 52: type=52; break;   case 53: type=53; break;  case 54: type=54; break;} 
			x = fgetc(Archivo);
			if(x == 32){
				insertar(&*lista, i, pala, AToken(pala));
				pala[0] = 0;
				
				variablename:
					name[0] = 0;
				//Removing spaces
				while(x == 32)
					x = fgetc(Archivo);
					
				//Name of variable(s)
				
				if(x >= 48 && x <= 57){
					ex=false;
						printf("Sorry but variable names cant start with numbers.");
						goto END;
				}
				
				//           SPACE    =          ,          [         ;
				while( x != 32 && x != 61 && x != 44 && x != 91 && x != 59){
					
					
					if(x >= 65 && x <=90 || x >= 97 && x <=122 || x >= 48 && x <= 57){ //This condition indicates that the variables' name are only letters
					
						strcatint(pala, x);
						x = fgetc(Archivo);	
					}else{
						if(x != 32 || x == 61 || x != 44 || x != 59){//If the condition is false, the varible 'ex' indicates that an error was found in the code
						ex=false;
						printf("Sorry but you can't asign special caracters to variable name.");
						goto END;
						}
					}
				}
				
				//Insert the variable name to the list with the Token #87
				insertar(&*lista, i, pala, 87);	
				strcpy(name, pala);				
				pala[0] = 0;
				
				//After variable name
				aftervariablename:
				switch(x){
					
					//Removing spaces
					case 32:
						while(x == 32)
							x = fgetc(Archivo);
						goto aftervariablename;	
					break;	
					
					//Equal
					case 61:
						eq=1;
						strcatint(pala, x);
						insertar(&*lista, i, pala, AToken(pala));	
						x = fgetc(Archivo);
						pala[0] = 0;
						//Removing spaces
						while(x == 32)
							x = fgetc(Archivo);
							
						switch(x){
							
							case 34:
								//If the variable is char can asign strings 
								if(type == 51){
									strcatint(pala, x);
									insertar(&*lista, i, pala, AToken(pala));	
									x = fgetc(Archivo);
									pala[0] = 0;
									//Getting whole string
									while(x != 34){
										strcatint(pala, x);
										x=fgetc(Archivo);
									}
								
									//After String
									insertar(&*lista, i, pala, 88);	
									insertarType(&types, i, name, 89, pala);
									pala[0] = 0;
									strcatint(pala, x);
									insertar(&*lista, i, pala, AToken(pala));	
									x = fgetc(Archivo);
									pala[0] = 0;
									goto aftervariablename;
									
								//Else will end the code with the error mark
								}else{
									ex=false;
									printf("Its not char type.");
									goto END;
								}
								
							break;
							
							case 48: // 0
							case 49: // 1
							case 50: // 2
							case 51: // 3
							case 52: // 4
							case 53: // 5
							case 54: // 6
							case 55: // 7
							case 56: // 8
							case 57: // 9
							case 46: // .
								if(type == 52 || type == 53 || type == 54){
									
									//While x get the value of , or ;
									while(x != 44 && x != 59){
									
										//If the x value is number or dot, continue, else error
										if(x >= 48 && x <= 57 || x == 46){
											
											//Concat the value
											strcatint(pala,x);
											x = fgetc(Archivo);
											
											//If the value have decimal
											if(x == 46){
												
												//Increase the dot count
												dot++;
												//If the value of dot is more than 1 or the type of the variable is INT make the error
												if(dot > 1 || type == 52){
													ex=false;
													printf("So many dots in the value.");
													goto END;
												}
											}
											
										}else{
											ex=false;
											printf("Error");
											goto END;
										}									
									}
										
									//After getting the whole value
									
									insertar(&*lista, i, pala, 89);	
									strcpy(value, pala);
									
									if(type == 52) //INT
										insertarType(&types, i, name, 90, value);
									
									if(type == 53) //FLOAT
										insertarType(&types, i, name, 91, value);
									
									if(type == 54) //double
										insertarType(&types, i, name, 92, value);
									
									pala[0] = 0;
									dot = 0;
									goto aftervariablename;
									
									
									
								}else{
									ex=false;
									printf("Error");
									goto END;
								}
								
							break;
						}
						
					break;	
					
					//Coma
					case 44:
						if(!eq){
								
							if(type==51){
								insertarType(&types, i, name, 89, "");
						
							}else{
								if(type == 52) //INT
									insertarType(&types, i, name, 90, "0");
								
								if(type == 53) //FLOAT
									insertarType(&types, i, name, 91, "0");
								
								if(type == 54) //double
									insertarType(&types, i, name, 92, "0");
							}
						}
						
						eq=0;
						strcatint(pala, x);
						insertar(&*lista, i, pala, AToken(pala));	
						x = fgetc(Archivo);
						pala[0] = 0;
						goto variablename;
						
					break;		
						
					//DotComa					
					case 59:
						if(!eq){
								
							if(type==51){
								insertarType(&types, i, name, 89, "");
						
							}else{
								
								if(type == 52) //INT
									insertarType(&types, i, name, 90, "0");
								
								if(type == 53) //FLOAT
									insertarType(&types, i, name, 91, "0");
								
								if(type == 54) //double
									insertarType(&types, i, name, 92, "0");
							}
						}
						
						eq=0;
						strcatint(pala, x);
						insertar(&*lista, i, pala, AToken(pala));	
						pala[0] = 0;
						goto next;
						
					break;	

					default:
						ex=false;
						printf("\nSyntax error!\n On line [%d] near to [%s]\n", i+1, pala);
						goto END;
						break;
						
				}
			}
		}				
				while(y < 80){
					if(strcmp(atoken[y].carc, pala) == 0){
						if(AToken(pala) == 51 || AToken(pala) == 52 || AToken(pala) == 53 || AToken(pala) == 54 ){}
					
						insertar(&*lista, i, pala, AToken(pala));
						pala[0] = 0;
		
					}
					y++;
				}
					
	
			}
			
				next:
			x = fgetc(Archivo);			
			
   		}
   	END:
   	 printf("");
			
	}
}
