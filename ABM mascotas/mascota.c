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

int inicializarMascotas(eMascota* mascota, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mascota[i].edad = -1; //Utilizaremos como bandera de estado la edad de la mascota, indicando como -1, libre
    }
    return 0;
}
int buscarMascotaLibre(eMascota* mascota, int size)
{
    int flag;
    int i;

    for(i=0; i<size; i++)
    {
        if(mascota[i].edad == -1) // En caso de la posicion estar libre
        {
            flag = i; // Devolvemos la posicion del primer lugar libre del array
            break;
        }
        else
        {
            flag = -1; //En caso de no encontrar posiciones libres ponemos la bandera en -1
        }
    }

    return flag;//Retornamos la posicion del array
}
int agregarMascota(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3, int id, int i)
{
    int j;
    int flag;

    printf("\nIngrese la edad de su mascota: ");
    mascota[i].edad = getFloat();
    mascota[i].id = id;
    printf("\nIngrese el nombre de su mascota");
    getChar(mascota[i].nombre);
    printf("\nIngrese su tipo de mascota: ");
    printf("\n1000-Ave\n1001-Perro\n1002-Gato\n1003-Roedor\n1004-Pez");
    mascota[i].idTipo = getInt();
    do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
    {
        for(j=0; j<tam2; j++)
        {
            if(mascota[i].idTipo != tipo[j].id) //En caso de que ninguno de los tipos que encontramos coincida
            {
                flag = -1; // Ponemos la bandera en -1 indicando error
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == -1)
        {
            printf("\nNo se encontro dicho ID de tipo, reingrese: ");
            mascota[i].idTipo = getInt();
        }
    }
    while(flag == -1);
    printf("\nIngrese el color de su mascota: ");
    printf("\n5000-Negro\n5001-Blanco\n5002-Gris\n5003-Rojo\n5004-Azul");
    mascota[i].idColor = getInt();
    do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
    {
        for(j=0; j<tam3; j++)
        {
            if(mascota[i].idColor != color[j].id) //En caso de que ninguno de los tipos que encontramos coincida
            {
                flag = -1; // Ponemos la bandera en -1 indicando error
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag == -1)
        {
            printf("\nNo se encontro dicho ID de tipo, reingrese: ");
            mascota[i].idColor = getInt();
        }
    }
    while(flag == -1);

    return 0;

}
int imprimirMascotas(eMascota* mascota, int tam, eTipo* tipo, int tam2, eColor* color, int tam3)
{
    int i;
    printf("\nID\t\tNOMBRE\t\tEDAD\t\tTIPO\t\tCOLOR\n");
    for(i=0; i<tam; i++)
    {
        if(mascota[i].edad != -1) //En el caso que la edad de la mascota no sea -1 imprimiremos sus datos
        {
            printf("%d\t\t%s\t\t%f\t\t",mascota[i].id, mascota[i].nombre, mascota[i].edad);
            imrpirmirTipo(tipo, tam2, mascota[i].idTipo);
            imprimirColor(color, tam3, mascota[i].idColor);
        }
    }
    return 0;
}
int buscarMascotaPorID(eMascota* mascota, int tam, int id)
{
    int i;
    int flag;

    for(i=0; i<tam; i++)
    {
        if(mascota[i].id == id && mascota[i].edad != -1) //En el caso de que el ID ingresado sea igual al id del array y se encuentre dado de alta
        {
            flag = i;// Guardamos su posicion en el array
            break;
        }
        else
        {
            flag = -1;
        }
    }
    return flag;//Devolvemos la psosición de ese elemento
}
int imprimirUnaMascota(eMascota* mascota, int tam, int id)
{

    int i;
    i = buscarMascotaPorID(mascota, tam, id); // En caso de no encontrarla, i nos devolverá -1
    if(i!=-1)
    {
        printf("\nID\t\tNOMBRE\t\tTIPO\t\tCOLOR\t\tEDAD\n");
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%f\n", mascota[i].id,mascota[i].nombre,mascota[i].idTipo,mascota[i].idColor,mascota[i].edad);
    }
    else
    {
        printf("\nNo se encontro dicho ID");
    }

    return 0;

}
int ModificarMascota(eMascota* mascota, int tam, int id, eTipo* tipo, int tam2, eColor* color, int size3)
{
    int modify; // Variable donde guardamos el dato que se vaya a modificar
    int flag; // Variable de control y retorno
    int i; // Variable donde guardamos la posicion de la mascota en el array
    int j;
    int flag2;

    i = buscarMascotaPorID(mascota, tam, id); // Guardamos en la variable "i" la posicion de la mascota en el array
    if(i != -1) // En caso de encontrar a la mascota ejecutamos la siguiente línea de código
    {
        imprimirUnaMascota(mascota, tam, id);
        printf("\nQue dato desea modificar\n1-Tipo\n2-Edad\n3-Nada");
        scanf("%d", &modify);
        switch(modify)
        {
        case 1:
            printf("\nIngrese el nuevo tipo: ");
            printf("\n1000-Ave\n1001-Perro\n1002-Gato\n1003-Roedor\n1004-Pez");
            mascota[i].idTipo = getInt();
            do //Utilizamos la siguiente secuencia de "do while" para evitar que se tome un valor como id de tipo que no sea alguno de los cargados
            {
                for(j=0; j<tam2; j++)
                {
                    if(mascota[i].idTipo != tipo[j].id) //En caso de que ninguno de los tipos que encontramos coincida
                    {
                        flag = -1; // Ponemos la bandera en -1 indicando error
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == -1)
                {
                    printf("\nNo se encontro dicho ID de tipo, reingrese: ");
                    mascota[i].idTipo = getInt();
                }
            }
            while(flag == -1);
            flag2 = 1;
            break;

        case 2:
            printf("\nIngrese la nueva edad: ");
            mascota[i].edad = getFloat();
            flag2 = 1;
            break;

        case 3:
            flag2 = -1; // En caso de no haber modificado nada ponemos la bandera de estado en -1
            break;
        }
    }
    else
    {
        printf("\nNo se encontro dicho ID");
    }
    return flag2; //Retorno 1 en caso de haber modificado, retorno -1 en caso contrario

}
int quitarMascota(eMascota* mascota, int tam, int id)
{
    int i; // Variable de control para la estructura "for"
    int decision; // Variable de control para la confirmación de baja
    int flag = 0; // Variable de control para indicar si se dió de baja

    i = buscarMascotaPorID(mascota, tam, id);
    if(i != -1) // En caso de este valor ser diferente a -1 (error) ejecutamos el siguiente bloque
    {
        system("CLS"); // Limpiamos pantalla
        imprimirUnaMascota(mascota, tam, id);
        printf("\nDesea darlo de baja? \n1-Si\n2-No\nUsted ingreso: "); // Imprimimos por pantalla consultando la reconfirmación
        scanf("%d", &decision); // Tomamos el ingreso por teclado
        if(decision == 1) //En caso de que la opción sea = 1 damos de baja al empleado
        {
            flag = 0; // Indicamos "flag = 0" diciendo que la baja está "OK"
            mascota[i].edad = -1; // Indicamos la edad en -11 para "lugar libre"
        }
        else
        {
            flag = -1; // En caso de no haberse dado de baja cambiamos el valor de flag a -1
        }
    }
    else
    {
        flag = -1; // En caso de no encontrar dicho ID en sistema cambiamos el valor de flag a -1
        system("CLS"); // Limpiamos pantalla
        printf("No se encontro en el sistema ese ID\n"); //Mostramos por mensaje el error
        system("PAUSE"); // Pausamos la ejecución del programa
    }
    return flag; // Retornamos el valor de flag - 1 En caso de no haberse dado de baja
}
int ordenarMascotas(eMascota* mascota, int size)
{

    int i;
    int j;
    eMascota auxMascotas[size]; // Variable auxiliar

/*METODO DE BURBUJEO POR DOS CRITERIOS*/
        for(i=0; i<size-1; i++)
        {
            for(j=i+1; j<size; j++)
            {
                if(mascota[i].idTipo<mascota[j].idTipo) //Ordenado por tipo
                {
                    auxMascotas[i] = mascota[i];
                    mascota[i] = mascota[j];
                    mascota[j] = auxMascotas[i];
                }
                else if(mascota[i].idTipo == mascota[j].idTipo && (strcmp(mascota[i].nombre, mascota[j].nombre)) >0) // En caso de que los tipos sean iguales, utilizo el criterio por nombre
                {
                    auxMascotas[i] = mascota[i];
                    mascota[i] = mascota[j];
                    mascota[j] = auxMascotas[i];
                }
            }
        }

    return 0;
}
