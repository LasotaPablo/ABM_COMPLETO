#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"

static int crearID(void)
{
    static int ID = 0;
    ID++;
    return ID;
}

int initEmpleados(struct eEmpleados* aArray,int cantidad)
{
    int i;
    int retorno = -1;
    if(aArray != NULL && cantidad > 0)
    {
        for(i = 0; i<cantidad; i++)
        {
            aArray[i].status = STATUS_EMPTY;
        }
        retorno = 0;
    }
    return retorno;
}

int buscarLugarLibreEmpleados(struct eEmpleados *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray != NULL && cantidad > 0)
    {
        for(i=0;i<cantidad;i++)
        {
            if(aArray[i].status == STATUS_EMPTY)
            {
                retorno = i;
                break;
            }
		}
	}
	return retorno;
}

int altaEmpleadosID(struct eEmpleados *aArray, int cantidad, struct eEmpleados item)
{
    int retorno = -1;
	int index;
    if(aArray != NULL && cantidad > 0)
    {
		index = buscarLugarLibreEmpleados(aArray, cantidad);
		if(index >= 0)
		{
			aArray[index] = item;
			aArray[index].status = STATUS_NOT_EMPTY;
			aArray[index].id = crearID();
			retorno = 0;
		}
	}
	return retorno;
}

int buscarEmpleadosID(struct eEmpleados *aArray, int cantidad, int id)
{
    int i;
    int retorno = -1;
    if(aArray != NULL && cantidad > 0)
    {
        for(i = 0; i < cantidad; i++)
        {
            if(aArray[i].id == id && aArray[i].status == STATUS_NOT_EMPTY)
            {
                retorno = i;
                break;
            }
        }
        return retorno;
    }
}

int altaEmpleados(struct eEmpleados *aArrays, int len)
{
	struct eEmpleados bEmpleados;
	int retorno = -1;
	if (buscarLugarLibreEmpleados(aArrays, len) != -1)
        {
            if (getString(bEmpleados.nombre, "Ingrese el nombre\n", "Error", 1, 50, 2) != -1)
            {
                if (getString(bEmpleados.apellido, "Ingrese el apellido\n", "Error", 1, 50, 2) != -1)
                {
                    if (getFloat(&bEmpleados.sueldo, "Ingrese el sueldo\n", "Error", 0, 1000000, 2) != -1)
                    {
						if (getInt(&bEmpleados.sector, "Ingrese el sector\n1.Gerencia\n2.Empleado\n", "Error", 1, 2, 2) != -1)
						{
							if (altaEmpleadosID(aArrays, len, bEmpleados) == 0)
							{
								printf("Alta exitosa\n");
								retorno = 0; // OK
							}
						}
                    }
                }
            }

        }
    if(retorno!=0)
	{
		printf("Error al cargar datos\n");
	}
	return retorno;
}

int modificarEmpleadosID(struct eEmpleados *aArray, int cantidad, struct eEmpleados item)
{
    int index;
    int retorno = -1;
    if(aArray != NULL && cantidad > 0)
    {
        index = buscarEmpleadosID(aArray ,cantidad, item.id);
        if(index != -1)
        {
            aArray[index] = item;
            aArray[index].status = STATUS_NOT_EMPTY;
            retorno = 0;
        }
    }
    return retorno;
}

int modificarEmpleados(struct eEmpleados *aArray, int cantidad,int ID)
{
    int retorno = -1;
    struct eEmpleados bEmpleados;
    int opcion;
    if (buscarEmpleadosID(aArray, CANT_EMPLEADOS,ID) == -1)
    {
        printf("Error el id no existe\n");
    }
    printf("¿Que desea modificar de este empleado?\n"
            "1.Nombre\n"
            "2.Apellido\n"
            "3.Sueldo\n"
            "4.Sector\n"
            "0.No deseo modificar nada\n");
    getInt(&opcion,"Ingrese una opcion: ","Error, esa no es una opcion!!",0,5,2);
    bEmpleados.id = ID;
    switch(opcion)
    {
        case 1:
            getString(bEmpleados.nombre,"Ingrese el nuevo nombre: \n","Error\n",1,51,2);
            break;
        case 2:
            getString(bEmpleados.apellido,"Ingrese el nuevo apellido: \n","Error\n",1,51,2);
            break;
        case 3:
            getFloat(&bEmpleados.sueldo,"Ingrese el nuevo sueldo: \n","Error, no es un sueldo valido\n",0,100000,2);
            printf("Cambio de sueldo exitoso!\n");
            break;
        case 4:
            getInt(&bEmpleados.sector,"Ingrese el nuevo sector\n1.Gerencia\n2.Empleado\n","Error, sector inexistente\n",1,2,2);
            printf("Cambio de sector exitoso!\n");
            break;
        default:
            printf("Precione cualquier tecla para salir \n");
            break;
    }
    if (modificarEmpleadosID(aArray, CANT_EMPLEADOS, bEmpleados) == 0)
    {
        printf("Modificacion exitosa\n");
        retorno = 0;
    }
    else
    {
        printf("Error al hacer la modificacion\n");
    }
    return retorno;
}
