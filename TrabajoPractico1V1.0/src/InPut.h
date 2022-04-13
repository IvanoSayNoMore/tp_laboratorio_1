/*
 * InPuts.h
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @param pNumeroIngresado Devuelve por referencia un numero ingresado
/// @param mensaje Mensaje de peticion
/// @param mensajeError Mensaje de error
/// @param mensajeSeguirNoSeguir Confirmacion de seguir o no
/// @param minimo Extencion minima
/// @param maximo Exencion maxima
/// @param reintentos Cantidad de reintentos
/// @return retorna 0 cuando se confirma que es un numero. Retorna 1 si no lo es.
int utnGetNumero(float* pNumeroIngresado, char* mensaje, char* mensajeFinal,char* mensajeSeguirNoSeguir, int minimo, int maximo, int reintentos);

/// @param mensajeValidacion Envia mensaje al usuario para verificar salida
/// @param mensajeFinal Envia mensaje de salida al usuario
/// @return Retorna 0 si el usr deside continuar. -1 si no desea continuar.
int utnVerificacionConChar(char* mensajeValidacion,char* mensajeFinal);

#endif /* INPUT_H_ */
