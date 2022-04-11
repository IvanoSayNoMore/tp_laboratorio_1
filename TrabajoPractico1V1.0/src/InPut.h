/*
 * InPuts.h
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#ifndef INPUT_H_
#define INPUT_H_
/// @param cadena Devuelve por referencia una cadena
/// @param longitud Recibe longitud de cadena
/// @return
int utnMyGets(char* cadena, int longitud);

/// @param pResultado Devuelve por referencia un numero
/// @return retorna 0 si es numero -1 si no es numero
int utnGetInt(int* pResultado);

/// @param pNumeroIngresado Devuelve por referencia un numero ingresado
/// @param mensaje Mensaje de peticion
/// @param mensajeError Mensaje de error
/// @param mensajeSeguirNoSeguir Confirmacion de seguir o no
/// @param minimo Extencion minima
/// @param maximo Exencion maxima
/// @param reintentos Cantidad de reintentos
/// @return
int utnGetNumero(float* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos);

/// @param cadena recibe una cadena a analizar
/// @return Retorna 0 si hay una letra o caracter que no sea numero. Retorna 1 si la cadena es solo numerica
int utnEsNumerica(char* cadena);

/// @param mensajeValidacion Envia mensaje al usuario para verificar salida
/// @param mensajeFinal Envia mensaje de salida al usuario
/// @return Retorna 0 si el usr deside continuar. -1 si no desea continuar.
int utnVerificacionConChar(char* mensajeValidacion,char* mensajeFinal);

#endif /* INPUT_H_ */
