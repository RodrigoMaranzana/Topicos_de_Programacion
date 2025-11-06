#include "funciones.h"
#include "comun.h"
#include <stdlib.h>
#include <string.h>

/// Claves validas
#define NOMBRE "nombre"
#define CLASE "clase"
#define NIVEL "nivel"

typedef struct {
    const char *cursor;
    int esFinSec;
} tSecuencia;

void _secuencia_crear(tSecuencia *sec, const char *buffer);
int _secuencia_es_fin(tSecuencia *sec);
int _secuencia_obtener_palabra(tSecuencia *sec, char *palabra);
char* _secuencia_obtener_palabra_heap(tSecuencia *sec);

int leer_jugador_txt(FILE *arch, char *buffer, unsigned tamBuffer)
{
    int finLectura = 0;
    unsigned cantLeidos, tamDisponible = tamBuffer;
    char *cursor = buffer;

    *cursor = '\0';

    while (!finLectura && fgets(cursor, tamDisponible, arch)) {

        cantLeidos = strlen(cursor);
        tamDisponible -= cantLeidos;
        cursor += cantLeidos;

        if (strstr(buffer, "},")) {
            finLectura = 1;
        }
    }

    return finLectura == 1 ? TODO_OK : FIN_ARCHIVO;
}

int crear_jugador(char *buffer, unsigned tamBuffer, tJugador *jugador)
{
    char clave[TAM_PALABRA], valor[TAM_PALABRA];
    tSecuencia sec;

    _secuencia_crear(&sec, buffer);

    puts("\n[PARSEANDO JUGADOR]");

    jugador->nombre = NULL;
    jugador->clase = NULL;
    jugador->nivel = 0;

    while (_secuencia_obtener_palabra(&sec, clave)) {

        _secuencia_obtener_palabra(&sec, valor);

        if (strcmp(clave, NOMBRE) == 0) {

            jugador->nombre = malloc(strlen(valor) + 1);
            if (!jugador->nombre) {

                destruir_jugador(jugador);
                return ERR_SIN_MEM;
            }

            strcpy(jugador->nombre, valor);

        } else if (strcmp(clave, CLASE)  == 0){

            jugador->clase = malloc(strlen(valor) + 1);
            if (!jugador->nombre) {

                destruir_jugador(jugador);
                return ERR_SIN_MEM;
            }

            strcpy(jugador->clase, valor);

        } else if (strcmp(clave, NIVEL)  == 0) {

            sscanf(valor, "%d", &jugador->nivel);
        }

        printf("%s: %s\n", clave, valor);
    }

    printf("\n[JUGADOR OBTENIDO]\n"
           "Nombre:\t%s\n"
           "Clase:\t%s\n"
           "Nivel:\t%d\n",jugador->nombre,jugador->clase,jugador->nivel);


    return TODO_OK;
}

void destruir_jugador(tJugador *jugador)
{
    free(jugador->nombre);
    free(jugador->clase);

    jugador->nombre = NULL;
    jugador->clase = NULL;
    jugador->nivel = 0;
}

int _secuencia_obtener_palabra(tSecuencia *sec, char *palabra)
{
    char *cursorE = palabra;

    while (*sec->cursor && !(ES_LETRA(*sec->cursor) || ES_NUMERO(*sec->cursor))) {
        ++sec->cursor;
    }

    if (!*sec->cursor) {
        sec->esFinSec = 1;
        return 0;
    }

    while (*sec->cursor && (ES_LETRA(*sec->cursor) || ES_NUMERO(*sec->cursor))) {

        *cursorE = *sec->cursor;
        ++sec->cursor;
        ++cursorE;
    }

    *cursorE = '\0';

    return 1;
}

void _secuencia_crear(tSecuencia *sec, const char *buffer)
{
    sec->cursor = buffer;
    sec->esFinSec = 0;
}

int _secuencia_es_fin(tSecuencia *sec)
{
    return sec->esFinSec;
}








/// CURIOSIDAD PERSONAL
char* _secuencia_obtener_palabra_heap(tSecuencia *sec)
{
    unsigned longitud;
    char *palabra;
    const char *inicioPal;

    while (*sec->cursor && !(ES_LETRA(*sec->cursor) || ES_NUMERO(*sec->cursor))) {
        ++sec->cursor;
    }

    inicioPal = sec->cursor;

    while (*sec->cursor && (ES_LETRA(*sec->cursor) || ES_NUMERO(*sec->cursor))) {
        ++sec->cursor;
    }

    longitud = sec->cursor - inicioPal

    if (longitud == 0) {
        return NULL;
    }

    palabra = malloc(longitud + 1);
    if (!palabra) {
        return NULL;
    }

    strncpy(palabra, inicioPal, longitud);
    palabra[longitud] = '\0';

    return palabra;
}

