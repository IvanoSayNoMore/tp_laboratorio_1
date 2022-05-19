/*
 * ArrayCencista.c
 *
 *  Created on: 14 may 2022
 *      Author: Usuario Programador
 */



#include "ArrayCencista.h"


#include "ArrayZona.h"
#include "printList.h"
#include "utnInPuts.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#define PENDIENTE -1
#define FINALIZADO 0
#define EMPTY 0
#define FULL -1
#define REINTENTOS 3
#define RETORNOPOSITIVO 0
#define RETORNONEGATIVO -1
#define MAXIMOCADENA 51
#define ACTIVO 1
#define INACTIVO -1
#define LIBERADO 0

int initPerson(Person* list, int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	if(list!=NULL)
	{
		int i;
		for(i=0;i<lenPerson;i++)
		{
			list[i].isEmpty=EMPTY;

		}
		retorno=RETORNOPOSITIVO;
	}

	return retorno;
}

int ingresPerson(char name[],char lastName[],char direccion[],int* anio,int* mes,int* dia, int* edad,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	char auxChar[lenCadena];
	int auxInt;
	int flagOk=RETORNOPOSITIVO;
	int continuar=0;

	do{
		//Nombre
		if(utnIngressStringChar(auxChar, "\nIngrese su nombre: \n", lenCadena)==0)
		{

			strncpy(name,auxChar,lenCadena);
		}
		else
		{
			flagOk=-1;
			break;
		}

		//Apellido
		if(utnIngressStringChar(auxChar, "\nIngrese su apellido: \n", lenCadena)==RETORNOPOSITIVO)
		{

			strncpy(lastName,auxChar,lenCadena);
		}
		else
		{
			flagOk=-1;
			break;
		}

		///Dia Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese el dia de nacimiento .\n","Reintente\n", "Error. Desea reintentar?\n", 1,31, REINTENTOS)==RETORNOPOSITIVO)
		{

			*dia=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

		///Mes Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese el mes de nacimiento .\n","Reintente\n", "Error. Desea reintentar?\n", 1,12, REINTENTOS)==RETORNOPOSITIVO)
		{
			*mes=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

		///Anio Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese el año de nacimiento .\n","Reintente \n", "Error. Desea reintentar?\n", 1,2000, REINTENTOS)==RETORNOPOSITIVO)
		{
			*anio=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}


		///Anio Nacimiento
		if(utnGetNumero(&auxInt, "\nIngrese su edad .\n","Reintente \n", "Error. Desea reintentar?\n", 18,99, REINTENTOS)==RETORNOPOSITIVO)
		{
			*edad=auxInt;
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}

		//Direccion
		if(utnIngresarAlfanumerico(auxChar, "Ingrese su domicilio \n", REINTENTOS, lenCadena)==RETORNOPOSITIVO)
		{
			strncpy(direccion,auxChar,lenCadena);
		}
		else
		{
			flagOk=RETORNONEGATIVO;
			break;
		}




	}while(continuar==1);

	retorno=flagOk;


	return retorno;

}

int addPerson(Person* person, int id, char name[],char lastName[],char direccion[],int dia,int mes, int anio,int edad)
{
	int retorno=RETORNONEGATIVO;

	if(person!=NULL &&  name!=NULL && lastName!= NULL)
	{
		person->idCensista=id;
		strncpy(person->dataPerson.lastName,lastName,sizeof(person->dataPerson.lastName));
		strncpy(person->dataPerson.name,name,sizeof(person->dataPerson.name));
		person->fechaNacimiento.dia=dia;
		person->fechaNacimiento.mes=mes;
		person->fechaNacimiento.anio=anio;
		person->dataPerson.edad=edad;
		strncpy(person->direccion.direccion,direccion,sizeof(person->direccion.direccion));
		person->estadoActual=LIBERADO;
		person->isEmpty=FULL;
		retorno=RETORNOPOSITIVO;
	}
	return retorno;
}

int utnIsEmptyOrFullPerson(Person* list,int fullEmpty,int lenPerson)
{
	int retorno=-1;
	int i;
	for(i=0;i<lenPerson;i++)
	{
		if(list[i].isEmpty==fullEmpty)
		{
			retorno=i;
			break;
		}
	}
	return retorno;
}

int findPersonById(Person* list, int id,int* posicion,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	int i;
	for(i=0;i<lenPerson;i++)
	{
		if(list[i].isEmpty==FULL && list[i].idCensista==id )
		{
			retorno=RETORNOPOSITIVO;
			*posicion=i;
			break;
		}
	}

	return retorno;
}

int changePerson(Person* person,int lenCadena)
{
	int retorno=RETORNONEGATIVO;
	int continuar;
	int auxInt;
	int auxDia;
	int auxMes;
	int auxAnio;
	char auxDireccion[lenCadena];
	int opcion;
	char auxChar[lenCadena];


	do{
		printf("Su nombre actual es %s\nSu Apellido actual es %s\n",person->dataPerson.name,person->dataPerson.lastName);
		printf("Su edad es %d y su fecha de nacimiento es el : %d/%d/%d\n",
				person->dataPerson.edad,person->fechaNacimiento.dia,person->fechaNacimiento.mes,person->fechaNacimiento.anio);

		puts("----------------------------------\n");
		if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-edad \n4-Direccion o fecha de nacimiento\n8-Para cancelar la modificacion\n "
				,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 1, 8, REINTENTOS)==RETORNOPOSITIVO)
		{
			switch(opcion)
			{
			case 1:
				if(utnIngressStringChar(auxChar, "\nIngrese su nombre: \n", lenCadena)==RETORNOPOSITIVO)
				{
					utnToupper(auxChar);
					printf("Cambio exitoso, el nuevo nombre es el de %s\n",auxChar);

					strncpy(person->dataPerson.name,auxChar,lenCadena);
					retorno=RETORNOPOSITIVO;
					break;
				}
				else
				{
					retorno=RETORNONEGATIVO;
					break;
				}

			case 2:
				if(utnIngressStringChar(auxChar, "\nIngrese su apellido: \n", lenCadena)==RETORNOPOSITIVO)
				{
					utnToupper(auxChar);
					printf("Cambio exitoso, el nuevo apellido es el de %s\n",auxChar);

					strncpy(person->dataPerson.lastName,auxChar,lenCadena);
					retorno=RETORNOPOSITIVO;
					break;
				}
				else
				{
					retorno=RETORNONEGATIVO;
					break;
				}

			case 3:
				if(utnGetNumero(&auxInt, "\nIngrese su edad\n", "Error al ingresar edad\n", "Error al ingresar edad, desea volver a ingresar?\n", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
				{
					person->dataPerson.edad=auxInt;
					printf("Cambio exitoso, el nuevo tipo es el de %d\n",auxInt);

					retorno=RETORNOPOSITIVO;
					break;
				}
				else
				{

					retorno=RETORNONEGATIVO;
					break;
				}

				//
			case 4:
				if(changeDate(&auxDia, &auxMes, &auxAnio, auxDireccion, lenCadena)==RETORNOPOSITIVO)
				{
					person->fechaNacimiento.anio=auxAnio;
					person->fechaNacimiento.dia=auxDia;
					person->fechaNacimiento.mes=auxMes;
					strncpy(person->direccion.direccion,auxDireccion,lenCadena);
					break;
				}
				else
				{
					retorno=RETORNONEGATIVO;
					break;
				}

			case 5:
				puts("Se cancela la opcion modificar\n");
				retorno=RETORNOPOSITIVO;
				break;
			default :
				retorno=RETORNONEGATIVO;
				puts("Error de opcion\n");

			}//Fin Switch

		}//Fin If utnGetNumero
		if(retorno==RETORNOPOSITIVO)
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


	return retorno;
}

int changeDate(int* dia, int* mes, int* anio, char* direccion,int lenCadena)
{
	int retorno=RETORNOPOSITIVO;
	int opcion;
	int auxInt;
	char auxChar[lenCadena];

	if(utnGetNumero(&opcion, "Ingrese la op que desea modificar.\n1-Nombre\n2-Apellido\n3-edad \n4-Direccion \n-0-Si desea cancelar \n "
					,"\nPor favor, ingrese solo numeros\n", "Error al ingresar Opcion. Desea reintentar?\n", 0, 4, REINTENTOS)==RETORNOPOSITIVO)
	{
		switch(opcion)
		{
		case 1:
			if(utnGetNumero(&auxInt, "\nIngrese dia de nacimiento\n", "Error al ingresar dia de nacimiento\n", "Error al ingresar dia, desea reintentar?", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
			{
				*dia=auxInt;
				break;
			}
			else
			{
				retorno=RETORNONEGATIVO;
				break;
			}

		case 2:
			if(utnGetNumero(&auxInt, "\nIngrese mes de nacimiento\n", "Error al ingresar mes de nacimiento\n", "Error al ingresar mes,desea reintentar?\n", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
			{
				*mes=auxInt;
				printf("Cambio exitoso, el nuevo mes de nacimiento es el de %d\n",auxInt);
				break;
			}
			else
			{
				retorno=RETORNONEGATIVO;
				break;
			}

		case 3:
			if(utnGetNumero(&auxInt, "\nIngrese año de nacimiento\n", "Error al ingresar año de nacimiento\n", "Error al ingresar año,desea reintentar?\n", 0, 5, REINTENTOS)==RETORNOPOSITIVO)
			{
				*anio=auxInt;
				printf("Cambio exitoso, el nuevo año de nacimiento es el de %d\n",auxInt);

				retorno=RETORNOPOSITIVO;
				break;
			}
			else
			{

				retorno=RETORNONEGATIVO;
				break;
			}
		case 4:
			//Direccion

			if(utnIngresarAlfanumerico(auxChar, "Ingrese su domicilio \n", REINTENTOS, lenCadena)==RETORNOPOSITIVO)
			{
				strncpy(direccion,auxChar,lenCadena);
			}
			else
			{
				retorno=RETORNONEGATIVO;
				break;
			}
		}


	}

	return retorno;

}

int statusChange(Person* list)
{
	int retorno=RETORNONEGATIVO;
	if(list!=NULL)
	{
		list->estadoActual=INACTIVO;
		retorno=RETORNOPOSITIVO;
		//list->isEmpty=EMPTY;
	}
	return retorno;
}

int deletPerson(Person* person)
{
	int retorno=RETORNONEGATIVO;
	if(person != NULL)
	{
		person->estadoActual=INACTIVO;
		retorno=RETORNOPOSITIVO;
	}

	return retorno;
}

int validAddPerson(Person* listPerson,int lenPerson)
{
	int retorno=RETORNONEGATIVO;
	char auxName[MAXIMOCADENA];
	char auxLastName[MAXIMOCADENA];
	char direccion[MAXIMOCADENA];
	int auxDia;
	int auxAnio;
	int auxMes;
	int auxEdad;
	int auxId;
	if(ingresPerson(auxName, auxLastName, direccion,
						&auxAnio, &auxMes, &auxDia, &auxEdad, MAXIMOCADENA)==RETORNOPOSITIVO)
	{
		contadorId(&auxId);
		if(addPerson(listPerson, auxId, auxName, auxLastName,
				direccion, auxDia, auxMes, auxAnio, auxEdad)==RETORNOPOSITIVO)
		{
			printf("Alta exitosa con el ID numero %d\n",auxId);
			retorno=RETORNOPOSITIVO;
		}

	}
	return retorno;
}

int validAssigZona(Person* listPerson,datoZona* zona,int idCensista,int lenPerson)
{
	Person * punteroPersona;
	int retorno=RETORNONEGATIVO;
	int posicionPerson;
	if(findPersonById(listPerson, idCensista, &posicionPerson, lenPerson)==RETORNOPOSITIVO)
	{
		punteroPersona=&listPerson[posicionPerson];
		if(punteroPersona->estadoActual==LIBERADO)
		{
			assignZone(zona, idCensista);
			punteroPersona->estadoActual=ACTIVO;
			retorno=RETORNOPOSITIVO;
		}
		else
		{
			puts("Actualmente , el id seleccionado esta inactivo o tiene una zona asignada.  ");
		}

	}//busca censista por id
	return retorno;

}
