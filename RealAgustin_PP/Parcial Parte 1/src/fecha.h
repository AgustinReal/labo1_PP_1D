/*
 * fecha.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int dia;
	int mes;
	int anio;

}dFecha;

int Fecha_pedirVerificarFecha(dFecha* fecha);
int Fecha_modificarFecha(dFecha* fecha);
void Fecha_imprimirFecha(dFecha fecha);

#endif /* FECHA_H_ */
