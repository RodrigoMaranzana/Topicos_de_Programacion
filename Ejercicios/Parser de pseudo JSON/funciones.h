#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>

typedef struct {
    char *nombre;
    char *clase;
    int nivel;
}tJugador;

int leer_jugador_txt(FILE *arch, char *buffer, unsigned tamBuffer);
int crear_jugador(char *buffer, unsigned tamBuffer, tJugador *jugador);
void destruir_jugador(tJugador *jugador);

#endif // FUNCIONES_H_INCLUDED
