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
								printf("ALTA EXITOSA!\n");
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
    struct eEmpleados bEmpleados;
    int retorno = -1;
    if (buscarEmpleadosID(aArray, CANT_EMPLEADOS,ID) == -1)
    {
        printf("Error el id no existe\n");
        return retorno;
    }
    bEmpleados.id = ID;
    if (getString(bEmpleados.nombre, "Ingrese el nuevo nombre: \n", "Error\n", 1, 51, 2) == -1)
    {
        printf("Error en el nombre\n");
        retorno = 0;
    }
    if (getString(bEmpleados.apellido, "Ingrese el nuevo apellido: \n", "Error\n", 1, 51, 2) == -1)
    {
        printf("Error en la direccion\n");
    }
    if (getFloat(&bEmpleados.sueldo, "Ingrese el nuevo sueldo: \n", "Error\n", 0, 1000000, 2) == -1)
    {
        printf("Error en el precio\n");
    }
    if (getInt(&bEmpleados.sector, "Ingrese el nuevo sector: \n Recuerde-\n1.Gerencia-----2.Empleado\n", "Error\n", 1, 2, 2) == -1)
    {
        printf("Error en el tipo\n");
    }
    if(modificarEmpleadosID(aArray,CANT_EMPLEADOS,bEmpleados) == -1)
    {
        printf("MODIFICACION EXITOSA!\n");
    }
    return retorno;
}
int imprimirEmpleados(struct eEmpleados *aArray, int cantidad)
{
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad > 0 )
	{
		retorno = 0;
		printf("Recuerde los sectores son:\n\n1.Gerencia -- 2.Empleado\n\n"
                "id     Nombre    Apellido    Sueldo     Tipo\n");
		for(i = 0; i < cantidad; i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				printf("%d ---- %s ---- %s ---- %2.f ---- %d \n",aArray[i].id,aArray[i].nombre,aArray[i].apellido,aArray[i].sueldo,aArray[i].sector);
			}

		}
	}
	return retorno;
}
int bajaEmpleadoID(struct eEmpleados *aArray, int cantidad,int id)
{
	int retorno = -1;
	int index;
	if(aArray!=NULL && cantidad > 0)
    {
		index = buscarEmpleadosID(aArray, cantidad, id);
		if(index != -1)
        {
			aArray[index].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}
int bajaEmpleado(struct eEmpleados *aArray, int cantidad, int ID)
{
    int retorno = -1;
    char conf;
    if(bajaEmpleado(aArray,CANT_EMPLEADOS, ID) == -1)
    {
        printf("No existe el id\n");
        return retorno;
    }
    getChar(&conf,"¿Esta seguro que desea realizar esta baja?(s/n)\n","No es una respuesta valida(s/n)\n",'a','z',2);
    if(conf == 's')
    {
        if(bajaEmpleadoID(aArray,CANT_EMPLEADOS,ID) == 0)
        {
            printf("BAJA EXITOSA!\n");
            retorno = 0;
        }
        else
        {
            printf("Error al dar la baja, verifique si el ID existe\n");
        }
    }
    return retorno;
}

int ordenarEmpleados(struct eEmpleados *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct eEmpleados bEmpleados;
	int swap;
	if(aArray != NULL && cantidad > 0)
	{
		retorno = 0;
		do
		{
			swap = 0;
			for(i = 0; i < cantidad - 1; i++)
			{
				if(strncmp(aArray[i].apellido,aArray[i+1].apellido,CANT_CARAC)>0)
				{
					swap = 1;
					bEmpleados = aArray[i];
					aArray[i] = aArray[i+1];
					aArray[i+1] = bEmpleados;
				}
				else if(strncmp(aArray[i].apellido,aArray[i+1].apellido,CANT_CARAC) == 0)
				{
					if(strncmp(aArray[i].sector,aArray[i+1].sector,CANT_CARAC) > 0)
					{
						swap = 1;
						bEmpleados = aArray[i];
						aArray[i] = aArray[i+1];
						aArray[i+1] = bEmpleados;
					}
				}
			}
		}while(swap);
	}
	return retorno;
}
