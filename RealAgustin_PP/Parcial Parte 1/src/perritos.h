/*
 * perritos.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef PERRITOS_H_
#define PERRITOS_H_

#include "inputs.h"

#define LEN 5



typedef struct
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estadoVacio;

}dPerritos;

int Perritos_iniciarLista(dPerritos lista[], int len);
int Perritos_agregarPerrito(dPerritos lista[], int len, int id, char nombre[],char raza[],int edad);
int Perritos_buscarEspacioLibrePerrito(dPerritos lista[], int tam);
int Perritos_buscarPorIdPerrito(dPerritos lista[], int len,int id);
int Perritos_eliminarPerrito(dPerritos lista[], int len, int id);
void Perritos_mostrarUnPerrito(dPerritos perro);
int ConfirmarSioNoPerrito(char* mensaje);
int Perritos_contarPerritosActivos(dPerritos lista[],int len, int* contadorperritos);
float Perritos_SumaEdadesGeneral(dPerritos lista[],int len, float* acumuladorEdadesPerritosAux);
float Perritos_PromedioEdades(dPerritos lista[],int len , float* promedio, float* acumuladorEdadesPerritosAux, int* contadorperritos);
int Perritos_imprimirPerritos(dPerritos lista[], int length);
#endif /* PERRITOS_H_ */
