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
	char auxCadena[51];
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
<<<<<<< HEAD
				if(menu_cargaDatosPasajerosDesdeBinario("data.bin",listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("El archivo se ha cargado con exito binario");
				}
				else
				{
					puts("Ocurrio un error al leer el archivo ");
=======
				if(menu_cargaDatosPasajerosDesdeCsv("data.csv",listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("\nEl archivo se ha cargado con exito");
				}
				else
				{
					puts("\nOcurrio un error al leer el archivo  \n");
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
				}

				break;

			case 3://Alta manual
				if(menu_altaPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Operacion realizada con exito");
				}
<<<<<<< HEAD
				else
				{
					puts("Ocurrio un error en la carga de datos del pasajero");
				}
=======
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c

				break;

			case 4://
				if(menu_modificarPasajero(listaPasajeros)==RETORNOPOSITIVO)
				{
<<<<<<< HEAD
					puts("Operacion realizada con exito");
				}
				else
				{
					puts("Ocurrio un error en la modificacion de datos del pasajero");
=======
					puts("Modificacion realizada con exito");
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
				}


				break;

			case 5://
<<<<<<< HEAD
				 if(menu_eliminarPasajero(listaPasajeros)==RETORNOPOSITIVO)
				 {
					 puts("Se ha eliminado con exito");
				 }
				 else
				 {
					 puts("Ocurrio un error al eliminar pasajero");
				 }
=======
				controller_ListPassenger(listaPasajeros);
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
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
				if(utnGetNumero(&opcion, "Ingrese 1 si desea crear un nuevo archivo o 0 si desea guardar sobre el mismo\n"
						, "Error al ingresar Opcion", "Desea reintentar? ", 0, 1, REINTENTOS)==RETORNOPOSITIVO)
				{
					if(opcion==1)
					{
						utnIngresarAlfanumerico(auxCadena, "Ingrese el nombre del archivo\n", REINTENTOS, 51);
						strcat(auxCadena,".csv");
						if(controller_saveAsText(auxCadena,listaPasajeros)==RETORNOPOSITIVO)
						{
							puts("Cargado. Se debe compilar el programa para obtener datos ");
						}
					}
					else
					{
						if(controller_saveAsText("data.csv",listaPasajeros)==RETORNOPOSITIVO)
						{
							puts("Cargado");
						}
					}
				}
				break;
			case 9:
				if(controller_saveAsBinary("Data.bin",listaPasajeros)==RETORNOPOSITIVO)
				{
					puts("Cargado");
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

