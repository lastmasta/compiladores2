#ifndef TABLASIMBOLOS_H
#define TABLASIMBOLOS_H
#include <QHash>
#include <QString>
#include "simbolo.h"
#include <iostream>
#include <fstream>

using namespace std;

class TablaSimbolos
{
public:
    TablaSimbolos();
    void agregarSimbolo(QString nombre, Simbolo* simbolo);
    Simbolo getSimbolo(QString nombre);
    bool existeSimbolo(QString nombre);
    void imprimir();
    void limpiar();



private:
    QHash<QString, Simbolo>* tabla;
    ofstream myfile;
};

#endif // TABLASIMBOLOS_H
