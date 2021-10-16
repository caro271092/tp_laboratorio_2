/* ArrayEmployees.h	 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "InputOutput.h"
	typedef struct{
		int id;
		char name[51];
		char lastName[51];
		float salary;
		int sector;
		int isEmpty;
	}Employee;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee list[], int len);

/// \fn int BuscarPrimerEspacioLibre(Employee[], int)
/// \brief busca primer posición sin datos cargados
/// \param list array a recorrer
/// \param len tamaño del array
/// \return primer posición sin datos cargados
int BuscarPrimerEspacioLibre(Employee list[], int len);

/// \fn int BuscarPrimerEspacioOcupado(Employee[], int)
/// \brief busca primer posición con datos cargados
/// \param list array a recorrer
/// \param len tamaño del array
/// \return primer posición con datos cargados
int BuscarPrimerEspacioOcupado(Employee list[], int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee* list array a recorrer
* \param len int len tamaño del array
* \param id int*
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
**/
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/// \fn int PedirEmpleado(Employee[], int, int*)
/// \brief pide al usuario que ingrese los datos del array Employee
/// \param list list array a recorrer
/// \param len tamaño del arrat
/// \param id identificador de cliente, llega a través de puntero
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int PedirEmpleado(Employee list[], int len, int* id);

/** \brief print the content of employees array
* \param list Employee*
* \param length int
* \return int 0 si pudo imprimir todos los campos, -1 si no logró completar la tarea
*/
int printEmployees(Employee list[], int len);

/** \brief find an Employee by Id and returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(Employee list[], int len, int idIngresado);

/// \fn int ModifyName(Employee[], int, int)
/// \brief modifica el campo nombre del array employee
/// \param list array
/// \param len tamaño del array
/// \param id identificador del array a modificar
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int ModifyName(Employee list[], int len, int id);

/// \fn int ModifyLastName(Employee[], int, int)
/// \brief modifica el campo apellido del array employee
/// \param list array
/// \param len tamaño del array
/// \param id identificador del array a modificar
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int ModifyLastName(Employee list[], int len, int id);

/// \fn int ModifySalary(Employee[], int, int)
/// \brief modifica el campo salario del array employee
/// \param list array
/// \param len tamaño del array
/// \param id identificador del array a modificar
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int ModifySalary(Employee list[], int len, int id);

/// \fn int ModifySector(Employee[], int, int)
/// \brief modifica el campo sector del array employee
/// \param list array
/// \param len tamaño del array
/// \param id identificador del array a modificar
/// \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
int ModifySector(Employee list[], int len, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
* \param list Employee*
* \param len int tamaño del array
* \param id int identificador del array a modificar
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee(Employee list[], int len, int idBaja);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee[]
* \param len int tamaño del array
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees(Employee list[], int len, int order);

/// \fn int PromedioSalarios(Employee[], int, float*, int*, float*, int*)
/// \brief calcula el promedio de los salarios de la lista de empleados,
/// la suma total de salarios y la cantidad de Empleados Sobre el Salario Promedio
/// \param list lista de arrays a recorrer
/// \param len tamaño del array
/// \param pAcumuladorSalarios sumatoria de los salarios de la lista
/// \param pContadorTotalEmpleados cantidad de empleados
/// \param pPromedioSalarios promedio de los salarios
/// \param cantidadEmpleadosSobreSalarioPromedio cantidad de Empleados Sobre el Salario Promedio
/// \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
int PromedioSalarios(Employee list[], int len, float *pAcumuladorSalarios,  int *pContadorTotalEmpleados, float *pPromedioSalarios, int *cantidadEmpleadosSobreSalarioPromedio);
#endif /* ARRAYEMPLOYEES_H_ */
