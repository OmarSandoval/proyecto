#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "entidad.h"

#ifndef CONSTANTES_SIMBOLICAS
#define CONSTANTES_SIMBOLICAS

#define CABECERA_PRINCIPAL 0L
#define SIN_DIRECCION -1L
#define UN_ELEMENTO 1

#endif

#ifndef MACROS_DE_CADENA
#define MACROS_DE_CADENA

#define SON_IGUALES(nombreA, nombreB) strcmp(nombreA, nombreB) == 0
#define VA_ANTES(nombreA, nombreB) strcmp(nombreA, nombreB) < 0

#endif

typedef enum
{
    IMPRIMIR_DICCIONARIO = 1,
    NUEVA_ENTIDAD,
    ELIMINAR_ENTIDAD,
    MODIFICAR_ENTIDAD,
    NUEVO_ATRIBUTO,
    ELIMINAR_ATRIBUTO,
    MODIFICAR_ATRIBUTO,
    REGRESAR,
    REINDEXAR_DICCIONARIO
} OpcionSubmenu;

void inicializar_diccionario(const char *nombreArchivo);
int abrir_diccionario_de_datos(const char *nombreArchivo);
void imprimir_diccionario_de_datos(FILE *ptrDiccionario, const char *nombreDiccionario);
void operar_diccionario(const OpcionSubmenu opcionSeleccionada, const char *nombreDiccionario);
int reindexar_diccionario(TEntidadMemoria *entidad, const char *nombreDiccionario);

#endif