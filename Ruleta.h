//
// Created by Rodrigo Gonzalez & Jorge Sepulveda
//
#include<stdlib.h>
#include <stdio.h>
#include<time.h>
#ifndef COLAS_RULETA_H
#define COLAS_RULETA_H

#endif //COLAS_RULETA_H
/*
 * La estructura ruleta contiene una cola que almacena los valores de la ruleta
 */
typedef struct Ruleta{
    Cola *ruleta;
    int tamano;
}Ruleta;

//Function Prototypes
Ruleta* CrearRuleta(int tamano);
void Girar(Ruleta* ruleta);
void ImprimirRuleta(Ruleta* ruleta);

// 2.a
/*
 * CrearRuleta recibe como parametro un tamano, y dentro de la estructura ruleta, se crea una cola del tamano ingresado.
 * Los valores asignados en esta cola son generados aleatoriamente entre 1 y 9999
 * Una vez generado el numero aleatorio, este es encolado en la pila de la estructura ruleta
 */
Ruleta* CrearRuleta(int tamano){
    Ruleta *ruleta = (Ruleta*)malloc(sizeof(Ruleta));
    ruleta->ruleta=CrearColaVacia();
    ruleta->tamano=tamano;
    //Genera los numeros aleatorios
    srand(time(NULL));
    int num;
    for (int i=0; i<tamano;i++){
        printf ("%i\r",i); //Verifica que se este encolando,  (utilizando para tamanos muy grandes)
        num=1+rand()%(9999-1);
        Encolar(ruleta->ruleta,num);
    }

    return ruleta;
}
//2.b
/*
 * Girar utiliza el tamaño de la ruleta para generar un numero aleatorio entre 1 y el tamano de esta ruleta.
 * El numero aleatorio es la posicion de la pila en la cual se detendra y entregará el valor en dicho lugar
 */
void Girar(Ruleta* ruleta){
    printf("Girando... \n");
    int num;
    num=1+rand()%(ruleta->tamano-1);
    for (int i=0; i<num;i++){
        unQueue(ruleta->ruleta);
    }
    printf ("Valor obtenido fue: %i\n",ruleta->ruleta->start->value);
}
/*
 * ImprimirRuleta, imprime los valores de la ruleta secuencualmente hasta que la pila contenida en esta se termine.
 * La ruleta es recorrida utilizando la operacion des-encolar
 */
void ImprimirRuleta(Ruleta* ruleta) {
    while (ruleta->ruleta != NULL) {
        printf("Valor: %i\n", ruleta->ruleta->start->value);
        unQueue(ruleta->ruleta);
    }
}