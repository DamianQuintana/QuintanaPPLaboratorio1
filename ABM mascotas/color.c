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

int listarColores(eColor* color, int tam)
{
    int i;
    printf("\nID\t\t\tDESCRIPCION\n");
    for(i=0; i<tam; i++)
    {
        printf("%d\t\t\t%s\n", color[i].id, color[i].nombreColor);

    }
    return 0;
}
int imprimirColor(eColor* color, int tam, int id)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(id == color[i].id)
        {
            printf("%s\n", color[i].nombreColor);
        }

    }
    return 0;
}
