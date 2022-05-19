/*
 * printList.c
 *
 *  Created on: 15 may 2022
 *      Author: Usuario Programador
 */

#include "ArrayZona.h"
#include "ArrayCencista.h"
#include "SortHead.h"
#include "utnInPuts.h"
#include "printList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define PENDIENTE -1
#define FINALIZADO 0
#define EMPTY 0
#define FULL -1
#define ACTIVO 1
#define INACTIVO -1
#define LIBERADO 0

int printListCensistas(Person* listPerson,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	if(listPerson!=NULL)
	{
		puts("Los censistas son:");
		puts("___________________________________________________________________________");
		puts("| \tID\t |  Apellido    |  Nombre       | Direccion      ");
		puts("---------------------------------------------------------------------------");

		for(int i=0;i<lenPerson;i++)
		{
			if(listPerson[i].isEmpty==FULL)
			{

				printOneCensista(&listPerson[i]);
				puts("___________________________________________________________________________");
				retorno=RETORNOPOSITIVO;
			}
		}
	}
	return retorno;
}

int printZonaLocalidad(datoZona* datoZona, localidad * listlocalidad,int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	for(int i=0;i<lenLocalidad;i++)
	{
		if(datoZona->localidadZona==listlocalidad[i].id)
		{
			printf("|%s\t         | %s   \n", datoZona->zonaCenso,listlocalidad[i].localidades);

			retorno=RETORNOPOSITIVO;
			break;
		}
	}
	return retorno;
}

int printListCensistaByStatus(Person* listPerson,char mensaje[],int order,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	if(listPerson!=NULL)
	{
		printf("Los censistas %s son:\n",mensaje);

		for(int i=0;i<lenPerson;i++)
		{
			if(listPerson[i].isEmpty==FULL)
			{
				if(listPerson[i].estadoActual==order)//ACTIVO
				{
					//printf("id %d nombre %s  apellido %s\n",listPerson[i].idCensista,listPerson[i].dataPerson.name,listPerson[i].dataPerson.lastName);

					printOneCensista(&listPerson[i]);
					retorno=RETORNOPOSITIVO;
				}
			}
		}
	}

	return retorno;
}

void printOneCensista(Person* person)
{
	printf("| \t%d\t |  %s\t|  %s\t| %s\t\n",person->idCensista,person->dataPerson.lastName,person->dataPerson.name,person->direccion.direccion);
}


int printLocalidad(localidad* localidad,int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	puts("LOCALIDADES: ");
	for(int i=0;i<lenLocalidad;i++)
	{
		if(localidad[i].isEmpty==FULL)
		{
			printf("%d-> %s\n",localidad[i].id,localidad[i].localidades);
		}

		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int printOneLocalidad(localidad* localidad)
{
	int retorno=RETORNONEGATIVO;
	puts("LOCALIDADES: ");

		if(localidad->isEmpty==FULL)
		{
			printf(" %s\n",localidad->localidades);
		}

		retorno=RETORNOPOSITIVO;

	return retorno;
}

int printAllZone(datoZona* listDatoZona,Person* listPerson,datosCenso* listdatosCenso,localidad* localidad,int lenPerson,int lenLocalidad,int lenDatoCenso)
{
	int retorno=RETORNONEGATIVO;
	int i;
	int flagIdCensista=RETORNOPOSITIVO;
	Person * punteroPerson;
	datoZona *punteroDatoZona;

	if(listDatoZona != NULL && listPerson != NULL && listdatosCenso != NULL)
	{
		if(utnIsEmptyOrFullZone(listDatoZona, FULL, lenDatoCenso)!=-1)
		{
			puts("----------------------------------------------------------------------------------------------------------------------\n");
			puts("------------ Datos Censista -------------------- listado de zonas ----------------------------------------------------\n");
			puts("-----------------------------------------|---------- CENSADOS -------------|------------------------------------------\n");
			puts("|Id Cesista |   Apellido   |   Nombre    |   Insitu | Virtual | Ausentes   |    Zona de Censo    |  Localidad           \n");
			puts("----------------------------------------------------------------------------------------------------------------------\n");

			for(i=0;i<lenPerson;i++)
			{
				if(listDatoZona[i].isEmpty==FULL)
				{
					flagIdCensista=RETORNOPOSITIVO;
					if(listDatoZona[i].idCensista==0)
					{
						printf("La zona aun no fue asignada a ningun censista\t\t\t\t   ");

						flagIdCensista=RETORNONEGATIVO;
					}

					if(flagIdCensista==RETORNOPOSITIVO)
					{
						for(int j=0;j<lenPerson;j++)
						{
							if(listDatoZona[i].idCensista==listPerson[j].idCensista )
							{

								if(listDatoZona[i].estadoCenso==FINALIZADO)
								{
									printf("|  %3d\t  |   %s\t   |  %s\t ",listPerson[j].idCensista,listPerson[j].dataPerson.lastName,listPerson[j].dataPerson.name);

									punteroPerson=&listPerson[j];
									printDatosCensados(punteroPerson, listdatosCenso, lenDatoCenso);
									break;//rompe for j
								}
								else
								{
									printf("|  %3d\t  |   %s\t   |  %s\t ",listPerson[j].idCensista,listPerson[j].dataPerson.lastName,listPerson[j].dataPerson.name);
									printf("|  No se han cargado datos\t   ");
									break;
								}

							}
						}

					}//fin validacion FlagidCensista
					punteroDatoZona=&listDatoZona[i];
					printZonaLocalidad(punteroDatoZona, localidad, lenLocalidad);
					retorno=RETORNOPOSITIVO;

				}
			}
		}
		else
		{
			puts("Aun no hay zonas cargadas");
		}



	}//Fin if

	return retorno;
}


int printPersonByLocalidad(datoZona* listDatoZona,Person* listPerson,datosCenso* listdatosCenso,localidad* localidades,int lenPerson,int lenLocalidad,int lenDatoCenso)
{
	int retorno=RETORNONEGATIVO;
	int auxLocalidad;
	int auxPosLocalidad;
	localidad * punteroLocalidad;
	if(listDatoZona != NULL && listPerson != NULL && listdatosCenso != NULL)
		{
			printLocalidad(localidades, lenLocalidad);
			if(utnGetNumero(&auxLocalidad, "Seleccione el numero que de localidad que corresponda o 0 para cancelar\n",
						"Error al seleccionar Localidad", "Opcion incorrecta. Desea reintentar?\n",0, lenLocalidad, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(findLocalidadById(localidades, auxLocalidad, &auxPosLocalidad, lenLocalidad)==RETORNOPOSITIVO)
				{
					punteroLocalidad=&localidades[auxPosLocalidad];
					puts("----------------------------------------------------------------------------------------------------------------------\n");
					puts("------------ Datos Censista ------------------------------------------------------------------------------------------\n");
					puts("-----------------------------------------|---------------------------------|------------------------------------------\n");
					puts("|Id Cesista |   Apellido   |   Nombre    |                 |    Zona de Censo    |  Localidad                         \n");
					puts("----------------------------------------------------------------------------------------------------------------------\n");
					for(int i=0;i<lenPerson;i++)
					{
						if(listPerson[i].isEmpty==FULL)
						{
							for(int j=0;j<lenDatoCenso;j++)
							{
								if(listDatoZona[j].isEmpty==FULL)
								{
									if(listPerson[i].idCensista==listDatoZona[j].idCensista && listDatoZona[j].localidadZona==auxLocalidad)
									{
										printf("%d    %s\t  %s\t    %s\t  ",listPerson[i].idCensista,listPerson[i].dataPerson.lastName,listPerson[i].dataPerson.name,listDatoZona[j].zonaCenso);
										printOneLocalidad(punteroLocalidad);
										retorno=RETORNOPOSITIVO;
									}
								}
							}
						}
					}


				}
			}


		}
	return retorno;
}

int printZonaById(datoZona* datoZona, int lenZona)
{
	int retorno=RETORNONEGATIVO;
	puts("_____________________________________________");
	puts("|  ID Zona  |   Zona     |   Id Localidad   |");
	if(datoZona!=NULL)
	{
		for(int i=0;i<lenZona;i++)
		{
			if(datoZona[i].isEmpty==FULL && datoZona[i].estadoCenso!=PENDIENTE)
			{
				printf("| %3d       |\t%s\t |  %3d         |\n",datoZona[i].idZona,datoZona[i].zonaCenso,datoZona[i].localidadZona);
			}
		}
	}
	return retorno;
}


int printDatosCensados(Person* person, datosCenso *listDatosCenso, int lenDatosCenso)
{
	int retorno=RETORNONEGATIVO;
	for(int k=0; k<lenDatosCenso;k++)
	{
		if(person->idCensista==listDatosCenso[k].idCensista)
		{
			printf("|   %3d   |   %3d    |   %2d  ",listDatosCenso[k].censadosInSitu,listDatosCenso[k].censadosVirtual,listDatosCenso[k].ausentes);
			retorno=RETORNOPOSITIVO;
			break;
		}
	}
	return retorno;
}

void printPersonByLastname(Person* listperson,int lenPerson)
{

	sortPersonByLastName(listperson, lenPerson);
	printListCensistas(listperson, lenPerson);

}

int printPersonByCantidadCensados(datosCenso* listDatosCenso,Person* listPerson, int lenDatosCenso)
{
	int retorno=RETORNONEGATIVO;
	Person * punteroPerson;

	sortPersonByCantidadCensados(listDatosCenso, lenDatosCenso);
	puts("____________________________________________________________________________");
	puts("| TOTAL CENSADOS |  ID CENSISTA  |   APELLIDO   |  NOMBRE       | Domicilio ");
	for(int i=0;i<lenDatosCenso;i++)
	{

		if(listDatosCenso[i].isEmpty==FULL)
		{
			for(int j=0;j<lenDatosCenso;j++)
			{

				if(listPerson[j].isEmpty==FULL)
				{
					if(listDatosCenso[i].idCensista==listPerson[j].idCensista)
					{
						punteroPerson=&listPerson[j];
						printf("|  \t%d\t ",listDatosCenso[i].totalCensados);
						printOneCensista(punteroPerson);
						retorno=RETORNOPOSITIVO;
						break;
					}
				}
			}
		}
		break;// Si se saca trae a todos los sencistas con sus totales
	}

	return retorno;
}



