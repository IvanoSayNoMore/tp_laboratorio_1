/*
 * PuntoDeMenu.c
 *
 *  Created on: 16 may 2022
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

#define EMPTY 0
#define FULL -1
#define MINIMOIDS 0
#define MAXIMOSIDS 1000
#define MAXIMOCADENA 51
//////////////
#define ACTIVO 1
#define INACTIVO -1
#define LIBERADO 0
#define PENDIENTE -1
#define FINALIZADO 0
//////////////
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1

int menuItemEnterPerson(Person* listPerson,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	if(listPerson!=NULL)
	{
		int espacioPerson;

		Person * punteroPerson;
		espacioPerson=utnIsEmptyOrFullPerson(listPerson, EMPTY, lenPerson);
		punteroPerson=&listPerson[espacioPerson];

		if(espacioPerson != RETORNONEGATIVO)
		{
			if(validAddPerson(punteroPerson, lenPerson)==RETORNONEGATIVO)
			{
				puts("Error al cargar el censista.");
			}
		}
		else
		{
			puts("No hay espacios para mas censistas");
		}

	}
	return retorno;
}

int menuItemChangePerson(Person* listPerson, int lenPerson)
{
	int retorno=RETORNOPOSITIVO;
	int auxId;
	int auxPosicion;
	Person * punteroPerson;

	if(listPerson!=NULL)
	{

		if(utnIsEmptyOrFullPerson(listPerson, FULL, lenPerson)!=RETORNONEGATIVO)
		{
			printListCensistas(listPerson, lenPerson);
			if(utnGetNumero(&auxId, "\nIngrese el ID a modificar o 0 si desea cancelar la modificacion:\n", "Ocurrio un error al ingresar el ID\n"
								, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(auxId==0)
				{
					retorno=RETORNONEGATIVO;
					puts("Se cancela la modificacion");
				}
				else
				{
					if(findPersonById(listPerson, auxId, &auxPosicion, lenPerson)==RETORNOPOSITIVO && retorno==RETORNOPOSITIVO)
					{
						punteroPerson=&listPerson[auxPosicion];
						changePerson(punteroPerson, MAXIMOCADENA);
					}
					else
					{
						puts("Error al ingresar ID a modificar\n");
					}
				}

			}
		}
		else
		{
			puts("No se encontraron Censistas. \n");
		}
	}



	return retorno;
}

int menuItemDeletPerson(Person* listPerson, int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int auxPosicion;
	Person * punteroPersona;
	if(listPerson!=NULL)
	{

		if(utnIsEmptyOrFullPerson(listPerson, FULL, lenPerson)!=RETORNONEGATIVO)
		{
			printListCensistaByStatus(listPerson,"LIBERADOS",LIBERADO, lenPerson);
			if(utnGetNumero(&auxId, "\nIngrese el ID a Borrar o 0 para cancelar :\n", "Ocurrio un error al ingresar el ID\n"
					, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(auxId==0)
				{
					puts("Se cancela el borrado");

				}
				else
				{
					if(findPersonById(listPerson, auxId, &auxPosicion, lenPerson)==RETORNOPOSITIVO)
					{
						punteroPersona=&listPerson[auxPosicion];
						if(punteroPersona->estadoActual==ACTIVO)
						{
							puts("El Censista actualmente tiene una zona asignada. ");
						}
						else
						{
							if(punteroPersona->estadoActual==INACTIVO)
							{
								puts("Actualmente , el id seleccionado esta inactivo ");
							}
							else
							{
								if(deletPerson(punteroPersona)==RETORNOPOSITIVO)
								{
									puts("Eliminado Correctamente\n");
									retorno=RETORNOPOSITIVO;
								}
							}

						}

					}
					else
					{
						puts("Error al seleccionar Censista");
					}

				}

			}
		}
		else
		{
			puts("No se encontraron Censistas. \n");
		}

	}
	return retorno;
}

int menuItemAddZona(datoZona* listZona,  localidad* localidad,int lenZona,int lenLocalidad)
{
	int retorno=RETORNONEGATIVO;
	int auxLocalidad;
	char auxZona[MAXIMOCADENA];
	int validar;
	int auxIdZona;
	datoZona * punteroZona;

	if(listZona != NULL )
	{
		validar=utnIsEmptyOrFullZone(listZona, EMPTY, lenZona);
		if(validar!=RETORNONEGATIVO)
		{
			printLocalidad(localidad, lenLocalidad);
			if(ingressZone(&auxLocalidad, auxZona, lenLocalidad, MAXIMOCADENA)==RETORNOPOSITIVO)
			{
				contadorIdZone(&auxIdZona);
				punteroZona=&listZona[validar];
				if(addZone(punteroZona, auxLocalidad,auxIdZona, auxZona)==RETORNOPOSITIVO)
				{
					printf("Id de zona %d   ",punteroZona->idZona);
					puts("Alta de zona correcta ");
				}
			}
			else
			{
				puts("Error en la carga de ZONA");
			}
		}
		else
		{
			puts("No se espacios para cargar Zonas ");
		}

	}


	return retorno;
}

int menuItemAssignZona(datoZona* listZona,Person* listPerson, int lenZona,int lenPerson)
{
	int validarZona;
	int validarPerson;
	int auxIdZona;
	int auxIdPerson;
	int posicionZona;

	int retorno=RETORNONEGATIVO;

	datoZona* punteroZona;
	if(listZona != NULL && listPerson != NULL)
	{
		validarZona=utnIsEmptyOrFullZone(listZona, FULL, lenZona);
		validarPerson=utnIsEmptyOrFullPerson(listPerson, FULL, lenPerson);
		if(validarZona!=RETORNONEGATIVO && validarPerson!=RETORNONEGATIVO)
		{
			printZonaById(listZona, lenZona);
			if(utnGetNumero(&auxIdZona, "Ingrese el id de la zona para asignar\n",
					"Error al seleccionar opcion\n", "Desea reintentar?\n", 1, 20, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(findZonaById(listZona, auxIdZona, &posicionZona, lenZona)==RETORNOPOSITIVO)
				{
					punteroZona=&listZona[posicionZona];
					if(punteroZona->idCensista==0)
					{
						printListCensistaByStatus(listPerson,"LIBERADO", LIBERADO,lenPerson);
						if(utnGetNumero(&auxIdPerson, "Ingrese el id del censista a asignar o 0 para camcelar \n",
								"Error al seleccionar censista\n", "Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
						{
							if(auxIdPerson==0)
							{
								puts("se cancela la asignacion");
							}
							else
							{
								if(validAssigZona(listPerson, punteroZona,auxIdPerson, lenPerson)==RETORNOPOSITIVO)
								{
									puts("Se asigno correctamente");
								}
							}

							/*if(findPersonById(listPerson, auxIdPerson, &posicionPerson, lenPerson)==RETORNOPOSITIVO)
							{
								punteroPersona=&listPerson[posicionPerson];
								if(punteroPersona->estadoActual==LIBERADO)
								{
									assignZone(punteroZona, auxIdPerson);
									retorno=RETORNOPOSITIVO;
								}
								else
								{
									puts("Actualmente , el id seleccionado esta inactivo o tiene una zona asignada.  ");
								}

							}//busca censista por id*/
						}
					}//verifica pendiente
					else
					{
						puts("La zona solicitada ya tiene un Censista asignado");
					}
				}
			}
		}
		else
		{
			puts("No hay zonas o personas cargadas ");
		}
	}
	return retorno;
}

int menuItemAddDataZona(datoZona* listZona,datosCenso* listCenso,Person* listPerson, int lenZona,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	int auxId;
	int auxPosicionPerson;//ver si puedo dejar solo un aux
	int auxPosicionZona;
	int auxAusentes;
	int auxInSitu;
	int auxVirtual;
	int posicionDatoCenso;
	datosCenso * punteroDatoCenso;
	Person * punteroPerson;
	datoZona * punteroDatoZona;

	if(listZona != NULL && listCenso != NULL && listPerson != NULL)
	{
		posicionDatoCenso=utnIsEmptyOrFullDatCenso(listCenso, EMPTY, lenZona);

		if(utnIsEmptyOrFullPerson(listPerson, FULL, lenPerson)!=RETORNONEGATIVO && posicionDatoCenso!=RETORNONEGATIVO)
		{
			printListCensistaByStatus(listPerson,"ACTVOS",ACTIVO, lenPerson);

			if(utnGetNumero(&auxId, "\nIngrese el ID a del censista que cargara datos o 0 si desea cancelar:\n", "Ocurrio un error al ingresar el ID\n"
								, "Error al ingresar Opcion. Desea reintentar?\n", MINIMOIDS, MAXIMOSIDS, REINTENTOS)==RETORNOPOSITIVO)
			{
				if(auxId!=0)
				{
					if(findPersonById(listPerson, auxId, &auxPosicionPerson, lenPerson)==RETORNOPOSITIVO)
					{

						punteroPerson=&listPerson[auxPosicionPerson];
						if(punteroPerson->estadoActual==ACTIVO)
						{
							if(findZonaByIdCensista(listZona, punteroPerson->idCensista, &auxPosicionZona, lenZona)==RETORNOPOSITIVO)
							{
								if(ingressDateCenso(&auxAusentes, &auxInSitu, &auxVirtual)==RETORNOPOSITIVO)
								{
									punteroDatoZona=&listZona[auxPosicionZona];
									punteroDatoCenso=&listCenso[posicionDatoCenso];

									if(addDataZona(punteroDatoZona, punteroDatoCenso, punteroPerson->idCensista,
											auxInSitu, auxVirtual, auxAusentes)==RETORNOPOSITIVO)
									{
										punteroPerson->estadoActual=LIBERADO;
										printf("Los datos se del Censista %s han cargado correctamente \n  ",punteroPerson->dataPerson.lastName);

									}

								}
								else
								{
									puts("Error al cargar datos de censo\n ");
								}
							}

						}
						else
						{
							puts("El censista no tiene zonas asignadas\n ");
						}


					}
					else
					{
						puts("No se encontraron cencistas con el ID ingresado");
					}
				}
				else
				{
					puts("Se cancela la carga");
				}

			}

		}
		else
		{
			puts("Aun no se cargaron los datos necesarios para Cargar datos ");
		}


	}

	return retorno;
}

int menuItemPrintCensistas(Person* listPerson,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	int auxOpcion;
	if(listPerson!=NULL)
	{
		if(utnIsEmptyOrFullPerson(listPerson,FULL,lenPerson)!=RETORNONEGATIVO)
		{
			if(utnGetNumero(&auxOpcion, "Ingrese:\n 0-Si desea ver todos los censistas\n1- Si desea ver los censistas Activos si\n2- Si desea ver los censista INACTIVOS\n3- Para ver los liberados\n4-Para cancelar \n",
						"Error al seleccionar censista\n", "Desea reintentar?\n", 0, 4, REINTENTOS)==RETORNOPOSITIVO)
				{
					retorno=RETORNOPOSITIVO;
					switch(auxOpcion)
					{

					case 0:
						if(printListCensistas(listPerson, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron cencistas");
						}
						break;
					case 1:
						if(printListCensistaByStatus(listPerson, "ACTIVOS",ACTIVO, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron Censistas activos");
						}
						break;
					case 2:
						if(printListCensistaByStatus(listPerson,"INACTIVOS", INACTIVO, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron cencistas inactivos");
						}
						break;
					case 3:
						if(printListCensistaByStatus(listPerson, "LIBERADOS",LIBERADO, lenPerson)==RETORNONEGATIVO)
						{
							puts("No se encontraron cencistas liberados");
						}
						break;
					case 4:

						puts("Se cancela el informe");
						break;
					}
				}
		}
		else
		{
			puts("No se encontraron Censistas. \n");
		}

	}

	return retorno;
}

int menuItemHardCode(datoZona* listZona,datosCenso* listCenso,Person* listPerson, int lenZona,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	int espacioPerson;
	int espacioDatoZona;
	int auxId;
	int auxIdZona;


	datoZona * punteroDatoZona;
	Person * punteroPerson;

	espacioPerson=utnIsEmptyOrFullPerson(listPerson, EMPTY, lenPerson);
	contadorId(&auxId);
	punteroPerson=&listPerson[espacioPerson];
	if(addPerson(punteroPerson, auxId, "Ivano", "BBabella",
			"Segurola y Habana 547", 19, 04, 1993, 29)==RETORNOPOSITIVO)
	{
		printf("Alta exitosa con el ID numero %d\n",auxId);
	}

	espacioPerson=utnIsEmptyOrFullPerson(listPerson, EMPTY, lenPerson);
	punteroPerson=&listPerson[espacioPerson];
	contadorId(&auxId);
	if(addPerson(punteroPerson, auxId, "Aldana", "AAMedina",
			"Calle falsa 123", 04, 02, 1992, 30)==RETORNOPOSITIVO)
	{
		printf("Alta exitosa con el ID numero %d\n",auxId);
	}

	espacioPerson=utnIsEmptyOrFullPerson(listPerson, EMPTY, lenPerson);
	punteroPerson=&listPerson[espacioPerson];
	contadorId(&auxId);
	if(addPerson(punteroPerson, auxId, "Enano", "DDZazu",
			"Juana manso 123", 19, 04, 2019, 3)==RETORNOPOSITIVO)
	{
		printf("Alta exitosa con el ID numero %d\n",auxId);
	}
	///////hard Censista


	espacioDatoZona=utnIsEmptyOrFullZone(listZona, EMPTY, lenZona);
	contadorIdZone(&auxIdZona);
	punteroDatoZona=&listZona[espacioDatoZona];
	if(addZone(punteroDatoZona, 2,auxIdZona, "OESTE")==RETORNOPOSITIVO)
	{
		printf("Id de zona %d   ",punteroDatoZona->idZona);
		puts("Alta de zona correcta\n ");
	}

	espacioDatoZona=utnIsEmptyOrFullZone(listZona, EMPTY, lenZona);
	contadorIdZone(&auxIdZona);
	punteroDatoZona=&listZona[espacioDatoZona];
	if(addZone(punteroDatoZona, 2,auxIdZona, "ESTE")==RETORNOPOSITIVO)
	{
		printf("Id de zona %d   ",punteroDatoZona->idZona);
		puts("Alta de zona correcta\n ");
	}

	espacioDatoZona=utnIsEmptyOrFullZone(listZona, EMPTY, lenZona);
	contadorIdZone(&auxIdZona);
	punteroDatoZona=&listZona[espacioDatoZona];
	if(addZone(punteroDatoZona, 1,auxIdZona, "CENTRO")==RETORNOPOSITIVO)
	{
		printf("Id de zona %d   ",punteroDatoZona->idZona);
		puts("Alta de zona correcta\n ");
	}

	espacioDatoZona=utnIsEmptyOrFullZone(listZona, EMPTY, lenZona);
	contadorIdZone(&auxIdZona);
	punteroDatoZona=&listZona[espacioDatoZona];
	if(addZone(punteroDatoZona, 3,auxIdZona, "Villa Porvenir")==RETORNOPOSITIVO)
	{
		printf("Id de zona %d   ",punteroDatoZona->idZona);
		puts("Alta de zona correcta\n ");
	}
	espacioDatoZona=utnIsEmptyOrFullZone(listZona, EMPTY, lenZona);
	contadorIdZone(&auxIdZona);
	punteroDatoZona=&listZona[espacioDatoZona];
	if(addZone(punteroDatoZona, 4,auxIdZona, "Parque Dominico")==RETORNOPOSITIVO)
	{
		printf("Id de zona %d   ",punteroDatoZona->idZona);
		puts("Alta de zona correcta\n ");
	}
	//hard Zona

	int posicionZona;
	if(findZonaById(listZona, 1, &posicionZona, lenZona)==RETORNOPOSITIVO)
	{
		punteroDatoZona=&listZona[posicionZona];

		if(validAssigZona(listPerson, punteroDatoZona,2, lenPerson)==RETORNOPOSITIVO)
		{
			puts("Se asigno correctamente");
		}
	}

	if(findZonaById(listZona, 2, &posicionZona, lenZona)==RETORNOPOSITIVO)
	{
		punteroDatoZona=&listZona[posicionZona];

		if(validAssigZona(listPerson, punteroDatoZona,3, lenPerson)==RETORNOPOSITIVO)
		{
			puts("Se asigno correctamente");
		}
	}
	//

	if(findZonaByIdCensista(listZona, 3, &posicionZona, lenZona)==RETORNOPOSITIVO)
	{
		punteroDatoZona=&listZona[posicionZona];

		addDataZona(punteroDatoZona, listCenso, 3, 2533, 32522, 1000);
		punteroPerson->estadoActual=LIBERADO;
		printf("Los datos se del Censista %s han cargado correctamente \n  ",punteroPerson->dataPerson.lastName);

	}

	return retorno;

}

int menuItemOrdenamientos(datoZona* listZona,datosCenso* listCenso,Person* listPerson, int lenZona,int lenPerson)
{
	int retorno=RETORNONEGATIVO;

	sortPersonByLastName(listPerson, lenPerson);
	printListCensistas(listPerson, lenPerson);

	if(printPersonByCantidadCensados(listCenso, listPerson, lenZona)==RETORNONEGATIVO)
	{
		puts("Aun no hay datos cargados para realizar los calculos");
	}

	sortPersonByDireccion(listPerson, lenPerson);
	printListCensistas(listPerson, lenPerson);

	return retorno;
}












