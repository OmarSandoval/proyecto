#include "main.h"

int main(void)
{
    int opcionSeleccionada = SIN_SELECCION;
    do
    {
        mostrar_menu();
        opcionSeleccionada = entrada_de_usuario();
        system(LIMPIAR_CONSOLA);
        procesar_opcion_seleccionada((OpcionMenu)opcionSeleccionada);
    } while (opcionSeleccionada != CERRAR_PROGRAMA);

    return EXIT_SUCCESS;
}

void mostrar_menu(void)
{
    puts("----------Diccionario de Datos----------");
    printf("%i) Crear un nuevo diccionario\n", NUEVO_DICCIONARIO);
    printf("%i) Abrir un diccionario existente\n", ABRIR_DICCIONARIO);
    printf("%i) Salir\n", CERRAR_PROGRAMA);
}

int entrada_de_usuario(void)
{
    int opcionSeleccionada;
    printf("Por favor selecciona una opcion: ");
    scanf("%i", &opcionSeleccionada);
    limpiar_buffer();

    return opcionSeleccionada;
}

void procesar_opcion_seleccionada(const OpcionMenu opcionSeleccionada)
{
    char nombreDiccionario[NOMBRE_DICCIONARIO];

    switch (opcionSeleccionada)
    {
    case NUEVO_DICCIONARIO:
        leer_nombre("Ingresa el nombre del diccionario: ", nombreDiccionario, NOMBRE_DICCIONARIO);
        inicializar_diccionario(nombreDiccionario);
        break;
    case ABRIR_DICCIONARIO:
        leer_nombre("Ingresa el nombre del diccionario: ", nombreDiccionario, NOMBRE_DICCIONARIO);
        if (abrir_diccionario_de_datos(nombreDiccionario) == EXIT_SUCCESS)
        {
            puts("El diccionario de datos ha sido abierto");
            int operacionRealizar = SIN_SELECCION;
            do
            {
                mostrar_submenu();
                operacionRealizar = entrada_de_usuario();
                system(LIMPIAR_CONSOLA);
                operar_diccionario((OpcionSubmenu)operacionRealizar, nombreDiccionario);
            } while (operacionRealizar != REGRESAR);
        }
        break;
    case CERRAR_PROGRAMA:
        puts("Saliendo...");
        break;
    default:
        puts("Opcion no valida, intenta de nuevo");
        break;
    }
}

void leer_nombre(const char *prompt, char *buffer, const size_t tamanio)
{
    if (prompt != NULL)
    {
        printf("%s", prompt);
    }
    if (fgets(buffer, tamanio, stdin) == NULL)
    {
        buffer[INDICE_INICIAL] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

void mostrar_submenu(void)
{
    puts("----------Operacion a realizar----------");
    printf("%i) Imprimir diccionario de datos\n", IMPRIMIR_DICCIONARIO);
    printf("%i) Nueva entidad\n", NUEVA_ENTIDAD);
    printf("%i) Eliminar entidad\n", ELIMINAR_ENTIDAD);
    printf("%i) Modificar entidad\n", MODIFICAR_ENTIDAD);
    printf("%i) Nuevo atributo\n", NUEVO_ATRIBUTO);
    printf("%i) Eliminar atributo\n", ELIMINAR_ATRIBUTO);
    printf("%i) Modificar atributo\n", MODIFICAR_ATRIBUTO);
    printf("%i) Regresar\n", REGRESAR);
}
