#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "utnInPuts.h"



#define MAXIMOPASAJEROS 16
#define MAXIMOVUELOS 8
#define MINIMOOPCION 1
#define MAXIMOOPCION 13
#define ESTADOVUELOACTIVO 0
#define ESTADOVUELOCANCELADO 1

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
int main()
{
	setbuf(stdout, NULL);
	int salir;

    int opcion;
    int retorno;
    char nombreArchivo[51];
	char direc[51]="C:\\RecuSegundoParcial\\";
    LinkedList* listaEntradas = ll_newLinkedList();
    LinkedList* listaParaClonar = NULL;

    do{
    	if(utnGetNumero(&opcion,
    			"\nOpcion 1: Cargar los datos desde archivo csv (modo texto).\n"
    			"\nOpcion 2: Imprimir Ventas:"
    			"\nOpcion 3: Generar archivo de montos:"
    			"\nOpcion 5 : salir\n"

    			,"", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", MINIMOOPCION,
				MAXIMOOPCION, REINTENTOS)==RETORNOPOSITIVO)
    	{
    	 	switch(opcion)
			{
    	 	case 1:
    	 		if(utnIngresarAlfanumerico(nombreArchivo, "Ingrese el nombre del archivo a abrir con su extencion\n", 3, 51)==0)
    	 		{
    	 			strncat(direc,nombreArchivo,51);
    	 			retorno=controller_loadFromText(direc, listaEntradas);
    	 			if(retorno==RETORNONEGATIVO)
    	 			{
    	 				printf("\nNo se pudo abrir el archivo csv.\n");
    	 			}
    	 			else
    	 			{
    	 				puts("Archivo cargado Ok");
    	 			}
    	 		}
    	 		break;
    	 	case 2:
    	 		if(ll_isEmpty(listaEntradas)==RETORNOPOSITIVO)
    	 		{
    	 			controller_ListPeliculas(listaEntradas);
    	 		}
    	 		else
    	 		{
    	 			puts("Primero debe cargar la lista");
    	 		}


    	 		break;
    	 	case 3:
    	 		if(ll_isEmpty(listaEntradas)==RETORNOPOSITIVO)
    	 		{
        	 		listaParaClonar=ll_map(listaEntradas, calcu_calculaMonto);
        	 		if(controller_saveAsText("C:\\RecuSegundoParcial\\Nuevo.csv",listaParaClonar)==0)
        	 		{
        	 			puts("Guardado Ok");
        	 		}
    	 		}
    	 		else
    	 		{
    	 			puts("Primero debe cargar la lista");
    	 		}


    	 		break;
    	 	case 4:
    	 		/*
    	 		 * 4.Informes: El usuario ingresará el número de sala y se imprimirá por pantalla:

			  	  	  Cantidad de entradas vendidas para la sala.
					  Monto total facturado para la sala.
				   	  Listado de películas que se proyectaron en dicha sala (sin repetir).
    	 		 */

    	 		if(utnGetNumero(&opcion, "Ingrese la sala a listar \n0-Para salir\n"
    	 				, "Error al ingresar opcion\n", "Desea salir ?", 1, 3, 3)==RETORNOPOSITIVO)
    	 		{

    	 		}
    	 		break;
    	 	case 5:
				if(utnVerificacionConChar("Realmente desea salir ? Ingrese Si para salir\nATENCION, SI NO GUARDO EL ARCHIVO, EL MISMO SE PERDERA\n",
						"Adios\n", "Sigue el programa", 0)==RETORNOPOSITIVO)
				{
					salir=-2;
					ll_deleteLinkedList(listaEntradas);
					ll_deleteLinkedList(listaParaClonar);
				}
				break;

			default:
				puts("Error en la seleccion\n");
				break;

			}//Fin Switch

    	}//Fin if elegir opcion
    	else
    	{
    		puts("\n Adios \n");
    		salir=-2;
    	}

    	//Clonado lista inicial
    	if(listaParaClonar == NULL )
    	{
    		listaParaClonar=ll_clone(listaEntradas);

    	}

    }while(salir!=-2);



    return 0;
}

