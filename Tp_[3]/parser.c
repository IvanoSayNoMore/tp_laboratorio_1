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

int parser_guardaPasajerosCsv(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	Passenger* pPassenger;
	Passenger pasajero;
	int lenpArrayList;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		lenpArrayList=ll_len(pArrayListPassenger);
		fprintf(pFile,"Id,Nombre,Apellido,Codigo De Vuelo, Tipo Pasajero, Estado Vuelo\n");
		for(int i=0;i<lenpArrayList+1;i++)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(Passenger_getApellido(pPassenger, pasajero.apellido)==RETORNOPOSITIVO
					&& Passenger_getNombre(pPassenger, pasajero.nombre)==RETORNOPOSITIVO
					&& Passenger_getId(pPassenger, &pasajero.id)==RETORNOPOSITIVO
					&& Passenger_getCodigoVuelo(pPassenger, pasajero.codigoVuelo)==RETORNOPOSITIVO
					&& Passenger_getTipoPasajero(pPassenger, pasajero.tipoPasajero)==RETORNOPOSITIVO
					&& Passenger_getEstadoVuelo(pPassenger, pasajero.statusFlight)==RETORNOPOSITIVO
					&& Passenger_getPrecio(pPassenger, &pasajero.precio)==RETORNOPOSITIVO)
			{
				fprintf(pFile,"%d,%s,%s,%s,%.2f,%s,%s\n",pasajero.id
						, pasajero.nombre,pasajero.apellido,pasajero.codigoVuelo,pasajero.precio
						,pasajero.tipoPasajero, pasajero.statusFlight);

				retorno=RETORNOPOSITIVO;
			}
		}
	}


	return retorno;
}


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

	int retorno = RETORNONEGATIVO;
<<<<<<< HEAD
	int cantidad;
	Passenger * pPassenger;
	Passenger pasajero;
=======
	Passenger * pPassenger;
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			pPassenger = Passenger_new();
<<<<<<< HEAD
			cantidad=fread(pPassenger,sizeof(Passenger),1,pFile);
			if (pPassenger != NULL && cantidad==1)
			{//id,name,lastname,price,flycode,typePassenger,statusFlight
				if(Passenger_getId(pPassenger, &pasajero.id)==RETORNOPOSITIVO
						&& Passenger_getNombre(pPassenger, pasajero.nombre)==RETORNOPOSITIVO
						&& Passenger_getApellido(pPassenger, pasajero.apellido)==RETORNOPOSITIVO
						&& Passenger_getPrecio(pPassenger, &pasajero.precio)==RETORNOPOSITIVO
						&& Passenger_getCodigoVuelo(pPassenger, pasajero.codigoVuelo)==RETORNOPOSITIVO
						&& Passenger_getTipoPasajero(pPassenger, pasajero.tipoPasajero)==RETORNOPOSITIVO
						&& Passenger_getEstadoVuelo(pPassenger, pasajero.statusFlight)==RETORNOPOSITIVO)
				{

					retorno = ll_add(pArrayListPassenger, pPassenger);
				}

=======
			if (pPassenger != NULL && fread(pPassenger,sizeof(pPassenger),1,pFile)==1)
			{
				retorno = ll_add(pArrayListPassenger, pPassenger);
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
			}
			else
			{
				Passenger_delete(pPassenger);
				break;
			}
<<<<<<< HEAD
		} while(!feof(pFile));
	}
	fclose(pFile);
=======
		} while (!feof(pFile));
	}
>>>>>>> 6ac921560a5d814f71475b007036fc0c702d9e3c
	return retorno;
}
