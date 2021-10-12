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

}sFecha;

int Fecha_pedirVerificarFecha(sFecha* fecha);
int Fecha_modificarFecha(sFecha* fecha);
void Fecha_imprimirFecha(sFecha fecha);
int Fecha_AcpyB(sFecha fechaA,sFecha fechaB);

#endif /* FECHA_H_ */
