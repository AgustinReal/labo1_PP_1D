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

typedef struct
{
	int id;
	char nombresDuenio[51];
	int telefonoContacto[10];
	int idPerro;
	int fecha;

}dEstadiaDiaria;

int EstadiaDiaria_initLista(dEstadiaDiaria list[], int len);
//int EstadiaDiaria_addEstadiaDiaria(dEstadiaDiaria list[], int len, int id, char nombreduenio[],int telefonoContacto, int idPerro, eFecha fecha);
int EstadiaDiaria_buscarEspacioLibre(dEstadiaDiaria list[], int tam);
int EstadiaDiaria_findById(dEstadiaDiaria list[], int len,int id);
int EstadiaDiaria_removePerro(dEstadiaDiaria list[], int len, int id);
int EstadiaDiaria_printLista(dEstadiaDiaria list[], int length);
void EstadiaDiaria_printEncabezado();
void EstadiaDiaria_printOne(dEstadiaDiaria estadia);
int EstadiaDiaria_PedirIdPerro(dPerritos list[], int length, int *idPerro,int cantidadIntentosPermitidos);



#endif /* ESTADIADIARIA_H_ */
