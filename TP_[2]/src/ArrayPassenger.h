/*
 * ArrayPassenger.h
 *
 *  Created on: 17 abr 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "ArrayDataFlight.h"

typedef struct{
	char name[51];
	char lastName[51];
}NamePassenger;

typedef struct{
	int idPasajero;
	int typePassenger;
	NamePassenger nameLastName;
	int isEmpty;
}Passenger;


///brief add in a existing list of passengers the values received as parameters
///in the first empty position
/// @param list passenger* recibe una lista en la cual sera agregado un pasajero
/// @param id recibe por parametro un numero de id
/// @param name recibe por parametro el nombre a ser asignado
/// @param lastName recibe por parametro el apellido a ser asignado
/// @param price recibe por parametro el precio a ser asignado
/// @param typePassenger recibe por parametro el tipo a ser asignado
/// @param flycode recibe por parametro el codigo del vuelo a ser asignado
/// @param len recibe por parametro recibe el largo posible de pasajeros para validar si existe o no un espacio libre
/// @return retorna 0 si salio bien. -1 si algo fallo
int addPassenger(Passenger* listPassager,DateFlight* listFlight, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int lenPassagers, int lenFlight);

/**
 * \brief solicita al usuario los datos del pasajero
 * @param name devuelve cadena nombre ingresado
 * @param lastName  devuelve cadena apillo ingresado
 * @param price devuelve el precio ingresado
 * @param typePassenger devuelve el tipo ingresado
 * @param flycode devuelve el codigo ingresado
 * @param len recibe el largo posible de las cadenas
 * @return retorna -1 si algun dato fue mal cargado o 0 si los datos se cargaron bien
 */
int ingresPassenger(char name[],char lastName[],int* typePassenger,int lenCadena);


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int lenPassenger);

/**
 * \brief Indica si encuentra un lugar empty o full
 * @param list recibe la lista a ser recorrida para verificar si hay empty o full
 * @param fullEmpty recibe la variable que desea encontrar . En caso de que se busque un lugar ocupado -1 . Si busca un lugar vacio 0
 * @param len Recibe el largo de la cadena list a analizar
 * @return retorna -1 si no se encontro la variable @param fullEmpty. Sino, 0
 */
int utnIsEmptyOrFullPassager(Passenger* list,int fullEmpty,int lenPassenger);


/**
 *  \brief find a Passenger by Id en returns the index position in array.
 * @param list recibe la lista de pasajeros
 * @param id para identificar un pasajero
 * @param posicion retorna por referencia la posicion del pasajero si es que se encontro
 * @param len largo de la lista passenger
 * @return return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 *  */
int findPassengerById(Passenger* list, int id,int* posicion,int len);

/**
 * \brief Remove a Passenger by puntero (put isEmpty Flag in 1)
 * @param list Passenger* recibe por un puntero el Passenger a borrar
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 */
int removePassenger(Passenger* list);


/***
 * \brief cambia un valor o mas de un pasajero
 * @param list Passenger* recibe un pasajero por puntero para modificar
 * @param lenCadena recibe el largo maximo de la cadena de char
 * @return retorna -1 si la ultima modificacion salio mal. Sino, retorna 0
 */

int changePassager(Passenger* listPassager,int lenCadena);




#endif /* ARRAYPASSENGER_H_ */
