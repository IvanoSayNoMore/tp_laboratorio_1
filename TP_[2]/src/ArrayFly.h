/*
 * ArrayFly.h
 *
 *  Created on: 5 may 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYFLY_H_
#define ARRAYFLY_H_


typedef struct{
	char vuelo[51];
	int statusFlight;
	char flycode[51];
	int isEmtpy;
}Flight;
/**
 * \brief Busca al menos un pasajeo con un codigo
 * @param list recibe la lista de pasajeros
 * @param code recibe el codigo a buscar
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si encontro un pasajero con ese codigo o -1 si no lo encontro
 */
int findPassengerByCode(Flight* list, char code[],int* posicion ,int len);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Flight* Pointer to array of passenger
* \param  lenFlght Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initFlight(Flight* list, int lenFlght);

/**
 * \brief Busca vuelos por codigo
 * @param list lista de vuelos
 * @param flycode retorna el vuelo si se encontro
 * @param maximoVuelos maximo de vuelos
 * @param reintentos maximo de reintentos
 * @param lenCharCodeFli largo de la cadena de char codigo
 * @return retorna 0 si salio ok -1 si algo salio mal
 */
int loadFlightCode(Flight* list,char flycode[], int maximoVuelos, int reintentos,int lenCharCodeFli);

/**
 *
 * @param list
 * @param price
 * @param flycode
 * @param lenCharCodeFli
 * @param lenVuelos
 * @return
 */
int ingresDataFlight(Flight* list,float* price, char flycode[],int lenCharCodeFli,int lenVuelos);

/**
 *  \brief find a Flight by Id en returns the index position in array.
 * @param list recibe la lista de vuelo
 * @param lenFlight recibe el largo de la list
 * @return return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
 *  */
int findFligthByCode(Flight* list,char codigoVuelo[],int lenFlight);

/**
 *
 * @param list
 * @param vuelo
 * @param codigoVuelo
 * @param estadoVuelo
 * @param lenVuelos
 * @param lenChar
 * @param lenCharCode
 * @return
 */
int loadFlight(Flight* list,char vuelo[],char codigoVuelo[],int estadoVuelo, int lenVuelos, int lenChar, int lenCharCode);



#endif /* ARRAYFLY_H_ */
