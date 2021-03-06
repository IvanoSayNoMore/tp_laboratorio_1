#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "utnInPuts.h"
#include "puntosDeMenu.h"

#define MAXIMOPASAJEROS 16
#define MAXIMOVUELOS 8
#define MINIMOOPCION 1
#define MAXIMOOPCION 10
#define ESTADOVUELOACTIVO 0
#define ESTADOVUELOCANCELADO 1

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).

    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout, NULL);
	int salir;
	int opcionGuardar = -1 ;

    int opcion;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	if(utnGetNumero(&opcion,
    			"\nOpcion 1: Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"Opcion 2: Cargar los datos de los pasajeros desde el archivo data.csv (modo binario) \n"
    			"Opcion 3: Alta de pasajero\n"
    			"Opcion 4: Modificar datos de pasajero\n"
    			"Opcion 5: Baja de pasajero\n"
    			"Opcion 6: Listar pasajeros\n"
    			"Opcion 7: Ordenar \n"
    			"Opcion 8: Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    			"Opcion 9: Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    			"Opcion 10: Salir\n"
    			,"", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", MINIMOOPCION,
				MAXIMOOPCION, REINTENTOS)==RETORNOPOSITIVO)
    	{
    	 	switch(opcion)
			{
			case 1://Carga .csv
				if(menu_cargaDatosPasajerosDesdeCsv("data.csv",listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("\nEl archivo se ha cargado con exito");
				}
				else
				{
					puts("\nOcurrio un error al leer el archivo  \n");
				}
				break;

			case 2:
				if(menu_cargaDatosPasajerosDesdeBinario("data.bin",listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("El archivo se ha cargado con exito binario");
				}
				else
				{
					puts("Ocurrio un error al leer el archivo ");
				}

				break;

			case 3://Alta manual
				if(menu_altaPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Operacion realizada con exito");
				}
				else
				{
					puts("Ocurrio un error en la carga de datos del pasajero");
				}

				break;

			case 4://
				if(menu_modificarPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Operacion realizada con exito");
				}
				else
				{
					puts("Ocurrio un error en la modificacion de datos del pasajero");
				}


				break;

			case 5://
				 if(menu_eliminarPasajero(listaPasajeros)==RETORNOPOSITIVO)
				 {
					 puts("Se ha eliminado con exito");
				 }
				 else
				 {
					 puts("Ocurrio un error al eliminar pasajero");
				 }
		        break;

			case 6://
				if(controller_ListPassenger(listaPasajeros)==RETORNONEGATIVO)
				{
					puts("Debe cargar datos antes de poder imprimir algo");
				}

				break;

			case 7://Ordenar
				if(menu_ordenarPasajero(listaPasajeros)==-2)
				{
					puts("Debe cargar datos antes de poder imprimir algo");
				}
				break;

			case 8:
				if(menu_guardarArchivoCsv(listaPasajeros)==RETORNOPOSITIVO)
				{
					opcionGuardar = 0;
				}

				break;
			case 9:
				if(controller_saveAsBinary("Data.bin",listaPasajeros)==RETORNOPOSITIVO)
				{
					opcionGuardar = 0;
				}
				break;
			case 10:
				if(utnVerificacionConChar("Realmente desea salir ? Ingrese Si para salir", "Se cierra el programa\n", "Sigue el programa", 0)==RETORNOPOSITIVO)
				{
					salir=-2;
					if(opcionGuardar == 0 )
					{
						ll_clear(listaPasajeros);
						ll_deleteLinkedList(listaPasajeros);
					}

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

    }while(salir!=-2);



    return 0;
}

