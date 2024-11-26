#include "diccionario.h"

void inicializar_diccionario(const char *nombreDiccionario)
{
    long cabecera = SIN_DIRECCION;
    FILE *ptrDiccionario = fopen(nombreDiccionario, "wb");

    if (ptrDiccionario == NULL)
    {
        fprintf(stderr, "Error al crear el diccionario de datos\n");
    }

    if (fwrite(&cabecera, sizeof(long), UN_ELEMENTO, ptrDiccionario) != UN_ELEMENTO)
    {
        fprintf(stderr, "Error al inicializar el diccionario de datos\n");
    }
    fprintf(stdout, "Diccionario \"%s\" creado exitosamente\n", nombreDiccionario);

    fclose(ptrDiccionario);
}

int abrir_diccionario_de_datos(const char *nombreDiccionario)
{
    int resultadoOperacion = EXIT_SUCCESS;
    long cabecera;
    FILE *ptrDiccionario = fopen(nombreDiccionario, "rb");

    if (ptrDiccionario)
    {
        if (fread(&cabecera, sizeof(long), UN_ELEMENTO, ptrDiccionario) != UN_ELEMENTO)
        {
            fprintf(stderr, "Error para leer datos\n");
            resultadoOperacion = EXIT_FAILURE;
        }
        else
        {
            printf("El valor de la cabecera es: %li\n", cabecera);
        }
        fclose(ptrDiccionario);
    }
    else
    {
        fprintf(stderr, "Error para abrir el diccionario de datos\n");
        resultadoOperacion = EXIT_FAILURE;
    }

    return resultadoOperacion;
}

void imprimir_diccionario_de_datos(FILE *ptrDiccionario, const char *nombreDiccionario)
{
    printf("Nombre del diccionario: %s\n", nombreDiccionario);
    imprimir_entidad(ptrDiccionario, valor_cabecera(ptrDiccionario));
}

void operar_diccionario(const OpcionSubmenu opcionSeleccionada, const char *nombreDiccionario)
{
    FILE *ptrDiccionario = fopen(nombreDiccionario, "r+b");
    TEntidad *entidadTemporal;
    TAtributo *atributoTemporal;

    switch (opcionSeleccionada)
    {
    case IMPRIMIR_DICCIONARIO:
        imprimir_diccionario_de_datos(ptrDiccionario, nombreDiccionario);
        break;
    case NUEVA_ENTIDAD:
        nueva_entidad(ptrDiccionario);
        break;
    case ELIMINAR_ENTIDAD:
        entidadTemporal = crear_entidad();
        eliminar_entidad(ptrDiccionario, CABECERA_PRINCIPAL, entidadTemporal);
        break;
    case MODIFICAR_ENTIDAD:
        modificar_entidad(ptrDiccionario);
        break;
    case NUEVO_ATRIBUTO:
        entidadTemporal = crear_entidad();
        entidadTemporal->direccionArchivo = buscar_entidad(ptrDiccionario, CABECERA_PRINCIPAL, entidadTemporal->nombre);
        if (entidadTemporal->direccionArchivo != SIN_DIRECCION)
        {
            long direccionAtributos = entidadTemporal->direccionArchivo + sizeof(char) * NOMBRE_ENTIDAD + sizeof(long);
            nuevo_atributo(ptrDiccionario, direccionAtributos);
        }
        else
        {
            fprintf(stderr, "Error de busqueda, entidad no encontrada\n");
        }
        break;
    case ELIMINAR_ATRIBUTO:
        entidadTemporal = crear_entidad();
        entidadTemporal->direccionArchivo = buscar_entidad(ptrDiccionario, CABECERA_PRINCIPAL, entidadTemporal->nombre);
        if (entidadTemporal->direccionArchivo != SIN_DIRECCION)
        {
            atributoTemporal = crear_atributo(BUSCAR_ATRIBUTO);
            long direccionAtributos = entidadTemporal->direccionArchivo + sizeof(char) * NOMBRE_ENTIDAD + sizeof(long);
            eliminar_atributo(ptrDiccionario, direccionAtributos, atributoTemporal);
        }
        else
        {
            fprintf(stderr, "Error de busqueda, entidad no encontrada\n");
        }
        break;
    case MODIFICAR_ATRIBUTO:
        entidadTemporal = crear_entidad();
        entidadTemporal->direccionArchivo = buscar_entidad(ptrDiccionario, CABECERA_PRINCIPAL, entidadTemporal->nombre);
        if (entidadTemporal->direccionArchivo != SIN_DIRECCION)
        {
            long direccionAtributos = entidadTemporal->direccionArchivo + sizeof(char) * NOMBRE_ENTIDAD + sizeof(long);
            modificar_atributo(ptrDiccionario, direccionAtributos);
        }
        else
        {
            fprintf(stderr, "Error de busqueda, entidad no encontrada\n");
        }
        break;
   
    case REGRESAR:
        break;
    default:
        puts("Opcion no valida, intenta de nuevo");
        break;
    }

    fclose(ptrDiccionario);
}
