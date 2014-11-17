#ifndef INGENIERIAINVERSA_H
#define INGENIERIAINVERSA_H

#include "tablasimbolos.h"
#include "graficadorast.h"
#include <QStringList>
#include "salidainversa.h"

class IngenieriaInversa
{
public:
    struct Metodo{
        QString nombre;
        QString clase;
        QString nombreBajoNivel;
    };
    typedef struct Metodo Metodo;

    struct Instruccion{
        QString instruccion;
        QString metodo;
        QString clase;
    };
    typedef struct Instruccion Instruccion;

    TablaSimbolos *tabla;
    IngenieriaInversa();
    void setTabla(TablaSimbolos *t);
    void inversaMetodos(QString nombre);

    void generarSalida();
    void buscarPrincipal();
    void iniciar(Nodo* nodo);

private:
    QList<QString> clases;
    QList<Metodo> metodos;
    QList <Instruccion> instrucciones;
    void recorrerArbol(Nodo* arbol);
    void agregarClase(QString idClase);
    void agregarMetodo(Metodo m);
    void agregarInstruccion(Instruccion i);
    QList<QString> getPatron(QList<QString> &patron, Nodo* arbol, QList<Nodo *> &arbolTemp);
    QString comprobarPatron(QList<QString> patron);
    void generarInversa(QList<Nodo *> arbol, QString tipoPatron);
    QString metodo;
    Metodo buscarMetodo(QString nombre);
    Metodo buscarMetodo(QString nombreBajoNivel, QString clase);
    Simbolo buscarVariable(QString ambito, int posicion);
    QString instruccion_actual;

    QList<Nodo*> arbolTemp;
};

#endif // INGENIERIAINVERSA_H
