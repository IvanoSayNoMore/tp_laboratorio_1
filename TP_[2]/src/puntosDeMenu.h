/*
 * puntosDeMenu.h
 *
 *  Created on: 1 may 2022
 *      Author: Usuario Programador
 */

#ifndef PUNTOSDEMENU_H_
#define PUNTOSDEMENU_H_
/**
 * \brief Punto de menu para ingresar un pasajero
 * @param list recibe la lista de pasajeros
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si el alta fue correcta. -1 si algo salio mal
 */
int menuItemEnterPassenger(Flight* vuelo,Passenger* listPassager,DateFlight* listFligt, int lenPassager, int lenFlight);

/**
 * \brief Punto de menu para modificar un pasajero
 * @param list recibe la lista de pasajeros
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si el alta fue correcta. -1 si algo salio mal
 */
int menuItemModify(Passenger* listDatePassenger,DateFlight* listDateFlight,Flight* listFlight, int lenPassager,int lenDataFlight,int lenFlight);

/**
 * \brief Punto de menu para ingresar un pasajero
 * @param list recibe la lista de pasajeros
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si el alta fue correcta. -1 si algo salio mal
 */
int deletMenuItem(Passenger* list,DateFlight* listDateFlight,Flight* vuelo, int lenPasajeros, int lenVuelos);


/**
 * \brief Punto de menu para imprimir la lista de pasajeros
 * @param list recibe la lista de pasajeros
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si el alta fue correcta. -1 si algo salio mal
 */
int reportMenuItem(Passenger* list,DateFlight* listDateFlight, Flight* vuelo,int lenPasajeros, int lenVuelos);


/**
 * \brief Punto de menu para hardkodear pasajeros
 * @param list recibe la lista de pasajeros
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si el alta fue correcta. -1 si algo salio mal
 */
int hardcodeMenuItem(Passenger* list,DateFlight* listFlight, int lenPasajeros, int lenVuelos);

/**
 * \brief Punto de menu para cambiar el estado del vuelo  un pasajero
 * @param list recibe la lista de pasajeros
 * @param len recibe el largo de la lista de pasajeros
 * @return retorna 0 si el alta fue correcta. -1 si algo salio mal
 */
int menuItemFlightStatusChange(DateFlight* listFlight, Flight* vuelo,int lenFligth);

#endif /* PUNTOSDEMENU_H_ */
