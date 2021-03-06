/*
 * utnInPuts.h
 *
 *  Created on: 9 abr 2022
 *      Author: Usuario Programador
 */

#ifndef UTNINPUTS_H_
#define UTNINPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @param pNumeroIngresado Devuelve por referencia un numero ingresado
/// @param mensaje Mensaje de peticion
/// @param mensajeError Mensaje de error
/// @param mensajeSeguirNoSeguir Confirmacion de seguir o no
/// @param minimo Extencion minima
/// @param maximo Exencion maxima
/// @param reintentos Cantidad de reintentos
/// @return retorna 0 cuando se confirma que es un numero. Retorna 1 si no lo es.
int utnGetNumero(int* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir,
		int minimo, int maximo, int reintentos);

/// @param mensajeValidacion Envia mensaje al usuario para verificar salida
/// @param mensajeFinal Envia mensaje de salida al usuario
/// @return Retorna 0 si el usr deside continuar. -1 si no desea continuar.
int utnVerificacionConChar(char* mensajeValidacion,char* mensajePorSi, char* mensajePorNo,int validacion);


int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam);

int utnIngresarAlfanumerico(char cadena[], char mensaje[],int reintentos, int tam);

int validacionLetraNumero(char cadena[],char mensaje[],int codigoValidacion,int len, int reintentos);

int utnIngresarFlotante(char mensaje[],float* numeroFloat, int reintentos);

int pasajeTodoAminusculaOmayusculaConNum(char cadena[], int validez);

void utnToupper(char cadena[]);

/**
 * \brief Contador para ID
 * @param num devuelve un numero id
 */
void contadorId(int* num);

#endif /* UTNINPUTS_H_ */
