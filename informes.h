/*
 * informes.h
 *
 *  Created on: 22 oct. 2020
 *      Author: Lucasdamiann
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eElectrodomesticos*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printElectros2020(eElectrodomestico *list, int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eElectrodomesticos*list puntero a array de estructura.
 * \param int marca valor de marca del array.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printElectrosMarca(eElectrodomestico *list,int marca, int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eElectrodomesticos*list puntero a array de estructura.
 * \param eCliente*list puntero a array de estructura.
 * \param int serieElectro valor de numero de serie del electrodomestico.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printReparacionesEfectuadas(eReparacion *lista,eCliente*list, int serieElectro,int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eReparacion*list puntero a array de estructura.
 * \param eServicio*list puntero a array de estructura.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printReparacionesEfectuadas2018(eReparacion *lista,eServicio*list,eElectrodomestico*listas, int len);
int printSinReparacionesEfectuadas(eReparacion *lista,eCliente*list,eElectrodomestico* listas,int len);
#endif /* INFORMES_H_ */
