/*
 * Bibliotecas.h
 *
 *  Created on: 6 abr 2022
 *      Author: Usuario Programador
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

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
void utnCalcularCostos(float parametroPivot, float parametroA, float parametroB,float* parametroAconDescuento,
		float* parametroBconDescuento,float* parametroAconAumento,float* parametroBconAumento,float* valorPorUnidadParametroB,
		float* valorPorUnidadParametroA,float* difDeValores);

/// @param valorInicial Recibe un valor inicial
/// @param valorConDescuento Devuelve por referencia el valorInicial con descuento.
void utnCostoConDescuento(float valorInicial,float* valorConDescuento);

/// @param valorInicial Recibe un valor inicial
/// @param valorConRecargo Devuelve por referencia el valorInicial con aumento.
void utnCostoConAumento(float valorInicial,float* valorConRecargo);

/// @param valorInicial Recibe un valor inicial
/// @param undiad Cantidad a calcular costo por unidad de valirInicial
/// @param valorPorUnidad Devuelve por referencia el valorInicial con aumento.
void utnCostoUnitario(float valorInicial, float undiad, float* valorPorUnidad);

/// @param valorA Valor a diferenciar con B
/// @param valorB Valor a diferenciar con A
/// @param valorResultado Resultado de diferencia entre valor A y B
void utnDiferenciaDeValores(float valorA, float valorB, float* valorResultado);



#endif /* CALCULOS_H_ */
