%{

  #include "InversaScanner.h"
  #include "tablasimbolos.h"
  #include "ingenieriainversa.h"
  #include <fstream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>
  #include <QString>
  using namespace std;

  extern int inversaparserlex(void);
  extern char *inversaparsertext;
  extern int inversaparserlineno;
  extern int inversaparsercolno;
  extern FILE *Mainin;
  void inversaparsererror(char*s);

  TablaSimbolos *tabla;
  IngenieriaInversa *ii = new IngenieriaInversa();


void inversaparsererror(const char *s) {
cout << "Error SINTACTICO en la fila: " << inversaparserlineno << " y columna: " << inversaparsercolno<< ": "<<inversaparsertext << endl;
}

void setTabla(TablaSimbolos *t){
  ii->setTabla(t);
}


%}

%code requires {
   #include "nodo.h"
}

%union{
char *st;
Nodo *nodo;
}



/* Simbolo inicial*/
%start INICIO

/* Error  */
%token <st> ERROR

/* Terminales */

%token <st> stack_rsv
%token <st> heap_rsv
%token <st> include_rsv
%token <st> using_rsv
%token <st> int_rsv
%token <st> long_rsv
%token <st> void_rsv
%token <st> goto_rsv
%token <st> if_rsv
%token <st> char_rsv
%token <st> main_rsv
%token <st> iostream_rsv
%token <st> namespace_rsv
%token <st> std_rsv
%token <st> ptr
%token <st> ptrH
%token <st> return_rsv
%token <st> cout_rsv
%token <st> endl_rsv

%token <st> esIgual
%token <st> noigual
%token <st> mayor
%token <st> menor
%token <st> mayorigual
%token <st> menorigual
%token <st> mas
%token <st> menos
%token <st> por
%token <st> divOp
%token <st> potencia
%token <st> numeral

%token <st> cor_a
%token <st> cor_c 
%token <st> par_a
%token <st> par_c
%token <st> llave_a
%token <st> llave_c
%token <st> sig_igual
%token <st> p_coma
%token <st> coma
%token <st> dos_p
%token <st> doblemenor

%token <st> id
%token <st> numero




%type <st> TRESDIRECCIONES
%type <st> INSTRUCCIONES
%type <st> INCLUDES
%type <st> DECTEMPORALES
%type <st> TEMPORALES_LIST
%type <st> DECMETODOS
%type <st> DECMETODO
%type <st> DECPUNTEROS
%type <st> DECSTACK
%type <st> DECHEAP
%type <st> CUERPOMETODO
%type <st> INSTRUCCIONESMETODO

%type <st> OBTENERDESTACK
%type <st> OBTENERDEHEAP
%type <st> ASIGSTACK
%type <st> ASIGHEAP
%type <st> LABEL
%type <st> SALTONOCOND
%type <st> SALTOCOND
%type <st> CAMBIOVIRTUAL
%type <st> CAMBIODEAMBITO
%type <st> REGRESODEAMBITO
%type <st> TEMPASIG
%type <st> TEMPOP
%type <st> OP
%type <st> OPREL
%type <st> FUNCALL
%type <st> RETURN
%type <st> AUMENTARHEAP
%type <st> IMPRIMIR


%%

//  Reglas Gramaticales

INICIO:         INSTRUCCIONES { cout << "Final de ingenieria inversa" << endl; ii->generarSalida(); }  ;

INSTRUCCIONES:    INSTRUCCIONES TRESDIRECCIONES 
                | TRESDIRECCIONES;

TRESDIRECCIONES:    INCLUDES 
                  | DECMETODOS
                  | DECTEMPORALES
                  | DECPUNTEROS
                  | DECSTACK
                  | DECHEAP;

DECTEMPORALES:    int_rsv TEMPORALES_LIST p_coma;

TEMPORALES_LIST:        TEMPORALES_LIST coma id 
                      | id 

DECMETODOS:       DECMETODOS DECMETODO
                | DECMETODO;

DECMETODO:      void_rsv id par_a par_c p_coma
              | void_rsv id par_a par_c llave_a CUERPOMETODO llave_c {
                                                                      QString nombre = $2;
                                                                      ii->inversaMetodos(nombre);
                                                                    }
              | int_rsv main_rsv par_a par_c llave_a CUERPOMETODO llave_c {
                                                                            ii->buscarPrincipal();
                                                                          } ;

DECPUNTEROS:    int_rsv ptr sig_igual numero p_coma 
              | int_rsv ptrH sig_igual numero p_coma;

DECSTACK:       long_rsv stack_rsv cor_a numero cor_c p_coma ;

DECHEAP:        long_rsv heap_rsv cor_a numero cor_c p_coma ;

INCLUDES:       numeral include_rsv iostream_rsv
              | using_rsv namespace_rsv std_rsv p_coma;

CUERPOMETODO:     CUERPOMETODO INSTRUCCIONESMETODO
                | INSTRUCCIONESMETODO;


INSTRUCCIONESMETODO:  OBTENERDESTACK
                    | OBTENERDEHEAP
                    | ASIGSTACK
                    | ASIGHEAP
                    | LABEL
                    | SALTONOCOND
                    | SALTOCOND
                    | CAMBIOVIRTUAL
                    | CAMBIODEAMBITO
                    | REGRESODEAMBITO
                    | TEMPASIG
                    | TEMPOP
                    | FUNCALL
                    | RETURN
                    | AUMENTARHEAP
                    | IMPRIMIR
                    | p_coma;


OBTENERDESTACK:   id sig_igual stack_rsv cor_a id cor_c p_coma ;

OBTENERDEHEAP:    id sig_igual heap_rsv cor_a id cor_c p_coma ;

ASIGSTACK:        stack_rsv cor_a id cor_c sig_igual id p_coma ;

ASIGHEAP:         heap_rsv cor_a id cor_c sig_igual id p_coma 
                | heap_rsv cor_a id cor_c sig_igual numero p_coma ;

LABEL:            id dos_p ;

SALTONOCOND:      goto_rsv id p_coma ;

SALTOCOND:        if_rsv par_a id OPREL id par_c goto_rsv id p_coma ;

CAMBIOVIRTUAL:    id sig_igual ptr mas numero p_coma ;

CAMBIODEAMBITO:   ptr sig_igual ptr mas numero p_coma ;

REGRESODEAMBITO: ptr sig_igual ptr menos numero p_coma ;

TEMPASIG:         id sig_igual ptrH p_coma 
                | id sig_igual numero p_coma ;

TEMPOP:         id sig_igual id OP id p_coma 
              | id sig_igual id OP numero p_coma ;

OP:         mas | menos | por | divOp  ;

FUNCALL:    id par_a par_c p_coma ;

RETURN:     return_rsv numero p_coma;

OPREL:      menor | mayor | mayorigual | menorigual | noigual | esIgual ;

AUMENTARHEAP: ptrH sig_igual ptrH mas numero p_coma ;

IMPRIMIR:     cout_rsv doblemenor par_a char_rsv par_c id p_coma
            | cout_rsv doblemenor endl_rsv
            | cout_rsv doblemenor par_a char_rsv par_c id doblemenor endl_rsv p_coma 
            | cout_rsv doblemenor id doblemenor endl_rsv p_coma  ;

%%

