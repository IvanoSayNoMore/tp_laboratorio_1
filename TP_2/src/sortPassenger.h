/*
 * sortPassenger.h
 *
 *  Created on: 28 abr 2022
 *      Author: Usuario Programador
 */

#ifndef SORTPASSENGER_H_
#define SORTPASSENGER_H_
/*Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
descendente.
* \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int order,int len);

/*2.7 Función sortPassengersByCode
Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o
descendente.
\brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int order, int len);


void soap(Passenger* list,int posicion);

void sortAscByTipe(Passenger* list, int len);

void sortDsdByTipe(Passenger* list, int len);

void sortAscByCode(Passenger* list, int len);

void sortDscByCode(Passenger* list, int len);

#endif /* SORTPASSENGER_H_ */
