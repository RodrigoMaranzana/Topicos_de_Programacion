#include <stdio.h>
#include <stdlib.h>
#include "comun.h"
#include "funciones.h"
#include "lote_prueba.h"

int main()
{
    FILE *arch;
    tJugador jugador;
    char buffer[TAM_BUFFER];

    /// LOTE DE PRUEBA
    generar_lote_prueba();

    puts("Parser de pseudo JSON");

    arch = fopen(NOMBRE_ARCH, "rt");
    if (!arch) {
        perror("Error al abrir el archivo");
        return ERR_ARCHIVO;
    }

    while (leer_jugador_txt(arch, buffer, TAM_BUFFER) != FIN_ARCHIVO)
    {
        printf("\n-----------------------\n"
               "Registro leido:\n%s", buffer);

        crear_jugador(buffer, TAM_BUFFER, &jugador);

        /// Para este punto tenemos un tJugador listo para ser utilizado como necesitemos

        destruir_jugador(&jugador);
    }

    fclose(arch);

    return TODO_OK;
}
