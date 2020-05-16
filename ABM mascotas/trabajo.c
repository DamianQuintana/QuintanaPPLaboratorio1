#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "mascota.h"
#include "auxiliar.h"
#include "tipos.h"
#include "servicio.h"
#include "color.h"


int inicializarTrabajos(eTrabajo* trabajo, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        trabajo[i].idServicio = -1; // Utilizaremos el id del servicio en -1 para indicar que esta libre esta posicion
    }
    return 0;

}
int buscarTrabajoLibre(eTrabajo* trabajo, int size)
{
    int flag;
    int i;

    for(i=0; i<size; i++)
    {
        if(trabajo[i].idServicio == -1) // En caso de la posicion estar libre
        {
            flag = i; // Devolvemos la posicion del primer lugar libre del array
            break;
        }
        else
        {
            flag = -1;
        }
    }

    return flag;//Retornamos la posicion del array

}
int agregarTrabajo(eTrabajo* trabajo, int size, int i, int id, eMascota* mascota, int size2, eServicio* servicio, int size3)
{

    int j;
    int flag;

    trabajo[i].id = id;
    printf("\nIngrese la fecha: ");
    printf("\nDia: ");
    trabajo[i].fecha.dia = getInt();
    printf("\nMes: ");
    trabajo[i].fecha.mes = getInt();
    printf("\nAnio: ");
    trabajo[i].fecha.anio = getInt();
    printf("\nIngrese el ID de la mascota: ");
    trabajo[i].idMascota = getInt();
    do
    {
        flag = buscarMascotaPorID(mascota, size2, trabajo[i].idMascota);
        if(flag ==-1)
        {
            printf("\nNo se ha encontrado dicho ID, reingrese: ");
            flag = buscarMascotaPorID(mascota, size2, trabajo[i].idMascota);
            trabajo[i].idMascota = getInt();
        }
    }
    while(flag ==-1);
    printf("Ingrese el ID del servicio: ");
    trabajo[i].idServicio = getInt();
    for(j=0; j<size3; j++)
    {
        if(trabajo[i].idServicio != servicio[j].id)
        {
            flag = -1;
            printf("\nNo se ha encontrado dicho ID, reingrese: ");
            trabajo[i].idServicio = getInt();
        }
        else
        {
            flag = 1;
            break;
        }
    }
    return 0;
}
int imprimirTrabajos(eTrabajo* trabajo, int size, eServicio* servicio, int size2)
{
    int i;
    printf("\nFECHA\t\tID\t\tMASCOTA\t\tSERVICIO\n");
    for(i=0; i<size; i++)
    {
        if( trabajo[i].idServicio !=-1)
        {
            printf("%d/%d/%d\t\t%d\t%d\t",trabajo[i].fecha.dia,trabajo[i].fecha.mes,trabajo[i].fecha.anio, trabajo[i].id,trabajo[i].idMascota);
            imprimirServicio(servicio, size2, trabajo[i].idServicio);
        }


    }
return 0;
}

