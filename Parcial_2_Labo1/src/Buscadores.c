/*
 * contadores.c
 *
 *  Created on: 28 jun 2022
 *      Author: Usuario Programador
 */

#include "Buscadores.h"
#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_BuscadorFirstClass(void* this)
{
	int retorno=-1;
	int valida;
	char auxTipo[51];
	if(this!=NULL)
	{
		Passenger_getTipoPasajero(this, auxTipo);
		valida=strncmp(auxTipo,"FirstClass",51);
		if(valida==0)
		{
			retorno=0;
		}
	}

	return retorno;
}

int count_BuscadorEconomyClass(void* this)
{
	int retorno=-1;
	int valida;
	char auxTipo[51];
	if(this!=NULL)
	{
		Passenger_getTipoPasajero(this, auxTipo);
		valida=strncmp(auxTipo,"EconomyClass",51);
		if(valida==0)
		{
			retorno=0;
		}
	}

	return retorno;
}

int count_BuscadorExecutiveClass(void* this)
{
	int retorno=-1;
	int valida;
	char auxTipo[51];
	if(this!=NULL)
	{
		Passenger_getTipoPasajero(this, auxTipo);
		valida=strncmp(auxTipo,"ExecutiveClass",51);
		if(valida==0)
		{
			retorno=0;
		}
	}

	return retorno;
}


