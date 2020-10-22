/*
 * reparacion.h
 *
 *  Created on: 14 oct. 2020
 *      Author: Lucasdamiann
 */
#include "electrodomestico.h"

#ifndef REPARACION_H_
#define REPARACION_H_
#define LEN_TIEMPO 4
#define LEN_SERVICIO 25
#define LEN_FECHA 4
#define QTY_SRV 4
#define LRG_NAME 51
#define QTY_CL 6

typedef struct
    {
	int dia;
	int mes;
	int anio;
    } eFecha;

typedef struct
    {
	int idCliente;
	char nombreCliente[LRG_NAME];
	char apellidoCliente[LRG_NAME];
	int isEmpty;
    } eCliente;

typedef struct
    {
	int idServicio;
	char descServicio[LEN_SERVICIO];
	int precio;
    } eServicio;

typedef struct
    {
	int id;
	eCliente idCliente;
	int numSerieElectro; //validar
	int idServ; //validar
	eFecha fecha;
	int isEmpty;
    } eReparacion;

/*\brief Recorre la estructura iniciando cada campo isEmpty en 1 (vacio).
 * \param eReparacion*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int inicializarReparacion(eReparacion *list, int len);
/*\brief Asigna valores hardcodeados a la estructura.
 * \param eServicio*list puntero a array de estructura.
 * \param int len valor de largo del array.
 */
void hardcodeoServicio(eServicio *list);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eServicio*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printServicios(eServicio *list, int len);
/*\brief Guarda a la estructura los valores ingresados.
 * \param eReparacion*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int idRep valor de id de reparacion.
 * \param int cliente valor de id de cliente.
 * \param int servicio valor de id de servicio.
 * \param int numSerieElectro valor de serie de electrodomestico.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int agregarReparacion(eReparacion *list, int len, int idRep,
	int servicio, int numSerieElectro);
/*\brief Recorre la estructura buscando cada campo isEmpty en 1 (vacio).
 * \param eReparacion*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int get_FreeSpaceR(eReparacion *list, int len);
/*\brief Asigna valores hardcodeados a la estructura.
 * \param eCliente*list puntero a array de estructura.
 * \param int len valor de largo del array.
 */
void hardcodeoCliente(eCliente *list, int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eCliente*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printClientes(eCliente *lista, int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eReparacion*list puntero a array de estructura.
 * \param eCliente*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printReparaciones(eReparacion *lista,eCliente*list, int len);
/*\brief Pide y valida los valores ingresados como dia mes y año.
 * \param eReparacion*list puntero a array de estructura.
 * \param int index valor de indice del array.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int validaFecha(eReparacion *list,int index,int len);
#endif /* REPARACION_H_ */

