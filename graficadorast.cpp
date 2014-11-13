#include "graficadorast.h"

GraficadorAST::GraficadorAST()
{
}

QString GraficadorAST::getCodigoGraphviz(){
    return this->codigoGraphviz;
}

void GraficadorAST::Graficar(Nodo *nodo){
    codigoGraphviz = "graph G {\n";
    codigoGraphviz += "node [shape = box];\n";
    indice = 0;
    declararNodos(nodo);
    indice = 0;
    enlazarNodos(nodo, 0);
    codigoGraphviz += "}";
    //cout<<codigoGraphviz.toStdString()<<endl;
    ofstream myfile;
    myfile.open ("AST.txt");
    myfile << codigoGraphviz.toStdString() << endl;
    myfile.close();
    system("dot -Tpng AST.txt -o AST.png");
}

void GraficadorAST::declararNodos(Nodo *nodo){
    int i = 0;
    if (nodo != NULL)
    {
        codigoGraphviz += "node" + QString::number(indice) + "[label = \"" + nodo->Etiqueta() + "\", style = filled, color = red];";
        indice++;
        while (nodo->hijos[i]!=NULL)
        {
            declararNodos(nodo->hijos[i]);
            i++;
        }
    }
}

void GraficadorAST::enlazarNodos(Nodo *nodo, int actual){
    int i = 0;
    if (nodo != NULL)
    {
        while (nodo->hijos[i] != NULL)
        {
            indice++;
            codigoGraphviz += "\"node" + QString::number(actual) + "\"--" + "\"node" + QString::number(indice) + "\"";
            enlazarNodos(nodo->hijos[i], indice);
            i++;
        }
    }
}
