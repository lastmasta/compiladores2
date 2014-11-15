#include "ingenieriainversa.h"

IngenieriaInversa::IngenieriaInversa()
{
    tabla = new TablaSimbolos();
}

void IngenieriaInversa::setTabla(TablaSimbolos *t){
    tabla = t;
  }

void IngenieriaInversa:: inversaMetodos(QString nombre){
    if(tabla->existeSimbolo(nombre+"()")){
      Simbolo s = tabla->getSimbolo(nombre+"()");
      QString params = "";

      QList<QString> parametros = s.parametros;

      if (parametros.size() != 0){
          for(int i=0; i<parametros.size()-1; i++){
              QString idParam = parametros.at(i);
              Simbolo param = tabla->getSimbolo(nombre+"_"+idParam);
              QString rol = param.rol;
              QString tipo = param.tipo;

              if(rol == "parametro_val"){
                  params+=idParam+" "+tipo+",";
              } else if (rol == "parametro_ref"){
                  params+="ref "+idParam+" "+tipo+",";
              }
          }

          QString idParam = parametros.at(parametros.size()-1);
          Simbolo param = tabla->getSimbolo(nombre+"_"+idParam);
          QString rol = param.rol;
          QString tipo = param.tipo;

          if(rol == "parametro_val"){
              params+=idParam+" "+tipo;
          } else if (rol == "parametro_ref"){
              params+="ref "+idParam+" "+tipo;
          }

      }
      QStringList claseList = nombre.split("_");
      QString nombreClase = claseList.at(0);
      agregarClase(nombreClase);
      QString metodoNombre = "def "+ s.visibilidad + " " + s.id + " " + s.tipo + "(" +params+")";
      Metodo m;
      m.clase = nombreClase;
      m.nombre = metodoNombre;
      agregarMetodo(m);

    }
}

void IngenieriaInversa::agregarClase(QString idClase)
{
    bool existe = false;
    for(int i = 0; i < clases.size(); i++){
        if(idClase == clases.at(i)){
            existe = true;
        }

    }

    if(!existe){
        clases.push_back(idClase);
    }
}

void IngenieriaInversa::agregarMetodo(IngenieriaInversa::Metodo m)
{
    metodos.push_back(m);
}

void IngenieriaInversa::generarSalida()
{
    for(int i = 0; i<clases.size(); i++){
        QString clase = clases.at(i);
        if(tabla->existeSimbolo(clase)){
            Simbolo s_clase = tabla->getSimbolo(clase);
            QString defClase = s_clase.visibilidad+" clase "+clase;
            cout << defClase.toStdString() << endl;
            cout << "$$" << endl;
            for (int j=0; j<metodos.size(); j++){
                Metodo m = metodos.at(j);
                if(m.clase == clase){
                    cout << "    " ;
                    cout << m.nombre.toStdString() << endl;
                    cout << "    $$" << endl;
                    cout << "    $$" << endl;
                }
            }
            cout << "$$" << endl;
        }
    }
}

void IngenieriaInversa::buscarPrincipal()
{
    QHash<QString, Simbolo>::iterator i;
    for (i=tabla->tabla->begin(); i!=tabla->tabla->end(); ++i){
        if(i.value().id == "Principal" && i.value().rol=="constructor"){
            QString nombreMain= i.key();
            QStringList claseList = nombreMain.split("_");
            QString nombreClase = claseList.at(0);
            agregarClase(nombreClase);
            QString nombreMetodo = "def "+i.value().visibilidad+" "+i.value().id+" ninguno()";
            Metodo main;
            main.nombre = nombreMetodo;
            main.clase = nombreClase;
            agregarMetodo(main);
        }
    }
}


