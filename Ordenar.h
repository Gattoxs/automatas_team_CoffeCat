//______________________ Guardar ____________________//

void guardar(tipo *lista, FILE *Archivo, char res[118][20]){
	tipo n, p=*lista;
	char pala[100], a[100], z;
	int x,y, i=0;
	bool ex=true;
	
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
		
		//Numeros
		if(x >= 48 && x <= 57){
			if(strlen(pala) > 1)
			insertar(&*lista, i, pala, AToken(pala));
			
			pala[0] = 0;
				z = x;
				a[0] = z;
				a[1] = 0;
				strcat(pala, a);
			x = fgetc(Archivo);
			while(x >= 48 && x <= 57){
				z = x;
				a[0] = z;
				a[1] = 0;
				strcat(pala, a);
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
				z = x;
				a[0] = z;
				a[1] = 0;
				strcat(pala, a);
				x = fgetc(Archivo);
			}
			insertar(&*lista, i, pala, 308);
			pala[0] = 0;
			z = x;
			a[0] = z;
			a[1] = 0;
			strcat(pala, a);
			insertar(&*lista, i, pala, 34);
			x = fgetc(Archivo);
			pala[0] = 0;
			goto back;
		}
		
		
		//Variable
		if(x == 36){
			z = x;
			a[0] = z;
			a[1] = 0;
			strcat(pala, a);
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
				z = x;
				a[0] = z;
				a[1] = 0;
				strcat(pala, a);
				x = fgetc(Archivo);
			}	
			insertar(&*lista, i, pala, 310);
			pala[0] = 0;
			}
			
			goto back;
		}
			
		if(x != 10 && x != 32 && x != 34 && x != 36 && x != 9 ){	
			z = x;
			a[0] = z;
			a[1] = 0;
			strcat(pala, a);
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
	}
}

