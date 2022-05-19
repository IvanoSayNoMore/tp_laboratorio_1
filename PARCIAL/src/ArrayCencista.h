/*
 * ArrayCencista.h
 *
 *  Created on: 17 may 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYCENCISTA_H_
#define ARRAYCENCISTA_H_

#include "ArrayZona.h"//ver

typedef struct{
	char name[51];
	char lastName[51];
	int edad;
}dataPerson;

typedef struct{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct{
	char direccion[51];
}DataHome;

typedef struct{
	int idCensista;
	dataPerson dataPerson;
	fecha fechaNacimiento;
	DataHome direccion;
	int estadoActual;//Activo Inactivo Liberado
	int isEmpty;
}Person;



/**
 * @biref Inicializa array del tipo Person
 * @param list lista a inicializar
 * @param lenPerson Largo de la lista
 * @return retorna 0 si inicializo OK
 */
int initPerson(Person* list, int lenPerson);

/**
 * @brief Ingreso de variables de person
 * @param name Retorna el nombre ingresado (cadena de char)
 * @param lastName Retorna el apellido ingresado (cadena de char)
 * @param direccion Retorna la direccion ingresada (cadena de char)
 * @param anio retorna año de nacimiento (int)
 * @param mes retorna mes de nacimiento (int)
 * @param dia retorna el dia de nacimiento (int)
 * @param edad retorna la edad (int)
 * @param lenCadena largo de las cadena char
 * @return retorna 0 si salio OK , sino -1
 */
int ingresPerson(char name[],char lastName[],char direccion[],int* anio,int* mes,int* dia, int* edad,int lenCadena);

/**
 * @brief Graba datos de persona
 * @param listPerson Recibe la primera direccion de memoria de una variable del tipo person
 * @param id Recibe id a grabar
 * @param name recibe nombre a grabar
 * @param lastName recibe apelldo a grabar
 * @param direccion recibe direccion a grabar
 * @param dia recibe dia a grabar
 * @param mes recibe mes a grabar
 * @param anio recibe anio a grabar
 * @param edad recibe edad a grabar
 * @return retorna 0 si grabo Ok -1 si person vino null
 */
int addPerson(Person* person, int id, char name[],char lastName[],char direccion[],int dia,int mes, int anio,int edad);

/**
 * @brief Busca espacio vacio o lleno en array person
 * @param list lista de persona
 * @param fullEmpty variable a buscar
 * @param lenPerson largo del array
 * @return retorna la posicion de la variable buscada si se encontro o -1 si no encontro nada
 */
int utnIsEmptyOrFullPerson(Person* list,int fullEmpty,int lenPerson);

/**
 * @brief Busca person por su ID
 * @param list recibe la lista array  de person
 * @param id Id a ser buscado
 * @param posicion retorna por referencia la posicion del iD si es encontrado
 * @param lenPerson largo del array person
 * @return retorna 0 si encontro el id -1 si no lo encontro
 */
int findPersonById(Person* list, int id,int* posicion,int lenPerson);

/**
 * @brief Cambia a una persona
 * @param person recibe por puntero a una persona
 * @param lenCadena largo de cadena char
 * @return retorna 0 si cambio ok o -1 si algo sailo mal
 */
int changePerson(Person* person,int lenCadena);

/**
 * @brief Validacion de cambios de datos de person
 * @param dia retorna el dia ingresado
 * @param mes retorna el mes ingresado
 * @param anio retorna el anio ingresado
 * @param direccion retorna el direccion ingresado
 * @param lenCadena largo de cadena char
 * @return retorna 0 si salio ok -1 si algo salio mal
 */
int changeDate(int* dia, int* mes, int* anio, char* direccion,int lenCadena);

/**
 * @brief Cambia el estado de un cencista
 * @param list recibe por puntero a una persona
 * @return retorna 0 si se cambio ok -1 si algo sailo mal
 */
int statusChange(Person* list);

/**
 * @brief Cambia el estado de un person a INACTIVO
 * @param person recibe por puntero a una persona
 * @return retorna 0 si se dio el alta ok . sino -1
 */
int deletPerson(Person* person);

/**
 * @brief Validaciones para ingresar un censista
 * @param listPerson array de person
 * @param lenPerson largo del array person
 * @return retorna 0 si se dio el alta ok . sino -1
 */
int validAddPerson(Person* listPerson,int lenPerson);

/**
 * @brief Validaciones para ingresar una zona
 * @param listPerson lista de cencistas para asignarle una zona
 * @param zona recibe por puntero zona a asignar
 * @param idCensista Id de censista para asignar zona
 * @param lenPerson largo del array person
 * @return retorna 0 si se logra asignar la zona ok -1 si algo salio mal
 */
int validAssigZona(Person* listPerson, datoZona* zona,int idCensista,int lenPerson);


#endif /* ARRAYCENCISTA_H_ */
