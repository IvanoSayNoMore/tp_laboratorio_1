/*
 * ArrayZona.h
 *
 *  Created on: 14 may 2022
 *      Author: Usuario Programador
 */

#ifndef ARRAYZONA_H_
#define ARRAYZONA_H_

typedef struct {
	int idCensista;
	int idZona;
	int localidadZona;
	char zonaCenso[15];
	int estadoCenso;
	int isEmpty;
}datoZona;

typedef struct{
	int id;
	char localidades[51];
	int isEmpty;
}localidad;

typedef struct {
	int idCensista;
	int totalCensados;
	int censadosInSitu;
	int censadosVirtual;
	int ausentes;
	int isEmpty;
}datosCenso;

int findLocalidadById(localidad* listlocalidad,int id,int* posicion, int lenLocalidad);
/**
 * @brief Inicializa array del tipo localidad
 * @param listlocalidad lista a inicializar
 * @param lenLocalidad Largo de la lista
 * @return retorna 0 si inicializo OK
 */
int initLocalidad(localidad* listlocalidad, int lenLocalidad);

/**
 * @brief Inicializa array del tipo datoZona
 * @param listZona lista a inicializar
 * @param lenZona Largo de la lista
 * @return retorna 0 si inicializo OK
 */
int initZona(datoZona* listZona, int lenZona);

/**
 * @brief Inicializa array del tipo datosCenso
 * @param listCenso lista a inicializar
 * @param lenDatosCenso Largo de la lista
 * @return retorna 0 si inicializo OK
 */
int initDateCenso(datosCenso* listCenso, int lenDatosCenso);

/**
 * @brief Validacion de datos del censo
 * @param ausentes retorna int
 * @param inSitu retorna int
 * @param virtual retorna int
 * @return retorna 0 si se ingresaron bien los datos o -1 si algo salio mal
 */
int ingressDateCenso(int* ausentes, int* inSitu, int* virtual);

/**
 * @brief Ingresa una zona nueva
 * @param localidad Retorna el numero de localidad a asignar zona
 * @param zona retorna la cedena de zona
 * @param lenLocalidad maximo de localidades
 * @param lenCadena maximo de cadena
 * @return retorna 0 si se dio el alta ok . sino -1
 */
int ingressZone(int* localidad, char zona[],int lenLocalidad,int lenCadena);

/**
 * @brief recibe por puntero un tipo de dato datoZona
 * @param zona zona a ser escrita
 * @param localidad localidad a ser asignada a zona
 * @param idZona id de zona a ser asignada
 * @param zona nombre de la zona
 * @return retorna 0 si se dio el alta ok . sino -1
 */
int addZone(datoZona* zona,int localidad,int idZona, char nombreZona[]);

/**
 * @brief Agrega una localidad
 * @param listalocalidad recibe la lista de un array del tipo localidad
 * @param localidad nombre de localidad
 * @param MaxLocalidad maximo de localidades
 * @param idLocalidad id a asignar
 * @param lenLocalidad maximo cadena char
 * @return retorna 0 si se dio el alta ok . sino -1
 */
int addLocalidad(localidad* listalocalidad,char localidad[],int MaxLocalidad,int idLocalidad,int lenLocalidad);

/**
 * @brief Agrega datos a datos de censo
 * @param zona Recibe la zona a asignar datos
 * @param datoCenso Recibe por puntero una direccion de datoCenso disponible para grabar datos
 * @param idCensista ID de censista que graba datos
 * @param censadosInSitu
 * @param censadosVirtual
 * @param ausentes
 * @return retorna 0 si se dio el alta ok . sino -1
 */
int addDataZona(datoZona* zona,datosCenso* datoCenso,int idCensista,int censadosInSitu,int censadosVirtual, int ausentes);

/**
 * @brief Busca espacio vacio o lleno en array datosCenso
 * @param listCenso lista de datosCenso
 * @param fullEmpty variable a buscar
 * @param lenDatoCenso largo del array
 * @return retorna la posicion de la variable buscada si se encontro o -1 si no encontro nada
 */
int utnIsEmptyOrFullDatCenso(datosCenso* listCenso,int fullEmpty,int lenDatoCenso);

/**
 * @brief Busca espacio vacio o lleno en array datoZona
 * @param listZona lista de datosCenso
 * @param fullEmpty variable a buscar
 * @param lenZona largo del array
 * @return retorna la posicion de la variable buscada si se encontro o -1 si no encontro nada
 */
int utnIsEmptyOrFullZone(datoZona* listZona,int fullEmpty,int lenZona);

/**
 * @brief Asignar la zona a un censita
 * @param zona Recibe por puntero una direccion de datoZona disponible para grabar datos
 * @param idCensista id de censita
 * @return retorna la posicion de la variable buscada si se encontro o -1 si no encontro nada
 */
int assignZone(datoZona* zona,int idCensista);

/**
 * @brief Busca datoZona por su ID
 * @param list recibe la lista array  de datoZona
 * @param id Id a ser buscado
 * @param posicion retorna por referencia la posicion del iD si es encontrado
 * @param lenZona largo del array datoZona
 * @return retorna 0 si encontro el id -1 si no lo encontro
 */
int findZonaById(datoZona* list, int id,int* posicion,int lenZona);

/**
 * @brief Busca datoZona por su ID
 * @param list recibe la lista array  de datoZona
 * @param idCensista Id a ser buscado
 * @param posicion retorna por referencia la posicion del iD si es encontrado
 * @param lenZona largo del array datoZona
 * @return retorna 0 si encontro el id -1 si no lo encontro
 */
int findZonaByIdCensista(datoZona* list, int idCensista,int* posicion,int lenZona);


#endif /* ARRAYZONA_H_ */
