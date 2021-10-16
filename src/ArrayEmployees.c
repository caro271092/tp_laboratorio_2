/* ArrayEmployees.c  */

#include "ArrayEmployees.h"
#include "InputOutput.h"
#define TRUE 1
#define FALSE 0

int initEmployees(Employee list[], int len){
	for(int i=0; i<len; i++){
	        list[i].isEmpty = TRUE;
	    }
	return 0;
}

int BuscarPrimerEspacioLibre(Employee list[], int len){
	int i;
	int index = -1;
	for(i=0; i<len;i++){
		if(list[i].isEmpty == TRUE){
			index = i;
			break;
		}
	}
	return index;
}

int BuscarPrimerEspacioOcupado(Employee list[], int len){
	int i;
	int index = -1;
	for(i=0; i<len;i++){
		if(list[i].isEmpty == FALSE){
			index = i;
			break;
		}
	}
	return index;
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector){
	int retorno = -1;
	int index;
	index = BuscarPrimerEspacioLibre(list, len);
	if(list != NULL && index != -1){
	list[index].id = id;
	strcpy(list[index].name, name);
	strcpy(list[index].lastName, lastName);
	list[index].salary = salary;
	list[index].sector = sector;
	list[index].isEmpty = FALSE;
	retorno = 0;
	}
	return retorno;
}

int PedirEmpleado(Employee list[], int len, int* id){
	int retorno = -1;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
		if(list != NULL){
		GetString(name, ">> Ingrese nombre: ", 51);
		ToUpperFirstLetter(name);
		GetString(lastName, ">> Ingrese apellido: ", 51);
		ToUpperFirstLetter(lastName);
		PedirNumeroFlotante(&salary, ">> Ingrese el salario: ", "-->ERROR.", 1, INT_MAX, 2);
		PedirNumeroEntero(&sector, ">> Ingrese el sector (1. Administración, 2. Gerencia, 3. Logística, 4. Otro): ", "-->ERROR.", 1, 4, 2);
		}
		*id += 1;
		retorno = addEmployee(list, len, *id, name, lastName, salary, sector);
		return retorno;
}

int printEmployees(Employee list[], int len){
	int retorno = -1;
	printf("%-8s%-10s%-10s%-10s%s","ID","Nombre", "Apellido", "Salario", "Sector\n");
	for(int i = 0; i < len; i++) {
		if(list[i].isEmpty == FALSE){
			printf("%-8d", list[i].id);
			printf("%-10s", list[i].name);
			printf("%-10s", list[i].lastName);
			printf("%-10.2f", list[i].salary);
			switch(list[i].sector){
			case 1: printf("Administración\n");
					break;
			case 2: printf("Gerencia\n");
					break;
			case 3: printf("Logística\n");
					break;
			case 4: printf("Otro\n");
					break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int findEmployeeById(Employee list[], int len, int idIngresado){
	int retorno = -1;
	int i;
	for(i=0;i<len;i++){
		if(list != NULL && list[i].isEmpty == FALSE && list[i].id == idIngresado){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int ModifyName(Employee list[], int len, int id){
	int retorno = -1;
	char newName[51];
	int idToModify;
	idToModify = findEmployeeById(list, len, id);
	if((findEmployeeById(list, len, id))!=-1){
		GetString(newName, "Ingrese el nuevo nombre: ", 51);
		ToUpperFirstLetter(newName);
		strcpy(list[idToModify].name, newName);
		retorno = 0;
		}
	 return retorno;
}

int ModifyLastName(Employee list[], int len, int id){
	int retorno = -1;
	char newLastName[51];
	int idToModify;
	idToModify = findEmployeeById(list, len, id);
	if((findEmployeeById(list, len, id))!=-1){
		GetString(newLastName, "Ingrese el nuevo apellido: ", 51);
		ToUpperFirstLetter(newLastName);
		strcpy(list[idToModify].lastName, newLastName);
		retorno = 0;
		}
	 return retorno;
}

int ModifySalary(Employee list[], int len, int id){
	int retorno = -1;
	float newSalary;
	int idToModify;
	idToModify = findEmployeeById(list, len, id);
	if((findEmployeeById(list, len, id))!=-1){
		PedirNumeroFlotante(&newSalary, ">> Ingrese el nuevo salario: ", "-->ERROR.", 1, INT_MAX, 2);
		list[idToModify].salary = newSalary;
		retorno = 0;
		}
	 return retorno;
}

int ModifySector(Employee list[], int len, int id){
	int retorno = -1;
	int newSector;
	int idToModify;
	idToModify = findEmployeeById(list, len, id);
	if((findEmployeeById(list, len, id))!=-1){
		PedirNumeroEntero(&newSector, "Ingrese el nuevo sector (1. Administración, 2. Gerencia, 3. Logística, 4. Otro): ", "-->ERROR.", 1, 4,2);
		list[idToModify].sector = newSector;
		retorno = 0;
		}
	 return retorno;
}

int removeEmployee(Employee list[], int len, int idBaja){
	int retorno = -1;
	int idBajaConfirmado;
	idBajaConfirmado = findEmployeeById(list, len, idBaja);
	if((findEmployeeById(list, len, idBaja))!=-1){
		list[idBajaConfirmado].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int sortEmployees(Employee list[], int len, int order){
	int retorno = -1;
	int i;
	int j;
    Employee auxiliar;
    if(order==1){
		for(i=0; i<len-1; i++){
			for(j = i+1; j<len; j++){
				if(strcmp(list[i].lastName, list[j].lastName) > 0){
						  auxiliar = list[i];
						  list[i] = list[j];
						  list[j] = auxiliar;
				}else{
					if(strcmp(list[i].lastName, list[j].lastName) == 0){
						//for(j = i+1; j<len; j++){
							if(list[i].sector > list[j].sector){
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
					}
				}
			}
		}
		retorno =0;
    }else{
		 if(order==0){
			for(i = 0; i < len - 1; i++){
			for(j = i + 1; j < len; j++){
			  if(strcmp(list[i].lastName, list[j].lastName) < 0){
				  auxiliar = list[i];
				  list[i] = list[j];
				  list[j] = auxiliar;
			  }else{
				if(strcmp(list[i].lastName, list[j].lastName) == 0){
					if(list[i].sector < list[j].sector){
						 auxiliar = list[i];
						 list[i] = list[j];
						 list[j] = auxiliar;
					}
				}
				}
			}
			}
		}
	retorno = 0;
	}
    return retorno;
}

int PromedioSalarios(Employee list[], int len, float *pAcumuladorSalarios,  int *pContadorTotalEmpleados, float *pPromedioSalarios, int *cantidadEmpleadosSobreSalarioPromedio){
	int retorno = -1;
	int i;
	int contadorSalarioAux = 0;
	int contadorEmpleadosAux = 0;
	*pContadorTotalEmpleados = contadorSalarioAux;
	int promedioAux;
	float acumuladorSalariosAux = 0;

	for(i = 0; i < len; i++){
	  if((list != NULL)&&(list[i].isEmpty == FALSE)){
		  contadorSalarioAux++;
		  acumuladorSalariosAux += list[i].salary;
      }
    }
	*pAcumuladorSalarios = acumuladorSalariosAux;
	if(contadorSalarioAux != 0){
		*pPromedioSalarios = acumuladorSalariosAux/ contadorSalarioAux;
		retorno = 0;
    }
	promedioAux = *pPromedioSalarios;
	for(i=0; i<len; i++){
		if((list != NULL)&&(list[i].isEmpty == FALSE)&&(list[i].salary > promedioAux)){
			contadorEmpleadosAux++;
		}
	}
	*cantidadEmpleadosSobreSalarioPromedio = contadorEmpleadosAux;
	return retorno;
}


