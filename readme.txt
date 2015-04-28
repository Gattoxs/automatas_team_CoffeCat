El codigo esta programado en el copilador Dev C++
En algunos otros compiladores es muy probable que marque error en las funciones
system("pause");
system("cls");

Se estra trabajando en su correcion para uso general.

Funcion pareas:
  Con parametro para recibir el token que deba de seguir y comparar si es el mismo en el que estamos
    si lo es:
      avanzamos una pocicion de nuestra lista 'k'
      y retorna un 1/positivo
    De lo contrario:
      Nos arroja el error (Renglon, cerca de)
      y retorna un 0/negativo

Una vez teniendo nuestra lista creada la pasaremos a una lista global 'k'
Empesaremos el recorrido de la lista 'k' con un ciclo:
  revisando los token de cada nodo en un switch
    dependiendo el caso en el que entre evaluaremos de la siguiente manera
      
      
      Si entra al token de '$' (309)
        entonces:
        avanza nuestra lista
          despues comparamos con pareas si..
          sigue una variable? (310)
          sigue un punto y coma? (9)
        si todo esto es positivo entonces:
          retrocedemos nuestra lista e iremos al ciclo de nuevo
        De lo contrario el programa nos arrojara el renglon, y cerca de que esta dicho error, despues termina el programa
        
      Si entra al token de 'echo' (317)
        entonces:
        avanza nuestra lista
          despues comparamos con pareas si..
          sigue punto y coma? (34)
          sigue una cadena? (308)
          sigue punto y coma? (34)
          sigue un punto y coma? (9)
        si todo esto es positivo entonces:
          retrocedemos nuestra lista e iremos al ciclo de nuevo
        De lo contrario el programa nos arrojara el renglon, y cerca de que esta dicho error, despues termina el programa
        
Si no se encontro ningun error el programa nos desplejara un mensaje que todo salio bien.
        
    
