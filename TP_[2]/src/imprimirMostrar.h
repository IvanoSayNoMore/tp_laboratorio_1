/*
 * imprimirMostrar.h
 *
 *  Created on: 25 abr 2022
 *      Author: Usuario Programador
 */

#ifndef IMPRIMIRMOSTRAR_H_
#define IMPRIMIRMOSTRAR_H_
#include "ArrayPassenger.h"
#include "sortPassenger.h"
#include "ArrayFly.h"


/***
 * \brief print the content of passengers array
 * @param list recibe la lista de pasajeros a imprimir.
 * @param len recibe el largo posible de la lista de pasajeros
 * @return retorna 0 si pudo imprimir algo -1 si no pudo imprimir nada
 */
int printPassenger(Passenger* list,DateFlight* listDateFlight,Flight* vuelo, int lenPassenger, int lenFlight);

/***
 * \brief imprime un pasajero
 * @param passenger recibe el pasajero a imprimir
 */
void printOnePassenger(Passenger* passenger);

/**
 * \brief Imprime la lista de pasajeros
 * @param vuelo
 * @param len
 * @return
 */
int printListFlight(Flight* vuelo,int len);

/**
 * \brief Imprime un vuelo
 * @param vuelo recibe por puntero una direccion de memoria del vuelo a imprimir
 */
void printFlight(Flight* vuelo);

/**
 *
 * @param listDateFlight
 * @param vuelo
 * @param lenPassenger
 * @param lenFlight
 */
void printOneDestin(DateFlight* listDateFlight,Flight* vuelo, int lenPassenger, int lenFlight);

/**
 *
 * @param passenger
 * @param vuelo
 * @param order
 * @param lenPassenger
 */
void printPassengerByCode(DateFlight* passenger,Flight* vuelo,int order,int lenPassenger);
#endif /* IMPRIMIRMOSTRAR_H_ */
