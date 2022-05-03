/*
 * sortPassenger.c
 *
 *  Created on: 27 abr 2022
 *      Author: Usuario Programador
 */
#include "ArrayPassenger.h"
#include "sortPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define FULL -1
#define VUELOACTIVO 1
//Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
//descendente.
int sortPassengers(Passenger* list, int order,int len)
{
	int retorno=-1;
	if (list != NULL && len > 0)
	{
		if(order==1)
		{
			sortAscByTipe(list,len);
			retorno=0;
		}
		else
		{
			sortDsdByTipe(list, len);
			retorno = 0;
		}

	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int order, int len)
{

	int retorno=-1;
	if (list != NULL && len > 0)
	{
		if(order==1)
		{
			sortAscByCode(list,len);
			retorno=0;
		}
		else
		{
			sortDscByCode(list, len);
			retorno = 0;
		}

	}
	return retorno;

}

void sortAscByCode(Passenger* list, int len)
{
	int i;
	int estaOrdenado;
	int sizeDeCodigoVuelo;

	if (list != NULL && len > 0)
	{
		do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++)
				{
					sizeDeCodigoVuelo=sizeof(list[i].nameLastName.lastName);
					if(list[i].isEmpty==FULL && list[i].statusFlight==VUELOACTIVO && strncmp(list[i].flycode,list[i+1].flycode,sizeDeCodigoVuelo)>0)
					{
						soap(list,i);
						estaOrdenado = 0;
					}

				}//Fin For
			  }while(estaOrdenado == 0);
	}

}

void sortDscByCode(Passenger* list, int len)
{
	int i;
	int estaOrdenado;
	int sizeDeCodigoVuelo;

	if (list != NULL && len > 0)
	{
		do {
				estaOrdenado = 1;
				len--;
				for (i = 0; i < len; i++)
				{
					sizeDeCodigoVuelo=sizeof(list[i].nameLastName.lastName);
					if(list[i].isEmpty==FULL && list[i].statusFlight==VUELOACTIVO && strncmp(list[i].flycode,list[i+1].flycode,sizeDeCodigoVuelo)<0)
					{
						soap(list,i);
						estaOrdenado = 0;
					}

				}//Fin For
			  }while(estaOrdenado == 0);
	}

}

void sortAscByTipe(Passenger* list, int len)
{
	int i;
	int estaOrdenado;
	int sizeDeApellido;

	if (list != NULL && len > 0)
	{
		do {
			estaOrdenado = 1;
			len--;
			for (i = 0; i < len; i++)
			{
				sizeDeApellido=sizeof(list[i].nameLastName.lastName);
				if(list[i].isEmpty==FULL && strncmp(list[i].nameLastName.lastName,list[i+1].nameLastName.lastName,sizeDeApellido)>0)
				{
					soap(list,i);
					estaOrdenado = 0;
				}
				else
				{
					if(list[i].isEmpty==FULL && strncmp(list[i].nameLastName.lastName,list[i+1].nameLastName.lastName,sizeDeApellido)==0
							&& list[i].typePassenger<list[i+1].typePassenger)
					{
							soap(list,i);
							estaOrdenado = 0;
					}
				}

			}//Fin For
		  }while(estaOrdenado == 0);

	}//Fin if inicial

}

void sortDsdByTipe(Passenger* list, int len)
{
	int i;
	int estaOrdenado;
	int sizeDeApellido;

	if (list != NULL && len > 0)
	{
		do{
			estaOrdenado = 1;
			len--;
			for (i = 0; i < len; i++)
			{
				sizeDeApellido=sizeof(list[i].nameLastName.lastName);
				if(list[i].isEmpty==-1 && strncmp(list[i].nameLastName.lastName,list[i+1].nameLastName.lastName,sizeDeApellido)<0)
				{
					soap(list,i);
					estaOrdenado = 0;
				}
				else
				{
					if(list[i].isEmpty==-1 && strncmp(list[i].nameLastName.lastName,list[i+1].nameLastName.lastName,sizeDeApellido)==0
							&& list[i].typePassenger>list[i+1].typePassenger)
					{
							soap(list,i);
							estaOrdenado = 0;
					}
				}

			}//Fin For
		  }while(estaOrdenado == 0);
	}

}

void soap(Passenger* list,int posicion)
{
	Passenger aux;
	aux = list[posicion];
	list[posicion] = list[posicion + 1];
	list[posicion + 1] = aux;
}

