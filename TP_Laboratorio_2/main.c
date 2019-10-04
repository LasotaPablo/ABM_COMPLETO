#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"

int main()
{
    struct eEmpleados aEmpleados[CANT_EMPLEADOS];
    int opcion;
    int ID;
    initEmpleados(aEmpleados,CANT_EMPLEADOS);
    do
    {
        printf("-------------------------------\n\n"
               "¿Que accion deseea realizar?\n\n"
               "1.Alta de un nuevo empleado\n"
               "2.Modificar un empleado\n"
               "3.Baja a un empleado\n"
               "4.Mostrar la lista de empleados\n"
               "0.Salir\n\n"
               "-------------------------------\n");
        getInt(&opcion,"Ingrese un numero: ","Error\n",0,6,2);
        system("cls");
        switch(opcion)
        {
        case 1:
            altaEmpleados(aEmpleados,CANT_EMPLEADOS);
            break;
        case 2:
            getInt(&ID,"Ingrese el id para modificar\n","Error\n",0,100000,2);
            modificarEmpleados(aEmpleados,CANT_EMPLEADOS,ID);
            break;
        case 3:
   			getInt(&ID,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
   			bajaEmpleado(aEmpleados,CANT_EMPLEADOS,ID);
   			break;
        case 4:
            imprimirEmpleados(aEmpleados,CANT_EMPLEADOS);
            break;
        default:
            printf("Precione enter para salir del programa\n");
            break;
        }

    }while(opcion < 5 && opcion > 0);

}
