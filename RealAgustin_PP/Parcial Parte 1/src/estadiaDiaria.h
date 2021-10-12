/*
 * estadiaDiaria.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

#include "inputs.h"
#include "perritos.h"
#include "fecha.h"
typedef struct
{
	int id;
	char nombresDuenio[51];
	int telefonoContacto;
	int idPerro;
	sFecha fecha;
	int estadoEstadiaVacio;

}sEstadiaDiaria;

int EstadiaDiaria_iniciarLista(sEstadiaDiaria lista[], int len);
int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria lista[], int len, int id, char nombresDuenio[],int telefonoContacto, int idPerro, sFecha fecha);
int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria lista[], int len);
int EstadiaDiaria_buscarPorId(sEstadiaDiaria lista[], int len,int id);
int EstadiaDiaria_eliminarPerroEstadia(sEstadiaDiaria lista[], int len, int id);
int ConfirmarSioNoEstadiaDiaria(char* mensaje);
void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria estadia);
int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria lista[], int len);
int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria lista[], int length);


#endif /* ESTADIADIARIA_H_ */
