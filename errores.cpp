#include "errores.h"

Errores::Errores()
{

}

void Errores::ExisteSimbolo(QString id, QString ambito)
{
    QString texto = "La variable "+id+" ya fue declara en el ambito "+ambito;
    errores << texto.toStdString() << endl;
}

void Errores::NoExistePrincipal(QString clase)
{
    QString texto = "No existe el método Principal() en la clase "+clase;
    errores << texto.toStdString() << endl;
}

void Errores::NoExisteSimbolo(QString id, QString ambito)
{
    QString texto = "No existe el identificador "+id+" en el ámbito "+ambito;
    errores << texto.toStdString() << endl;
}

void Errores::NoExisteConstructor(QString id)
{
    QString texto = "El constructor "+id+"() no está definido";
    errores << texto.toStdString() << endl;
}

void Errores::ErrorDeTipos(QString id, QString tipo)
{
    QString texto = "La variable "+id+ " no es del tipo "+tipo;
    errores << texto.toStdString() << endl;

}

void Errores::ErrorReturn(QString id, QString tipo)
{
    QString texto = "";
    if(tipo == "ninguno"){
        texto = "Error: el metodo "+id+" no devuelve ningun tipo.";
    } else {
        texto = "Error: el retorno del metodo "+id+" debe ser de tipo "+tipo;
    }
    errores << texto.toStdString() << endl;
}

void Errores::ErrorCantParametros(QString id)
{
    QString texto = "La cantidad de parametros no coincide con la definición del método "+id;
    errores << texto.toStdString() << endl;
}

void Errores::ErrorTipoIndefinido(QString tipo)
{
    QString texto = "El tipo "+tipo+" no está definido";
    errores << texto.toStdString() << endl;
}

void Errores::ErrorVisibilidad(QString id)
{
    QString texto = "El objeto o atributo "+id+" no es accesible para esta clase";
    errores << texto.toStdString() << endl;
}
