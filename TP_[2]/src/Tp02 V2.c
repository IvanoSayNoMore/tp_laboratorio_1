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
#include "ArrayFly.h"
#include "imprimirMostrar.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXIMOPASAJEROS 16
#define MAXIMOVUELOS 8
#define MINIMOOPCION 1
#define ESTADOVUELOACTIVO 0
#define ESTADOVUELOCANCELADO 1
#define MAXIMOOPCION 7
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3


int main(void){
	setbuf(stdout, NULL);
    int salir;
    int opcion;

    Passenger datosPasajeros[MAXIMOPASAJEROS];
    DateFlight datosVuelo[MAXIMOPASAJEROS];
    Flight vuelo[MAXIMOVUELOS];
    initPassengers(datosPasajeros, MAXIMOPASAJEROS);
    initDataFlight(datosVuelo, MAXIMOPASAJEROS);
    initFlight(vuelo, MAXIMOVUELOS);

    loadFlight(vuelo, "FRANCIA","EA012F",ESTADOVUELOACTIVO, MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "POLONIA","EA012G",ESTADOVUELOACTIVO,MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "INDONESIA","EA012H",ESTADOVUELOCANCELADO, MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "IRLANDA","EA012I",ESTADOVUELOCANCELADO, MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "ALEMANIA","EA012J",ESTADOVUELOACTIVO, MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "GRECIA","EA012K",ESTADOVUELOACTIVO,MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "ITALIA","EA012Q",ESTADOVUELOCANCELADO, MAXIMOVUELOS,51,51);
    loadFlight(vuelo, "NUEVA ZELANDA","EA012P",ESTADOVUELOCANCELADO, MAXIMOVUELOS,51,51);

    do{
    	if(utnGetNumero(&opcion,
    			"\nOpcion 1: Altas\n"
    			"Opcion 2: Modificar datos de vuelo o pasajero \n"
    			"Opcion 3: Baja\n"
    			"Opcion 4: Informar\n"
    			"Opcion 5: Carga Forzada\n"
    			"Opcion 6: Cambiar estado de vuelo\n"
    			"Opcion 7: Salir\n"
    			,"", "Error al ingresar Opcion. Desea reintentar?Ingrese SI si desea continuar.\n", MINIMOOPCION,
				MAXIMOOPCION, REINTENTOS)==RETORNOPOSITIVO)
    	{
    	 	switch(opcion)
			{

			case 1://Ingresar Pasajero

				menuItemEnterPassenger(vuelo,datosPasajeros,datosVuelo,MAXIMOPASAJEROS,MAXIMOVUELOS);
				break;

			case 2://Modificar

				menuItemModify(datosPasajeros,datosVuelo,vuelo,MAXIMOPASAJEROS,MAXIMOPASAJEROS,MAXIMOVUELOS);
				break;

			case 3://Borrar

				deletMenuItem(datosPasajeros,datosVuelo,vuelo,MAXIMOPASAJEROS,MAXIMOVUELOS);
				break;

			case 4://Informar

				reportMenuItem(datosPasajeros,datosVuelo,vuelo,MAXIMOPASAJEROS,MAXIMOVUELOS);
				break;

			case 5://Carga Forzada

				hardcodeMenuItem(datosPasajeros,datosVuelo,MAXIMOPASAJEROS,MAXIMOVUELOS);
		        break;

			case 6://Cambio de estado de vuelo

				menuItemFlightStatusChange(datosVuelo,vuelo,MAXIMOPASAJEROS);
				break;

			case 7:

				if(utnVerificacionConChar("\nRealmente desea salilr ?\n", "\nAdios","\nContinua\n",0)==RETORNOPOSITIVO)
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

