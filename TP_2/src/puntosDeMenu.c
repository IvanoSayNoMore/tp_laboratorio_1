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
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMPTY 0
#define FULL -1
#define REINTENTOS 3
#define RETORNONEGATIVO -1
#define RETORNOPOSITIVO 0
#define MAXIMOPASAJEROS 3
#define MAXIMOCADENA 51
#define MAXIMOCADENACODIGOVUELO 51
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MINIMOIDS 0
#define MAXIMOSIDS 1000

int puntoDeMenuIngresarPasajero(Passenger* list, int len)
{
    char auxName[MAXIMOCADENA];
    char auxLastName[MAXIMOCADENA];
    char auxFlyCode[MAXIMOCADENA];
    int auxId;
    float auxPrice;
    int auxTypePassenger;
    // int auxStatusFlight;
	int retorno;

	if(utnIsEmptyOrFull(list, EMPTY, len)!=RETORNONEGATIVO)
	{
		if(ingresPassenger(auxName, auxLastName, &auxPrice, &auxTypePassenger,
				auxFlyCode, MAXIMOCADENA)==RETORNOPOSITIVO)
		{
			contadorId(&auxId);
			if(addPassenger(list, auxId, auxName, auxLastName, auxPrice, auxTypePassenger,
					auxFlyCode, MAXIMOPASAJEROS)==RETORNOPOSITIVO)
			{
				printf("Se ha dado de alta correctamente con el ID N°: %d, ",auxId);
				retorno=RETORNOPOSITIVO;
			}

		}
		else
		{
			puts("Error al cargar pasajero.\n");
		}

	}//If espacioLibre
	else
	{
		retorno=RETORNONEGATIVO;
	}

	return retorno;

}

int puntoDeMenuModificar(Passenger* list, int len)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int posicionId;

	if(utnIsEmptyOrFull(list, FULL, len)!=RETORNONEGATIVO)
	{
		if(utnGetNumero(&auxId, "\nIngrese el ID a modificar :\n", "Ocurrio un error al ingresar el ID\n"
				, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
		{
			if(findPassengerById(list,auxId,&posicionId, MAXIMOPASAJEROS)==RETORNOPOSITIVO)
			{
				if(changePassager(list, posicionId, MAXIMOCADENA)==RETORNOPOSITIVO)
				{
					puts("El pasajero fue cambiado correctamente, ");
					retorno=RETORNOPOSITIVO;
				}
			}
			else
			{
				puts("No se encontro el ID solicitado\n");
				retorno=RETORNOPOSITIVO;
			}
		}//Fin if GetNumero
		else
		{
			puts("Error al ingresar ID a modificar\n");
			retorno=RETORNOPOSITIVO;
		}
	}
	else
	{
		puts("No se encontraron pasajeros. \n");
		retorno=RETORNOPOSITIVO;
	}


	return retorno;
}

int puntoDeMenuBorrar(Passenger* list, int len)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int posicionId;

	if(utnIsEmptyOrFull(list, FULL, len)!=RETORNONEGATIVO)
	{
		if(utnGetNumero(&auxId, "\nIngrese el ID a Borrar :\n", "Ocurrio un error al ingresar el ID\n"
				, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
		{
			if(findPassengerById(list,auxId,&posicionId, MAXIMOPASAJEROS)==RETORNOPOSITIVO)
			{
				puts("El pasajero a borrar es :\n");
				printOnePassenger(list[posicionId]);
				if(utnVerificacionConChar("Confirma el borrado? si o no", "Se elimina el pasajero", "Se cancela la operacion", 0)==-2)
				{
					removePassenger(list, auxId,MAXIMOPASAJEROS);
					retorno=RETORNOPOSITIVO;
				}

			}
			else
			{
				puts("No se encontro el ID solicitado\n");
				retorno=RETORNOPOSITIVO;
			}
		}

	}//fin EspacioLibre
	else
	{
		puts("No se encontrarn pasajeros. \n");
		retorno=RETORNOPOSITIVO;
	}


	return retorno;
}

int puntoDeMenuInforme(Passenger* list, int len)
{
    int auxOrdenImprimir;
	int retorno=-1;
	int seguir;
	int opcion;
	float totalPrecios;
	float promedioDePrecios;

	int pasajerosMayorAlPromedio;
	if(utnIsEmptyOrFull(list, FULL, len)!=RETORNONEGATIVO)
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
						sortPassengers(list, auxOrdenImprimir, len);
						printPassenger(list, len);
						retorno=0;
						break;
					}
					else
					{
						puts("Error en seleccion de ordenamiento\n");
						break;
					}

				case 2:
					calculosPasajeros(list, &pasajerosMayorAlPromedio, &totalPrecios, &promedioDePrecios, len);
					printf("\nEl total de precios de pasajeros es: %.2f\nEl promedio es de: %.2f\nCantidad de pasajeros que superan el precio promedio: %d\n"
							,totalPrecios,promedioDePrecios,pasajerosMayorAlPromedio);
					break;

				case 3:
					if(utnGetNumero(&auxOrdenImprimir, "Ingrese 1 si desea ordenar de manera Ascendente, sino, 0\n",
							"Error en el ingreso de opcion\n", "Desea continuar con el informe ?\n", 0, 1, REINTENTOS)==RETORNOPOSITIVO)
					{
						sortPassengersByCode(list, auxOrdenImprimir, len);
						printPassenger(list, len);
						retorno=0;
						break;
					}
					else
					{
						puts("Error en seleccion de ordenamiento\n");
						break;
					}




				default:
					puts("Error en seleccion de opcion\n");
					break;

				}//Fin switch

			}//Fin if opcion
			if(utnVerificacionConChar("Desea continuar con el informe?\n","Continua\n", "Se cierra el informe\n", 0)==-2)
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

int puntoDeMenuHardCodeo(Passenger* list,int len)
{
	int auxId;
	int retorno=-1;
	if(utnIsEmptyOrFull(list, EMPTY, len)!=-1)
	{
	    contadorId(&auxId);
	    if(addPassenger(list, auxId, "Ivan", "Fabella", 15020.20, 1, "EA012F", MAXIMOPASAJEROS)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }
	    contadorId(&auxId);
	    if(addPassenger(list, auxId, "Aldana", "Medina", 123500.20, 1, "SARASA12", MAXIMOPASAJEROS)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }
	    contadorId(&auxId);
	    if(addPassenger(list, auxId, "Enano", "Zazu", 23300.20, 1, "SARASA12", MAXIMOPASAJEROS)==RETORNOPOSITIVO)
	    {
	    	printf("Se ha dado de alta correctamente con el ID N°: %d \n",auxId);
	    	retorno=0;
	    }
	}
	return retorno;

}

int puntoDeMenuCambioEstadoDeVuelo(Passenger* list, int len)
{
	int retorno;
	int estadoVuelo;
	char codigoVuelo[MAXIMOCADENACODIGOVUELO];
	if(utnIsEmptyOrFull(list, -1, len)!=-1)
	{
		if(utnIngresarAlfanumerico(codigoVuelo, "Ingrese el codigo del vuelo\n", MAXIMOCADENACODIGOVUELO)==RETORNOPOSITIVO)
		{	printf("%s\n",codigoVuelo);
			pasajeTodoAminusculaOmayusculaConNum(codigoVuelo, 0, MAXIMOCADENACODIGOVUELO);
			printf("%s\n",codigoVuelo);
			if(findPassengerByCode(list, codigoVuelo, len)==RETORNOPOSITIVO)
			{
				if(utnGetNumero(&estadoVuelo, "Ingrese 1 para activar el estado de vuelo o 0 si fue cancelado\n", "Error al cargar opcion\n", "Desea volver a intentar?", 0, 1, REINTENTOS)==RETORNOPOSITIVO)
				{
					for(int i=0;i<len;i++)
					{
						if(list[i].isEmpty==FULL && strncmp(list[i].flycode,codigoVuelo,MAXIMOCADENACODIGOVUELO)==0)
						{
							list[i].statusFlight=estadoVuelo;
							retorno=0;
						}
					}//Fin For

				}//Fin if activa/desactiva
				else
				{
					retorno=-1;//Le erro a la opcion estado
				}
			}//fin if busqueda codigo
			else
			{
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




