#ifndef MAIN_H
#define MAIN_H
#ifndef ENTIDAD_H
#define ENTIDAD_H

#ifdef _WIN64

#define LIMPIAR_CONSOLA "cls"

#elif _WIN32

#define LIMPIAR_CONSOLA "cls"

#else

#define LIMPIAR_CONSOLA "clear"

#endif

/*EL MANUAL DE USUARIO ES EL DOCUMENTO QUE EXPLICA EL FUNCIONAMIENTO DE LA APLICACION
7 PROYECTO
1 TAREA
2 APUNTES*/

#define NOMBRE_DICCIONARIO 50
#define INDICE_INICIAL 0

#include "diccionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CABECERA_PRINCIPAL 0L
#define SIN_DIRECCION -1L
#define UN_ELEMENTO 1

#endif

#ifndef MACROS_DE_CADENA
#define MACROS_DE_CADENA

#define SON_IGUALES(nombreA, nombreB) strcmp(nombreA, nombreB) == 0
#define VA_ANTES(nombreA, nombreB) strcmp(nombreA, nombreB) < 0

#endif

#define NOMBRE_ENTIDAD 50

typedef enum opcionesDelMenu
{
    SIN_SELECCION,
    NUEVO_DICCIONARIO,
    ABRIR_DICCIONARIO,
    CERRAR_PROGRAMA
} OpcionMenu;

typedef struct datoEntidad
{
    long direccionArchivo;
    char nombre[NOMBRE_ENTIDAD];
    long ptrDato;
    long ptrAtributo;
    long ptrEntidad;
} TEntidad;

typedef struct entidadEnMemoria
{
    char nombre[NOMBRE_ENTIDAD];
    long ptrDato;
    TAtributoMemoria *ptrAtributo;
    struct entidadEnMemoria *ptrEntidad;
} TEntidadMemoria;

void mostrar_menu(void);
int entrada_de_usuario(void);
void procesar_opcion_seleccionada(const OpcionMenu opcionSeleccionada);
void leer_nombre(const char *prompt, char *buffer, const size_t tamanio);
void mostrar_submenu(void);

int nueva_entidad(FILE *ptrDiccionario);
int agregar_entidad(FILE *ptrDiccionario, TEntidad *datoEntidad);
int eliminar_entidad(FILE *ptrDiccionario, const long ptrEntidadActual, TEntidad *entidadTemporal);
void reasignar_punteros_entidad(FILE *ptrDiccionario, const long cabeceraActual, const char *nombreNuevaEntidad, const long direccionNuevaEntidad);
void imprimir_entidad(FILE *ptrDiccionario, const long cabeceraActual);
long buscar_entidad(FILE *ptrDiccionario, const long cabecera, const char *nombreEntidad);
int modificar_entidad(FILE *ptrDiccionario);
int desenlazar_entidad(FILE *ptrDiccionario, const long cabecera, const char *nombreEntidad);
TEntidad *crear_entidad(void);
TEntidad *guardar_entidades_en_memoria(FILE *ptrDiccionario, long direccionActual);

#endif