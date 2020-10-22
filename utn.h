/*
 * valicacion.h
 *
 *  Created on: 23 sep. 2020
 *      Author: Lucasdamiann
 */

#ifndef VALICACION_H_
#define VALICACION_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "electrodomestico.h"

typedef struct
{

    int id;
    int sector;
    char valorDeChar[100];
    float valor;
    int isEmpty;
}estructura;


/*\brief Obtiene una cadena de caracteres, muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para la letras que ingrese, recibe cantidad de reintentos.
 * \param char *aResultado array de caracteres.
 * \param char *mensaje array de caracteres con mensaje.
 * \param char *mensajeError array de caracteres con mensaje de error.
 * \param int len valor de largo del array.
 * \param char minimo valor de minima que puede ingresarse.
 * \param char maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int utn_getName(char *aResultado, char *mensaje, char *mensajeError, int len,
	char minimo, char maximo, int retries);
/*\brief Recibe un numero,por teclado,muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para el numero que se ingrese, recibe cantidad de reintentos.
 * \param int* pResultado puntero a variable que recibe un valor por teclado y lo retorna por referencia.
 * \param char* mensaje array de caracteres con mensaje.
 * \param char* mensajeError array de caracteres con mensaje de error.
 * \param int minimo valor de minima que puede ingresarse.
 * \param int maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL, minimo mayor a maximo, reintentos negativos] - (0) si está Ok
 */
int utn_getNumber(int *pResultado, char *mensaje, char *mensajeError,
	int minimo, int maximo, int reintentos);
/*\brief Recibe un numero,por teclado,muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para el numero que se ingrese, recibe cantidad de reintentos.
 * \param int* pResultado puntero a variable que recibe un valor por teclado y lo retorna por referencia.
 * \param char* mensaje array de caracteres con mensaje.
 * \param char* mensajeError array de caracteres con mensaje de error.
 * \param int minimo valor de minima que puede ingresarse.
 * \param int maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL, minimo mayor a maximo, reintentos negativos] - (0) si está Ok
 */
int utn_getUnsignedNumber(int *pResultado, char *mensaje, char *mensajeError,
	int minimo, int maximo, int reintentos);
/*\brief Recibe un numero,por teclado,muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para el numero que se ingrese, recibe cantidad de reintentos.
 * \param float* pResultado puntero a variable que recibe un valor por teclado y lo retorna por referencia.
 * \param char* mensaje array de caracteres con mensaje.
 * \param char* mensajeError array de caracteres con mensaje de error.
 * \param float minimo valor de minima que puede ingresarse.
 * \param float maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL, minimo mayor a maximo, reintentos negativos] - (0) si está Ok
 */

float utn_getNumberFloat(float *pResultado, char *mensaje, char *mensajeError,
	float minimo, float maximo, int reintentos);
/*\brief Recibe un numero y lo convierte a int.
 * \param int *pResultado array de numeros, retorna por referencia.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int getInt(int *pResultado);
/*\brief Recibe un numero y lo convierte a int.
 * \param int *pResultado array de numeros, retorna por referencia.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int getIntUnsigned(int *pResultado);
/*\brief Recibe un numero y lo convierte a float.
 * \param float *pResultado array de numeros, retorna por referencia.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int getFloat(float *pResultado);
/*\brief Valida si el dato ingresado es un numero(positivo o negativo) y  cuenta cantidad de puntos.
 * \param char *pResultado array de caracteres numericos.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int isNumber(char* pResultado);
/*\brief Valida si el dato ingresado es un numero.
 * \param char *pResultado array de caracteres numericos.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int isValidNumber(char* pResultado);
/*\brief Valida si el dato ingresado es una cadena de caracteres.
 * \param char *aResultado array de caracteres.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int isName(char *aResultado);
/*\brief Valida el largo y el final de un array de caracteres.
 * \param char *aResultado array de caracteres.
 * \param int longitud largo de array de caracteres.
 *\ return int retorno (-1) si hay Error [puntero == NULLy longitud <0] - (0) si está Ok
 */
int myGets(char *aResultado, int longitud);
/*\brief imprime el array recibido indice por indice.
 * \param int*array puntero a array.
 * \param int len valor de largo del array.
 */
void printArray(int *array, int len);
/*\brief Ordena el array recibido en orden ascendente o descendente segun se ingrese 0 o 1.
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int order valor de orden ascendente 0 o descendente 1.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (cantidad de iteraciones) si está Ok
 */
int ordenaConCriterio(estructura *list, int len, int order);
/*\brief Ordena el array recibido.
 * \param int*recibeArray puntero a array.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int orderArray(int *recibeArray, int len);
/*\brief Entrega un valor de ID en base a un contador.
 * \param int valorId valor actual de contador (asociado a ID)
 * \param int *id  valor de puntero de contador (asociado a ID)
 *\ return int ret (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int get_ID(int valorId, int *id);
/*\brief Busca espacios vacios en el array(isEmpty==1).
 * \param estructura*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (pasaje del i por valor) si está Ok
 */
int get_FreeSpace(eElectrodomestico *list, int len);
/*\brief Entrega la cantidad de salarios acumulados.
 * \param estructura*list puntero a la estructura.
 * \param float * valorFloat valor de puntero que recibe el valor del salario y lo devuelve por referencia.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [algun puntero == NULL y len <0] - (0) si está Ok
 */
int acumularFloat(estructura *list, float *valorFloat, int len);
/*\brief Entrega la cantidad de salarios acumulados.
 * \param estructura*list puntero a la estructura.
 * \param float * valorFloat valor de puntero que recibe el valor del salario y lo devuelve por referencia.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [algun puntero == NULL y len <0] - (0) si está Ok
 */
int superanPromedio(estructura *list, float valorFloat, int len);
/*\brief Entrega un valor promediado por los datros recibidos.
 * \param estructura*list puntero a la estructura.
 * \param float *pCalculoResulProm puntero a variable donde se devuelve lo hecho por la funcion.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL y len <0] - (0) si está Ok
 */
int promedioPorEstructura(estructura *list, float *pCalculoResultProm, int len);
/*\brief Recorre el array iniciando cada campo isEmpty en 1 (vacio).
 * \param estructura*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int inicializarEstructura(eElectrodomestico *list, int len);
/*\brief Agrega un usuario con sus datos (nombre, apellido,id,salario y sector).
 * \param estructura*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de ID del usuario asignado por el sistema.
 * \param char arrayChar estructura de caracteres del array.
 * \param float valor valor de salario del usuario.
 * \param int sector valor de sector del usuario.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */

#endif /* VALIDACION_H_ */
