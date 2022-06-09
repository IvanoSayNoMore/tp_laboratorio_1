/*
 * puntosDeMenu.c
 *
 *  Created on: 5 jun 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "parser.h"
#include "Passenger.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXIMOCHAR 51
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;

	Passenger * pPassenger;
	char auxCabecera[200];
	char auxId[MAXIMOCHAR],auxName[MAXIMOCHAR],auxLastName[MAXIMOCHAR];
	char auxPrice[MAXIMOCHAR],auxFlycode[MAXIMOCHAR],auxTypePassenger[MAXIMOCHAR],auxstatusFlight[MAXIMOCHAR];
	int retScan;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^\n]\n",auxCabecera);//Titulo Datos
		do
		{
			retScan = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
					,auxId,auxName,auxLastName,auxPrice,auxFlycode,auxTypePassenger,auxstatusFlight);
			if(retScan==7)
			{

				pPassenger = Passenger_newParametros(atoi(auxId), auxName, auxLastName, atof(auxPrice), auxFlycode, auxTypePassenger,auxstatusFlight);

				if(pPassenger != NULL)
				{
					retorno = ll_add(pArrayListPassenger, pPassenger);
				}

			}
			else
			{
				break;
			}
			//printf("\nCodigo en Parser %s: ",pPassenger->codigoVuelo);
		}while(!feof(pFile));

	}

    return retorno;
}
/*
 * 	Passenger * pPassenger;
	Passenger passenger;
	char auxCabecera[200];
	int retScan;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^\n]\n",auxCabecera);//Titulo Datos
		do
		{
			retScan = fscanf(pFile,"%d,%[^,],%[^,],%f,%[^,],%[^,],%[^\n]\n",&passenger.id
					,passenger.nombre,passenger.apellido,&passenger.precio,passenger.codigoVuelo,passenger.tipoPasajero,passenger.statusFlight);
			if(retScan==7)
			{

				pPassenger = Passenger_newParametros(passenger.id, passenger.nombre, passenger.apellido, passenger.precio
						,passenger.codigoVuelo, passenger.tipoPasajero,passenger.statusFlight);

				if(pPassenger != NULL)
				{
					retorno = ll_add(pArrayListPassenger, pPassenger);
					printf("\nCodigo en parser : %s",passenger.codigoVuelo);
				}
			}
			else
			{
				break;
			}

		}while(!feof(pFile));
 */


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
