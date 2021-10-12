/*
 * estadiaDiaria.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadiaDiaria.h"
#include "inputs.h"

int EstadiaDiaria_iniciarLista(sEstadiaDiaria lista[], int len)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].estadoEstadiaVacio=1;
		}
		retorno=1;
	}
	return retorno;
}
int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria lista[], int len, int id, char nombresDuenio[],int telefonoContacto, int idPerro, sFecha fecha)
{
	int retorno=-1;

	int index;
	  index=EstadiaDiaria_buscarEspacioLibre(lista, len);

		if(index!=-1)
		{
			printf("\nCargando la lista en espacios libres espere unos segundos...\n");
			if(lista!=NULL && lista[index].estadoEstadiaVacio==1)
			{
				lista[index].id=id;
				strcpy(lista[index].nombresDuenio, nombresDuenio);
				lista[index].telefonoContacto=telefonoContacto;
				lista[index].idPerro=idPerro;
				lista[index].fecha=fecha;
				lista[index].estadoEstadiaVacio=0;

			}
			else
			{
				printf("\nError ya se cargo la lista no hay espacios disponibles...\n");
			}
			retorno=0;
		}
		else
		{
			printf("\nNo se pudo cargar...\n");
			retorno=-1;
		}


	return retorno;
}
int EstadiaDiaria_eliminarPerroEstadia(sEstadiaDiaria lista[], int len, int id)
{
	int retorno=-1;
	int index;
	int idIngresado;

	if(lista!=NULL)
	{
		pedirEntero(&idIngresado,"Ingrese el ID del perrito de la estadia a borrar de (0-1000): ", "Reingrese el ID del perrito a borrar de la estadia de (0-1000): ", 0, 1000);
		index=EstadiaDiaria_buscarPorId(lista, len, idIngresado);

		if(index!=-1)
		{
			printf("\nEl Perrito de la estadia a eliminar:\n\n %-5d %-20s %-20d %-20d %d-%d-%d %-20d\n\n", "Id", "NombreDueño", "telefonoContacto", "idPerro", "dia-mes-anio", "estado");
			EstadiaDiaria_mostrarUnaEstadia(lista[index]);

			if(!ConfirmarSioNoEstadiaDiaria("\nIngrese 's' para confirmar la eliminacion del perrito de la estadia."))
			{
				lista[index].estadoEstadiaVacio=0;
				printf("\nEl perrito de la estadia %s fue eliminado correctamente!\n\n", lista[index].nombresDuenio);
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la eliminacion...\n\n");
			}
		}
		else
		{
			printf("\nError. No se encontro la estadia del perrito...");
		}
	}
	return retorno;
}
int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria lista[], int len)
{
		int order;
		int retorno=-1;
		sEstadiaDiaria auxLista;

		if(lista!=NULL)
		{

		   printf("Ingrese la manera que quiere ordenar los nombres, 1 para ascendente o 2 para de descendente: ");
		   fflush(stdin);
		   scanf("%d", &order);

		   while(order>3)
		   {
			   printf("Ingrese la manera que quiere ordenar los nombres, 1 para ascendente o 2 para de descendente: ");
			   fflush(stdin);
			   scanf("%d", &order);
		   }

		   switch(order)
		   {
			 case 1:
				for(int i=0;i<len;i++)
				{
				  for(int j=i+1;j<len;j++)
				  {
					  if(lista[i].estadoEstadiaVacio==1 && lista[j].estadoEstadiaVacio==1 && strcmp(lista[i].nombresDuenio, lista[j].nombresDuenio)==1)
					  {
						  auxLista=lista[i];
						  lista[i]=lista[j];
						  lista[j]=auxLista;
					  }
					  else if(strcmp(lista[i].nombresDuenio, lista[j].nombresDuenio)==0 && Fecha_AcpyB(lista[i].fecha, lista[j].fecha))
					  {
						  auxLista=lista[i];
						  lista[i]=lista[j];
					      lista[j]=auxLista;
					  }
				  }
				}
			 break;
			 case 2:
				 for(int i=0;i<len;i++)
				 {
				   for(int j=i+1;j<len;j++)
				   {
					   if(lista[i].estadoEstadiaVacio==1 && lista[j].estadoEstadiaVacio==1 && strcmp(lista[i].nombresDuenio, lista[j].nombresDuenio)==-1)
					   {
						  auxLista=lista[i];
						  lista[i]=lista[j];
						  lista[j]=auxLista;
					   }
					   else if(strcmp(lista[i].nombresDuenio, lista[j].nombresDuenio)==0 && Fecha_AcpyB(lista[i].fecha, lista[j].fecha))
					  {
						  auxLista=lista[i];
						  lista[i]=lista[j];
						  lista[j]=auxLista;
					  }
				   }
				 }
			 order=0;
			 break;
			 retorno=1;
		   }

		}

		return retorno;
}
void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria estadia)
{
	printf("%-5d %-20s %-20d %-20d %d-%d-%d %-20d\n", estadia.id, estadia.nombresDuenio, estadia.telefonoContacto, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio, estadia.estadoEstadiaVacio);
}
int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria lista[], int length)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		printf("\nEl Perrito de la estadia a eliminar:\n\n %-5d %-20s %-20d %-20d %d-%d-%d %-20d\n\n", "Id", "NombreDueño", "telefonoContacto", "idPerro", "dia-mes-anio", "estado");

		for(int i=0;i<length;i++)
		{
			if(lista[i].estadoEstadiaVacio==0)
			{
				EstadiaDiaria_mostrarUnaEstadia(lista[i]);
			}
		}
		printf("\n");
	 retorno=1;
	}

	return retorno;

}
int ConfirmarSioNoEstadiaDiaria(char* mensaje)
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
int EstadiaDiaria_buscarPorId(sEstadiaDiaria lista[], int len,int id)
{
	int index=-1;

		if(lista!=NULL && id!=NULL)
		{
			for(int i=0;i<len;i++)
			{
				if(lista[i].estadoEstadiaVacio==0 && lista[i].id==id)
				{
					index=1;
					break;
				}
			}
		}
		return index;
}
int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria lista[], int len)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(lista[i].estadoEstadiaVacio==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;

}

