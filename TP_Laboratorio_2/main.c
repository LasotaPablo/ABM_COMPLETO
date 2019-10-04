#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmpleados.h"
#include "utn.h"

int main()
{
    struct eEmpleados aEmpleados[CANT_EMPLEADOS];
    struct eEmpleados bEmpleados;
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
			if (buscarEmpleadosID(aEmpleados, CANT_EMPLEADOS,ID) == -1)
            {
				printf("Error el id no existe\n");
				break;
			}
			bEmpleados.id = ID;
			if (getString(bEmpleados.nombre, "Ingrese el nuevo nombre\n", "Error\n", 1, 49, 2) == -1) {
				printf("Error en el nombre\n");
				break;
			}
			if (getString(bEmpleados.apellido, "Ingrese el nuevo apellido\n", "Error", 1, 49, 2) == -1) {
				printf("Error en la direccion\n");
				break;
			}
			if (getFloat(&bEmpleados.sueldo, "Ingrese el nuevo sueldo\n", "Error\n", 0, 1000000, 2) == -1) {
				printf("Error en el precio\n");
				break;
			}
			if (getInt(&bEmpleados.sector, "Ingrese el nuevo sector\n1.Gerencia\n2.Empleado\n", "Error\n", 1, 2, 2) == -1) {
				printf("Error en el tipo\n");
				break;
			}
			if (modificarEmpleadosID(aEmpleados, CANT_EMPLEADOS, bEmpleados) == 0) {
				printf("Modificacion exitosa\n");
			} else {
				printf("Error al hacer la modificacion\n");
			}
			break;
        case 3:

        }

    }while(opcion < 5 && opcion >= 0);

}
