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

}sPerritos;

int Perritos_iniciarLista(sPerritos lista[], int len);
int Perritos_agregarPerrito(sPerritos lista[], int len, int id, char nombre[],char raza[],int edad);
int Perritos_buscarEspacioLibrePerrito(sPerritos lista[], int tam);
int Perritos_buscarPorIdPerrito(sPerritos lista[], int len,int id);
int Perritos_eliminarPerrito(sPerritos lista[], int len, int id);
void Perritos_mostrarUnPerrito(sPerritos perro);
int ConfirmarSioNoPerrito(char* mensaje);
int Perritos_contarPerritosActivos(sPerritos lista[],int len, int* auxContadorPerritos);
float Perritos_SumaEdadesGeneral(sPerritos lista[],int len, float* acumuladorEdadesPerritosAux);
float Perritos_PromedioEdades(sPerritos lista[],int len , float* promedio, float* acumuladorEdadesPerritosAux, int* auxContadorPerritos);
int Perritos_imprimirPerritos(sPerritos lista[], int length);
#endif /* PERRITOS_H_ */
