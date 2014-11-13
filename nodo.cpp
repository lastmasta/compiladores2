#include "nodo.h"


Nodo::Nodo(){}

Nodo::Nodo(QString etiqueta)
{
    this->etiqueta = etiqueta;
    this->cantHijos = 0;
    for (int i = 0; i<10; i++){
        this->hijos[i] = NULL;
    }
}

void Nodo::AgregarHijo(Nodo* hijo){
    this->hijos[cantHijos] = hijo;
    this->cantHijos++;
}

QString Nodo::Etiqueta(){
    return this->etiqueta;
}
