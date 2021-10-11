/*
 * perritos.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perritos.h"
#include "inputs.h"

int Perro_iniciarLista(dPerritos lista[], int len)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			lista[i].estadoVacio=1;
		}
		retorno=1;
	}
  return retorno;
}
int Perritos_agregarPerrito(dPerritos lista[], int len, int id, char nombre[],char raza[],int edad)
{
	int valor;
	  int index;
	  index=Perritos_buscarEspacioLibrePerrito(lista, len);

		if(index!=-1)
		{
			printf("\nCargando la lista en espacios libres espere unos segundos...\n");
			if(lista!=NULL && lista[index].estadoVacio==1)
			{
				lista[index].id=id;
				strcpy(lista[index].nombre, nombre);
				strcpy(lista[index].raza, raza);
				lista[index].edad=edad;
				lista[index].estadoVacio=0;

			}
			else
			{
				printf("\nError ya se cargo la lista no hay espacios disponibles...\n");
			}
			valor=0;
		}
		else
		{
			printf("\nNo se pudo cargar...\n");
			valor=-1;
		}
	return valor;
}
int Perritos_eliminarPerrito(dPerritos lista[], int len, int id)
{
	int retorno=-1;
	int index;
	int idIngresado;

	if(lista!=NULL)
	{
		pedirEntero(&idIngresado,"Ingrese el ID del perrito a borrar de (0-1000): ", "Reingrese el ID del perrito a borrar de (0-1000): ", 0, 1000);
		index=Perritos_buscarPorIdPerrito(lista, len, idIngresado);

		if(index!=-1)
		{
			printf("\nEl Perrito a eliminar:\n\n %-5d %-20s %-20s %-20d %-20d\n", "Id", "Nombre", "raza", "edad", "estado");
			Perritos_mostrarUnPerrito(lista[index]);

			if(!ConfirmarSioNoPerrito("\nIngrese 's' para confirmar la eliminacion del perrito."))
			{
				lista[index].estadoVacio=0;
				printf("\nEl perrito %s fue eliminado correctamente!\n\n", lista[index].nombre);
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la eliminacion...\n\n");
			}
		}
		else
		{
			printf("\nError. No se encontro el perrito..");
		}
	}
	return retorno;
}
int Perritos_contarPerritosActivos(dPerritos lista[], int len, int* contadorperritos)
{
	int retorno=-1;
	*contadorperritos=0;

	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].estadoVacio==0)
			{
				*contadorperritos+=1;
				retorno=1;
			}
		}
	}
	return retorno;
}
float Perritos_SumaEdadesGeneral(dPerritos lista[],int len, float* acumuladorEdadesPerritosAux)
{
	int retorno=-1;
		*acumuladorEdadesPerritosAux=0;

		if(lista!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				if(lista[i].estadoVacio==0)
				{
					*acumuladorEdadesPerritosAux+=lista[i].edad;
					retorno=1;
				}
			}
		}
		return retorno;
}
float Perritos_PromedioEdades(dPerritos lista[],int len , float* promedio, float* acumuladorEdadesPerritosAux, int* contadorperritos)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		*promedio=*acumuladorEdadesPerritosAux/(float)*contadorperritos;
		retorno=1;
	}
	return retorno;
}
void Perritos_mostrarUnPerrito(dPerritos perro)
{
	printf("%-5d %-20s %-20s %-20d %-20d\n", perro.id, perro.nombre, perro.raza, perro.edad, perro.estadoVacio);
}
int Perritos_imprimirPerritos(dPerritos lista[], int length)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		printf("\nLista de perritos:\n\n %-5d %-20s %-20s %-20d %-20d\n", "Id", "nombre", "raza", "edad", "estado");

		for(int i=0;i<length;i++)
		{
			if(lista[i].estadoVacio==0)
			{
				Perritos_mostrarUnPerrito(lista[i]);
			}
		}
		printf("\n");
	 retorno=1;
	}

	return retorno;

	 return 0;
}
int Perritos_buscarEspacioLibrePerrito(dPerritos lista[], int len)
{
	int i;
		int index=-1;

		if(lista!=NULL)
		{
			for(i=0; i<len; i++)
			{
				if(lista[i].estadoVacio==1)
				{
					index = i;
					break;
				}
			}
		}
		return index;
}
int ConfirmarSioNoPerrito(char* mensaje)
{
	int retorno=-1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}

	return retorno;
}
int Perritos_buscarPorIdPerrito(dPerritos lista[], int len,int id)
{
	int index=-1;

	if(lista!=NULL && id!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].estadoVacio==0 && lista[i].id==id)
			{
				index=1;
				break;
			}
		}
	}
	return index;
}