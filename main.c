/*
 * Lab03 - ED 2017 2do Semestre
 * Created by Rodrigo Gonzalez & Jorge Sepulveda
 */

#include "Colas.h"
#include "Ruleta.h"


int main() {
    Cola* Cola = CrearColaVacia();
    Ruleta* ruleta;
    ruleta = CrearRuleta(99);
    //ImprimirRuleta(ruleta);
    Girar(ruleta);
}