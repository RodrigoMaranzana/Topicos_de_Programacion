#ifndef COMUN_H_INCLUDED
#define COMUN_H_INCLUDED

/**
    ' '  Espacio
    '\t' Tabulador
    '\n' Salto de linea
    '\r' Retorno de carro
    '\f' Salto de página
    '\v' Tabulador vertical
**/

#define ES_BLANCO(a) ((a) == ' ' || (a) == '\t' || (a) == '\n' || (a) == '\r' || (a) == '\f' || (a) == '\v')
#define ES_NUMERO(a) ((a) >= '0' && (a) <= '9')
#define ES_LETRA(a) (((a) >= 'a' && (a) <= 'z') || ((a) >= 'A' && (a) <= 'Z'))

#define NOMBRE_ARCH "jugadores.txt"
#define TAM_BUFFER 1024
#define TAM_PALABRA 128

#define TODO_OK 0
#define ERR_SIN_MEM 1
#define ERR_ARCHIVO 2
#define ERR_LINEA 3
#define ERR_SINTAXS 4
#define FIN_ARCHIVO 5

#endif // COMUN_H_INCLUDED
