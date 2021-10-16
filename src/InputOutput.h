/* InputOutput.h  */

#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayEmployees.h"

/// \fn int ValidacionIngresoDeUnEnteroPositivo(char[])
/// \brief valida que el ingreso sea un número entero positivo
/// \param ingreso ingreso recibido como cadena de caracteres
/// \return 0 si el ingreso es un entero positivo, -1 si no lo es
int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]);

/// \fn int PedirNumeroEntero(int*, char[], char[], int, int, int)
/// \brief solicita al usuario un número entero positivo dentro de un rango
/// \param ingresoValidado devuelve por parámetro el ingreso si es válido
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje si el ingreso no es un entero positivo dentro del rango
/// \param minimo mínimo valor aceptado del ingreso
/// \param maximo mayor valor aceptado del ingreso
/// \param reintentos cantidad de veces que se vuelve a pedir el ingreso en caso de no ser válido
/// \return 0 ok, -1 si el ingreso es inválido
int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/// \fn int ValidacionIngresoDeUnFlotantePositivo(char[])
/// \brief valida que el ingreso sea un número flotante positivo
/// \param ingreso ingreso recibido como cadena de caracteres
/// \return 0 si el ingreso es un fotante positivo, -1 si no lo es
int ValidacionIngresoDeUnFlotantePositivo(char ingreso[]);

/// \fn int PedirNumeroFlotante(float*, char[], char[], float, float, int)
/// \brief solicita al usuario un número flotante positivo dentro de un rango
/// \param ingresoValidado devuelve por parámetro el ingreso si es válido
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje si el ingreso no es un entero positivo dentro del rango
/// \param minimo mínimo valor aceptado del ingreso
/// \param maximo mayor valor aceptado del ingreso
/// \param reintentos cantidad de veces que se vuelve a pedir el ingreso en caso de no ser válido
/// \return 0 ok, -1 si el ingreso es inválido
int PedirNumeroFlotante(float* ingresoValidado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

/// \fn int GetString(char[], char[], int)
/// \brief solicita una cadena de caracteres
/// \param string cadena validada devuelta por parámetro
/// \param message mensaje para solicitar el ingreso
/// \param len largo de la cadena
/// \return
int GetString(char string[], char message[], int len);

/// \fn float ValidacionFloatDentroDeUnRango(float, int, int)
/// \brief valida que el float recibido esté dentro de un rango determinado, sino lo vuelve a pedir
/// \param ingreso valor ingresado
/// \param minimo mínimo valor aceptado para validar
/// \param maximo máximo valor aceptado para validar
/// \return valor validado
float ValidacionFloatDentroDeUnRango(float ingreso, int minimo, int maximo);

/// \fn int ValidacionEnteroDentroDeUnRango(int, int, int)
/// \brief valida que el entero recibido esté dentro de un rango determinado, sino lo vuelve a pedir
/// \param ingreso valor ingresado
/// \param minimo mínimo valor aceptado para validar
/// \param maximo máximo valor aceptado para validar
/// \return valor validado
int ValidacionEnteroDentroDeUnRango(int ingreso,int minimo,int maximo);

/// \fn char ToUpperFirstLetter*(char[])
/// \brief cambia a mayúscula la primer letra de la cadena recibida
/// \param cadena cadena recibida
/// \return cadena con primer caracter en mayúscula
char* ToUpperFirstLetter(char cadena[]);

/// \fn int PedirNumeroEnteroVersionCorta(char[])
/// \brief valida que el valor recibido sea un entero positivo y lo retorna
/// \param mensaje mensaje para pedir el valor
/// \return valor validado
int PedirNumeroEnteroVersionCorta(char mensaje[]);

/// \fn float PedirNumeroFlotanteVersionCorta(char[])
/// \brief valida que el valor recibido sea un float positivo y lo retorna
/// \param mensaje mensaje para pedir el valor
/// \return valor validado
float PedirNumeroFlotanteVersionCorta(char mensaje[]);

#endif /* INPUTOUTPUT_H_ */
