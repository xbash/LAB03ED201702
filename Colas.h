//
// Created by Rodrigo Gonzalez & Jorge Sepulveda
//

#ifndef COLAS_COLAS_H
#define COLAS_COLAS_H

#endif //COLAS_COLAS_H

#include <stdlib.h>

typedef struct Nodo{
    int value;
    struct Nodo* next;
} Nodo;

typedef struct Cola{
    Nodo* start;
    Nodo* end;
    int size;
}Cola;

//Function Prototype
Nodo * CrearNodo(int valor);
void AsignarValorNodo(Nodo* nodo, int valor);
Cola* CrearColaVacia();
void Encolar(Cola* Cola,int value);
void EncolarNodo(Cola* Cola, Nodo *nodo);
int Frente(Cola* Cola);
void unQueue(Cola* Cola);

//Operaciones con Nodo
//Crear Nodo con un valor dado
Nodo * CrearNodo(int valor){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->value=valor;
    return aux;
}
//Asignar un valor al nodo
void AsignarValorNodo(Nodo* nodo, int valor){
    nodo->value=valor;
}

//Creación de una Cola vacía
Cola* CrearColaVacia(){
    Cola* Pivote;
    Pivote = (Cola*)malloc(sizeof(Cola));
    if (Pivote == NULL) exit (-1);
    Pivote->size=0;
    Pivote->start=NULL;
    Pivote->end=NULL;
    return Pivote;
}

//Encolar (enqueue) un valor numérico.
void Encolar(Cola* Cola,int value){
    Nodo* aux = CrearNodo(value);

    if(Cola->size==0){
        aux->next=NULL;
        Cola->start=aux;
        Cola->end=aux;
        Cola->size++;
    }else{
        Cola->end->next=aux;
        Cola->end=aux;
        Cola->size++;
    }
}

//Encolar un Nodo
void EncolarNodo(Cola* Cola, Nodo *nodo){
    if(Cola->size==0){
        nodo->next=NULL;
        Cola->start=nodo;
        Cola->end=nodo;
        Cola->size++;
    }else{
        Cola->end->next=nodo;
        Cola->end=nodo;
        Cola->size++;
    }
}

//Frente: devuelve el número almacenado en el primer nodo de la cola
int Frente(Cola* Cola){
    return Cola->start->value;
}

//Desencolar (Dequeue): Elimina el primer nodo almacenado en la cola.
void unQueue(Cola* Cola){
    if (Cola->size > 0){
        Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
        aux = Cola->start->next;
        Cola->start = aux;
        Cola->size--;
    }
}