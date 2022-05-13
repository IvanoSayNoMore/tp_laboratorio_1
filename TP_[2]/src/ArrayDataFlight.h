/*
 * ArrayDataFlight.h
 *
 *  Created on: 13 may 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYDATAFLIGHT_H_
#define ARRAYDATAFLIGHT_H_
#include  "ArrayFly.h"

typedef struct{
	int idPasajero;
	float price;
	char flyCode[51];
	int isEmpty;
}DateFlight;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list DateFlight* Pointer to array of passenger
 * \param lenDateFlight int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initDataFlight(DateFlight* list, int lenDateFlight);

/**
 *  \brief find a DateFlight by Id en returns the index position in array.
 * @param list recibe la lista de datos de vuelo
 * @param id id de vuelo a buscar
 * @param posicion devuelve por referencia la posicion
 * @param lenDateFligh recibe el largo de la list
 * @return return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 *  */
int findFlightById(DateFlight* list, int id,int* posicion,int lenDateFligh);

/**
 * \brief Indica si encuentra un lugar empty o full
 * @param list recibe la lista a ser recorrida para verificar si hay empty o full
 * @param fullEmpty recibe la variable que desea encontrar . En caso de que se busque un lugar ocupado -1 . Si busca un lugar vacio 0
 * @param len Recibe el largo de la cadena list a analizar
 * @return retorna -1 si no se encontro la variable @param fullEmpty. Sino, 0
 */
int utnIsEmptyOrFullFlight(DateFlight* list,int fullEmpty,int lenDateFligh);

/**
 * \brief cambia un dato o mas de un vuelo
 * @param list DateFlight* recibe por un puntero el DateFlight
 * @param listFlight Flight*  recibe el array Flight
 * @param lenFlight Largo del array dataFlight
 * @param lenChar recibe el largo maximo de una cadena de char
 * @param lenCharCode recibe el largo maximo de una cadena de char
 * @return retorna -1 si la ultima modificacion salio mal. Sino, retorna 0
 */
int changeDataFlight(DateFlight* dateFl,Flight* listFlight, int lenFlight,int lenChar,int lenCharCode);

/**
 * \brief Remove a dataflight by puntero (put isEmpty Flag in 1)
 * @param list DateFlight* recibe por un puntero el vuelo a borrar
 * @return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
 */
int removeFlight(DateFlight* dateFl);



#endif /* ARRAYDATAFLIGHT_H_ */
