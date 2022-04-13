/*
 * Bibliotecas.h
 *
 *  Created on: 6 abr 2022
 *      Author: Usuario Programador
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief Calculadora de datos. recibe 3 datos. Puntero al espacio de memoria de cada resultado
/// @param parametroPivot Recibe valor central
/// @param parametroA Recibe valor vinculado con el pivot
/// @param parametroB Recibe valor vinculado con el pivot
/// @param parametroAconDescuento Devuelve por referencia el valor A con descuento
/// @param parametroBconDescuento Devuelve por referencia el valor B con descuento
/// @param parametroAconAumento Devuelve por referencia el valor A con aumento
/// @param parametroBconAumento Devuelve por referencia el valor B con aumento
/// @param valorPorUnidadParametroB Devuelve por referencia el valor B por unidad
/// @param valorPorUnidadParametroA Devuelve por referencia el valor A por unidad
/// @param difDeValores Devuelve por referencia la diferencia entre A y B
void utnCalcularValores(float parametroPivot, float parametroA, float parametroB,float* parametroAconDescuento,
		float* parametroBconDescuento,float* parametroAconAumento,float* parametroBconAumento,float* valorPorUnidadParametroB,
		float* valorPorUnidadParametroA,float* difDeValores,float* parametroABitcoin, float* parametroBBitcoin);

/// @brief Calcula cantidad en una unidad. Puntero al espacio de memoria del resultado del calculo
/// @param valorInicial Recibe un valor inicial
/// @param undiad Cantidad a calcular costo por unidad de valirInicial
/// @param valorPorUnidad Devuelve por referencia el valorInicial con aumento.
void valorUnitario(float valorInicial, float undiad, float* valorPorUnidad);

/// @brief Calcula la diferencia entre dos valores, independientemente de quien sea el mayor/menor siempre se busca el calculo positivo.
/// @param valorA Valor a diferenciar con B
/// @param valorB Valor a diferenciar con A
/// @param valorResultado Puntero al espacio de memoria del resultado del calculo de diferencia entre valor A y B
void diferenciaDeValores(float valorA, float valorB, float* valorResultado);

/// @brief Calcula Valor inicial a valor Bitcoin.
/// @param valorInicial Valor a pasar a bitcoin
/// @param valorABitcoin Puntero al espacio de memoria del valor inicial en porcentaje Bitcoin
void valorAbitcoin(float valorInicial,float* valorABitcoin);

/// @brief Calcula el porcentaje de un valor.
/// @param valorInicial Valor a convertir
/// @param valorPorcentaje Valor cantidad porcentaje
/// @param valorResultado Puntero al espacio de memoria del valor resultado.
void porcentajeDeUnValor(float valorInicial, float valorPorcentaje, float* valorResultado);

#endif /* CALCULOS_H_ */
