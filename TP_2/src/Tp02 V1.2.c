/*
 ============================================================================
 Name        : Trabajo Practico N° 2.c
 Author      : Fabella Ivan
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "utnInPuts.h"
#include "ArrayPassenger.h"
#include "puntosDeMenu.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXIMOPASAJEROS 3
#define MINIMOOPCION 1
#define MAXIMOOPCION 6
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3

int main(void) {

	setbuf(stdout, NULL);
    int salir;
    int validar;
    int opcion;
    Passenger datosPasajeros[MAXIMOPASAJEROS];
    initPassengers(datosPasajeros, MAXIMOPASAJEROS);

    do{
    	if(utnGetNumero(&opcion, "Opcion 1: Altas\nOpcion 2: Modificar\nOpcion 3: Baja\nOpcion 4: Informar\nOpcion 5: Carga Forzada\nOpcion 6: Cambiar estado de vuelo\nOpcion 7: Salir\n"
    			,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", MINIMOOPCION,
				MAXIMOOPCION, REINTENTOS)==RETORNOPOSITIVO)
    	{
    	 	switch(opcion)
			{
			case 1://Ingresar Pasajero

				if(puntoDeMenuIngresarPasajero(datosPasajeros, MAXIMOPASAJEROS)==RETORNONEGATIVO)
				{
					puts("No hay espacios para mas pasajeros  \n");
					break;
				}
				else
				{
					puts("continua el programa\n");
					break;
				}

			case 2://Modificar

				if(puntoDeMenuModificar(datosPasajeros, MAXIMOPASAJEROS)==RETORNONEGATIVO)
				{
					puts("Hubo errores en el cambio del pasajero \n");
					break;
				}
				else
				{
					puts("continua el programa\n");
					break;
				}

			case 3://Borrar

				if(puntoDeMenuBorrar(datosPasajeros, MAXIMOPASAJEROS)==RETORNONEGATIVO)
				{
					puts("Hubo un error en el borrado del pasajero \n");
					break;
				}
				else
				{
					puts("continua el programa\n");
					break;
				}

			case 4://Informar

			/*	3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’*/
				if(puntoDeMenuInforme(datosPasajeros, MAXIMOPASAJEROS)==RETORNONEGATIVO)
				{
					puts("Hubo un error para imprimir los pasajeros \n");
					break;
				}
				else
				{
					puts("continua el programa\n");
					break;
				}

			case 5://Salir

				if(puntoDeMenuHardCodeo(datosPasajeros, MAXIMOPASAJEROS)==-1)
				{
					puts("No hay espacios disponibles \n");
				}

		        break;

			case 6:
				validar=puntoDeMenuCambioEstadoDeVuelo(datosPasajeros, MAXIMOPASAJEROS);

				if(validar==0)
				{
					puts("Se ha cambiado el estado de vuelo correctamente");
				}
				else
				{
					if(validar==-1)
					{
						puts("No se encontraron pasajeros\n");
					}
					else
					{
						if(validar==-2)
						{
							puts("No se encontraron pasajeros con el codigo de vuelo solicitado \n");
						}
					}
				}
				break;


			case 7:
				if(utnVerificacionConChar("\nRealmente desea salilr ?\n", "Continua\n","\nAdios\n",0)==-2)
				{
					salir=-2;
					break;
				}
				else
				{
					puts("Continua\n");
					break;
				}


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

    return EXIT_SUCCESS;
}
