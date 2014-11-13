#ifndef ERRORES_H
#define ERRORES_H

#include <iostream>
#include <QMessageBox>
#include <fstream>
using namespace std;

class Errores
{
public:
    ofstream errores;
    Errores();
    void ExisteSimbolo(QString id, QString ambito);
    void NoExistePrincipal(QString clase);
    void NoExisteSimbolo(QString id, QString ambito);
    void NoExisteConstructor(QString id);
    void ErrorDeTipos(QString id, QString tipo);
    void ErrorReturn(QString id, QString tipo);
    void ErrorCantParametros(QString id);
    void ErrorTipoIndefinido(QString tipo);
    void ErrorVisibilidad(QString id);
};

#endif // ERRORES_H
