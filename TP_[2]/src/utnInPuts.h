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

/**
 * \brief
 * @param pNumeroIngresado
 * @param mensaje
 * @param mensajeError
 * @param mensajeSeguirNoSeguir
 * @param minimo
 * @param maximo
 * @param reintentos
 * @return
 */
int utnGetNumero(int* pNumeroIngresado, char* mensaje, char* mensajeError,char* mensajeSeguirNoSeguir,
		int minimo, int maximo, int reintentos);

/**
 *
 * @param mensajeValidacion
 * @param mensajeFinal
 * @return
 */
int utnVerificacionConChar(char* mensajeValidacion,char* mensajePorSi, char* mensajePorNo,int validacion);

void utnMostrarResultados(float parametroPivot, float parametroA, float parametroB,float parametroAconDescuento,
		float parametroBconDescuento,float parametroAconAumento,float parametroBconAumento,float valorPorUnidadParametroB,
		float valorPorUnidadParametroA,float difDeValores);

//float utnIngresarFlotante(char mensaje[]);

int utnRecibeCadenaSoloCaracteres(char cadena[],char mensaje[],int reintentos,int tam);

int utnIngresarAlfanumerico(char cadena[], char mensaje[], int tam);


int validacionLetraNumero(char cadena[],char mensaje[],int codigoValidacion,int len, int reintentos);

int utnIngresarFlotante(char mensaje[],float* numeroFloat, int reintentos);


int pasajeTodoAminusculaOmayusculaConNum(char cadena[], int validez, int len);

void utnToupper(char cadena[],int len);




#endif /* UTNINPUTS_H_ */
