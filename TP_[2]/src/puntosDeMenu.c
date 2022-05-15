/*
 * puntosDeMenu.c
 *
 *  Created on: 1 may 2022
 *      Author: Usuario Programador
 */
#include "ArrayPassenger.h"
#include "imprimirMostrar.h"
#include "sortPassenger.h"
#include "calculosPasajeros.h"
#include "ArrayFly.h"
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FULL 0
#define EMPTY -1
#define REINTENTOS 3
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0
#define MAXIMOCADENA 51
#define MAXIMOCADENACODIGOVUELO 51
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MINIMOIDS 0
#define MAXIMOSIDS 1000

int menuItemEnterPassenger(Flight* vuelo,Passenger* listPassager,DateFlight* listFligt, int lenPassager, int lenFlight)
{
    char auxName[MAXIMOCADENA];
    char auxLastName[MAXIMOCADENA];
    char auxFlyCode[MAXIMOCADENA];
    int auxId;
    float auxPrice;
    int auxTypePassenger;
	int retorno=RETORNONEGATIVO;

	if(utnIsEmptyOrFullPassager(listPassager, EMPTY, lenPassager)!=RETORNONEGATIVO
			&& utnIsEmptyOrFullFlight(listFligt, EMPTY, lenFlight)!=RETORNONEGATIVO)
	{
		if(ingresPassenger(auxName, auxLastName, &auxTypePassenger,MAXIMOCADENA)==RETORNOPOSITIVO
				&& ingresDataFlight(vuelo,&auxPrice, auxFlyCode,MAXIMOCADENA,lenFlight)==RETORNOPOSITIVO)
		{
			contadorId(&auxId);
			if(addPassenger(listPassager,listFligt, auxId, auxName, auxLastName, auxPrice, auxTypePassenger,
					auxFlyCode, lenPassager,lenFlight)==RETORNOPOSITIVO)
			{
				printf("Se ha dado de alta correctamente con el ID N°: %d, \n",auxId);
				retorno=RETORNOPOSITIVO;
			}
		}
		else
		{
			puts("Error al cargar pasajero.\n");
			retorno=RETORNONEGATIVO;
		}

	}//If espacioLibre
	else
	{
		puts("No hay espacios para mas pasajeros  \n");
		retorno=RETORNONEGATIVO;
	}

	return retorno;

}

int menuItemModify(Passenger* listDatePassenger,DateFlight* listDateFlight,Flight* listFlight, int lenPassager,int lenDataFlight,int lenFlight)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int posicionIdPassenger;
	int posicionIdFlight;
	int seleccion;
	int seguir=0;
	Passenger * punteroAdatoPasajero;
	DateFlight * punteroAdatoVuelo;
	do{
		if(utnIsEmptyOrFullPassager(listDatePassenger, FULL, lenPassager)!=RETORNONEGATIVO)
		{
			puts("Actualmente, estan cargados los siguientes pasajeros\n");
			printPassenger(listDatePassenger, listDateFlight,listFlight, lenPassager, lenDataFlight);

			if(utnGetNumero(&auxId, "\nIngrese el ID a modificar o 0 si desea cancelar la modificacion:\n", "Ocurrio un error al ingresar el ID\n"
					, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(auxId==0)
				{
					puts("Se cancela la modificacion");
					break;
				}
				if((findPassengerById(listDatePassenger,auxId,&posicionIdPassenger, lenPassager)==RETORNOPOSITIVO)&&
						(findFlightById(listDateFlight,auxId, &posicionIdFlight, lenDataFlight)==RETORNOPOSITIVO))
				{
					if(utnGetNumero(&seleccion, "\nSi esea modificar datos personales, ingrese 1. Para modificar datos del vuelo, 2?  :\n", "Ocurrio un error al ingresar seleccion\n"
									, "Error al ingresar Opcion. Desea reintentar?\n", 1, 2, REINTENTOS)==RETORNOPOSITIVO)
					{
						switch(seleccion)
						{
						case 1:
							punteroAdatoPasajero=&listDatePassenger[posicionIdPassenger];
							changePassager(punteroAdatoPasajero,MAXIMOCADENA);

							break;
						case 2:
							punteroAdatoVuelo=&listDateFlight[posicionIdFlight];
							changeDataFlight(punteroAdatoVuelo,listFlight,lenFlight,MAXIMOCADENA,MAXIMOCADENACODIGOVUELO);
							break;
						}
					}
				}
				else
				{
					puts("Error al ingresar ID a modificar\n");
				}

			}//Fin if GetNumero
		}
		else
		{
			puts("No se encontraron pasajeros. \n");
			seguir=-1;
			break;
		}
		if(seguir==0)
		{
			seguir=utnVerificacionConChar("Desea continuar con la modificacio del pasajero? si o no ?\n","Continua\n", "Se cierra el menu modificar\n", 0);
		}
	}while(seguir==0);


	return retorno;
}

int deletMenuItem(Passenger* list,DateFlight* listDateFlight,Flight* vuelo,int lenPasajeros, int lenVuelos)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int posicionIdPass;
	int posicionIdFlig;
	Passenger * punteroAdatoPasajero;
	DateFlight * punteroAdatoVuelo;

	if(utnIsEmptyOrFullPassager(list, FULL, lenPasajeros)!=RETORNONEGATIVO)
	{
		if(utnGetNumero(&auxId, "\nIngrese el ID a Borrar :\n", "Ocurrio un error al ingresar el ID\n"
				, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
		{
			if(findPassengerById(list,auxId,&posicionIdPass, lenPasajeros)==RETORNOPOSITIVO && findFlightById(listDateFlight, auxId, &posicionIdFlig, lenVuelos)==RETORNOPOSITIVO)
			{
				puts("El pasajero a borrar es :\n");
				puts("---------------------------------------------------------------------------------------------------------------\n");
				punteroAdatoPasajero=&list[posicionIdPass];
				punteroAdatoVuelo=&listDateFlight[posicionIdFlig];

				printOnePassenger(punteroAdatoPasajero);
				printOneDestin(punteroAdatoVuelo,vuelo,lenPasajeros,lenVuelos);

				if(utnVerificacionConChar("Confirma el borrado? si o no\n", "Se elimina el pasajero", "Se cancela la operacion", 0)==RETORNOPOSITIVO)
				{
					removePassenger(punteroAdatoPasajero);
					removeFlight(punteroAdatoVuelo);
					retorno=RETORNOPOSITIVO;
				}

			}
			else
			{
				puts("No se encontro el ID solicitado\n");
			}
		}

	}//fin EspacioLibre
	else
	{
		puts("No se encontrarn pasajeros. \n");
	}
	return retorno;
}

int reportMenuItem(Passenger* list,DateFlight* listDateFlight,Flight* vuelo, int lenPasajeros, int lenVuelos)
{
    int auxOrdenImprimir;
	int retorno=-1;
	int seguir;
	int opcion;
	float totalPrecios;
	float promedioDePrecios;

	int pasajerosMayorAlPromedio;
	if(utnIsEmptyOrFullPassager(list, FULL, lenPasajeros)!=RETORNONEGATIVO)
	{
		do
		{
			if(utnGetNumero(&opcion, "1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n",
						"Error de ingreso de opcion\n", "Desea reintentar?\n", 1, 3, REINTENTOS)==RETORNOPOSITIVO)
			{
				switch(opcion)
				{
				case 1:
					if(utnGetNumero(&auxOrdenImprimir, "Ingrese 1 si desea ordenar de manera Ascendente, sino, 0\n",
							"Error en el ingreso de opcion\n", "Desea continuar con el informe ?\n", 0, 1, REINTENTOS)==RETORNOPOSITIVO)
					{
						sortPassengers(list,listDateFlight, auxOrdenImprimir, lenPasajeros,lenVuelos);
						printPassenger(list, listDateFlight, vuelo,lenPasajeros, lenVuelos);
						retorno=0;
						break;
					}
					else
					{
						puts("Error en seleccion de ordenamiento\n");
						break;
					}

				case 2:
					flightCalculator(listDateFlight, &pasajerosMayorAlPromedio, &totalPrecios, &promedioDePrecios, lenVuelos);
					printf("\nEl total de precios de pasajeros es: %.2f\nEl promedio es de: %.2f\nCantidad de pasajeros que superan el precio promedio: %d\n"
							,totalPrecios,promedioDePrecios,pasajerosMayorAlPromedio);
					break;

				case 3:
					if(utnGetNumero(&auxOrdenImprimir, "Ingrese 0 si desea ver  los cancelados(SI LOS HAY), sino, 1\n",
							"Error en el ingreso de opcion\n", "Desea continuar con el informe ?\n", 0, 1, REINTENTOS)==RETORNOPOSITIVO)
					{
						printPassengerByCode(listDateFlight, vuelo,auxOrdenImprimir, lenPasajeros);
						break;
					}
					else
					{
						puts("Error en seleccion de ordenamiento\n");
						break;
					}
				case 4:

				default:
					puts("Error en seleccion de opcion\n");
					break;

				}//Fin switch

			}//Fin if opcion
			if(utnVerificacionConChar("Desea continuar con el informe?\n","Continua\n", "Se cierra el informe\n", 0)==RETORNOPOSITIVO)
			{
				seguir=0;
			}
			else
			{
				seguir=-1;
			}

		}while(seguir==0);

	}//Fin espacio libre o no
	else
	{
		puts("No se encontraron pasajeros. \n");
		retorno=-2;
	}

	return retorno;
}

int hardcodeMenuItem(Passenger* list,DateFlight* listFlight, int lenPasajeros, int lenVuelos)
{
	int auxId;
	int retorno=-1;
	if(utnIsEmptyOrFullPassager(list, EMPTY, lenPasajeros)!=-1)
	{

	   contadorId(&auxId);
	    if(addPassenger(list,listFlight, auxId, "Ivan", "CCedina  ", 15020.20, 2, "EA012F", lenPasajeros,lenVuelos)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }

	    contadorId(&auxId);
	    if(addPassenger(list,listFlight, auxId, "Aldana", "AAabella", 123500.20, 4, "EA012G", lenPasajeros,lenVuelos)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }

	    contadorId(&auxId);
	    if(addPassenger(list,listFlight, auxId, "Enano", "AAabella", 23300.20, 3,"EA012I", lenPasajeros,lenVuelos)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }

	    contadorId(&auxId);
	    if(addPassenger(list,listFlight, auxId, "Abu", "Gris", 244300.20, 3, "EA012G", lenPasajeros,lenVuelos)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }

	}
    else
	    {
	    	puts("error");
	    	retorno=-1;
	    }
	return retorno;

}

int menuItemFlightStatusChange(DateFlight* listFlight, Flight* vuelo,int lenFligth)
{
	int retorno;
	int estadoVuelo;
	int auxEspacio;
	char codigoVuelo[MAXIMOCADENACODIGOVUELO];
	if(utnIsEmptyOrFullFlight(listFlight, -1, lenFligth)!=-1)
	{
		if(utnIngresarAlfanumerico(codigoVuelo, "Ingrese el codigo del vuelo a cambiar estado\n",REINTENTOS, MAXIMOCADENACODIGOVUELO)==RETORNOPOSITIVO)
		{
			pasajeTodoAminusculaOmayusculaConNum(codigoVuelo, 0);

			if(findPassengerByCode(vuelo, codigoVuelo,&auxEspacio, lenFligth)==RETORNOPOSITIVO)
			{
				if(utnGetNumero(&estadoVuelo, "Ingrese 0 para activar el estado de vuelo o 1 si fue cancelado\n", "Error al cargar opcion\n", "Desea volver a intentar?", 0, 1, REINTENTOS)==RETORNOPOSITIVO)
				{
					if(vuelo[auxEspacio].isEmtpy==FULL && strncmp(listFlight[auxEspacio].flyCode,codigoVuelo,MAXIMOCADENACODIGOVUELO)==RETORNOPOSITIVO)
					{
							vuelo[auxEspacio].statusFlight=estadoVuelo;
							puts("El estado de vuelo se ha cambiado correctamente");
							retorno=0;
					}
				}//Fin if activa/desactiva
				else
				{
					puts("No se encontraron vuelos\n");
					retorno=-1;//Le erro a la opcion estado
				}
			}//fin if busqueda codigo
			else
			{
				puts("No se encontraron vuelos con el codigo  solicitado \n");
				retorno=-2;
			}

		}//fin if peticion de codigo
		else
		{
			retorno=-3;
		}

	}//Fin if busca si hay pasajero
	else
	{
		retorno=-1;
	}
	return retorno;
}




