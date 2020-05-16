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
#include "trabajo.h"

 // Definicion de los tamaños
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMTT 10
#define TAMM 10

int main()
{
    eTipo tipo[TAMT] = {{1000, "Ave"},{1001, "Perro"},{1002, "Gato"},{1003, "Roedor"},{1004, "Pez"}}; //Hardocdeo del array de estructuras
    eColor color[TAMC]= {{5000, "Negro"},{5001, "Blanco"},{5002, "Gris"},{5003, "Rojo"},{5004, "Azul"}};//Hardocdeo del array de estructuras
    eServicio servicio[TAMS] = {{20000, "Corte", 250},{20001, "Desparasitado", 250},{20002, "Castrado", 250},};//Hardocdeo del array de estructuras
    eTrabajo trabajo[TAMTT]; //Definicion de estructura
    eMascota mascota[TAMM];//Definicion de estructura

    int menu; //Variable de control del menu
    int lugarLibre;//Variable de control para los indices libres
    int idMascota = 0; //Variable donde iremos guardando los ID de las mascotas, autoincremental
    char decision; //Variable de control para saber si se desea cargar otra mascota
    int modifyID;//Variable donde guardamos el ID a modificar
    int removeID;//Variable donde guardo el ID a dar de baja
    int control;//Variable de control para las funciones
    int idTrabajos = 0; // Variable autoincremental del id de los trabajos
    int controlMenu;

    inicializarMascotas(mascota, TAMM); // Inicializo el array de mascotas, es decir, pongo sus edades en -1
    inicializarTrabajos(trabajo, TAMTT); // Inicializa el array de trabajos, es decir, pongo sus id de servicio en -1
    do
    {
        printf("\n1- Alta mascota");
        printf("\n2- Modificar mascota");
        printf("\n3- Baja mascota");
        printf("\n4- Listar mascotas");
        printf("\n5- Listar tipos");
        printf("\n6- Listar colores");
        printf("\n7- Listar servicios ");
        printf("\n8- Alta trabajo");
        printf("\n9- Listar trabajos");
        printf("\n10 - Salir");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            do
            {
                controlMenu = 1; // Variable de control, si entramos en la primer opciona la ponemos en 1
                lugarLibre = buscarMascotaLibre(mascota, TAMM); // utilizamos la variable lugarLibre para guardar la primer posicion libre del array
                if(lugarLibre != -1)// En caso de haber encontrado lugar
                {
                    idMascota++; // Incrementamos el contador de ID en 1
                    agregarMascota(mascota, TAMM, tipo, TAMT, color, TAMC, idMascota, lugarLibre);
                    printf("\nAlta exitosa");
                    printf("\nDesea cargar otra mascota?\ns - SI\nn - NO");
                    fflush(stdin);
                    scanf("%c", &decision); // Consultamos si desea cargar otra mascota
                }
                else
                {
                    printf("\nNo hay mas espacio"); // En caso de no haber encontrado lugar
                    decision = 'n';
                }
            }
            while(decision == 's');

            break;

        case 2:
            if(controlMenu == 1) // Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                printf("\nIngrese el ID que desea modificar: ");
                scanf("%d", &modifyID);
                control = ModificarMascota(mascota, TAMM, modifyID, tipo, TAMT, color, TAMC); // Llamada de funcion donde vamos a guardar el valor retornado en control
                if(control!=-1)
                {
                    printf("\nModificado con exito");
                }
                else
                {
                    printf("No se modifico");
                }

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 3:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                printf("\nIngrese el ID que desea dar de baja: ");
                scanf("%d", &removeID);
                control = quitarMascota(mascota, TAMM, removeID);// Llamada de funcion donde vamos a guardar el valor retornado en control
                if(control == -1)
                {
                    printf("\nNo se dio de baja");
                }
                else
                {
                    printf("\nBaja exitosa");
                }


            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 4:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                ordenarMascotas(mascota, TAMM); // Llamada a la funcion
                imprimirMascotas(mascota, TAMM, tipo, TAMT, color, TAMC);// Llamada a la funcion

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 5:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                listarTipos(tipo, TAMT);// Llamada a la funcion
            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 6:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                listarColores(color, TAMC);// Llamada a la funcion

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }
            break;

        case 7:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                listarServicios(servicio, TAMS);

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }
            break;

        case 8:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                do
                {
                    lugarLibre = buscarTrabajoLibre(trabajo, TAMTT);
                    if(lugarLibre != -1)
                    {
                        idTrabajos++;
                        agregarTrabajo(trabajo, TAMTT,  lugarLibre, idTrabajos, mascota, TAMM, servicio, TAMS);
                        printf("\nDesea cargar otr trabajo?\ns - SI\nn - NO");
                        fflush(stdin);
                        scanf("%c", &decision);
                    }
                    else
                    {
                        printf("\nNo hay mas espacio");
                        decision = 'n';
                    }
                }
                while(decision == 's');

            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;

        case 9:
            if(controlMenu == 1)// Si ya ingresamos en el menu 1 ejecutamos la siguiente linea
            {
                imprimirTrabajos(trabajo, TAMTT, servicio, TAMS);
            }
            else
            {
                printf("\nPrimero cargue alguna mascota");
            }

            break;
        }
    }
    while(menu!=10);
}
