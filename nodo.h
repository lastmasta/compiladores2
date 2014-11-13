#ifndef NODO_H
#define NODO_H

#include <QString>

class Nodo
{
public:
    Nodo* hijos[10];

    Nodo(QString etiqueta);

    Nodo ();

    void AgregarHijo(Nodo* hijo);

    QString Etiqueta();

    int cantHijos;


private:
    QString etiqueta;



};

#endif // NODO_H
