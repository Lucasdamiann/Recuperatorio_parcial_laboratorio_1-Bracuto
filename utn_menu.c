/*
 * menu.c
 *
 *  Created on: 26 sep. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "reparacion.h"
#include "electrodomestico.h"
#include "informes.h"

int menuOpciones()
    {

    printf("\n<<BIENVENIDO AL MENU>>\n");
    char respuesta = 'r';
    int comando;
    int flag1 = 0;
    int flag2 = 0;
    int identify = 0;
    int identifyRep = 0;
    int index;
    int numeroMarca;
    int numeroSerie;
    int contadorElectro = 0;
    int contServ1=0;
    int contServ2=0;
    int contServ3=0;
    int contServ4=0;
    char masPedido[10];
    eCliente cliente[QTY_ELEC];
    eReparacion reparacion[QTY_ELEC];
    eServicio auxServ;
    eServicio servicios[QTY_SRV];
    eMarca auxMarca;
    eMarca marca[QTY_MARCA];
    eElectrodomestico auxElectro;
    eElectrodomestico electro[QTY_ELEC];
    inicializarEstructura(electro, QTY_ELEC);
    inicializarReparacion(reparacion, QTY_ELEC);
    hardcodeoServicio(servicios);
    hardcodeoMarcas(marca);
    hardcodeoCliente(cliente, QTY_ELEC);
    do
	{
	printf("\n<<MENU INICIAL>>\n");
	printf(
		"\n#1-ALTA DE ELECTRODOMESTICO.\n#2-MODIFICAR ELECTRODOMESTICO.\n#3-BAJA DE ELECTRODOMESTICO.\n#4-LISTAR ELECTRODOMESTICOS.\n#5-LISTAR MARCAS.\n#6-LISTAR SERVICIOS.\n#7-ALTA DE REPARACION.\n#8-LISTAR REPARACIONES.\n#9-LISTAR CLIENTES.\n#10-INFORMES.\n#11-SALIR.\n");
	utn_getNumber(&comando, "\nINGRESE OPCION: ", "\nOPCION INCORRECTA\n",
		1, 11, 2);
	switch (comando)
	    {
	case 1:
	    printf("\nSECCION DE ALTA DE CLIENTE\n");
	    if ((utn_getNumber(&auxElectro.modelo, "\nINGRESE MODELO: ",
		    "\nALGO SALIO MAL\n", 1900, 2020, 2)) == 0
		    && (utn_getNumber(&auxElectro.numSerie,
			    "\nINGRESE LOS ULTIMOS 4 CARACTERES DEL NUMERO DE SERIE: ",
			    "\nALGO SALIO MAL\n", 0, 9999, 2)) == 0)
		{
		printMarcas(marca, QTY_MARCA);
		utn_getNumber(&auxMarca.idMarca, "\n\nINGRESE ID DE MARCA: ",
			"\nALGO SALIO MAL\n", 1000, 1004, 2);
		get_ID(identify, &identify);
		agregarElectro(electro, QTY_ELEC, identify, auxElectro.numSerie,auxMarca.idMarca,
			auxElectro.modelo);
		contadorElectro++;
		index = findElectroById(electro, QTY_ELEC, identify);
		printf("\nELEMENTO ALMACENADO\n");
		printOneElectro(electro, marca, index, auxMarca.idMarca);
		printf("\n\n");
		flag1 = 1;
		}
	    break;
	case 2:
	    if (flag1 == 1)
		{
		printf("\nMODIFICAR ELECTRODOMESTICO\n\n");
		printf(
			"\n#1-MODIFICAR N° DE SERIE.\n#2-MODIFICAR MODELO.\n#3-SALIR.\n");
		utn_getNumber(&comando, "\nINGRESE OPCION: ",
			"\nOPCION INCORRECTA\n", 1, 3, 2);
		if (comando == 1 && comando == 2 && comando == 3)
		    {
		    printElectros(electro, QTY_ELEC);
		    utn_getNumber(&identify, "\nINGRESE ID:",
			    "\nOPCION INCORRECTA", 1, 3000, 2);
		    index = findElectroById(electro, QTY_ELEC, identify);
		    }
		if (index != -1)
		    {
		    switch (comando)
			{
		    case 1:
			printf("\nMODIFICACION DE NUMERO DE SERIE\n");
			utn_getNumber(&electro[index].numSerie,
				"\nINGRESE NUMERO DE SERIE NUEVO: ",
				"\nALGO SALIO MAL\n", 0, 100000, 2);
			printf("\nMODIFICACION REALIZADA\n");
			printOneElectro(electro, marca, index,
				auxMarca.idMarca);
			printf("\n\n");
			break;
		    case 2:
			printf("\nMODIFICACION DE MODELO\n");
			utn_getNumber(&electro[index].modelo,
				"\nINGRESE MODELO NUEVO: ",
				"\nALGO SALIO MAL\n", 1900, 2020, 2);
			printf("\n¡MODIFICACION REALIZADA!\n");
			printOneElectro(electro, marca, index,
				auxMarca.idMarca);
			printf("\n\n");
			break;
		    case 3:
			printf("\nVOLVIENDO AL MENU PRINCIPAL\n");
			printf("\n\n");
			break;
			}
		    }
		else
		    {
		    printf("\nESE ID NO ESTA REGISTRADO O FUE DADO DE BAJA\n");
		    printf("\n\n");
		    }
		}
	    else
		{
		printf(
			"\nDEBE INGRESAR UN ELECTRODOMESTICO PARA PODER MODIFICARLO\n");
		printf("\n\n");
		}
	    break;
	case 3:
	    if (flag1 == 1)
		{
		printf("\nELIMINAR ELECTRODOMESTICO\n");
		printf("\n#1-ELIMINAR ELECTRODOMESTICO.\n#2-SALIR.\n");
		utn_getNumber(&comando, "\nINGRESE OPCION: ",
			"\nOPCION INCORRECTA\n", 1, 2, 2);
		if (comando != 2)
		    {
		    printElectros(electro, QTY_ELEC);
		    utn_getNumber(&identify, "\nINGRESE ID:",
			    "\nOPCION INCORRECTA\n", 1, 3000, 2);
		    index = findElectroById(electro, QTY_ELEC, identify);
		    }
		if (index != -1)
		    {
		    switch (comando)
			{
		    case 1:
			printf("\nVA A ELIMINAR A:\n ");
			printOneElectro(electro, marca, index,
				auxMarca.idMarca);
			printf("\n#1-ELIMINAR.\n#2-CANCELAR.\n");
			utn_getNumber(&comando, "\nINGRESE OPCION: ",
				"\nOPCION INCORRECTA\n", 1, 2, 2);
			switch (comando)
			    {
			case 1:
			    removeElectro(electro, QTY_ELEC, identify);
			    contadorElectro--;
			    printf("\nELECTRODOMESTICO ELIMINADO\n");
			    printf("\n\n");
			    break;
			case 2:
			    printf("\nELIMINAR CANCELADO.\n");
			    printf("\n\n");
			    break;
			    }
			break;
		    case 2:
			printf("\nVOLVIENDO AL MENU PRINCIPAL\n");
			printf("\n\n");
			break;
			}
		    }
		else
		    {
		    printf("\nESE ID NO ESTA REGISTRADO O FUE DADO DE BAJA\n");
		    printf("\n\n");
		    }
		}
	    else
		{
		printf(
			"\nDEBE INGRESAR UN ELECTRODOMESTICO PARA PODER ELIMINARLO\n");
		printf("\n\n");
		}
	    break;
	case 4:
	    if (flag1 == 1)
		{
		printf("\nMOSTRAR ELECTRODOMESTICOS\n");
		printf("\n#1-MOSTRAR ELECTRODOMESTICOS.\n#2-SALIR.\n");
		utn_getNumber(&comando, "\nINGRESE OPCION: ",
			"\nALGO SALIO MAL\n", 1, 2, 2);
		switch (comando)
		    {
		case 1:
		    if (contadorElectro > 0)
			{
			printf("\nSECCION MOSTRAR ELECTRODOMESTICOS\n");
			ordenaElectrosConCriterio(electro, QTY_ELEC, 1);
			printElectros(electro, QTY_ELEC);
			printf("\n\n");
			}
		    else
			{
			printf("\nNO HAY ELECTRODOMESTICOS PARA MOSTRAR\n");
			}
		    break;
		case 2:
		    printf("\nVOLVIENDO AL MENU PRINCIPAL\n");
		    printf("\n\n");
		    break;
		    }
		}
	    else
		{
		printf(
			"\nDEBE INGRESAR AL MENOS UN ELECTRODOMESTICO PARA PODER MOSTRAR\n");
		printf("\n\n");
		}
	    break;
	case 5:
	    printf("\nSECCION MOSTRAR MARCAS\n");
	    printMarcas(marca, QTY_MARCA);
	    printf("\n\n");
	    break;
	case 6:
	    printf("\nSECCION MOSTRAR SERVICIOS\n");
	    printServicios(servicios, QTY_SRV);
	    printf("\n\n");
	    break;
	case 7:
	    if (flag1 == 1)
		{
		printf("\nSECCION ALTA DE REPARACION\n");
		printf("\n#1-ELEGIR ELECTRODOMESTICO.\n#2-SALIR.\n");
		utn_getNumber(&comando, "\nINGRESE OPCION: ",
			"\nALGO SALIO MAL\n", 1, 2, 2);
		switch (comando)
		    {
		case 1:
		    get_ID(identifyRep, &identifyRep);
		    printElectros(electro, QTY_ELEC);
		    if (utn_getNumber(&auxElectro.idElectro,
			    "\nINGRESE ID DE ELECTRODOMESTICO: ",
			    "\nID INEXISTENTE\n", 1, 3000, 2) == 0)
			{
			printServicios(servicios, QTY_SRV);
			if (utn_getNumber(&auxServ.idServicio,
				"\nINGRESE ID DE SERVICIO: ",
				"\nID INEXISTENTE\n", 20000, 20003, 2) == 0)
			    {
			    if(auxServ.idServicio==20000)
				{
				contServ1++;
				}
			    if(auxServ.idServicio==20001)
			    {
				contServ2++;
			    }
			    if(auxServ.idServicio==20002)
				{
				contServ3++;
				}
			    if(auxServ.idServicio==20003)
				{
				contServ4++;
				}
			    if(contServ1>contServ2 && contServ1>contServ3 && contServ1>contServ4)
				{
				strncpy(masPedido,"GARANTIA",10);
				}
			    if(contServ2>contServ1 && contServ2>contServ3 && contServ2>contServ4)
				{
				strncpy(masPedido,"MANTENIM.",10);
				}
			    if(contServ3>contServ1 && contServ3>contServ2 && contServ3>contServ4)
				{
				strncpy(masPedido,"REPUESTOS",10);
				}
			    if(contServ4>contServ1 && contServ4>contServ2 && contServ4>contServ3)
				{
				strncpy(masPedido,"REFACCION",10);
				}

			    printf("\nINGRESE FECHA DE ALTA\n");
			    agregarReparacion(reparacion, QTY_ELEC, identifyRep,
				    auxServ.idServicio, auxElectro.idElectro);
			    flag2 = 1;
			    }
			else
			    {
			    break;
			    }
			}
		    else
			{
			break;
			}

		    printf("\n\n");
		    break;
		case 2:
		    printf("\nVOLVIENDO AL MENU PRINCIPAL\n");
		    printf("\n\n");
		    break;
		    }
		}
	    else
		{
		printf(
			"\nDEBE INGRESAR AL MENOS UN ELECTRODOMESTICO PARA PODER REPARAR\n");
		printf("\n\n");
		}
	    break;
	case 8:
	    if (flag2 == 1)
		{
		printReparaciones(reparacion, cliente, QTY_ELEC);
		printf("\n\n");
		}
	    else
		{
		printf("\nDEBE INGRESAR UNA REPARACION PARA LISTAR\n");
		printf("\n\n");
		}
	    break;
	case 9:

	    printClientes(cliente, QTY_CL);
	    printf("\n\n");
	    break;
	case 10:
		printf("\nSECCION INFORMES\n");
	    if (flag1 == 1)
		{
		printf("\n#1-MOSTRAR ELECTRODOMESTICOS DEL AÑO.\n#2-MOSTRAR ELECTRODOMESTICOS DE UNA MARCA SELECCIONADA.\n#3-MOSTRAR TODAS LAS REPARACIONES EFECTUADAS AL ELECTRODOMESTICO SELECCIONADO.\n#4-LISTAR LOS ELECTRODOMESTICOS QUE NO TUVIERON REPARACIONES.\n#6-MOSTRAR EL SERVICIO MAS PEDIDO.\n#9-TRABAJOS REALIZADOS A ELECTRODOMESTICOS DEL AÑO 2018.\n");
		utn_getNumber(&comando, "\nINGRESE OPCION: ",
			"\nOPCION INCORRECTA\n", 1, 12, 2);
		if(comando>=1 && comando<=12)
		    {
		    switch(comando)
			{
		    case 1:
			printElectros2020(electro, QTY_ELEC);
			printf("\n\n");
			break;
		    case 2:
			printMarcas(marca, QTY_MARCA);
			utn_getNumber(&numeroMarca, "\nINGRESE OPCION: ","\nOPCION INCORRECTA\n", 1000, 1004, 2);
			printElectrosMarca(electro, numeroMarca, QTY_ELEC);
			break;
		    case 3:
			printElectros(electro, QTY_ELEC);
			utn_getNumber(&numeroSerie, "\nSELECCIONE NUMERO DE SERIE: ","\nOPCION INCORRECTA\n", 0, 9999, 2);
			printReparacionesEfectuadas(reparacion, cliente, numeroSerie, QTY_ELEC);
			break;
		    case 4:
			printSinReparacionesEfectuadas(reparacion, cliente,electro, QTY_ELEC);
			break;
		    case 6:
			printf("\nEL SERVICIO MAS PEDIDO ES %s",masPedido);
			break;
		    case 9:
			printReparacionesEfectuadas2018(reparacion, servicios, electro, QTY_ELEC);
			break;
		    }
		}
		}
	    else
		{
		printf(
			"\nDEBE INGRESAR ELESCTRODOMESTICOS ANTES DE LISTAR INFORMES\n");
		}
	    break;
	case 11:
	    printf("\nSALIENDO DEL PROGRAMA\n\n¡HASTA LUEGO!\n");
	    printf("\n\n");
	    respuesta = 'j';
	    break;
	    }

	}
    while (respuesta == 'r');

    return 0;
    }

