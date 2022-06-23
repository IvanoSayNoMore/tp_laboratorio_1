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
#define MAXIMOOPCION 11
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
	int flagCarga = -1;
    int opcion;
    int valida;
    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaParaClonar = NULL;

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
				if(menu_cargaDatosPasajerosDesdeCsv("data.csv",listaPasajeros)==RETORNOPOSITIVO && flagCarga == -1)
				{
					puts("\nEl archivo se ha cargado con exito");
					flagCarga = 0;
				}
				else
				{
					puts("\nOcurrio un error al leer o cargar el archivo.\nRecuerde que solo puede cargar el archivo solo 1 vez\n");
				}
				break;

			case 2:
				if(menu_cargaDatosPasajerosDesdeBinario("data.bin",listaPasajeros)==RETORNOPOSITIVO && flagCarga == -1)
				{
					puts("El archivo se ha cargado con exito binario");
					flagCarga = 0;
				}
				else
				{
					puts("Ocurrio un error al leer o cargar el archivo.\nRecuerde que solo puede cargar el archivo solo 1 vez \n");
				}

				break;

			case 3://Alta manual
				if(menu_altaPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Operacion realizada con exito\n");
				}
				else
				{
					puts("Ocurrio un error en la carga de datos del pasajero\n");
				}

				break;

			case 4://
				if(menu_modificarPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Operacion realizada con exito\n");
				}
				else
				{
					puts("Ocurrio un error en la modificacion de datos del pasajero\n");
				}

				break;

			case 5://
				if(menu_eliminarPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Se ha eliminado con exito\n");
				}
				else
				{
					puts("Ocurrio un error al eliminar pasajero\n");
				}

			 break;

			case 6://
				if(controller_ListPassenger(listaPasajeros)==RETORNONEGATIVO)
				{
					puts("Debe cargar datos antes de poder imprimir algo\n");
				}

				break;

			case 7://Ordenar
				if(menu_ordenarPasajero(listaPasajeros)==-2)
				{
					puts("Debe cargar datos antes de poder imprimir algo\n");
				}
				break;

			case 8:
				if(menu_guardarArchivoCsv(listaPasajeros)==RETORNOPOSITIVO)
				{
					opcionGuardar = 0;
				}

				break;
			case 9:
				if(menu_guardarArchivoBinario(listaPasajeros)==RETORNOPOSITIVO)
				{
					opcionGuardar = 0;
				}

				break;

			case 10:
				if(utnVerificacionConChar("Realmente desea salir ? Ingrese Si para salir\nATENCION, SI NO GUARDO EL ARCHIVO, EL MISMO SE PERDERA\n",
						"Adios\n", "Sigue el programa", 0)==RETORNOPOSITIVO)
				{
					salir=-2;

					if(opcionGuardar == 0 )
					{
						valida=ll_containsAll(listaPasajeros,listaParaClonar);

						if(listaParaClonar != NULL && (valida!=1))
						{
							if(utnVerificacionConChar("\n WARNING \n Se han borrado datos del archivo origianl . Desea guardar una copia del antiguo ? ",
									"Adios\n", "Se guarda una copia del antiguo archivo como dataBKP ", 0)==RETORNOPOSITIVO)
							{
								controller_saveAsText("dataBKP.csv",listaParaClonar);
							}

						}
					}

					ll_deleteLinkedList(listaPasajeros);
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
    	if(listaParaClonar == NULL && flagCarga == 0)
    	{
    		listaParaClonar=ll_clone(listaPasajeros);
    		flagCarga = 1;
    	}

    }while(salir!=-2);



    return 0;
}

