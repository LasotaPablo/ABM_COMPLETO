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

