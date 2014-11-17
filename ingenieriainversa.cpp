#include "ingenieriainversa.h"

IngenieriaInversa::IngenieriaInversa()
{
    tabla = new TablaSimbolos();
}

void IngenieriaInversa::setTabla(TablaSimbolos *t){
    tabla = t;
    clases.clear();
    metodos.clear();
    instrucciones.clear();
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
      m.nombreBajoNivel = nombre;
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

void IngenieriaInversa::agregarInstruccion(IngenieriaInversa::Instruccion i)
{
    instrucciones.push_back(i);
}

void IngenieriaInversa::generarSalida()
{
    SalidaInversa *s = new SalidaInversa();


    for(int i = 0; i<clases.size(); i++){
        QString clase = clases.at(i);
        if(tabla->existeSimbolo(clase)){
            Simbolo s_clase = tabla->getSimbolo(clase);
            QString defClase = s_clase.visibilidad+" clase "+clase;
            s->setTexto(defClase);
            cout << defClase.toStdString() << endl;
            s->setTexto("$$");
            cout << "$$" << endl;
            for (int j=0; j<metodos.size(); j++){
                Metodo m = metodos.at(j);
                if(m.clase == clase){
                    cout << "    " ;
                    s->setTexto("    ");
                    cout << m.nombre.toStdString() << endl;
                    s->setTexto(m.nombre);
                    cout << "    $$" << endl;
                    s->setTexto("    $$");
                    for (int k=0; k<instrucciones.size(); k++){
                        Instruccion i = instrucciones.at(k);
                        if(i.metodo == m.nombre && i.clase==clase){
                            cout << "    " ;
                            s->setTexto("    ");
                            cout << "    " << i.instruccion.toStdString()<< endl;
                            s->setTexto("    "+i.instruccion);
                        }
                    }
                    cout << "    $$" << endl;
                    s->setTexto("    $$");
                }
            }
            cout << "$$" << endl;
            s->setTexto("$$");
        }
    }

    s->show();
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

void IngenieriaInversa::iniciar(Nodo *nodo)
{
    arbolTemp.clear();
    GraficadorAST ga;
    //ga.Graficar(nodo);
    recorrerArbol(nodo);
    generarSalida();

}

void IngenieriaInversa::recorrerArbol(Nodo *arbol)
{
    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();
        for(int i = 0; i < arbol->cantHijos; i++){
            recorrerArbol(arbol->hijos[i]);
            if(etiqueta == "DECMAIN"){
                metodo = "Principal";
                QList<QString> patron;
                patron = getPatron(patron,arbol,arbolTemp);
            }else if(etiqueta == "DECMETODO"){
                QString id = arbol->hijos[0]->Etiqueta();
                if(!(id=="imprimir_num"|| id=="imprimir_caracter" || id=="imprimir_cadena")){
                    metodo = id;
                    QList<QString> patron;
                    patron = getPatron(patron,arbol,arbolTemp);
                    break;
                }
            }
        }
    }
}

QList<QString> IngenieriaInversa::getPatron(QList<QString> &patron, Nodo *arbol, QList<Nodo*> &arbolTemp)
{
    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();
        for (int i = 0; i < arbol->cantHijos; i++){
            if(!(etiqueta == "IGNORAR" || etiqueta == "CUERPOMETODO" || etiqueta == "DECMAIN" || etiqueta == "DECMETODO")){
                patron.push_back(etiqueta);
                arbolTemp.push_back(arbol);
                QString tipoPatron = comprobarPatron(patron);
                if(tipoPatron!=""){
                    cout << "PATRON DETECTADO" << endl;
                    cout << "generando inversa de " << tipoPatron.toStdString() << endl;
                    generarInversa(arbolTemp,tipoPatron);
                    cout << instruccion_actual.toStdString() << endl;
                    this->arbolTemp.clear();
                    patron.clear();
                    arbolTemp.clear();
                }
                break;
            }
            getPatron(patron,arbol->hijos[i], arbolTemp);

        }
    }
    return patron;
}

QString IngenieriaInversa::comprobarPatron(QList<QString> patron)
{
    //Verificar patron de asignacion

    if(patron.size()==3 && patron.at(0) == "CAMBIOVIRTUAL" && patron.at(patron.size()-1) == "ASIGSTACK"){
        return "asignacion";
    }
    // Verificar patron de bifurcacion simple

    else if(patron.size() > 6
              && patron.at(0) == "TEMPASIG"
              && patron.at(3) == "SALTOCOND"
              && patron.at(4) == "SALTONOCOND"
              && patron.at(5) == "ETIQ"
              && patron.at(patron.size()-1)=="ETIQ"

              ){
        return "si_cumple_1";
    }

    //Verificar patron de ciclo

    else if (patron.size() > 7
             && patron.at(0) == "ETIQ"
             && patron.at(patron.size()-1) == "ETIQ"
             && patron.at(patron.size()-2) == "SALTONOCOND"
             ){
        return "ciclo";

    }
    else {
        return "";
    }

}

void IngenieriaInversa::generarInversa(QList<Nodo*> arbol, QString tipoPatron)
{
    if(tipoPatron == "asignacion"){
        QString tipo = "";
        Metodo m;
        Simbolo variable;
        for(int i=0; i<arbol.size(); i++){
            QString etiqueta = arbol.at(i)->Etiqueta();
            if(etiqueta=="CAMBIOVIRTUAL"){
                if(metodo == "Principal"){
                    int posicion = arbol.at(i)->hijos[1]->Etiqueta().toInt();
                    m = buscarMetodo(metodo);
                    QString ambito = m.clase+"_Principal";
                    variable = buscarVariable(ambito,posicion);
                    tipo = variable.tipo;
                    instruccion_actual = variable.id + " " + tipo;
                    if(variable.tipo == "cadena"){
                        instruccion_actual += " = \""+variable.valor+"\";";
                        Instruccion i;
                        i.instruccion = instruccion_actual;
                        i.clase = m.clase;
                        i.metodo = m.nombre;
                        instrucciones.push_back(i);
                        break;
                    }
                }
                else {
                        Simbolo funcion = tabla->getSimbolo(metodo+"()");
                        QStringList qsl = metodo.split("_");
                        m = buscarMetodo(metodo,funcion.ambito);
                        int posicion = arbol.at(i)->hijos[1]->Etiqueta().toInt();
                        QString ambito = metodo;
                        variable = buscarVariable(ambito,posicion);
                        tipo = variable.tipo;
                        instruccion_actual = variable.id + " " + tipo;
                        if(variable.tipo == "cadena"){
                            instruccion_actual += " = \""+variable.valor+"\";";
                            Instruccion i;
                            i.instruccion = instruccion_actual;
                            i.clase = m.clase;
                            i.metodo = m.nombre;
                            instrucciones.push_back(i);
                            break;
                        }
                    }
            } else if ("TEMPASIG"){

                if(arbol.at(i)->hijos[1]!=NULL){
                    QString valor = arbol.at(i)->hijos[1]->Etiqueta();
                    if(tipo=="entero"){
                        instruccion_actual += " = "+valor+";";
                        Instruccion i;
                        i.instruccion = instruccion_actual;
                        i.clase = m.clase;
                        i.metodo = m.nombre;
                        instrucciones.push_back(i);
                    } else if (tipo == "caracter"){
                        char c = (char)valor.toInt();
                        QChar qc = QChar::fromLatin1(c);
                        QString caracter = QString(qc);
                        instruccion_actual += " = '"+QString(qc)+"';";
                        Instruccion i;
                        i.instruccion = instruccion_actual;
                        i.clase = m.clase;
                        i.metodo = m.nombre;
                        instrucciones.push_back(i);
                    } else if (tipo == "bool"){
                        if(valor=="1"){
                            valor = "true";
                        } else {
                            valor = "false";
                        }
                        instruccion_actual += " = "+valor+";";
                        Instruccion i;
                        i.instruccion = instruccion_actual;
                        i.clase = m.clase;
                        i.metodo = m.nombre;
                        instrucciones.push_back(i);
                    }
                }


                break;
            }
        }
    }

    else if(tipoPatron == "si_cumple_1"){
        QString val2;
        Metodo m;
        Simbolo variable;
        QString opRel;
        int cont = 0;

        for(int i=0; i<arbol.size(); i++){
            if(arbol.at(i)!=NULL){
                Nodo* arbolTemp = arbol.at(i);
                QString etiqueta = arbolTemp->Etiqueta();
                if(etiqueta == "TEMPASIG"){
                    if(cont ==0){
                        val2 = arbolTemp->hijos[1]->Etiqueta();
                    }
                    cont++;
                } else if(etiqueta == "CAMBIOVIRTUAL"){
                    QString posicion = arbolTemp->hijos[1]->Etiqueta();
                    if(metodo == "Principal"){
                        m = buscarMetodo(metodo);
                        QString ambito = m.clase+"_Principal";
                        variable = buscarVariable(ambito,posicion.toInt());
                    } else {
                        Simbolo funcion = tabla->getSimbolo(metodo+"()");
                        m = buscarMetodo(metodo,funcion.ambito);
                        QString ambito = metodo;
                        variable = buscarVariable(ambito,posicion.toInt());
                    }
                } else if(etiqueta == "SALTOCOND"){
                    opRel = arbolTemp->hijos[2]->hijos[0]->Etiqueta();
                }
            }

        }
        QString instruccion = "si_cumple("+variable.id+opRel+val2+")$$ $$";
        cout << instruccion.toStdString() << endl;
        Instruccion i;
        i.instruccion = instruccion;
        i.metodo = m.nombre;
        i.clase = m.clase;
        instrucciones.push_back(i);
    }

    else if (tipoPatron == "ciclo"){
        QString val2;
        Metodo m;
        Simbolo variable;
        QString opRel;
        int cont;
        for (int i = 0; i<arbol.size(); i++){
            if(arbol.at(i)!=NULL){
                Nodo* arbolTemp = arbol.at(i);
                QString etiqueta = arbolTemp->Etiqueta();
                if(etiqueta == "TEMPASIG"){
                    if(cont==0){
                        val2 = arbolTemp->hijos[1]->Etiqueta();
                    }
                    cont++;
                } else if (etiqueta=="CAMBIOVIRTUAL"){
                    QString posicion = arbolTemp->hijos[1]->Etiqueta();
                    if(metodo == "Principal"){
                        m = buscarMetodo(metodo);
                        QString ambito = m.clase+"_Principal";
                        variable = buscarVariable(ambito,posicion.toInt());
                    } else {
                        Simbolo funcion = tabla->getSimbolo(metodo+"()");
                        m = buscarMetodo(metodo,funcion.ambito);
                        QString ambito = metodo;
                        variable = buscarVariable(ambito,posicion.toInt());
                    }
                } else if(etiqueta == "SALTOCOND"){
                    opRel = arbolTemp->hijos[2]->hijos[0]->Etiqueta();
                }
            }
        } QString instruccion = "repetir_mientras("+variable.id+opRel+val2+")$$ $$";
        cout << instruccion.toStdString() << endl;
        Instruccion i;
        i.instruccion = instruccion;
        i.metodo = m.nombre;
        i.clase = m.clase;
        instrucciones.push_back(i);
    }
}

IngenieriaInversa::Metodo IngenieriaInversa::buscarMetodo(QString nombre)
{
    for(int i = 0; i<metodos.size(); i++){
        Metodo m = metodos.at(i);
        if (m.nombre == nombre);
        return m;
    }

    Metodo m;
    m.nombre=""; m.clase = "";
    return m;
}

IngenieriaInversa::Metodo IngenieriaInversa::buscarMetodo(QString nombreBajoNivel, QString clase)
{
    for(int i = 0; i<metodos.size(); i++){
        Metodo m = metodos.at(i);
        if (m.nombreBajoNivel == nombreBajoNivel && m.clase == clase){
            return m;
        }

    }

    Metodo m;
    m.nombre=""; m.clase = "";
    return m;
}

Simbolo IngenieriaInversa::buscarVariable(QString ambito, int posicion)
{
    QHash<QString, Simbolo>::iterator i;
    for (i=tabla->tabla->begin(); i!=tabla->tabla->end(); ++i){
        if(i.value().ambito == ambito && i.value().posicion == posicion){
            return i.value();
        }
    }

    Simbolo s;
    s.id = "";
    return s;
}


