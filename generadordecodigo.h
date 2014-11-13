#ifndef GENERADORDECODIGO_H
#define GENERADORDECODIGO_H

#include "nodo.h"
#include "tablasimbolos.h"
#include "errores.h"
#include "MainParser.h"
#include <iostream>
#include <fstream>
#include <QList>
#include <QStack>
#include <QChar>
#include <QFile>
#include <QTextStream>

#define TAMANO 1

using namespace std;

extern int mainparserparse();
extern FILE *mainparserin;

class GeneradorDeCodigo : public Errores
{
public:
    QString codigo3D;
    ofstream archivo3D;
    GeneradorDeCodigo();
    void Iniciar();
    void llenarTabla(Nodo* arbol);
    void analizarImports(Nodo* arbol);
    void AgregarAbol(Nodo* arbol);
    QList<QString> *llenarConParametros(QList<QString> *identificadores, Nodo* arbol);
    QString generarCodigo3D(int &tmp, int &etq, Nodo* arbol);
    QString getParamsTipo(QString params, Nodo* arbol);
    QString generarAsignacion(int &tmp, int &etq, Nodo* arbol);
    QString generarDecVar(int &tmp, int &etq, Nodo* arbol);
    void escribir(QString codigo);
    void emitirCodigo3D();
    QString generaTmp();
    QString generaETQ();
    QString eV;
    QString eF;
    QString eSalida;
    QString etRetorno;
    QList<Nodo> *getDimensiones(QList<Nodo> *dimensiones, Nodo *arbol);
    QString idClase;
    int tmp;
    int etq;
    QList<Nodo*> *listaAboles;
    TablaSimbolos tabla;

private:

    QStack<QString> *ambitos;

    QString ambito;
    QString ambitotmp;
    QString accesoClase;
    QString params;
    QString tipo;
    QString metodoActual;
    int tamanoMetodo;
    int tamanoClase;
    int nivel;
    int posicion;
    int ambitoid;
    int contadorImports;
    bool cicloIf;
    void generarParametros(QString temporal, QString nombre, Nodo* arbol, int &cont);
    void generarImprimir();
    void CompilarImport(QString path);

    QString decIniciales;
    QString decMetodos;
};

#endif // GENERADORDECODIGO_H
