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
#define FULL 0
#define EMPTY -1

int sortPassengers(Passenger* list,DateFlight* listDateFlight, int order,int lenPassenger, int lenFlight)
{

	//Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero
	int retorno=-1;
	if (list != NULL && listDateFlight != NULL && lenPassenger > 0 && lenFlight > 0)
	{
		if(order==1)
		{
			sortAscByNameTipe(list,lenPassenger);
			retorno=0;
		}
		else
		{
			sortDsdByNameTipe(list,lenPassenger);
			retorno=0;
		}

	}
	return retorno;
}

void sortDsdByNameTipe(Passenger* list, int len)
{
	int estaOrdenado;
	int j;
	int valor;

	do{
		estaOrdenado=0;
		j=0;
		for(int i=0; i<len-1; i++)
		{
			if(list[i].isEmpty==FULL)
			{
				for(j=i+1;j<len;j++)
				{
					if(list[j].isEmpty==FULL)
					{
						valor=(strcmp(list[i].nameLastName.lastName,list[j].nameLastName.lastName)<0);
						if(valor>0)
						{
							estaOrdenado=1;
							soap(list, i,j);
							break;
						}
						else
						{
							if(valor!=0 && list[i].typePassenger<list[j].typePassenger)
							{
								estaOrdenado=1;
								soap(list, i,j);
								break;
							}
						}
					}

				}
			}

		}//Fin for i
		len--;
	}while(estaOrdenado==1);
}

void sortAscByNameTipe(Passenger* list, int len)
{
	int estaOrdenado;
	int j;
	int valor;

	do{
		estaOrdenado=0;
		j=0;
		for(int i=0; i<len-1; i++)
		{
			if(list[i].isEmpty==FULL)
			{
				for(j=i+1;j<len;j++)
				{
					if(list[j].isEmpty==FULL)
					{
						valor=(strcmp(list[i].nameLastName.lastName,list[j].nameLastName.lastName)>0);
						if(valor>0)
						{
							estaOrdenado=1;
							soap(list, i,j);
							break;
						}
						else
						{
							if(valor!=0 && list[i].typePassenger>list[j].typePassenger)
							{
								estaOrdenado=1;
								soap(list, i,j);
								break;
							}
						}
					}

				}
			}

		}//Fin for i
		len--;
	}while(estaOrdenado==1);

}


int sortPassengersByCode(Passenger* list,DateFlight* dateFlight , int len)
{
	int estaOrdenado;
	int j;
	int valor;
	int auxPosicionA;
	int auxPosicionB;

	do{
		estaOrdenado=0;
		j=0;
		for(int i=0; i<len-1; i++)
		{
			if(dateFlight[i].isEmpty==FULL)
			{
				for(j=i+1;j<len;j++)
				{
					if(dateFlight[j].isEmpty==FULL)
					{
						valor=(strncmp(dateFlight[i].flyCode,dateFlight[j].flyCode,51)>0);
						if(valor>0)
						{
							findPassengerById(list, dateFlight[i].idPasajero, &auxPosicionA, len);
							findPassengerById(list, dateFlight[j].idPasajero, &auxPosicionB, len);
							estaOrdenado=1;
							soap(list, auxPosicionA,auxPosicionB);
							break;
						}
					}

				}
			}

		}//Fin for i
		len--;
	}while(estaOrdenado==1);
	return 0;
}

void soap(Passenger* list,int posicionA, int posicionB)
{
	Passenger auxPassenger;
	auxPassenger = list[posicionA];
	list[posicionA] = list[posicionB];
	list[posicionB] = auxPassenger;

}


