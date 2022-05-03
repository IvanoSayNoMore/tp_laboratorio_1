/*
 * imprimirMostrar.h
 *
 *  Created on: 25 abr 2022
 *      Author: Usuario Programador
 */

#ifndef IMPRIMIRMOSTRAR_H_
#define IMPRIMIRMOSTRAR_H_
#include "ArrayPassenger.h"

/*2.6 Función printPassengers
Imprime el array de pasajeros de forma encolumnada.
brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int len);

void printOnePassenger(Passenger passenger);



#endif /* IMPRIMIRMOSTRAR_H_ */
