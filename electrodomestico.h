/*
 * electrodomestico.h
 *
 *  Created on: 14 oct. 2020
 *      Author: Lucasdamiann
 */

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_
#define DESC 10
#define QTY_ELEC 3000
#define QTY_MARCA 5

typedef struct
    {
	int idMarca;
	char descripcion[DESC];
	int isEmpty;
    } eMarca;

typedef struct
    {
	int idElectro;
	int numSerie;
	int idMarca;
	int modelo;
	int isEmpty;
    } eElectrodomestico;

/*\brief Recorre la estructura iniciando cada campo isEmpty en 1 (vacio).
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int inicializarElectros(eElectrodomestico *list, int len);
/*\brief Guarda a la estructura los valores ingresados.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de id de electrodomestico.
 * \param int serie valor de numero de serie de electrodomestico.
 * \param int idMarca valor de numero de marca de electrodomestico.
 * \param int modelo valor de numero de modelo.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int agregarElectro(eElectrodomestico *list, int len, int id, int serie,int idMarca,
	int modelo);
/*\brief Asigna valores hardcodeados a la estructura.
 * \param eMarca*lista puntero a array de estructura.
 */
void hardcodeoMarcas(eMarca *lista);
/*\brief Busca un elemento en la estructura a partir de un dato.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de id de electrodomestico.
 * *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (valor del indice) si está Ok
 */
int findElectroById(eElectrodomestico *list, int len, int id);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eElectrodomesticos*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printElectros(eElectrodomestico *list, int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eMarca*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printMarcas(eMarca *lista, int len);
/*\brief Recorre la estructura imprimiendo los los campos especificados.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int index valor de indice del electrodomestico.
 * \param int id valor de id del electrodomestico que se ingresa.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printOneElectro(eElectrodomestico *list, eMarca *lista, int index,int id);
/*\brief Recorre la estructura poniendo el campo isEmpty en 0 (vacio) de determinado id.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de id del electrodomestico.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int removeElectro(eElectrodomestico *list, int len, int id);
/*\brief Recorre la estructura ordenando cada elemento del array.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int order valor de orden (1=ascencende, 0=descendente).
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int ordenaElectrosConCriterio(eElectrodomestico *list, int len, int order);
/*\brief Guarda a la estructura los valores ingresados.
 * \param eElectrodomestico*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de id de electrodomestico.
 * \param int serie valor de numero de serie del electrodomestico.
 * \param int modelo valor de numero de modelo.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int agregarUsuario(eElectrodomestico *list, int len, int id, int serie,
	int modelo);

#endif /* ELECTRODOMESTICO_H_ */
