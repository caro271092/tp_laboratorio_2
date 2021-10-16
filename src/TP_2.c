/*Name: TP_2.c // Author: Carolina Alvarez*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayEmployees.h"
#define T 1000

int main(void){
	setbuf(stdout, NULL);
	int opcionIngresada;
	int opcionIngresadaModificaciones;
	int opcionIngresadaInformes;
	Employee listaEmpleados[T];
	int retornoFuncion;
	int id = 0;
	int idIngresado;
	int orden;
	float totalSalarios = 0;
	float promedioSalarios;
	int contadorCantidadEmpleados = 0;
	int contadorEmpleadosQueSuperanSalarioPromedio = 0;
	int hayEmpleadosCargados;

	initEmployees(listaEmpleados, T);
	do{
	printf("\n 1. ALTA "
		   "\n 2. MODIFICAR "
		   "\n 3. BAJA "
		   "\n 4. INFORMAR "
		   "\n 5. FINALIZAR "
			);
	PedirNumeroEntero(&opcionIngresada, "\n --->Ingrese la opción que desea ejecutar: " , "---> ERROR. Ingrese una opción válida.", 1, 5, 2);
	switch(opcionIngresada){
	case 1:
		   retornoFuncion = PedirEmpleado(listaEmpleados,T, &id);
		   if(retornoFuncion != -1){
					printf("\n--->El empleado se dió de alta exitosamente.\n");
			}else{
					printf("\n--->ERROR. El empleado no se pudo cargar.\n");
				 }
	break;
	case 2:
		hayEmpleadosCargados = BuscarPrimerEspacioOcupado(listaEmpleados,T);
		if(hayEmpleadosCargados==-1){
			printf("\n--->No hay empleados dados de alta aún.\n");
		}else{
			printEmployees(listaEmpleados,T);
			printf("\n 1. Modificar: Nombre "
				   "\n 2. Modificar: Apellido "
				   "\n 3. Modificar: Salario"
				   "\n 4. Modificar: Sector"
				   "\n --->Ingrese la opción que desea ejecutar: "
					);
		fflush(stdin);
		scanf("%d", &opcionIngresadaModificaciones);
		opcionIngresadaModificaciones = ValidacionEnteroDentroDeUnRango(opcionIngresadaModificaciones, 1, 4);
		switch(opcionIngresadaModificaciones){
				case 1:
					PedirNumeroEntero(&idIngresado, "--->Ingrese el Id. del empleado que desea modificar: ", "--->ERROR.", 1, INT_MAX,3);
					retornoFuncion = ModifyName(listaEmpleados,T, idIngresado);
					if(retornoFuncion==-1){
							PedirNumeroEntero(&idIngresado, "--->El Id. ingresado no es válido. Intente nuevamente: ", "--->ERROR.", 1, INT_MAX,1);
							retornoFuncion = ModifyName(listaEmpleados,T, idIngresado);
							}
					if(retornoFuncion==0){
						printf("\n--->El empleado se modificó exitosamente.\n");
					}else{
						printf("\n--->No se pudieron modificar los datos del empleado.\n");
						}
				break;
				case 2:
					PedirNumeroEntero(&idIngresado, "--->Ingrese el Id. del empleado que desea modificar: ", "--->ERROR.", 1, INT_MAX,3);
					retornoFuncion = ModifyLastName(listaEmpleados,T, idIngresado);
					if(retornoFuncion==-1){
							PedirNumeroEntero(&idIngresado, "--->El Id. ingresado no es válido. Intente nuevamente: ", "--->ERROR.", 1, INT_MAX,1);
							retornoFuncion = ModifyLastName(listaEmpleados,T, idIngresado);
					}
					if(retornoFuncion==0){
							printf("\n--->El empleado se modificó exitosamente.\n");
					}else{
							printf("\n--->No se pudieron modificar los datos del empleado.\n");
							}
				break;
				case 3:
					PedirNumeroEntero(&idIngresado, "--->Ingrese el Id. del empleado que desea modificar: ", "--->ERROR.", 1, INT_MAX,3);
					retornoFuncion = ModifySalary(listaEmpleados,T, idIngresado);
					if(retornoFuncion==-1){
						PedirNumeroEntero(&idIngresado, "--->El Id. ingresado no es válido. Intente nuevamente: ", "--->ERROR.", 1, INT_MAX,1);
						retornoFuncion = ModifySalary(listaEmpleados,T, idIngresado);
					}
					if(retornoFuncion==0){
						printf("\n--->El empleado se modificó exitosamente.\n");
					}else{
						printf("\n--->No se pudieron modificar los datos del empleado.\n");
					}
				break;
				case 4:
					PedirNumeroEntero(&idIngresado, "--->Ingrese el Id. del empleado que desea modificar: ", "--->ERROR.", 1, INT_MAX,3);
					retornoFuncion = ModifySector(listaEmpleados,T, idIngresado);
					if(retornoFuncion==-1){
						PedirNumeroEntero(&idIngresado, "--->El Id. ingresado no es válido. Intente nuevamente: ", "--->ERROR.", 1, INT_MAX,1);
						retornoFuncion = ModifySector(listaEmpleados,T, idIngresado);
					}
					if(retornoFuncion==0){
						printf("\n--->El empleado se modificó exitosamente.\n");
					}else{
						printf("\n--->No se pudieron modificar los datos del empleado.\n");
					}
				break;
			}
		}
	break;
	case 3:
		hayEmpleadosCargados = BuscarPrimerEspacioOcupado(listaEmpleados,T);
		if(hayEmpleadosCargados==-1){
					printf("\n--->No hay empleados dados de alta aún.\n");
		}else{
			printEmployees(listaEmpleados,T);
			PedirNumeroEntero(&idIngresado, "--->Ingrese el Id. del empleado que desea dar de baja: ", "--->ERROR.", 1, INT_MAX,3);
			retornoFuncion = removeEmployee(listaEmpleados,T, idIngresado);
				if(retornoFuncion==-1){
					PedirNumeroEntero(&idIngresado, "--->El Id. ingresado no es válido. Intente nuevamente: ", "--->ERROR.", 1, INT_MAX,1);
					retornoFuncion = removeEmployee(listaEmpleados,T, idIngresado);
				}
				if(retornoFuncion==0){
							printf("\n--->El empleado se dió de baja exitosamente.\n");
				}else{
							printf("\n--->No se pudo dar de baja el empleado.\n");
					}
		}
		break;
	case 4:
		hayEmpleadosCargados = BuscarPrimerEspacioOcupado(listaEmpleados,T);
			if(hayEmpleadosCargados==-1){
				printf("\n--->No hay empleados dados de alta aún.\n");
			}else{
			printf("\n \t1. Listado ordenado por nombre y sector."
				   "\n \t2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. "
					"\n --->Seleccione la opción que desea informar: ");
			fflush(stdin);
			scanf("%d", &opcionIngresadaInformes);
			opcionIngresadaInformes = ValidacionEnteroDentroDeUnRango(opcionIngresadaInformes, 1, 2);
			switch(opcionIngresadaInformes){
				case 1:
					printf("--->Ingrese 1 para orden alfabético ascendentemente o 0 para ordenar descendentemente: ");
					fflush(stdin);
					scanf("%d", &orden);
					orden = ValidacionEnteroDentroDeUnRango(orden, 0,1);
					retornoFuncion = sortEmployees(listaEmpleados,T, orden);
					if(retornoFuncion==0){
						printEmployees(listaEmpleados,T);
					}else{
						printf("\n--->No se pudieron ordenar los datos.\n");
					}
				break;
				case 2:
					retornoFuncion = PromedioSalarios(listaEmpleados, T, &totalSalarios,  &contadorCantidadEmpleados, &promedioSalarios, &contadorEmpleadosQueSuperanSalarioPromedio);
					if(retornoFuncion==0){
						printf("---> El total de los salarios es %.2f\n"
								"---> Promedio: %.2f\n"
								"---> Cantidad de empleados que superan el salario promedio: %d.", totalSalarios, promedioSalarios, contadorEmpleadosQueSuperanSalarioPromedio);
					}else{
						printf("\n--->No se pudo realizar el informe.");
						}
			}
			break;
			}
		}
	}while(opcionIngresada!=5);
	printf("\n----------------> Ha finalizado el programa.");
	return EXIT_SUCCESS;
}
