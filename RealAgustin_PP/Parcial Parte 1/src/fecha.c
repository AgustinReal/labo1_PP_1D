/*
 * fecha.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "inputs.h"

int Fecha_pedirVerificarFecha(dFecha* fecha)
{
	int retorno=-1;
	int huboError=0;
	int diaAux;
	int mesAux;
	int anioAux;

	if(fecha!=NULL)
	{

		pedirEntero(diaAux, "Ingrese el dia para la estadia del perrito: ", "Error. Ingrese el dia para la estadia del perrito: ", 1, 31);
		pedirEntero(mesAux, "Ingrese el mes para la estadia del perrito: ", "Error. Ingrese el mes para la estadia del perrito: ", 1, 12);
		pedirEntero(anioAux, "Ingrese el anio para la estadia del perrito: ", "Error. Ingrese el anio para la estadia del perrito: ", 2021, 2100);

		if(mesAux>1 && mesAux<12)
		{
			switch(mesAux)
			{
				case  1:
				case  3:
				case  5:
				case  7:
				case  8:
				case 10:
				case 12:
					if (diaAux>= 1 && diaAux<=31)
					{
						printf("\nFECHA CORRECTA");
					}
					else
					{
						printf("\nFECHA INCORRECTA");
						huboError=1;
					}
				break;
				case  4:
				case  6:
				case  9:
				case 11:
					if(diaAux>=1 && diaAux<=30)
					{
					   printf("\nFECHA CORRECTA");
					}
					else
					{
					   printf("\nFECHA INCORRECTA");
					   huboError=1;
					}
			    break;
				case 2:
					if(anioAux%4==0 && anioAux%100!=0 || anioAux%400==0)
					{
						if (diaAux>=1 && diaAux<=29)
						{
							printf("\nFECHA CORRECTA");
						}
						else
						{
							printf("\nFECHA INCORRECTA");
							huboError=1;
						}
					}
					else
					{
						if (diaAux>=1 && diaAux<=28)
						{
							printf("\nFECHA CORRECTA");
						}
						else
						{
							printf("\nFECHA INCORRECTA");
							huboError=1;
						}
					}
				break;
			}
		}
		else
		{
			printf("\nFECHA INCORRECTA");
			huboError=1;
			getch();
		}
	}

	if(huboError==0)
	{
		retorno=1;
	}
	return retorno;
}
int Fecha_modificarFecha(dFecha* fecha)
{
	int retorno=-1;

	if(fecha!=NULL)
	{

		Fecha_pedirVerificarFecha(fecha);

	}
	return retorno;
}
void Fecha_imprimirFecha(dFecha fecha)
{
	printf("%-3d %-3d %-5d", fecha.dia, fecha.mes, fecha.anio);
}
