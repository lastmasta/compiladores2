#include "simbolo.h"

Simbolo::Simbolo(QString nombre, QString ambito, int nivel, int posicion, QString tipo, QString rol, int tamano, QString visibilidad)
{
    this->nombre = nombre;
    this->ambito = ambito;
    this->nivel = nivel;
    this->posicion = posicion;
    this->tipo = tipo;
    this->rol = rol;
    this->tamano = tamano;
    this->visibilidad = visibilidad;
}

Simbolo::Simbolo(QString nombre, QString ambito, int nivel, int posicion, QString tipo, QString rol, int tamano, QString visibilidad, QList<Nodo> *dimensiones)
{
    this->nombre = nombre;
    this->ambito = ambito;
    this->nivel = nivel;
    this->posicion = posicion;
    this->tipo = tipo;
    this->rol = rol;
    this->tamano = tamano;
    this->visibilidad = visibilidad;
    this->dimensiones = dimensiones;
}

Simbolo::Simbolo()
{
}

