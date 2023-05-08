/************************************************************************************************
Copyright (c) 2023, Balthazar Martin <balthazarm8@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/**
 ** \author Balthazar Martin
 ** \date ??/04/23
 ** \brief Implementacion del modulo de alumnos
 **
 ** \addtogroup Alumno Alumnos.c
 ** \brief Modulo para gestion de alumnos
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

#if ( !defined( DINAMICO) && !defined (ESTATICO ) )
//! Si no se define el modo Estatico entonces se almacenara los datos del alumno de forma Dinamica
#define ESTATICO 0
#endif

/* === Private data type declarations ========================================================== */
//! Estructura SOLO para almacenar datos del alumno
struct alumno_s {
    char apellido[FIELD_SIZE]; //!< Almacena el apellido del alumno
    char nombre[FIELD_SIZE];   //!< Almacena el nombre del alumno
    uint32_t documento;        //!< Almacena el documento del alumno
    bool ocupado;              //!< Booleano que indica si la estructura esta vacia o no
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

//! Funcion para serializar el nombre y el apellido del alumno
static int SerializarCadena(
    const char * campo, //!< Puntero que permitira mostrar en pantalla cual es el campo
    const char * valor, //!< Puntero que permitira mostrar en pantalla la cadena de dicho campo
    char * cadena,      //!< Puntero a la cadena de resultado
    int espacio /*!< Maximo espacio que puede ocupar la cadena */);

//! Funcion para serializar el documento del alumno
static int
SerializarNumero(const char * campo, //!< Puntero que permitira mostrar en pantalla cual es el campo
                 int valor, //!< Puntero que permitira mostrar en pantalla la cadena de dicho campo
                 char * cadena, //!< Puntero a la cadena de resultado
                 int espacio /*!< Maximo espacio que puede ocupar la cadena */);

//! Funcion para almacenar de forma Estatica los datos del alumno
static alumno_t Alocar(alumno_t resultado);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}

static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {
    return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

static alumno_t Alocar(alumno_t resultado){
    static struct alumno_s instancias[NUMBER_OF_STRUCTS] = {0};
    for (int i = 0; i < NUMBER_OF_STRUCTS; i++) {
        if (!instancias[i].ocupado) {
            printf("Modo: Estatico. \n");
            instancias[i].ocupado=true; 
            resultado = &instancias[i];
            resultado->ocupado = true;
	        break;
	    }else {
        printf("Instancia %d ocupada.\n", i);
	    }
    }
    return resultado;
}

/* === Public function implementation ========================================================== */

alumno_t CrearAlumno(char * apellido, char * nombre, int documento) {
    alumno_t resultado;
    #if ESTATICO == 1
    resultado=Alocar(resultado);
    #else
    printf("Modo: Dinamico. \n");
    resultado = malloc(sizeof(struct alumno_s)); 
    #endif
    GetApellido(resultado, apellido);
    GetNombre(resultado, nombre);
    GetDocumento(resultado, documento);
    return resultado;
}

int * GetApellido(alumno_t alumno, char cadena[]) {
    strcpy(alumno->apellido, cadena);
    return NULL;
}

int * GetNombre(alumno_t alumno, char cadena[]) {
    strcpy(alumno->nombre, cadena);
    return NULL;
}

int * GetDocumento(alumno_t alumno, int documento) {
    alumno->documento = documento;
    return NULL;
}

int Serializar(alumno_t alumno, char cadena[], uint32_t espacio) {
    int disponibles = espacio;
    int resultado;

    cadena[0] = '{';
    cadena++;

    disponibles--;
    resultado = SerializarCadena("apellido", alumno->apellido, cadena, disponibles);

    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarCadena("nombre", alumno->nombre, cadena, disponibles);
    }
    if (resultado > 0) {
        disponibles -= resultado;
        cadena += resultado;
        resultado = SerializarNumero("documento", alumno->documento, cadena, disponibles);
    }
    if (resultado > 0) {
        cadena += resultado;
        *(cadena - 1) = '}';
        resultado = espacio - disponibles;
    }
    return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
