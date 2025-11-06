#include "lote_prueba.h"
#include "comun.h"
#include <stdio.h>

void generar_lote_prueba()
{
    FILE *arch = fopen(NOMBRE_ARCH, "wt");
    if (!arch) {
        perror("Error al generar el lote de pruebas.");
        return;
    }

    fprintf(arch,
            "{\n"
            "\tnombre: Carlos,\n"
            "\tclase: Paladin,\n"
            "\tnivel: 12\n"
            "},\n"
            "{\n"
            "\tnombre: Pepe,\n"
            "\tclase: Mago,\n"
            "\tnivel: 5\n"
            "},\n"
            "{\n"
            "\tnombre: Ana,\n"
            "\tclase: Bruja,\n"
            "\tnivel: 9\n"
            "},\n"
            "{\n"
            "\tnombre: Pancho,\n"
            "\tclase: NULL,\n"
            "\tnivel: 7\n"
            "},\n"
            "{\n"
            "\tnombre: Manuel,\n"
            "\tclase: Elfo,\n"
            "\tnivel: 3\n"
            "}\n"
            );

    fclose(arch);
}
