/*
 * sortPassenger.h
 *
 *  Created on: 28 abr 2022
 *      Author: Usuario Programador
 */

#ifndef SORTPASSENGER_H_
#define SORTPASSENGER_H_

/**
 * \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 * @param list Passenger* recibe una lista de pasajeros a ser ordenada
 * @param order order int [1] indicate UP - [0] indicate DOWN
 * @param len largo maximo de la list
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengers(Passenger* list,DateFlight* listDateFlight, int order,int lenPassenger, int lenFlight);

/**
 * \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
 * @param list recibe la lista de pasajeros a ordenar
 * @param order int [1] indicate UP - [0] indicate DOWN
 * @param len el largo posible de de la lista de pasajeros
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersByCode(Passenger* list,DateFlight* dateFlight , int len);

/**
 * \brief Ordena la lista de pasajeros de forma ascendente por tipo
 * @param list lista de pasajeros
 * @param len largo maximo de la lista de pasajeros
 */
void sortAscByNameTipe(Passenger* list, int len);

/**
 * \brief Ordena la lista de pasajeros de forma descendente por tipo
 * @param list lista de pasajeros
 * @param len largo maximo de la lista de pasajeros
 */
void sortDsdByNameTipe(Passenger* list, int len);

/**
 *\brief Ordena la lista de pasajeros por codigo de forma ascendente
 * @param list lista de pasajeros
 * @param len largo maximo de la lista de pasajeros
 */
void sortAscByCode(Passenger* list, int len);

/**
 *\brief Ordena la lista de pasajeros por codigo de forma descendente
 * @param list lista de pasajeros
 * @param len largo maximo de la lista de pasajeros
 */
void sortDscByCode(Passenger* list, int len);

/**
 *\brief Soapea
 * @param list recibe la lista
 * @param posicionA y B recibe la posicion a modificar y ser modificada
 */
void soap(Passenger* list,int posicionA,int posicionB);
#endif /* SORTPASSENGER_H_ */
