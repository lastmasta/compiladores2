#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <QString>
#include <QList>
#include "nodo.h"

class Simbolo
{
public:

    enum Rol {atributo, variable, metodo, objeto, clase};

    Simbolo(QString nombre, QString id, QString ambito, int nivel, int posicion, QString tipo, QString rol, int tamano, QString visibilidad);
    Simbolo(QString nombre, QString id, QString ambito, int nivel, int posicion, QString tipo, QString rol, int tamano, QString visibilidad, QList<Nodo>* dimensiones);
    Simbolo();
    QList<Nodo>* dimensiones;
    QString nombre;
    QString id;
    QString ambito;
    int nivel;
    int posicion;
    QString tipo;
    QString rol;
    int tamano;
    QString visibilidad;
    QString valor;
    QList<QString> parametros;
private:


};

#endif // SIMBOLO_H
