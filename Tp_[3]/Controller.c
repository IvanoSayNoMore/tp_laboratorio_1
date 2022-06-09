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
#include "Passenger.h"
#include "parser.h"
#include "utnInPuts.h"
#include "Controller.h"
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define REINTENTOS 3
#define MAXIMOCHAR 51

static int controller_buscaIdMaximo(LinkedList* pArrayListPassenger);

static int controller_nuevoIdPartiendoDelMaximo(LinkedList* pArrayListPassenger,int* nuevoId);

static int controller_nuevoIdPartiendoDelMaximo(LinkedList* pArrayListPassenger,int* nuevoId)
{
	int retorno=RETORNONEGATIVO;
    static int id = 0 ;
    static int primeraEntrada = RETORNOPOSITIVO;

    if(pArrayListPassenger != NULL)
    {
    	if(primeraEntrada == RETORNOPOSITIVO)
    	{
    		id = controller_buscaIdMaximo(pArrayListPassenger);
    		primeraEntrada = RETORNONEGATIVO;;
    	}
    	*nuevoId=id++;
    	retorno=RETORNOPOSITIVO;
    }
    return retorno;
}

static int controller_buscaIdMaximo(LinkedList* pArrayListPassenger)
{
	Passenger* pPassenger;
	int len;
	int maxId;
	int id=0;

	if(pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		//printf("LEN: %d \n",len);
		for(int i=0;i<len;i++)
		{
			pPassenger = ll_get(pArrayListPassenger,i);
			Passenger_getId(pPassenger,&id);
			if (i == 0 || id > maxId)
			{
				maxId = id;
			}
		}
		id = maxId;
	}
	return id;
}

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -2;
	FILE *pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			retorno = parser_PassengerFromText(pFile, pArrayListPassenger);
			fclose(pFile);//mmmm

		}
		else
		{
			retorno=RETORNONEGATIVO;
		}
	}
	else
	{
		puts("Error . -> path == NULL || pArrayListPassenger == NULL ");
	}
	return retorno;

}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -2;
	FILE *pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			retorno=parser_PassengerFromBinary(pFile, pArrayListPassenger);
			fclose(pFile);
		}
		else
		{
			retorno=RETORNONEGATIVO;
		}
	}

    return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=RETORNONEGATIVO;
	Passenger* pPassenger;
	Passenger passenger;


	if(pArrayListPassenger != NULL)
	{
		if(controller_ingresPassenger(passenger.nombre, passenger.apellido,
				passenger.tipoPasajero,&passenger.precio,passenger.codigoVuelo,passenger.statusFlight, MAXIMOCHAR)==RETORNOPOSITIVO)
		{
			controller_nuevoIdPartiendoDelMaximo(pArrayListPassenger, &passenger.id);
			passenger.id++;
			pPassenger=Passenger_newParametros(passenger.id, passenger.nombre,
					passenger.apellido, passenger.precio, passenger.codigoVuelo, passenger.tipoPasajero, passenger.statusFlight);

			if(pPassenger != NULL)
			{
				retorno = ll_add(pArrayListPassenger, pPassenger);
				retorno=RETORNOPOSITIVO;
			}
		}
	}
	else
	{
		puts("\n\npArrayListPassenger==NULL\n");
		retorno=-2;
	}

    return retorno;
}

int controller_ingresPassenger(char name[],char lastName[],char typePassenger[],float* price, char flyCode[],char estadoVuelo[], int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	int auxTipo;
	int auxEstado;
	Passenger auxPasajero;


	do{
		if(utnIngressNameLastname(auxPasajero.nombre, "\nIngrese el nombre del pasajero: \n", lenCadena)==RETORNOPOSITIVO
				&& utnIngressNameLastname(auxPasajero.apellido, "\nIngrese el apellido del pasajero: \n", lenCadena)==RETORNOPOSITIVO
				&& utnGetNumero(&auxTipo, "\nIngrese el tipo, hay 2 .\n","Reintente TIPO\n", "Error. Hay 2 tipos maximos. Desea reintentar?\n", 0,1, REINTENTOS)==RETORNOPOSITIVO
				&& utnGetNumero(&auxEstado, "\nIngrese el estado del vuelo , hay 2 .\n","Reintente TIPO\n", "Error. Hay 2 tipos maximos. Desea reintentar?\n", 1, 2, REINTENTOS)==RETORNOPOSITIVO
				&& utnIngresarFlotante("\nIngrese el precio del vuelo\n",&auxPasajero.precio,REINTENTOS)!=RETORNONEGATIVO
				&& utnIngresarAlfanumerico(auxPasajero.codigoVuelo, "Ingrese codigo del Vuelo a asignar\n",REINTENTOS,lenCadena)==RETORNOPOSITIVO)
		{
			strncpy(name,auxPasajero.nombre,lenCadena);
			strncpy(lastName,auxPasajero.apellido,lenCadena);
			strncpy(flyCode,auxPasajero.codigoVuelo,lenCadena);
			*price=auxPasajero.precio;
			controller_convierte(auxTipo, auxPasajero.tipoPasajero, "FirstClass", "ExecutiveClass");
			strncpy(typePassenger,auxPasajero.tipoPasajero,lenCadena);
			controller_convierte(auxEstado, auxPasajero.statusFlight, "En Horario", "Aterrizado");
			strncpy(estadoVuelo, auxPasajero.statusFlight,lenCadena);
			retorno=RETORNOPOSITIVO;
		}
		else
		{
			if(utnVerificacionConChar("Ocurrio un error al ingresar algun dato del vuelo. Desea reintentar? Si o no\n"
					,"Vuelva a intentar. \n", "Adios", 0)!=RETORNOPOSITIVO)
			{
				break;
			}

		}
	}while(retorno==RETORNONEGATIVO);

	return retorno;

}

void controller_convierte(int opcion, char* tipoChar,char* opcionAsgnarA, char*opcionAsignarB)
{
	if(opcion==1)
	{
		strncpy(tipoChar,opcionAsgnarA,51);
	}
	else
	{
		strncpy(tipoChar,opcionAsignarB,51);
	}
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int posicionPasajeroId;
	Passenger auxPasajero;
	if(pArrayListPassenger != NULL )
	{
		if(utnGetNumero(&auxPasajero.id, "\nIngrese el ID del pasajero a modificar",
				"\nError al ingresar ID", "\nDesea reintentar?",1, 5000, REINTENTOS)==RETORNOPOSITIVO)
		{
			if(controller_findPassengerById(pArrayListPassenger,auxPasajero.id,&posicionPasajeroId)==RETORNOPOSITIVO)
			{
				controller_cambioDeDatos(pArrayListPassenger,posicionPasajeroId);
			}
			else
			{
				puts("no se encontro el ID");
			}
		}
	}
    return 1;
}

int controller_cambioDeDatos(LinkedList* pArrayListPassenger,int posicion)
{
	int retorno=RETORNOPOSITIVO;
	int opcion;
	int auxInt;
	int flagOk;
	int continuar;
	Passenger auxPasajero;
	Passenger * pPasajero;
	pPasajero = (Passenger*)ll_get(pArrayListPassenger, posicion);
	if(pPasajero != NULL)
	{
		do{
			puts("El pasajero a modificar  es : ");
			controller_scanPasajeroParaImprimir(pArrayListPassenger, posicion);
			puts("-------------------------------------------------------------------------------------------------\n");
			if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-Tipo de pasajero\n4-Para cancelar la modificacion\n "
					,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 1, 4, REINTENTOS)==RETORNOPOSITIVO)
			{
				switch(opcion)
				{
				case 1:
					if(utnIngressNameLastname(auxPasajero.nombre, "\nIngrese su nombre: \n", MAXIMOCHAR)==RETORNOPOSITIVO)
					{
						printf("Cambio exitoso, el nuevo nombre es el de %s\n",auxPasajero.nombre);
						Passenger_setNombre(pPasajero, auxPasajero.nombre);
				//		strncpy(pPasajero->nombre,auxPasajero.nombre,MAXIMOCHAR);
						flagOk=RETORNOPOSITIVO;
						break;
					}
					else
					{
						flagOk=RETORNONEGATIVO;
						break;
					}

				case 2:
					if(utnIngressNameLastname(auxPasajero.apellido, "\nIngrese su apellido: \n", MAXIMOCHAR)==RETORNOPOSITIVO)
					{
						printf("Cambio exitoso, el nuevo apellido es el de %s\n",auxPasajero.apellido);
						Passenger_setApellido(pPasajero, auxPasajero.apellido);
						flagOk=RETORNOPOSITIVO;
						break;
					}
					else
					{
						flagOk=RETORNONEGATIVO;
						break;
					}

				case 3:
					if(utnGetNumero(&auxInt, "\nIngrese el tipo\n", "Error al ingresar tipo\n", "", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
					{
						controller_convierte(auxInt, auxPasajero.tipoPasajero, "FirstClass", "ExecutiveClass");
						Passenger_setTipoPasajero(pPasajero, auxPasajero.tipoPasajero);
						printf("Cambio exitoso, el nuevo tipo es el de %s\n",auxPasajero.tipoPasajero);
						flagOk=RETORNOPOSITIVO;
						break;
					}
					else
					{
						flagOk=RETORNONEGATIVO;
						break;
					}
				case 4:
					puts("Se cancela la opcion modificar\n");
					flagOk=RETORNOPOSITIVO;
					break;
				default :
					flagOk=RETORNONEGATIVO;
					puts("Error de opcion\n");

				}//Fin Switch

			}//Fin If utnGetNumero
			if(flagOk==RETORNOPOSITIVO)
			{
				continuar=utnVerificacionConChar( "Desea continuar con la opcion de cambio de datos personales ? \n",
									"Seleccione que desea modificar\n", "Finaliza la modificacion de datos personales" , 0);
			}
			else
			{
				continuar=utnVerificacionConChar( "Ocurrio un error al modificar,desea continuar el cambio de datos personales ?\n",
									"Seleccione que desea modificar\n", "Finaliza la modificacion de datos personales " , 0);
			}

		}while(continuar==RETORNOPOSITIVO);
	}

	return retorno;
}

int controller_findPassengerById(LinkedList* pArrayListPassenger, int id,int* posicion)
{
	int retorno=RETORNONEGATIVO;
	int lenListPassenger;
	int auxId;
	Passenger * pPasajero;
	if(pArrayListPassenger != NULL && id > -1)
	{
		lenListPassenger = ll_len(pArrayListPassenger);
		for(int i = 0 ; i<lenListPassenger;i++)
		{
			pPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			if(pPasajero != NULL
					&& Passenger_getId(pPasajero, &auxId)==RETORNOPOSITIVO
					&& auxId==id)
			{
				*posicion=i;
				retorno=RETORNOPOSITIVO;
				break;
			}
		}
	}

	return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int posicionPasajeroId;
	int retorno=RETORNONEGATIVO;
	int auxId;
	Passenger* pPasajero;
	if(pArrayListPassenger != NULL )
	{
		if(utnGetNumero(&auxId, "\nIngrese el ID del pasajero a eliminar",
				"\nError al ingresar ID", "\nDesea reintentar?",1, 5000, REINTENTOS)==RETORNOPOSITIVO)
		{
			if(controller_findPassengerById(pArrayListPassenger,auxId,&posicionPasajeroId)==RETORNOPOSITIVO)
			{
				pPasajero = (Passenger*)ll_get(pArrayListPassenger, posicionPasajeroId);
				if(pPasajero!=NULL)
				{
					puts("\nEl pasajero a eliminar es : ");
					controller_scanPasajeroParaImprimir(pArrayListPassenger, posicionPasajeroId);
					if(utnVerificacionConChar("Realmente desa Eliminarlo?", "Pasajero Eliminado", "Se procede a la eliminacion", 0)==RETORNOPOSITIVO)
					{
						Passenger_delete(pPasajero);
						retorno = ll_remove(pArrayListPassenger, posicionPasajeroId);
					}

				}

			}
			else
			{
				puts("no se encontro el ID");

			}
		}
	}

    return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = RETORNONEGATIVO;
    int len;

    if(pArrayListPassenger != NULL)
    {
    	len = ll_len(pArrayListPassenger);

    	puts("|   ID    | NOMBRE |  APELLIDO  |   PRECIO  |     C.VUELO     | T.PASAJERO | ESTADO VUELO | ");

    	for(int i=0;i<len;i++)
    	{
    		retorno = controller_scanPasajeroParaImprimir(pArrayListPassenger,i);
    	}
    }
    return retorno;
}

int controller_scanPasajeroParaImprimir(LinkedList* pArrayListPassenger, int posicion)
{
	int retorno=RETORNONEGATIVO;
	Passenger* pPasajero;
	Passenger pasajeroAux;
	if(pArrayListPassenger != NULL && posicion > -1)
	{
		pPasajero = (Passenger*)ll_get(pArrayListPassenger, posicion);
		if(pPasajero != NULL
				&& Passenger_getId(pPasajero, &pasajeroAux.id) 					  	 == RETORNOPOSITIVO
				&& Passenger_getNombre(pPasajero, pasajeroAux.nombre)				 == RETORNOPOSITIVO
				&& Passenger_getApellido(pPasajero, pasajeroAux.apellido)			 == RETORNOPOSITIVO
				&& Passenger_getPrecio(pPasajero, &pasajeroAux.precio)				 == RETORNOPOSITIVO
				&& Passenger_getCodigoVuelo(pPasajero, pasajeroAux.codigoVuelo)		 == RETORNOPOSITIVO
				&& Passenger_getTipoPasajero(pPasajero, pasajeroAux.tipoPasajero) 	 == RETORNOPOSITIVO
				&& Passenger_getEstadoVuelo(pPasajero, pasajeroAux.statusFlight) 	 == RETORNOPOSITIVO)
		{
			printf("\n|%5d    | %10s | %10s |  %.2f | %15s | %10s | %10s \n "
					,pasajeroAux.id,pasajeroAux.nombre,pasajeroAux.apellido,
					pasajeroAux.precio,pasajeroAux.codigoVuelo,pasajeroAux.tipoPasajero,pasajeroAux.statusFlight);
			retorno=RETORNOPOSITIVO;
		}
	}

	return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

