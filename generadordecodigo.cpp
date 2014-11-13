#include "generadordecodigo.h"


GeneradorDeCodigo::GeneradorDeCodigo()
{
    this->etq = 0;
    this->tmp = 0;
    this->listaAboles = new QList<Nodo*>();
    this->decIniciales = "";
    this->decMetodos = "";
    this->contadorImports = 0;
}

void GeneradorDeCodigo::Iniciar(){
    archivo3D.open ("3D.cpp");
    archivo3D.flush();
    int tmp = 0;
    int etq = 0;
    decIniciales = "#include <iostream>|";
    decIniciales += "using namespace std;|";
    decIniciales += "long Stack[10000];|";
    decIniciales += "long Heap[10000];|";
    cout << "Generando codigo de 3 direcciones..." << endl;
    cicloIf = false;
    generarImprimir();
    emitirCodigo3D();
    archivo3D.close();
}

void GeneradorDeCodigo::analizarImports(Nodo *arbol){
    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();

        if(etiqueta == "INICIO"){
            for(int i = 0; i < arbol->cantHijos; i++){
                analizarImports(arbol->hijos[i]);
            }
        } else if (etiqueta == "IMPORT_LIST"){
            for (int i = 0; i < arbol->cantHijos; i++){
                analizarImports(arbol->hijos[i]);
            }
        } else if (etiqueta == "IMPORT"){
            QString path = arbol->hijos[0]->Etiqueta();
            CompilarImport(path);

        } else if (etiqueta == "CLASE_LIST"){
            errores.open("errores.txt");
            llenarTabla(arbol);
            generarCodigo3D(tmp,etq,arbol);
            Iniciar();
            errores.close();


        }
    }
}

void GeneradorDeCodigo::AgregarAbol(Nodo *arbol)
{
    listaAboles->push_back(arbol);
    analizarImports(arbol);
    this->contadorImports++;
    tabla.imprimir();


}

void GeneradorDeCodigo::llenarTabla(Nodo *arbol){
    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();
        cout<<etiqueta.toStdString()<<endl;

        if(etiqueta == "INICIO"){
            for (int i = 0; i< arbol->cantHijos; i++){
                llenarTabla(arbol->hijos[i]);
            }
        }

        else if(etiqueta == "CLASE_LIST"){
            for (int i = 0; i< arbol->cantHijos; i++){
                llenarTabla(arbol->hijos[i]);
            }
        }

        else if(etiqueta == "CLASE"){
            ambitoid = 0;
            nivel = 0;
            posicion = 0;
            QString id = "";
            for(int i = 0; i< arbol->cantHijos; i++){
                QString etiqueta = arbol->hijos[i]->Etiqueta();
                if(etiqueta=="TIPO_ACCESO"){
                    accesoClase = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if (etiqueta=="ID"){
                    id = arbol->hijos[i]->hijos[0]->Etiqueta();
                    idClase = id;
                    ambito = id;

                } else if (etiqueta == "CUERPO_CLASE"){
                    llenarTabla(arbol->hijos[i]);
                }
            }
            Simbolo* s = new Simbolo(id, "N/A", -1, -1, "N/A", "clase", posicion, accesoClase);
            if(!tabla.existeSimbolo(id)){
                tabla.agregarSimbolo(id,s);
            } else {
                ExisteSimbolo(id,ambito);
            }

        }
        else if (etiqueta == "CUERPO_CLASE"){
            int i = 0;
            while(arbol->hijos[i]!=NULL){
                llenarTabla(arbol->hijos[i]);
                i++;
            }
        }
        else if (etiqueta == "SENTENCIAS_CLASE"){
            llenarTabla(arbol->hijos[0]);
        }
        else if (etiqueta == "DECATR"){
            int i = 0;
            Nodo* hijo = arbol->hijos[i];
            QString id;
            QString visibilidad;
            QString tipo;
            while(hijo!=NULL){
                if(hijo->Etiqueta() == "ID") {id = hijo->hijos[0]->Etiqueta();}
                else if (hijo->Etiqueta() == "TIPO_ACCESO") {visibilidad = hijo->hijos[0]->Etiqueta();}
                else if (hijo->Etiqueta() == "TIPO") {tipo = hijo->hijos[0]->Etiqueta();}
                i++;
                hijo = arbol->hijos[i];
            }
            QString nombre = ambito+"_"+id;
            Simbolo* s = new Simbolo(nombre,ambito,nivel,posicion,tipo,"atributo",TAMANO,visibilidad);
            if(!tabla.existeSimbolo(nombre)){
                tabla.agregarSimbolo(nombre,s);
                posicion++;
            } else {
                ExisteSimbolo(id,ambito);
            }
        } else if (etiqueta == "DECMETODO"){
            QList<QString> *identificadores;
            tamanoMetodo = 0;
            ambitoid = 0;
            params = "";
            QString acceso = "";
            QString id = "";
            QString tipo = "";
            QString ambitotemp = ambito;
            int posiciontemp = posicion;
            posicion = 1;
            for (int i = 0; i<arbol->cantHijos; i++){
                if(arbol->hijos[i]->Etiqueta()=="TIPO_ACCESO"){
                    acceso = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if(arbol->hijos[i]->Etiqueta() == "ID"){
                    id = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if(arbol->hijos[i]->Etiqueta() == "TIPO"){
                    tipo = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if (arbol-> hijos[i]->Etiqueta()=="PARAMLIST"){
                    llenarTabla(arbol->hijos[i]);
                    ambito = ambito+"_"+id+params;
                    nivel++;
                    identificadores = new QList<QString>();
                    identificadores = llenarConParametros(identificadores, arbol->hijos[i]);
                    ambito = ambitotemp;
                    nivel--;
                }
            }

            //Creamos el nombre del metodo con el ambito, el id y los tipos de los parametros.
            QString nombre = ambito+"_"+id+params;
            if (acceso == ""){acceso = accesoClase;}
            int cantHijos = arbol->cantHijos;

            // Cambio de ambito
            ambito = nombre;
            nivel++;

            //Agregamos el "this" en la posicion 0 del metodo
            Simbolo* This = new Simbolo(ambito+"_this",ambito,nivel,0,"entero","variable",1,"N/A");
            tabla.agregarSimbolo(ambito+"_this",This);
            tamanoMetodo++;



            // Lleno tabla con los simbolos dentro de las instrucciones del nuevo ambito
            llenarTabla(arbol->hijos[cantHijos-1]);

            //Agregamos el "return" en la posicion 1 del metodo
            if (!(tipo=="ninguno")){
                Simbolo *s = new Simbolo(ambito+"_return", ambito, nivel, posicion, tipo, "retorno", TAMANO, "N/A");
                if(!tabla.existeSimbolo(ambito+"_return")) {tabla.agregarSimbolo(ambito+"_return", s);}
                posicion++;
                tamanoMetodo++;
            }

            // Vuelvo al ámbito anterior
            nivel--;
            ambito = ambitotemp;
            posicion = posiciontemp;

            // Agregamos metodo a la tabla de simbolos
            nombre+="()";
            Simbolo* s = NULL;
            if(id == idClase && tipo=="ninguno"){
                s = new Simbolo(nombre,ambitotemp,nivel,-1,tipo,"constructor",tamanoMetodo,acceso);
            } else {
                s = new Simbolo(nombre,ambitotemp,nivel,-1,tipo,"metodo",tamanoMetodo,acceso);
            }

            //Agregamos los identificadores de los parametros al simbolo
            s->parametros = identificadores;

            //Verificamos que el simbolo no exista en la tabla de simbolos
            if(!tabla.existeSimbolo(nombre)){
                tabla.agregarSimbolo(nombre,s);
            } else {ExisteSimbolo(id,ambito);}



        } else if (etiqueta == "PARAMLIST"){
            for (int i = 0; i<arbol->cantHijos; i++){
                llenarTabla(arbol->hijos[i]);
            }
        }
        else if (etiqueta == "PARAM"){
            params += "_"+arbol->hijos[1]->hijos[0]->Etiqueta();
        }
        else if (etiqueta == "REFPARAM"){
            params += "_"+arbol->hijos[2]->hijos[0]->Etiqueta();
        }
        else if (etiqueta == "INSTRUCCIONES"){
            int i = 0;
            while(arbol->hijos[i]!=NULL){
                llenarTabla(arbol->hijos[i]);
                i++;
            }
        }
        else if(etiqueta == "SENTENCIAS"){
            llenarTabla(arbol->hijos[0]);
        }
        else if(etiqueta == "DECVAR"){
            QString id = arbol->hijos[0]->hijos[0]->Etiqueta();
            QString tipo = arbol->hijos[1]->hijos[0]->Etiqueta();
            QString nombre = ambito+"_"+id;
            Simbolo* s = new Simbolo(nombre,ambito,nivel,posicion,tipo,"variable",TAMANO,"N/A");
            if(!tabla.existeSimbolo(nombre)){
                tabla.agregarSimbolo(nombre,s);
                posicion++;
                tamanoMetodo++;
            } else {
                ExisteSimbolo(id,ambito);
            }
        } else if (etiqueta == "IF"){
            ambitotmp = ambito;
            ambito+="_if"+QString::number(ambitoid);
            ambitoid++;
            int ambitoidtmp = ambitoid;
            for(int i = 0; i<arbol->cantHijos; i++){
                ambitoid = 0;
                nivel++;
                llenarTabla(arbol->hijos[i]);
                nivel--;
            }
            ambitoid = ambitoidtmp;
            ambito = ambitotmp;
        }
        else if (etiqueta == "ELSEIFLIST"){
            int i = 0;
            while(arbol->hijos[i]!=NULL){
                llenarTabla(arbol->hijos[i]);
                i++;
            }
        }

        else if (etiqueta == "ELSEIF"){
            ambitotmp = ambito;
            ambito+="_elseif"+QString::number(ambitoid);
            ambitoid++;
            int ambitoidtmp = ambitoid;
            for (int i = 0; i<arbol->cantHijos; i++){
                ambitoid = 0;
                nivel++;
                llenarTabla(arbol->hijos[i]);
                nivel--;
            }
            ambito = ambitotmp;
            ambitoid = ambitoidtmp;
        }
        else if (etiqueta == "ELSE"){
            ambitotmp = ambito;
            ambito+="_else";
            llenarTabla(arbol->hijos[0]);
            ambito = ambitotmp;
        }

        else if (etiqueta == "CICLO"){
            ambitotmp = ambito;
            ambito+="_ciclo"+QString::number(ambitoid);
            ambitoid++;
            int ambitoidtmp = ambitoid;
            for (int i = 0; i<arbol->cantHijos; i++){
                ambitoid = 0;
                nivel++;
                llenarTabla(arbol->hijos[i]);
                nivel--;
            }
            ambitoid = ambitoidtmp;
            ambito = ambitotmp;
        }

        else if(etiqueta == "DECARRATR"){
            QString acceso = arbol->hijos[0]->hijos[0]->Etiqueta();
            QString id = arbol->hijos[1]->hijos[0]->Etiqueta();
            QString tipo = arbol->hijos[2]->hijos[0]->Etiqueta();
            QString rol = "arreglo";
            QString nombre = ambito+"_"+id;


            if(!tabla.existeSimbolo(nombre)){
                QList<Nodo>* dimensiones = new QList<Nodo>();
                dimensiones = getDimensiones(dimensiones,arbol->hijos[3]);
                Simbolo* s = new Simbolo(nombre,ambito,nivel,posicion,tipo,rol,TAMANO,acceso,dimensiones);
                tabla.agregarSimbolo(nombre,s);
                posicion++;
            } else {ExisteSimbolo(id,ambito);}
        }
        else if (etiqueta=="DECARRVAR"){
            QString id = arbol->hijos[0]->hijos[0]->Etiqueta();
            QString tipo = arbol->hijos[1]->hijos[0]->Etiqueta();
            QString nombre = ambito+"_"+id;
            if(!tabla.existeSimbolo(nombre)){
                QList<Nodo>* dimensiones = new QList<Nodo>();
                dimensiones = getDimensiones(dimensiones,arbol->hijos[2]);
                Simbolo* s = new Simbolo(nombre,ambito,nivel,posicion,tipo,"arreglo",TAMANO,"N/A",dimensiones);
                tabla.agregarSimbolo(nombre,s);
                posicion++;
                tamanoMetodo++;
            }
        }
    }
}

QList<Nodo>* GeneradorDeCodigo::getDimensiones(QList<Nodo>* dimensiones, Nodo *arbol){
    int i=0;
    while(arbol->hijos[i]!=NULL){
        if(arbol->hijos[i]->Etiqueta()=="DIM"){
            Nodo &n = *arbol->hijos[i]->hijos[0];
            dimensiones->push_back(n);
        }
        dimensiones = getDimensiones(dimensiones,arbol->hijos[i]);
        i++;
    }
    return dimensiones;

}

void GeneradorDeCodigo::generarParametros(QString temporal, QString nombre, Nodo *arbol, int &cont){
    for(int i = 0; i<arbol->cantHijos; i++){
        if(arbol->hijos[i]->Etiqueta()=="VALOR"){
            Simbolo metodo = tabla.getSimbolo(nombre+"()");
            QList<QString>* idList = metodo.parametros;

            QString idparam = idList->at(cont);
            Simbolo parametro = tabla.getSimbolo(nombre+"_"+idparam);


            QString temp2 = generarCodigo3D(tmp,etq,arbol->hijos[i]->hijos[0]);

            if(parametro.tipo == tipo){
                QString temporal2 = generaTmp();
                escribir(temporal2+"="+temporal+"+"+QString::number(parametro.posicion)+";");
                escribir("Stack["+temporal2+"]="+temp2+";");
            } else {
                ErrorDeTipos(idparam,tipo);
            }
            cont++;
        } else {
            generarParametros(temporal,nombre,arbol->hijos[i],cont);
        }

    }
}

void GeneradorDeCodigo::generarImprimir()
{
    if(this->contadorImports==0){
        // Imprimir Cadena
        this->decMetodos+="void imprimir_cadena();|";
        escribir("void imprimir_cadena(){");
        QString temp = generaTmp();
        escribir(temp+"=ptr+0;");
        QString temp2 = generaTmp();
        escribir(temp2+"=Stack["+temp+"];");
        QString etiqueta1 = generaETQ();
        QString etiqueta2 = generaETQ();
        QString etiquetaSalida = generaETQ();
        escribir(etiqueta1+":");
        QString tempH = generaTmp();
        escribir(tempH+"=Heap["+temp2+"];");
        QString temporal10 = generaTmp();
        escribir(temporal10+"=10;");
        escribir("if("+tempH+"!="+temporal10+") goto "+etiqueta2+";");
        escribir("goto "+etiquetaSalida+";");
        escribir(etiqueta2+":");
        escribir("cout<<(char)"+tempH+";");
        escribir(temp2+"="+temp2+"+1;");
        escribir("goto "+etiqueta1+";");
        escribir(etiquetaSalida+":");
        escribir("cout << endl;");
        escribir("}");

        //Imprimir número
        this->decMetodos+="void imprimir_num();|";
        escribir ("void imprimir_num(){");
        temp = generaTmp();
        escribir(temp+"=ptr+0;");
        temp2 = generaTmp();
        escribir(temp2+"=Stack["+temp+"];");
        escribir("cout<<"+temp2+"<<endl;");
        escribir("}");

        //Imprimir caracter
        this->decMetodos+="void imprimir_caracter();|";
        escribir ("void imprimir_caracter(){");
        temp = generaTmp();
        escribir(temp+"=ptr+0;");
        temp2 = generaTmp();
        escribir(temp2+"=Stack["+temp+"];");
        escribir("cout<<(char)"+temp2+"<<endl;");
        escribir("}");

    }
}

void GeneradorDeCodigo::CompilarImport(QString path)
{
    QString codigo = "";
    QFile inputFile(path);
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while ( !in.atEnd() )
           {
              QString line = in.readLine();
              codigo += line;
           }
           inputFile.close();
        }
        ofstream fichero;
        fichero.open("archivoImport.txt",ofstream::out|ofstream::trunc);
        fichero << codigo.toStdString();
        fichero.close();

        mainparserin=fopen("archivoImport.txt","rt");
        mainparserparse();
}

QList<QString> * GeneradorDeCodigo::llenarConParametros(QList<QString> *identificadores, Nodo *arbol)
{
    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();
        if(etiqueta == "PARAMLIST"){
            for (int i = 0; i<arbol->cantHijos; i++){
                llenarConParametros(identificadores, arbol->hijos[i]);
            }
        } else if (etiqueta=="PARAM"){
            QString id = arbol->hijos[0]->hijos[0]->Etiqueta();
            identificadores->push_back(id);
            QString tipo = arbol->hijos[1]->hijos[0]->Etiqueta();
            QString nombre = ambito +"_"+id;
            Simbolo* s = new Simbolo(nombre, ambito,nivel,posicion,tipo,"parametro_val",TAMANO,"N/A");
            if(!tabla.existeSimbolo(nombre)){
                tabla.agregarSimbolo(nombre,s);
                posicion++;
                tamanoMetodo++;
            } else {
                ExisteSimbolo(id,ambito);
            }

        } else if (etiqueta == "REFPARAM"){
            QString id = arbol->hijos[1]->hijos[0]->Etiqueta();
            identificadores->push_back(id);
            QString tipo = arbol->hijos[2]->hijos[0]->Etiqueta();
            QString nombre = ambito +"_"+id;
            Simbolo* s = new Simbolo(nombre, ambito,nivel,posicion,tipo,"parametro_ref",TAMANO,"N/A");
            if(!tabla.existeSimbolo(nombre)){
                tabla.agregarSimbolo(nombre,s);
                posicion++;
                tamanoMetodo++;
            } else {
                ExisteSimbolo(id,ambito);
            }
        }
    }
    return identificadores;
}

QString GeneradorDeCodigo::generarCodigo3D(int &tmp,int &etq, Nodo* arbol) {

    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();
        cout << etiqueta.toStdString() << endl;
        if(etiqueta == "INICIO"){
            int i = 0;
            while(arbol->hijos[i]!=NULL){
                generarCodigo3D(tmp,etq,arbol->hijos[i]);
                i++;
            }
        }else if(etiqueta == "CLASE_LIST"){
            for(int i = 0; i<arbol->cantHijos; i++){
                generarCodigo3D(tmp,etq,arbol->hijos[i]);
            }
        }

        else if (etiqueta=="CLASE"){
            int i = 0;
            idClase = arbol->hijos[1]->hijos[0]->Etiqueta();
            ambito = idClase;
            generarCodigo3D(tmp,etq,arbol->hijos[2]);
        } else if (etiqueta == "CUERPO_CLASE"){
            int i = 0;
            while(arbol->hijos[i]!=NULL){
                generarCodigo3D(tmp,etq,arbol->hijos[i]);
                i++;
            }
        } else if (etiqueta == "SENTENCIAS_CLASE"){
            generarCodigo3D(tmp,etq,arbol->hijos[0]);

        } else if (etiqueta == "DECATR"){
            if(arbol->cantHijos == 4){
                int i = 0;
                Nodo* hijo = arbol->hijos[i];
                QString id;
                QString visibilidad;
                QString tipo;
                QString temporal;
                while(hijo!=NULL){
                    if(hijo->Etiqueta() == "ID") {id = hijo->hijos[0]->Etiqueta();}
                    else if (hijo->Etiqueta() == "TIPO_ACCESO") {visibilidad = hijo->hijos[0]->Etiqueta();}
                    else if (hijo->Etiqueta() == "TIPO") {tipo = hijo->hijos[0]->Etiqueta();}
                    else if (hijo->Etiqueta() == "ASIGNACION") {temporal = generarCodigo3D(tmp,etq,hijo);}
                    i++;
                    hijo = arbol->hijos[i];
                }
                QString nombre = ambito+"_"+id;
                Simbolo s = tabla.getSimbolo(nombre);
                int pos = s.posicion;
                QString codigo = "Stack["+QString::number(pos)+"]="+temporal+";";
                escribir(codigo);
            }

        } else if(etiqueta == "ASIGNACION"){
            return generarCodigo3D(tmp,etq,arbol->hijos[0]);

        } else if (etiqueta=="VALOR"){
            return generarCodigo3D(tmp,etq,arbol->hijos[0]);

        } else if (etiqueta == "EXPLOG"){
            tipo = "bool";
            QString Vactual = "";
            QString Factual = "";
            QString codigo = "";
            if (arbol->cantHijos==3){
                QString signo = arbol->hijos[1]->Etiqueta();
                if(signo == "||"){
                    generarCodigo3D(tmp,etq,arbol->hijos[0]);
                    Vactual = eV;
                    escribir(eF+":");
                    generarCodigo3D(tmp,etq,arbol->hijos[2]);
                    if(Vactual!=""){Vactual = Vactual+":"+'\n'+eV;}
                    eV = Vactual;
                } else if(signo == "&&"){
                    generarCodigo3D(tmp,etq,arbol->hijos[0]);
                    Factual = eF;
                    escribir(eV+":");
                    generarCodigo3D(tmp,etq,arbol->hijos[2]);
                    if(Factual!=""){Factual = Factual+":"+'\n'+eF;}
                    eF = Factual;
                }
            } else {
                generarCodigo3D(tmp,etq,arbol->hijos[1]);
                Vactual = eV;
                Factual = eF;
                eV = Factual;
                eF = Vactual;
            }


        } else if (etiqueta == "EXPRESION"){
            tipo = "bool";
            eV = generaETQ();
            eF = generaETQ();
            QString codigo = "if ("+generarCodigo3D(tmp,etq,arbol->hijos[0])+arbol->hijos[1]->Etiqueta()+generarCodigo3D(tmp,etq,arbol->hijos[2])+") goto "+eV+";";
            escribir(codigo);
            codigo = "goto "+eF+";";
            escribir(codigo);

        } else if (etiqueta == "EXPMAT"){
            tipo = "entero";
            QString etIzq = generarCodigo3D(tmp, etq, arbol->hijos[0]);
            QString etDer = generarCodigo3D(tmp, etq, arbol->hijos[2]);
            QString temporal = generaTmp();
            QString codigo = temporal + "=" + etIzq + arbol->hijos[1]->Etiqueta() + etDer +";";
            escribir(codigo);
            return temporal;

        } else if (etiqueta == "CADENA"){
            tipo = "cadena";
            QString cadena = arbol->hijos[0]->Etiqueta();
            QString temporal = generaTmp();
            escribir(temporal+"=ptrH;");
            QString temp ="";
            int cont = 0;
            for(int i = 0; i<cadena.length(); i++){
                temp = generaTmp();
                QChar c = cadena.at(i);
                escribir(temp+"="+temporal+"+"+QString::number(i)+";");
                escribir("Heap["+temp+"]="+QString::number(c.toLatin1())+";");
                cont = i+1;
            }
            temp = generaTmp();
            escribir(temp+"="+temporal+"+"+QString::number(cont)+";");
            escribir("Heap["+temp+"]=10;");
            escribir("ptrH=ptrH+"+QString::number(cont+1)+";");
            return temporal;
        } else if (etiqueta == "CHAR"){
            tipo = "caracter";
            QString valor = arbol->hijos[0]->Etiqueta();
            QChar c = valor.at(1);
            QString temporal = generaTmp();
            escribir(temporal+"="+QString::number(c.toLatin1())+";");
            return temporal;
        } else if (etiqueta == "ID"){
            QString id = arbol->hijos[0]->Etiqueta();
            Simbolo s;

            if (tabla.existeSimbolo(metodoActual+"_"+id)){
                s = tabla.getSimbolo(metodoActual+"_"+id);
                tipo = s.tipo;
                QString tmp = generaTmp();
                escribir(tmp+"=ptr+"+QString::number(s.posicion)+";");
                QString temporal = generaTmp();
                escribir(temporal+"=Stack["+tmp+"];");
                return temporal;
            }

            else if(tabla.existeSimbolo(ambito+"_"+id)){
                s = tabla.getSimbolo(ambito+"_"+id);
                tipo = s.tipo;
                QString tmp = generaTmp();
                escribir(tmp+"=ptr+"+QString::number(s.posicion)+";");
                QString temporal = generaTmp();
                escribir(temporal+"=Stack["+tmp+"];");
                return temporal;
            } else if (tabla.existeSimbolo(idClase+"_"+id)){
                s = tabla.getSimbolo(idClase+"_"+id);
                tipo = s.tipo;
                QString tmp = generaTmp();
                escribir(tmp+"=ptr+0;");
                QString temp2 = generaTmp();
                escribir(temp2+"=Stack["+tmp+"];");
                escribir(tmp+"="+temp2+"+"+QString::number(s.posicion)+";");
                QString temporal = generaTmp();
                escribir(temporal+"=Heap["+tmp+"];");
                return temporal;
            } else if (tabla.existeSimbolo(ambitotmp+"_"+id) && cicloIf){
                s = tabla.getSimbolo(ambitotmp+"_"+id);
                tipo = s.tipo;
                QString tmp = generaTmp();
                escribir(tmp+"=ptr+"+QString::number(s.posicion)+";");
                QString temporal = generaTmp();
                escribir(temporal+"=Stack["+tmp+"];");
                return temporal;
            }
            else {
                NoExisteSimbolo(id,"");
                return "";
            }

        } else if (etiqueta == "NUM"){
            tipo = "entero";
            QString temporal = generaTmp();
            escribir(temporal+"="+arbol->hijos[0]->Etiqueta()+";");
            return temporal;

        } else if (etiqueta == "BOOL"){
            tipo = "bool";
            QString temporal = generaTmp();
            if (arbol->hijos[0]->Etiqueta()=="true"){
                escribir(temporal+"=1;");
                return temporal;
            } else if (arbol->hijos[0]->Etiqueta()=="false"){
                escribir(temporal+"=0;");
                return temporal;
            }
        } else if (etiqueta == "OPSIMP"){
            tipo = "entero";
            QString id = arbol->hijos[0]->hijos[0]->Etiqueta();
            QString nombre = ambito+"_"+id;
            if(tabla.existeSimbolo(nombre)){
                Simbolo s = tabla.getSimbolo(nombre);
                if (s.tipo == tipo){
                    QString tmpPos = generaTmp();
                    escribir(tmpPos+"=ptr+"+QString::number(s.posicion)+";");
                    QString temp1 = generaTmp();
                    escribir(temp1+"=Stack["+tmpPos+"];");
                    QString temp2 = generaTmp();
                    if(arbol->hijos[1]->Etiqueta()=="++"){
                        escribir(temp2+"="+temp1+"+1;");
                    } else if(arbol->hijos[1]->Etiqueta()=="--"){
                        escribir(temp2+"="+temp1+"-1;");
                    }
                    else if(arbol->hijos[1]->Etiqueta()=="**"){
                        escribir(temp2+"="+temp1+"*2;");
                    }
                    else if(arbol->hijos[1]->Etiqueta()=="##"){
                        escribir(temp2+"="+temp1+"/2;");
                    }
                    escribir("Stack["+tmpPos+"]="+temp2+";");
                    return temp2;
                } else {
                    ErrorDeTipos(id,tipo);
                }
            } else {
                NoExisteSimbolo(id,ambito);
                return "";
            }

        } else if (etiqueta == "DECMETODO"){
            tamanoMetodo = 0;
            ambitoid = 0;
            params = "";
            QString acceso = "";
            QString id = "";
            QString tipo = "";
            QString ambitotemp = ambito;
            int posiciontemp = posicion;
            posicion = 0;
            for (int i = 0; i<arbol->cantHijos; i++){
                if(arbol->hijos[i]->Etiqueta()=="TIPO_ACCESO"){
                    acceso = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if(arbol->hijos[i]->Etiqueta() == "ID"){
                    id = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if(arbol->hijos[i]->Etiqueta() == "TIPO"){
                    tipo = arbol->hijos[i]->hijos[0]->Etiqueta();
                } else if (arbol-> hijos[i]->Etiqueta()=="PARAMLIST"){
                    llenarTabla(arbol->hijos[i]);
                }
            }

            //Genero el nombre del metodo
            QString nombre = ambito+"_"+id+params;

            //Cambio el ambito
            ambito = nombre;
            metodoActual = nombre;
            nombre += "()";

            //Escribo el nombre del metodo

            if(id=="Principal"){
                escribir("int main(){");
            } else {
                this->decMetodos+="void "+nombre+";|";
                escribir("void " + nombre + "{");
            }


            // Cambio de ambito
            nivel++;

            Simbolo s = tabla.getSimbolo(nombre);
            if(s.rol=="constructor"){

                // genera código de 3d de las instrucciones del constructor
                //QString tmp1 = generaTmp();
                //Simbolo s = tabla.getSimbolo(ambito+"_this");
                //escribir(tmp1+"=ptr+"+QString::number(s.posicion)+";");
                //QString tmp2 = generaTmp();
                //escribir(tmp2+"=Stack["+tmp1+"];");
                //tmp1 = generaTmp();
                //escribir(tmp1+"="+tmp2+"+"+QString::number(s.posicion)+";");
                generarCodigo3D(tmp,etq,arbol->hijos[arbol->cantHijos-1]);

            } else {

                // genera código 3d de las instrucciones del metodo
                generarCodigo3D(tmp, etq, arbol->hijos[arbol->cantHijos-1]);
            }

            // Vuelvo al ámbito anterior
            nivel--;
            ambito = ambitotemp;
            posicion = posiciontemp;

            if(id=="Principal"){
                escribir("return 0;");
                escribir("}");
            } else {
                if(etRetorno!=""){
                    escribir(etRetorno+":");
                    escribir(";");
                    etRetorno="";
                }
                escribir("}");
            }

        } else if (etiqueta == "INSTRUCCIONES"){
            for (int i = 0; i<arbol->cantHijos; i++){ generarCodigo3D(tmp,etq, arbol->hijos[i]);}
        } else if (etiqueta == "SENTENCIAS") {
            generarCodigo3D(tmp,etq,arbol->hijos[0]);
        } else if (etiqueta == "DECVAR"){
            generarDecVar(tmp,etq,arbol);
        } else if (etiqueta == "VAR_ASIG"){
            generarAsignacion(tmp,etq,arbol);
        } else if (etiqueta == "CICLO"){
            QString etInicio = generaETQ();
            escribir(etInicio+":");
            generarCodigo3D(tmp,etq,arbol->hijos[0]);
            escribir(eV+":");
            generarCodigo3D(tmp,etq,arbol->hijos[1]);
            escribir("goto "+etInicio+";");
            escribir(eF+":");
        } else if (etiqueta == "IF"){
            generarCodigo3D(tmp,etq,arbol->hijos[0]);
            ambitotmp = ambito;
            ambito+="_if"+QString::number(ambitoid);
            ambitoid++;
            int ambitoidtmp = ambitoid;
            if(arbol->cantHijos == 2){
                ambitoid = 0;
                nivel++;
                cicloIf = true;
                escribir(eV+":");
                generarCodigo3D(tmp,etq,arbol->hijos[1]);
                nivel--;
                cicloIf = false;
                escribir(eF+":");
            }


            else if (arbol->cantHijos == 3){
                escribir(eV+":");
                generarCodigo3D(tmp,etq,arbol->hijos[1]);
                eSalida = generaETQ();
                escribir("goto "+eSalida+";");
                escribir(eF+":");
                ambitoid = 0;
                nivel++;
                cicloIf = true;
                generarCodigo3D(tmp,etq,arbol->hijos[2]);
                nivel--;
                cicloIf = false;
                escribir(eSalida+":");
            }

            else if (arbol->cantHijos == 4){
                escribir(eV+":");
                generarCodigo3D(tmp,etq,arbol->hijos[1]);
                eSalida = generaETQ();
                escribir("goto "+eSalida+";");
                escribir(eF+":");
                ambitoid = 0;
                nivel++;
                cicloIf = true;
                generarCodigo3D(tmp,etq,arbol->hijos[2]);
                nivel--;
                ambitoid = 0;
                nivel++;
                generarCodigo3D(tmp,etq,arbol->hijos[3]);
                nivel--;
                cicloIf = false;
                escribir(eSalida+":");
            }

            ambitoid = ambitoidtmp;
            ambito = ambitotmp;

        } else if (etiqueta == "ELSEIFLIST"){
            int i = 0;
            while(arbol->hijos[i]!=NULL){
                generarCodigo3D(tmp, etq, arbol->hijos[i]);
                i++;
            }
        }

        else if (etiqueta == "ELSEIF"){
            generarCodigo3D(tmp,etq,arbol->hijos[0]);
            ambitotmp = ambito;
            ambito+="_elseif"+QString::number(ambitoid);
            ambitoid++;
            int ambitoidtmp = ambitoid;

            ambitoid = 0;
            nivel++;
            escribir(eV+":");
            generarCodigo3D(tmp,etq,arbol->hijos[1]);
            escribir("goto "+eSalida+";");
            escribir(eF+":");
            nivel--;

            ambito = ambitotmp;
            ambitoid = ambitoidtmp;
        }
        else if (etiqueta == "ELSE"){
            ambitotmp = ambito;
            ambito+="_else";
            generarCodigo3D(tmp,etq,arbol->hijos[0]);
            ambito = ambitotmp;
        }

        else if (etiqueta == "COND"){
            generarCodigo3D(tmp, etq,arbol->hijos[0]);
        }

        else if (etiqueta == "IMPRIMIR"){
            QString tipo = arbol->hijos[0]->hijos[0]->Etiqueta();
            if(tipo == "CADENA"){
                QString temporal = generarCodigo3D(tmp, etq, arbol->hijos[0]->hijos[0]);
                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                QString temp = generaTmp();

                //paso de parametro
                escribir(temp+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"="+temp+"+0;");
                escribir("Stack["+temp2+"]="+temporal+";");

                //llamada al metodo
                escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                escribir("imprimir_cadena();");
                escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");
            }
            else if (tipo == "ID"){

                QString temporal = generarCodigo3D(tmp, etq, arbol->hijos[0]->hijos[0]);
                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                QString temp = generaTmp();

                //paso de parametro
                escribir(temp+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"="+temp+"+0;");
                escribir("Stack["+temp2+"]="+temporal+";");

                 //llamada al metodo
                if(this->tipo=="cadena"){
                    escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                    escribir("imprimir_cadena();");
                    escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");

                } else if(this->tipo=="entero" || this->tipo == "bool"){
                    escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                    escribir("imprimir_num();");
                    escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");

                } else if (this->tipo == "caracter"){
                    escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                    escribir("imprimir_caracter();");
                    escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");
                }

            } else if (tipo == "CHAR"){
                QString temporal = generarCodigo3D(tmp, etq, arbol->hijos[0]->hijos[0]);
                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                QString temp = generaTmp();

                //paso de parametro
                escribir(temp+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"="+temp+"+0;");
                escribir("Stack["+temp2+"]="+temporal+";");
                escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                escribir("imprimir_caracter();");
                escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");
            }


            else {
                QString temporal = generarCodigo3D(tmp, etq, arbol->hijos[0]->hijos[0]);
                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                QString temp = generaTmp();

                //paso de parametro
                escribir(temp+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"="+temp+"+0;");
                escribir("Stack["+temp2+"]="+temporal+";");
                escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                if(this->tipo == "entero" || this->tipo == "bool"){
                    escribir("imprimir_num();");
                } else if (this->tipo == "cadena"){
                    escribir("imprimir_cadena();");
                } else if (this->tipo == "caracter"){
                    escribir("imprimir_caracter();");
                }

                escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");
            }

        } else if (etiqueta == "FUNCALL"){
            params = "";
            QString id = arbol->hijos[0]->Etiqueta();

            if(id == "IMPRIMIR"){
                generarCodigo3D(tmp,etq,arbol->hijos[0]);
                return 0;

            } else if (id == "ACCESOMETODO"){
                generarCodigo3D(tmp,etq,arbol->hijos[0]);
                return 0;
            }

            QString nombre = idClase+"_"+id;
            params = getParamsTipo(params,arbol->hijos[1]);
            if(params!=""){nombre+=params;}
            nombre+="()";
            if(tabla.existeSimbolo(nombre)){
                Simbolo metodo = tabla.getSimbolo(nombre);
                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                int size = metodoPadre.tamano;

                //envío del this
                QString tmp1 = generaTmp();
                escribir(tmp1+"=ptr+0;");
                QString tmp2 = generaTmp();
                escribir(tmp2+"=Stack["+tmp1+"];");
                QString tmp3 = generaTmp();
                escribir(tmp3+"=ptr+"+QString::number(size)+";");
                QString tmp4 = generaTmp();
                escribir(tmp4+"="+tmp3+"+0;");
                escribir("Stack["+tmp4+"]="+tmp2+";");

                //envío de parametros
                if(params!=""){
                    QString nombre = idClase+"_"+id+params;
                    int cont = 0;
                    generarParametros(tmp3,nombre,arbol->hijos[1],cont);
                }

                //Llamada al método
                escribir("ptr=ptr+"+QString::number(size)+";");
                escribir(nombre+";");
                escribir("ptr=ptr-"+QString::number(size)+";");



            } else {NoExisteSimbolo(nombre,idClase);}

        } else if (etiqueta == "MODIFATRIBUTO") {
            QString objetoId = arbol->hijos[0]->hijos[0]->Etiqueta();

            if(objetoId=="este"){
                QString id = arbol->hijos[0]->hijos[1]->Etiqueta();
                QString nombre = idClase+"_"+id;
                if(tabla.existeSimbolo(nombre)){
                    QString temporal1 = generaTmp();
                    escribir(temporal1+"=ptr+0;");
                    QString temporal2 = generaTmp();
                    escribir(temporal2+"=Stack["+temporal1+"];");
                    Simbolo s = tabla.getSimbolo(nombre);
                    QString temp = generarCodigo3D(tmp,etq,arbol->hijos[1]);
                    QString posHeap = QString::number(s.posicion);
                    QString ptrHeap = generaTmp();
                    escribir(ptrHeap+"="+temporal2+"+"+posHeap+";");
                    escribir("Heap["+ptrHeap+"]="+temp+";");
                } else {NoExisteSimbolo(id,idClase);}
            } else {

                QString atributoId = arbol->hijos[0]->hijos[1]->Etiqueta();

                QString posHeap ="";

                Simbolo objeto;
                Simbolo atributo;

                if(tabla.existeSimbolo(metodoActual+"_"+objetoId)){
                    objeto = tabla.getSimbolo(metodoActual+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambito+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambito+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambitotmp+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambitotmp+"_"+objetoId);
                } else if(tabla.existeSimbolo(idClase+"_"+objetoId)){
                    objeto = tabla.getSimbolo(idClase+"_"+objetoId);
                } else {
                    NoExisteSimbolo(objetoId,metodoActual);
                    return "-1";
                }

                QString tipoObjeto = objeto.tipo;

                if(tabla.existeSimbolo(tipoObjeto+"_"+atributoId)){
                    atributo = tabla.getSimbolo(tipoObjeto+"_"+atributoId);
                    if(atributo.visibilidad=="para_todos"){
                        tipo = atributo.tipo;
                    } else {
                        ErrorVisibilidad(atributoId);
                        return "-1";
                    }
                } else {
                    NoExisteSimbolo(atributoId,tipoObjeto);
                    return "-1";
                }

                if(objeto.rol == "atributo"){
                    QString temp1 = generaTmp();
                    escribir(temp1+"=ptrH+"+QString::number(objeto.posicion)+";");
                    QString temp2 = generaTmp();
                    escribir(temp2+"=Heap["+temp1+"];");
                    posHeap = temp2;
                } else if(objeto.rol == "variable"){
                    QString temp1 = generaTmp();
                    escribir(temp1+"=ptr+"+QString::number(objeto.posicion)+";");
                    QString temp2 = generaTmp();
                    escribir(temp2+"=Stack["+temp1+"];");
                    posHeap = temp2;
                }

                QString temp1 = generaTmp();
                escribir(temp1+"="+posHeap+"+"+QString::number(atributo.posicion)+";");

                QString tempValor = generarCodigo3D(tmp,etq,arbol->hijos[1]);

                escribir("Heap["+temp1+"]="+tempValor+";");

            }



        } else if(etiqueta == "RETORNO"){
            QString nombreMetodo = ambito+"()";
            Simbolo metodo = tabla.getSimbolo(nombreMetodo);
            QString tipoReturn = metodo.tipo;
            if(tipoReturn != "ninguno"){
                QString ret = arbol->hijos[0]->Etiqueta();
                QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[0]);
                if(tipoReturn == tipo){
                    QString temp = generaTmp();
                    etRetorno = generaETQ();
                    escribir(temp+"=ptr+"+QString::number(metodo.tamano-1)+";");
                    escribir("Stack["+temp+"]="+temporal+";");
                    escribir("goto "+etRetorno+";");
                } else {
                    ErrorReturn(nombreMetodo,tipoReturn);
                }
            } else {
                ErrorReturn(nombreMetodo,"ninguno");
            }
        } else if(etiqueta == "ACCESOATRIBUTO"){
            QString objetoId = arbol->hijos[0]->Etiqueta();
            QString atributoId = arbol->hijos[1]->Etiqueta();

            if(objetoId == "este"){
                QString posHeap = "";
                Simbolo atributo;

                if(tabla.existeSimbolo(idClase+"_"+atributoId)){
                    atributo = tabla.getSimbolo(idClase+"_"+atributoId);
                    tipo = atributo.tipo;
                } else {
                    NoExisteSimbolo(atributoId,idClase);
                    return "-1";
                }

                QString temp1 = generaTmp();
                escribir(temp1+"=ptr+0;");
                QString temp2 = generaTmp();
                escribir(temp2+"=Stack["+temp1+"];");
                temp1 = generaTmp();
                escribir(temp1+"="+temp2+"+"+QString::number(atributo.posicion)+";");
                temp2 = generaTmp();
                escribir(temp2+"=Heap["+temp1+"];");
                return temp2;


            } else {


                QString posHeap ="";

                Simbolo objeto;
                Simbolo atributo;

                if(tabla.existeSimbolo(metodoActual+"_"+objetoId)){
                    objeto = tabla.getSimbolo(metodoActual+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambito+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambito+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambitotmp+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambitotmp+"_"+objetoId);
                } else if(tabla.existeSimbolo(idClase+"_"+objetoId)){
                    objeto = tabla.getSimbolo(idClase+"_"+objetoId);
                } else {
                    NoExisteSimbolo(objetoId,metodoActual);
                    return "-1";
                }

                QString tipoObjeto = objeto.tipo;

                if(tabla.existeSimbolo(tipoObjeto+"_"+atributoId)){
                    atributo = tabla.getSimbolo(tipoObjeto+"_"+atributoId);
                    if(atributo.visibilidad=="para_todos"){
                        tipo = atributo.tipo;
                    } else {
                        ErrorVisibilidad(atributoId);
                        return "-1";
                    }
                } else {
                    NoExisteSimbolo(atributoId,tipoObjeto);
                    return "-1";
                }

                if(objeto.rol == "atributo"){
                    QString temp1 = generaTmp();
                    escribir(temp1+"=ptrH+"+QString::number(objeto.posicion)+";");
                    QString temp2 = generaTmp();
                    escribir(temp2+"=Heap["+temp1+"];");
                    posHeap = temp2;
                } else if(objeto.rol == "variable"){
                    QString temp1 = generaTmp();
                    escribir(temp1+"=ptr+"+QString::number(objeto.posicion)+";");
                    QString temp2 = generaTmp();
                    escribir(temp2+"=Stack["+temp1+"];");
                    posHeap = temp2;
                }

                QString temp1 = generaTmp();
                escribir(temp1+"="+posHeap+"+"+QString::number(atributo.posicion)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"=Heap["+temp1+"];");
                return temp2;
            }



        }

        else if (etiqueta == "ACCESOMETODO"){
            QString objetoId = arbol->hijos[0]->Etiqueta();

            QString metodoId = arbol->hijos[1]->Etiqueta();

            QString posHeap ="";

            QString params="";

            Simbolo objeto;
            Simbolo metodo;

            if(tabla.existeSimbolo(metodoActual+"_"+objetoId)){
                objeto = tabla.getSimbolo(metodoActual+"_"+objetoId);
            } else if(tabla.existeSimbolo(ambito+"_"+objetoId)){
                objeto = tabla.getSimbolo(ambito+"_"+objetoId);
            } else if(tabla.existeSimbolo(ambitotmp+"_"+objetoId)){
                objeto = tabla.getSimbolo(ambitotmp+"_"+objetoId);
            } else if(tabla.existeSimbolo(idClase+"_"+objetoId)){
                objeto = tabla.getSimbolo(idClase+"_"+objetoId);
            } else {
                NoExisteSimbolo(objetoId,metodoActual);
                return "-1";
            }


            QString tipoObjeto = objeto.tipo;

            QString nombre = tipoObjeto+"_"+metodoId;

            params = getParamsTipo(params,arbol->hijos[2]);

            if (params!=""){
                nombre+=params;
            }


            if(tabla.existeSimbolo(nombre+"()")){
                metodo = tabla.getSimbolo(nombre+"()");
                if(metodo.visibilidad=="para_todos"){
                    tipo = metodo.tipo;
                } else {
                    ErrorVisibilidad(metodoId);
                    return "-1";
                }
            } else {
                NoExisteSimbolo(metodoId,tipoObjeto);
                return "-1";
            }

            Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");

            //Paso del this
            QString temp1 = generaTmp();
            escribir(temp1+"=ptr+"+QString::number(objeto.posicion)+";");
            QString temp2 = generaTmp();
            escribir(temp2+"=Stack["+temp1+"];"); // Obtenemos la posicion en el heap del this

            temp1 = generaTmp();
            escribir(temp1+"=ptr+"+QString::number(metodoPadre.tamano)+";");
            QString temp3 = generaTmp();
            escribir(temp3+"="+temp1+"+0;");
            escribir("Stack["+temp3+"]="+temp2+";"); // Pasamos el this


            // envío de parametros
            if(params!=""){
                int cont = 0;
                generarParametros(temp1,nombre,arbol->hijos[2],cont);
            }


            // Llamada al metodo
            escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
            escribir(metodo.nombre+";");
            escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");



        }
    }
    return "";

}

QString GeneradorDeCodigo::getParamsTipo(QString params, Nodo *arbol)
{
    if(arbol!=NULL){
        QString etiqueta = arbol->Etiqueta();
        if(etiqueta=="PARAMS"){
            for (int i = 0; i<arbol->cantHijos; i++){
                params = getParamsTipo(params,arbol->hijos[i]);
            }
        } else if (etiqueta == "VALOR"){
            QString tipo = arbol->hijos[0]->Etiqueta();
            if(tipo == "NUM"){
                params+="_entero";
            } else if (tipo == "CADENA"){
                params+= "_cadena";
            } else if (tipo == "CARACTER"){
                params+= "_caracter";
            } else if (tipo == "ID"){
                QString id = arbol->hijos[0]->hijos[0]->Etiqueta();
                QString nombre = ambito+"_"+id;
                if(tabla.existeSimbolo(nombre)){
                    Simbolo s = tabla.getSimbolo(nombre);
                    params+="_"+s.tipo;
                } else {NoExisteSimbolo(nombre,ambito);}
            }
        }
    }
    return params;
}

QString GeneradorDeCodigo::generaTmp()
{

    QString temporal = "t"+QString::number(tmp);
    tmp++;
    return temporal;
}

QString GeneradorDeCodigo::generaETQ()
{
    QString etiqueta = "L"+QString::number(etq);
    etq++;
    return etiqueta;
}

QString GeneradorDeCodigo::generarAsignacion(int &tmp, int &etq, Nodo* arbol){
    QString id = arbol->hijos[0]->Etiqueta();
    Simbolo s;
    if(tabla.existeSimbolo(metodoActual+"_"+id)){
        s = tabla.getSimbolo(metodoActual+"_"+id);
    } else if (tabla.existeSimbolo(ambitotmp+"_"+id) && cicloIf){
        s = tabla.getSimbolo(ambitotmp+"_"+id);
    } else if (tabla.existeSimbolo(ambito+"_"+id)){
        s = tabla.getSimbolo(ambito+"_"+id);
    } else if (tabla.existeSimbolo(idClase+"_"+id)){
        s = tabla.getSimbolo(idClase+"_"+id);
    } else {
        NoExisteSimbolo(id,ambito);
        s.nombre = "";
    }

    if(s.nombre != ""){
        QString temp;
        if(arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta() == "EXPMAT"){
            if(s.tipo == "entero"){

                temp = generaTmp();
                escribir(temp + "=ptr+"+QString::number(s.posicion)+";");
                QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[1]);
                escribir("Stack["+temp+"]="+temporal+";");

            } else {
                ErrorDeTipos(id,"entero");
            }

        } else if(arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta() == "EXPRESION"){

            if(s.tipo == "bool"){
                QString tmpVariable = generaTmp();
                escribir(tmpVariable + "=ptr+"+QString::number(s.posicion)+";");
                generarCodigo3D(tmp,etq,arbol->hijos[1]);
                escribir(eV+":");
                escribir("Stack["+tmpVariable+"]=1;");
                eSalida = generaETQ();
                escribir("goto "+eSalida+";");
                escribir(eF+":");
                escribir("Stack["+tmpVariable+"]=0;");
                escribir(eSalida+":");
            } else {
                ErrorDeTipos(id,"bool");
            }
        } else if(arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta() == "EXPLOG"){
            if (s.tipo == "bool"){

                QString tmpVariable = generaTmp();
                escribir(tmpVariable + "=ptr+"+QString::number(s.posicion)+";");

                generarCodigo3D(tmp,etq,arbol->hijos[1]);
                escribir(eV+":");
                escribir("Stack["+tmpVariable+"]=1;");
                eSalida = generaETQ();
                escribir("goto "+eSalida+";");
                escribir(eF+":");
                escribir("Stack["+tmpVariable+"]=0;");
                escribir(eSalida+":");
            } else {
                ErrorDeTipos(id,"bool");
            }
        }
            else if (arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta()=="CADENA"){
                if(s.tipo == "cadena"){

                    temp = generaTmp();
                    escribir(temp+"=ptr+"+QString::number(s.posicion)+";");

                    QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[1]);

                    escribir("Stack["+temp+"]="+temporal+";");
                } else {
                    ErrorDeTipos(id,"cadena");
                }
        }
        else if (arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta()=="FUNCALL"){
            Nodo* arbolNuevo = arbol->hijos[1]->hijos[0]->hijos[0];
            params = "";
            QString id = arbolNuevo->hijos[0]->Etiqueta();
            if(id=="ACCESOMETODO"){
                arbolNuevo = arbolNuevo->hijos[0];

                QString objetoId = arbolNuevo->hijos[0]->Etiqueta();

                QString metodoId = arbolNuevo->hijos[1]->Etiqueta();

                QString posHeap ="";

                QString params="";

                Simbolo objeto;
                Simbolo metodo;

                if(tabla.existeSimbolo(metodoActual+"_"+objetoId)){
                    objeto = tabla.getSimbolo(metodoActual+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambito+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambito+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambitotmp+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambitotmp+"_"+objetoId);
                } else if(tabla.existeSimbolo(idClase+"_"+objetoId)){
                    objeto = tabla.getSimbolo(idClase+"_"+objetoId);
                } else {
                    NoExisteSimbolo(objetoId,metodoActual);
                    return "-1";
                }


                QString tipoObjeto = objeto.tipo;

                QString nombre = tipoObjeto+"_"+metodoId;

                params = getParamsTipo(params,arbolNuevo->hijos[2]);

                if (params!=""){
                    nombre+=params;
                }


                if(tabla.existeSimbolo(nombre+"()")){
                    metodo = tabla.getSimbolo(nombre+"()");
                    if(metodo.visibilidad=="para_todos"){
                        tipo = metodo.tipo;
                    } else {
                        ErrorVisibilidad(metodoId);
                        return "-1";
                    }
                } else {
                    NoExisteSimbolo(metodoId,tipoObjeto);
                    return "-1";
                }

                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");

                //Paso del this
                QString temp1 = generaTmp();
                escribir(temp1+"=ptr+"+QString::number(objeto.posicion)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"=Stack["+temp1+"];"); // Obtenemos la posicion en el heap del this

                temp1 = generaTmp();
                escribir(temp1+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                QString temp3 = generaTmp();
                escribir(temp3+"="+temp1+"+0;");
                escribir("Stack["+temp3+"]="+temp2+";"); // Pasamos el this


                // envío de parametros
                if(params!=""){
                    int cont = 0;
                    generarParametros(temp1,nombre,arbolNuevo->hijos[2],cont);
                }


                // Llamada al metodo
                escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                escribir(metodo.nombre+";");
                escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");

                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                temp1 = generaTmp();
                escribir(temp1+"="+temp+"+"+QString::number(metodo.tamano-1)+";");
                temp2 = generaTmp();
                escribir(temp2+"=Stack["+temp1+"];");
                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(s.posicion)+";");
                escribir("Stack["+temp+"]="+temp2+";");


            } else {
                QString nombre = idClase+"_"+id;
                params = getParamsTipo(params,arbolNuevo->hijos[1]);
                if(params!=""){nombre+=params;}
                nombre+="()";
                if(tabla.existeSimbolo(nombre)){
                    Simbolo metodo = tabla.getSimbolo(nombre);
                    Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                    if(s.tipo == metodo.tipo){
                        QString temporal;
                        int size = metodoPadre.tamano;

                        QString temporalVariable = generaTmp();
                        escribir(temporalVariable+"=ptr+"+QString::number(s.posicion)+";");

                        //enviamos el this
                        QString tmp1 = generaTmp();
                        escribir(tmp1+"=ptr+0;");
                        QString tmp2 = generaTmp();
                        escribir(tmp2+"=Stack["+tmp1+"];");
                        QString tmp3 = generaTmp();
                        escribir(tmp3+"=ptr+"+QString::number(size)+";");
                        QString tmp4 = generaTmp();
                        escribir(tmp4+"="+tmp3+"+0;");
                        escribir("Stack["+tmp4+"]="+tmp2+";");


                        //envío de parametros
                        if(params!=""){
                            QString nombre = idClase+"_"+id+params;
                            int cont = 0;
                            generarParametros(tmp3,nombre,arbolNuevo->hijos[1],cont);
                        }


                        escribir("ptr=ptr+"+QString::number(size)+";");
                        escribir(nombre+";");
                        escribir("ptr=ptr-"+QString::number(size)+";");
                        temporal = generaTmp();
                        escribir (temporal+"=ptr+"+QString::number(size)+";");
                        temp  = generaTmp();
                        escribir(temp+"="+temporal+"+"+QString::number(metodo.tamano-1)+";");
                        temporal = generaTmp();
                        escribir(temporal+"=Stack["+temp+"];");

                        escribir("Stack["+temporalVariable+"]="+temporal+";");
                    } else {
                        ErrorDeTipos(id,metodo.tipo);
                    }

                } else {NoExisteSimbolo(nombre,idClase);}
            }
        }


        else if (arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta()=="CHAR"){
            if(s.tipo == "caracter"){

                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(s.posicion)+";");

                QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[1]);

                escribir("Stack["+temp+"]="+temporal+";");
            } else {
                ErrorDeTipos(id,"caracter");
            }
        }

        else if(arbol->hijos[1]->hijos[0]->Etiqueta() == "INSTANCIAR"){
            QString tipo = s.tipo;

            if(tabla.existeSimbolo(tipo)){
                Simbolo clase = tabla.getSimbolo(tipo);
                QString temporalVariable = generaTmp();
                QString nombreConstructor = arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta();
                if(nombreConstructor == s.tipo){
                    escribir(temporalVariable+"=ptr+"+QString::number(s.posicion)+";");
                    QString temporalHeap = generaTmp();
                    escribir(temporalHeap+"=ptrH;");
                    escribir("ptrH=ptrH+"+QString::number(clase.tamano)+";");
                    escribir("Stack["+temporalVariable+"]="+temporalHeap+";");


                    // Llamada al constructor;
                    QString nombreConstructor = arbol->hijos[1]->hijos[0]->hijos[0]->Etiqueta();
                    QString nombreSimbolo = tipo+"_"+nombreConstructor;
                    QString params = "";
                    if(arbol->hijos[1]->hijos[0]->hijos[1]!=NULL){

                        params = getParamsTipo(params,arbol->hijos[1]->hijos[0]->hijos[1]);
                        nombreSimbolo += params;
                    }
                    if(tabla.existeSimbolo(nombreSimbolo+"()")){
                        Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");

                        //paso del this
                        QString temporal = generaTmp();
                        escribir(temporal+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                        QString temp2 = generaTmp();
                        escribir(temp2+"="+temporal+"+0;");
                        escribir("Stack["+temp2+"]="+temporalHeap+";");

                        //paso de parametros
                        if(params!=""){
                            int cont = 0;
                            generarParametros(temporal,
                                              nombreSimbolo,
                                              arbol->hijos[1]->hijos[0]->hijos[1],cont);


                        }

                        escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                        escribir(nombreSimbolo+"();");
                        escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");

                    } else {
                        NoExisteConstructor(nombreSimbolo);
                    }
                } else {
                    ErrorDeTipos(id,nombreConstructor);
                }

            } else {
                ErrorTipoIndefinido(tipo);
            }



        }


        else {
            temp = generaTmp();
            escribir(temp + "=ptr+"+QString::number(s.posicion)+";");
            QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[1]);
            if (s.tipo == tipo){
                escribir("Stack["+temp+"]="+temporal+";");
            } else {
                ErrorDeTipos(id,tipo);
            }

        }

    }
    return "";


}

QString GeneradorDeCodigo::generarDecVar(int &tmp, int &etq, Nodo *arbol){
    if(arbol->cantHijos == 3){
        QString id = arbol->hijos[0]->hijos[0]->Etiqueta();
        QString nombre = ambito+"_"+id;
        Simbolo s = tabla.getSimbolo(nombre);
        QString temp;

        if(arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta() == "EXPMAT"){
            if (s.tipo == "entero"){
                temp = generaTmp();
                escribir(temp + "=ptr+"+QString::number(s.posicion)+";");

                QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[2]);

                escribir("Stack["+temp+"]="+temporal+";");
            } else {
                ErrorDeTipos(id,"entero");
            }

        }

        else if(arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta() == "EXPRESION"){
            if(s.tipo == "bool"){
                QString tmpVariable = generaTmp();
                escribir(tmpVariable + "=ptr+"+QString::number(s.posicion)+";");

                generarCodigo3D(tmp,etq,arbol->hijos[2]);
                escribir(eV+":");              
                escribir("Stack["+tmpVariable+"]=1;");
                eSalida = generaETQ();
                escribir("goto "+eSalida+";");
                escribir(eF+":");
                escribir("Stack["+tmpVariable+"]=0;");
                escribir(eSalida+":");
            } else {
                ErrorDeTipos(id,"bool");
            }
        }

        else if(arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta() == "EXPLOG"){
            if(s.tipo == "bool"){
                QString tmpVariable = generaTmp();
                escribir(tmpVariable + "=ptr+"+QString::number(s.posicion)+";");
                generarCodigo3D(tmp,etq,arbol->hijos[2]);
                escribir(eV+":");
                escribir("Stack["+tmpVariable+"]=1;");
                eSalida = generaETQ();
                escribir("goto "+eSalida+";");
                escribir(eF+":");
                escribir("Stack["+tmpVariable+"]=0;");
                escribir(eSalida+":");
            } else {
                ErrorDeTipos(id,"bool");
            }

        }

        else if (arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta() == "CADENA"){
            if(s.tipo == "cadena"){
                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(s.posicion)+";");
                QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[2]);

                escribir("Stack["+temp+"]="+temporal+";");
            } else {
                ErrorDeTipos(id,"cadena");
            }
        }

        else if (arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta() == "CARACTER"){
            if(s.tipo == "caracter"){
                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(s.posicion)+";");
                QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[2]);

                escribir("Stack["+temp+"]="+temporal+";");
            } else {
                ErrorDeTipos(id,"caracter");
            }
        }

        else if (arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta()=="FUNCALL"){
            Nodo* arbolNuevo = arbol->hijos[2]->hijos[0]->hijos[0];
            params = "";
            QString id = arbolNuevo->hijos[0]->Etiqueta();


            if(id=="ACCESOMETODO"){
                arbolNuevo = arbolNuevo->hijos[0];

                QString objetoId = arbolNuevo->hijos[0]->Etiqueta();

                QString metodoId = arbolNuevo->hijos[1]->Etiqueta();

                QString posHeap ="";

                QString params="";

                Simbolo objeto;
                Simbolo metodo;

                if(tabla.existeSimbolo(metodoActual+"_"+objetoId)){
                    objeto = tabla.getSimbolo(metodoActual+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambito+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambito+"_"+objetoId);
                } else if(tabla.existeSimbolo(ambitotmp+"_"+objetoId)){
                    objeto = tabla.getSimbolo(ambitotmp+"_"+objetoId);
                } else if(tabla.existeSimbolo(idClase+"_"+objetoId)){
                    objeto = tabla.getSimbolo(idClase+"_"+objetoId);
                } else {
                    NoExisteSimbolo(objetoId,metodoActual);
                    return "-1";
                }


                QString tipoObjeto = objeto.tipo;

                QString nombre = tipoObjeto+"_"+metodoId;

                params = getParamsTipo(params,arbolNuevo->hijos[2]);

                if (params!=""){
                    nombre+=params;
                }


                if(tabla.existeSimbolo(nombre+"()")){
                    metodo = tabla.getSimbolo(nombre+"()");
                    if(metodo.visibilidad=="para_todos"){
                        tipo = metodo.tipo;
                    } else {
                        ErrorVisibilidad(metodoId);
                        return "-1";
                    }
                } else {
                    NoExisteSimbolo(metodoId,tipoObjeto);
                    return "-1";
                }

                Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");

                //Paso del this
                QString temp1 = generaTmp();
                escribir(temp1+"=ptr+"+QString::number(objeto.posicion)+";");
                QString temp2 = generaTmp();
                escribir(temp2+"=Stack["+temp1+"];"); // Obtenemos la posicion en el heap del this

                temp1 = generaTmp();
                escribir(temp1+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                QString temp3 = generaTmp();
                escribir(temp3+"="+temp1+"+0;");
                escribir("Stack["+temp3+"]="+temp2+";"); // Pasamos el this


                // envío de parametros
                if(params!=""){
                    int cont = 0;
                    generarParametros(temp1,nombre,arbolNuevo->hijos[2],cont);
                }


                // Llamada al metodo
                escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                escribir(metodo.nombre+";");
                escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");

                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                temp1 = generaTmp();
                escribir(temp1+"="+temp+"+"+QString::number(metodo.tamano-1)+";");
                temp2 = generaTmp();
                escribir(temp2+"=Stack["+temp1+"];");
                temp = generaTmp();
                escribir(temp+"=ptr+"+QString::number(s.posicion)+";");
                escribir("Stack["+temp+"]="+temp2+";");


            } else {

                QString nombre = idClase+"_"+id;
                params = getParamsTipo(params,arbolNuevo->hijos[1]);
                if(params!=""){nombre+=params;}
                nombre+="()";
                if(tabla.existeSimbolo(nombre)){
                    Simbolo metodo = tabla.getSimbolo(nombre);
                    Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");
                    if(s.tipo == metodo.tipo){
                        QString temporal;
                        int size = metodoPadre.tamano;

                        QString temporalVariable = generaTmp();
                        escribir(temporalVariable+"=ptr+"+QString::number(s.posicion)+";");

                        //enviamos el this
                        QString tmp1 = generaTmp();
                        escribir(tmp1+"=ptr+0;");
                        QString tmp2 = generaTmp();
                        escribir(tmp2+"=Stack["+tmp1+"];");
                        QString tmp3 = generaTmp();
                        escribir(tmp3+"=ptr+"+QString::number(size)+";");
                        QString tmp4 = generaTmp();
                        escribir(tmp4+"="+tmp3+"+0;");
                        escribir("Stack["+tmp4+"]="+tmp2+";");

                        //envío de parametros
                        if(params!=""){
                            QString nombre = idClase+"_"+id+params;
                            int cont = 0;
                            generarParametros(tmp3,nombre,arbolNuevo->hijos[1],cont);
                        }

                        escribir("ptr=ptr+"+QString::number(size)+";");
                        escribir(nombre+";");
                        escribir("ptr=ptr-"+QString::number(size)+";");
                        temporal = generaTmp();
                        escribir (temporal+"=ptr+"+QString::number(size)+";");
                        temp  = generaTmp();
                        escribir(temp+"="+temporal+"+"+QString::number(metodo.tamano-1)+";");
                        temporal = generaTmp();
                        escribir(temporal+"=Stack["+temp+"];");

                        escribir("Stack["+temporalVariable+"]="+temporal+";");
                    } else {
                        ErrorDeTipos(id,metodo.tipo);
                    }

                } else {NoExisteSimbolo(nombre,idClase);}
            }
        }

        else if(arbol->hijos[2]->hijos[0]->Etiqueta() == "INSTANCIAR"){
            QString tipo = arbol->hijos[1]->hijos[0]->Etiqueta();

            if(tabla.existeSimbolo(tipo)){
                Simbolo clase = tabla.getSimbolo(tipo);
                QString temporalVariable = generaTmp();
                QString nombreConstructor = arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta();
                if(nombreConstructor == s.tipo){
                    escribir(temporalVariable+"=ptr+"+QString::number(s.posicion)+";");
                    QString temporalHeap = generaTmp();
                    escribir(temporalHeap+"=ptrH;");
                    escribir("ptrH=ptrH+"+QString::number(clase.tamano)+";");
                    escribir("Stack["+temporalVariable+"]="+temporalHeap+";");


                    // Llamada al constructor;
                    QString nombreConstructor = arbol->hijos[2]->hijos[0]->hijos[0]->Etiqueta();
                    QString nombreSimbolo = tipo+"_"+nombreConstructor;
                    QString params = "";
                    if(arbol->hijos[2]->hijos[0]->hijos[1]!=NULL){
                        params = getParamsTipo(params,arbol->hijos[2]->hijos[0]->hijos[1]);
                        nombreSimbolo += params;
                    }
                    if(tabla.existeSimbolo(nombreSimbolo+"()")){
                        Simbolo metodoPadre = tabla.getSimbolo(metodoActual+"()");

                        // paso del this
                        QString temporal = generaTmp();
                        escribir(temporal+"=ptr+"+QString::number(metodoPadre.tamano)+";");
                        QString temp2 = generaTmp();
                        escribir(temp2+"="+temporal+"+0;");
                        escribir("Stack["+temp2+"]="+temporalHeap+";");

                        // paso de parametros
                        if(params!=""){
                            int cont = 0;
                            generarParametros(temporal,nombreSimbolo,arbol->hijos[2]->hijos[0]->hijos[1],cont);
                        }

                        // Llamada al constructor
                        escribir("ptr=ptr+"+QString::number(metodoPadre.tamano)+";");
                        escribir(nombreSimbolo+"();");
                        escribir("ptr=ptr-"+QString::number(metodoPadre.tamano)+";");

                    } else {
                        NoExisteConstructor(nombreConstructor);
                    }
                } else {
                    ErrorDeTipos(id,nombreConstructor);
                }

            } else {
                ErrorTipoIndefinido(tipo);
            }



        }

        else {

            temp = generaTmp();
            escribir(temp + "=ptr+"+QString::number(s.posicion)+";");

            QString temporal = generarCodigo3D(tmp,etq,arbol->hijos[2]);

            if(s.tipo == tipo){
                escribir("Stack["+temp+"]="+temporal+";");
            } else {
                ErrorDeTipos(id,tipo);
            }
        }
    }
    return "";
}

void GeneradorDeCodigo::escribir(QString codigo)
{
    this->codigo3D += codigo;
    this->codigo3D += '\n';
}

void GeneradorDeCodigo::emitirCodigo3D()
{
    // Declaracion de imports, includes, stack y heap
    QStringList decInicialesInd = decIniciales.split("|");
    for(int i = 0; i< decInicialesInd.size(); i++){
        archivo3D << decInicialesInd.at(i).toStdString() << endl;
    }

    // Declaracion de TODOS los temporales
    QString tmpDec = "int ";
    for(int i=0; i<tmp-1; i++){
        tmpDec += "t"+QString::number(i)+",";
    }
    tmpDec += "t"+QString::number(tmp-1)+";";
    archivo3D << tmpDec.toStdString() << endl;

    //Declaracion de los punteros
    archivo3D << "int ptr = 0;" << endl ;
    archivo3D << "int ptrH = 0;" << endl;

    // Declaracion de TODOS los metodos
    QStringList decMetodosInd = this->decMetodos.split("|");
    for (int i = 0; i<decMetodosInd.size(); i++){
        archivo3D << decMetodosInd.at(i).toStdString() << endl;
    }

    // Imprimir el codigo de tres direcciones
    archivo3D << this->codigo3D.toStdString() << endl;
}
