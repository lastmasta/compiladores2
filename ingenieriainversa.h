#ifndef INGENIERIAINVERSA_H
#define INGENIERIAINVERSA_H

#include "tablasimbolos.h"
#include <QStringList>

class IngenieriaInversa
{
public:
    struct Metodo{
        QString nombre;
        QString clase;
    };
    typedef struct Metodo Metodo;

    TablaSimbolos *tabla;
    IngenieriaInversa();
    void setTabla(TablaSimbolos *t);
    void inversaMetodos(QString nombre);
    void agregarClase(QString idClase);
    void agregarMetodo(Metodo m);
    void generarSalida();
    void buscarPrincipal();

private:
    QList<QString> clases;
    QList<Metodo> metodos;
};

#endif // INGENIERIAINVERSA_H
