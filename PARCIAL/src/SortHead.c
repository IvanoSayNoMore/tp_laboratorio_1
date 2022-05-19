/*
 * SortHead.c
 *
 *  Created on: 18 may 2022
 *      Author: Usuario Programador
 */
#include "ArrayZona.h"
#include "ArrayCencista.h"
#include "SortHead.h"
#include "Calculos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY 0
#define FULL -1

int sortPersonByLastName(Person* listPerson, int lenPerson)
{
	int retorno;

	int estaOrdenado;
	int j;
	int valor;

	do{
		estaOrdenado=0;
		j=0;
		for(int i=0; i<lenPerson-1; i++)
		{
			if(listPerson[i].isEmpty==FULL)
			{
				for(j=i+1;j<lenPerson;j++)
				{
					if(listPerson[j].isEmpty==FULL)
					{
						valor=(strcmp(listPerson[i].dataPerson.lastName,listPerson[j].dataPerson.lastName)>0);
						if(valor>0)
						{
							estaOrdenado=1;
							soap(listPerson, i,j);
							retorno=0;
							break;
						}
					}

				}
			}

		}//Fin for i
		lenPerson--;
	}while(estaOrdenado==1);


	return retorno;
}

void soap(Person* list,int posicionA, int posicionB)
{
	Person auxPassenger;
	auxPassenger = list[posicionA];
	list[posicionA] = list[posicionB];
	list[posicionB] = auxPassenger;

}


int sortPersonByCantidadCensados(datosCenso* datos, int lenDatosCenso)
{
	int estaOrdenado;
	int retorno=-1;

	if(datos!=NULL)
	{

		do{
			estaOrdenado=0;
			int j=0;
			dataCollection(datos, lenDatosCenso);
			for(int i=0;i<lenDatosCenso-1;i++)
			{
				if(datos[i].isEmpty==FULL)
				{
					for(j=i+1;j<lenDatosCenso;j++)
					{
						if(datos[j].isEmpty==FULL)
						{
							if(datos[i].totalCensados<datos[j].totalCensados)
							{
								soapDatoCenso(datos, i, j);
							}
						}
					}

				}
			}
			lenDatosCenso--;
		}while(estaOrdenado==1);
	}

	return retorno;
}

void sortPersonByDireccion(Person* person, int lenPerson)
{

	int estaOrdenado;
	int valida;
	if(person!=NULL)
	{

		do{
			estaOrdenado=0;
			int j=0;
			for(int i=0;i<lenPerson-1;i++)
			{
				if(person[i].isEmpty==FULL)
				{
					for(j=i+1;j<lenPerson;j++)
					{
						if(person[j].isEmpty==FULL)
						{
						valida=strncmp(person[i].direccion.direccion,person[j].direccion.direccion,sizeof(person->direccion.direccion));
						if(valida>0)
							{
								soap(person, i, j);
							}
						}
					}

				}
			}
			lenPerson--;
		}while(estaOrdenado==1);
	}

}
void soapDatoCenso(datosCenso* list,int posicionA, int posicionB)
{
	datosCenso auxDatoCenso;
	auxDatoCenso = list[posicionA];
	list[posicionA] = list[posicionB];
	list[posicionB] = auxDatoCenso;
}





