#ifndef GRAFICADORAST_H
#define GRAFICADORAST_H
#include <QString>
#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class GraficadorAST
{
public:
    GraficadorAST();
    QString getCodigoGraphviz();
    void Graficar(Nodo* nodo);


private:
    int indice;
    QString codigoGraphviz;
    void declararNodos(Nodo* nodo);
    void enlazarNodos(Nodo* nodo, int actual);
};

#endif // GRAFICADORAST_H
