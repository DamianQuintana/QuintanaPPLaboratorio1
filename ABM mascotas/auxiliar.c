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
int getInt(void)
{
    char numero[30];
    int numeroI;
    int longitud;
    int estado=0;
    int i;

    fflush(stdin);
    gets(numero);
    longitud = strlen(numero); // Copiamos la longitud de la cadeba

    do
    {

        for(i=0; i<longitud; i++)
        {
            estado = isalpha(numero[i]);

            if(numero[i] == '.' || numero[i] == ',') // En el caso de que alguno de los caracteres sean los siguientes, cambiamos el etado a 1
            {
                estado =1;
                break;
            }
        }

        if(estado !=0)
        {
            printf("Invalido, reingrese un numero entero: ");
            gets(numero);
            longitud = strlen(numero);
        }

    }
    while(estado !=0);

    numeroI = atoi(numero); // Transformo ese numero en entero
    return numeroI;
}
float getFloat(void)
{
    char numero[30];
    int numeroF;
    int longitud;
    int estado=0;
    int i;

    fflush(stdin);
    gets(numero);
    longitud = strlen(numero);

    do
    {
        for(i=0; i<longitud; i++)
        {
            estado = isalpha(numero[i]); // En cso de que el valor que ingresamos sea un caracter nos va a dar un 1
        }

        if(estado !=0)
        {
            printf("Invalido, reingrese un numero valido: ");
            gets(numero);
            longitud = strlen(numero);
        }

    }
    while(estado !=0); // Si el estado está en 0 quiere decir que solamente se ingresaron numeros

    numeroF = atof(numero); // Transforme ese numero en flotante y lo retorno
    return numeroF;
}

void getChar(char palabra[30])
{
    int estado = 1;
    int estado2 = 1;
    int longitud;
    int i;

    fflush(stdin);

    gets(palabra);
    longitud = strlen(palabra);

    do
    {
        if(estado == 0)
        {
            printf("\n\nReingrese la palabra: ");
            gets(palabra);
            longitud = strlen(palabra);
        }
        for(i = 0; i < longitud; i++)
        {
            estado = isalpha(palabra[i]); // Si es una letra me da un no cero

        }
        for(i=0; i<longitud; i++)
        {
            estado2 = isdigit(palabra[i]); // Si es un numero me devuelve un no cero;

        }
    }
    while(estado == 0 || estado2 != 0);
}

