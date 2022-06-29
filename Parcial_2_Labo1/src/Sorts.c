/*
 * Sorts.c
 *
 *  Created on: 10 jun 2022
 *      Author: Usuario Programador
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Sorts.h"
#include "Passenger.h"
#define MAXIMOCHAR 51
//id,name,lastname,price,flycode,typePassenger,statusFlight



int Sort_compareByApellido(void* pasajeroUno, void* pasajeroDos)
{
	int retorno=-2;
	char auxApellidoUno[MAXIMOCHAR];
	char auxApellidoDos[MAXIMOCHAR];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getApellido(pasajeroUno, auxApellidoUno);
		Passenger_getApellido(pasajeroDos, auxApellidoDos);
		retorno = strncmp(auxApellidoUno, auxApellidoDos, MAXIMOCHAR);
		if(retorno>0)
		{
			retorno=1;
		}else if(retorno<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}

int Sort_compareByNombre(void* pasajeroUno, void* pasajeroDos)
{
	int retorno=-2;
	char auxNombreoUno[MAXIMOCHAR];
	char auxNombreDos[MAXIMOCHAR];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getNombre(pasajeroUno, auxNombreoUno);
		Passenger_getNombre(pasajeroDos, auxNombreDos);
		retorno = strncmp(auxNombreoUno, auxNombreDos, MAXIMOCHAR);
		if(retorno>0)
		{
			retorno=1;
		}else if(retorno<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}

int Sort_compareByPrecio(void* pasajeroUno, void* pasajeroDos)
{
	int retorno;
	float auxPrecioUno;
	float auxPrecioDos;
	retorno = 0;
	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getPrecio(pasajeroUno, &auxPrecioUno);
		Passenger_getPrecio(pasajeroDos, &auxPrecioDos);

		if(auxPrecioUno > auxPrecioDos)
		{
			retorno = 1;
		}else if(auxPrecioDos > auxPrecioUno)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int Sort_compareById(void* pasajeroUno, void* pasajeroDos)
{
	int retorno;
	int auxIdUno;
	int auxIdDos;
	retorno = 0;
	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getId(pasajeroUno, &auxIdUno);
		Passenger_getId(pasajeroDos, &auxIdDos);
		if(auxIdUno > auxIdDos)
		{
			retorno = 1;
		}else if(auxIdDos > auxIdUno)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int Sort_compareByTipoPasajero(void* pasajeroUno, void* pasajeroDos)
{
	int retorno=-2;
	char auxTipoPasajeroA[MAXIMOCHAR];
	char auxTipoPasajeroB[MAXIMOCHAR];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getTipoPasajero(pasajeroUno, auxTipoPasajeroA);
		Passenger_getTipoPasajero(pasajeroDos, auxTipoPasajeroB);
		retorno = strncmp(auxTipoPasajeroA, auxTipoPasajeroB, MAXIMOCHAR);
		if(retorno>0)
		{
			retorno=1;
		}else if(retorno<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}

int Sort_compareByEstado(void* pasajeroUno, void* pasajeroDos)
{
	int retorno=-2;
	char auxEstadoA[MAXIMOCHAR];
	char auxEstadoB[MAXIMOCHAR];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getEstadoVuelo(pasajeroUno, auxEstadoA);
		Passenger_getEstadoVuelo(pasajeroDos, auxEstadoB);
		retorno = strncmp(auxEstadoA, auxEstadoB, MAXIMOCHAR);
		if(retorno>0)
		{
			retorno=1;
		}else if(retorno<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}

int Sort_compareByCodigoVuelo(void* pasajeroUno, void* pasajeroDos)
{
	int retorno=-2;
	char auxCodigoVueloA[MAXIMOCHAR];
	char auxCodigoVueloB[MAXIMOCHAR];

	if(pasajeroUno != NULL && pasajeroDos != NULL)
	{
		Passenger_getCodigoVuelo(pasajeroUno, auxCodigoVueloA);
		Passenger_getCodigoVuelo(pasajeroDos, auxCodigoVueloB);
		retorno = strncmp(auxCodigoVueloA, auxCodigoVueloB, MAXIMOCHAR);
		if(retorno>0)
		{
			retorno=1;
		}else if(retorno<0)
		{
			retorno=-1;
		}
	}
	return retorno;
}

