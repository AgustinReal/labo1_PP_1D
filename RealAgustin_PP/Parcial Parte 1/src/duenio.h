/*
 * duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef DUENIO_H_
#define DUENIO_H_

#include "inputs.h"

#define LEN 5

typedef struct
{
	int id;
	char nombre[41];
	int telefono;
	int estadoDuenioVacio;

}sDuenio;

int duenio_iniciarLista(sDuenio lista[], int len);
int duenio_buscarPorId(sDuenio lista[], int len, sDuenio* id);
int duenio_buscarEspacioLibre(sDuenio lista[], int len);
int duenio_agregarDuenio(sDuenio lista[], int len, int* id, char nombre[],int telefono);
void duenio_mostrarUnaEstadia(sDuenio estadia);
int duenio_imprimirListaEstadiaDiaria(sDuenio lista[], int length);

#endif /* DUENIO_H_ */
