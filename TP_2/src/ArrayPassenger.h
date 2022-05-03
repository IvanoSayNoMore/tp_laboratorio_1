/*
 * ArrayPassenger.h
 *
 *  Created on: 17 abr 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	char name[51];
	char lastName[51];

}NamePassenger;

typedef struct{

	int id;
	float price;
	char flycode[51];
	int typePassenger;
	int statusFlight;
	int isEmpty;
	NamePassenger nameLastName;
}Passenger;

//Agrega en un array de pasajeros existente los valores recibidos como parámetro en la primer
//posición libre.
/* \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int addPassenger(Passenger* list, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int len);

int ingresPassenger(char name[],char lastName[],float* price,int* typePassenger, char flycode[],int len);
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int len);

int utnIsEmptyOrFull(Passenger* list,int fullEmpty,int len);

/*Busca un pasajero recibiendo como parámetro de búsqueda su Id.
* \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int id,int* posicion,int len);
/*2.4 Función removePassenger
Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
* \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int id, int len);

void contadorId(int* num);

int changePassager(Passenger* list, int posicion, int lenChar);

int findPassengerByCode(Passenger* list, char code[],int len);

#endif /* ARRAYPASSENGER_H_ */
