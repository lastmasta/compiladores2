#include "tablasimbolos.h"

TablaSimbolos::TablaSimbolos()
{
    tabla = new QHash<QString, Simbolo>();
}

void TablaSimbolos::agregarSimbolo(QString nombre, Simbolo* simbolo){
    tabla->insert(nombre, *simbolo);
}

Simbolo TablaSimbolos::getSimbolo(QString nombre){
    Simbolo s = tabla->take(nombre);
    tabla->insert(nombre,s);
    return s;
}

bool TablaSimbolos::existeSimbolo(QString nombre)
{
    return tabla->contains(nombre);
}

void TablaSimbolos::imprimir(){
    QString HTML = "<html>";
        HTML += "<h1>TABLA DE SIMBOLOS</h1>";
        HTML += "<table border = \"1\">";
        HTML += "<tr>";
        HTML += "<th scope=\"col\">Nombre</th>";
        HTML += "<th scope=\"col\">Id</th>";
        HTML += "<th scope=\"col\">Ambito</th>";
        HTML += "<th scope=\"col\">Nivel</th>";
        HTML += "<th scope=\"col\">Posicion</th>";
        HTML += "<th scope=\"col\">Rol</th>";
        HTML += "<th scope=\"col\">Tipo</th>";
        HTML += "<th scope=\"col\">Visibilidad</th>";
        HTML += "<th scope=\"col\">Tamano</th>";
        HTML += "</tr>";

        QHash<QString, Simbolo>::iterator i;
        for (i=tabla->begin(); i!=tabla->end(); ++i){
            HTML += "<tr>";
            HTML += "<td>" + i.key() +"</td>";
            HTML += "<td>" +i.value().id +"</td>";
            HTML += "<td>" + i.value().ambito +"</td>";
            HTML += "<td>" + QString::number(i.value().nivel) +"</td>";
            HTML += "<td>" + QString::number(i.value().posicion) +"</td>";
            HTML += "<td>" + i.value().rol +"</td>";
            HTML += "<td>" + i.value().tipo +"</td>";
            HTML += "<td>" + i.value().visibilidad +"</td>";
            HTML += "<td>" + QString::number(i.value().tamano) +"</td>";
            HTML += "</tr>";
        }

        HTML += "</table>";
        HTML += "</html>";

        myfile.open ("tabla.html");
        myfile.flush();
        myfile << HTML.toStdString() << endl;
        myfile.close();
}

void TablaSimbolos::limpiar()
{
    this->tabla->clear();
}


