/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXIMOCHAR 51

Passenger* Passenger_new()
{
	return (Passenger*) malloc(sizeof(Passenger));
}
Passenger* Passenger_newParametros(int id,char* nombreStr,char* apellidoStr,float price
		,char* flyCode,char* tipoPasajeroStr,char* estadoVuelo)
{
	Passenger* punteroPassenger = NULL;
	punteroPassenger = Passenger_new();
	if(punteroPassenger != NULL && nombreStr != NULL && apellidoStr != NULL && flyCode != NULL && tipoPasajeroStr != NULL && estadoVuelo != NULL && id>0 && price>0)
	{
		Passenger_setId(punteroPassenger,id);
		Passenger_setNombre(punteroPassenger,nombreStr);
		Passenger_setApellido(punteroPassenger,apellidoStr);
		Passenger_setPrecio(punteroPassenger,price);
		Passenger_setCodigoVuelo(punteroPassenger,flyCode);
		Passenger_setTipoPasajero(punteroPassenger,tipoPasajeroStr);
		Passenger_setEstadoVuelo(punteroPassenger, estadoVuelo);
	}
	else
	{
		puts("PunteroPerson == null");
	}

	return punteroPassenger;
}
void Passenger_delete(Passenger* this)
{
	free(this);
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && id>0)
	{
		this->id=id;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && id>0)
	{
		*id=this->id;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(this->nombre,nombre,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;

}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && nombre!=NULL)
	{
		strncpy(nombre,this->nombre,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && apellido!=NULL)
	{
		strncpy(this->apellido,apellido,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && apellido!=NULL)
	{
		strncpy(apellido,this->apellido,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && codigoVuelo!=NULL)
	{
		strncpy(this->codigoVuelo,codigoVuelo,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo,this->codigoVuelo,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}



	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(this->tipoPasajero,tipoPasajero,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && tipoPasajero != NULL)
	{
		strncpy(tipoPasajero,this->tipoPasajero,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && precio>0)
	{
		this->precio=precio;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && precio>0)
	{
		*precio=this->precio;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* statusFlight)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && statusFlight!=NULL)
	{
		strncpy(this->statusFlight,statusFlight,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;

}

int Passenger_getEstadoVuelo(Passenger* this,char* statusFlight)
{
	int retorno=RETORNONEGATIVO;
	if(this != NULL && statusFlight!=NULL)
	{
		strncpy(statusFlight,this->statusFlight,MAXIMOCHAR);
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

