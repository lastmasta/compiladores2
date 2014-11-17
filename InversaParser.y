%{

  #include "InversaScanner.h"
  #include "tablasimbolos.h"
  #include "ingenieriainversa.h"
  #include "nodo.h"
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




%type <nodo> TRESDIRECCIONES
%type <nodo> INSTRUCCIONES
%type <nodo> INCLUDES
%type <nodo> DECTEMPORALES
%type <nodo> TEMPORALES_LIST
%type <nodo> DECMETODOS
%type <nodo> DECMETODO
%type <nodo> DECPUNTEROS
%type <nodo> DECSTACK
%type <nodo> DECHEAP
%type <nodo> CUERPOMETODO
%type <nodo> INSTRUCCIONESMETODO

%type <nodo> OBTENERDESTACK
%type <nodo> OBTENERDEHEAP
%type <nodo> ASIGSTACK
%type <nodo> ASIGHEAP
%type <nodo> LABEL
%type <nodo> SALTONOCOND
%type <nodo> SALTOCOND
%type <nodo> CAMBIOVIRTUAL
%type <nodo> CAMBIODEAMBITO
%type <nodo> REGRESODEAMBITO
%type <nodo> TEMPASIG
%type <nodo> TEMPOP
%type <nodo> OP
%type <nodo> OPREL
%type <nodo> FUNCALL
%type <nodo> RETURN
%type <nodo> AUMENTARHEAP
%type <nodo> IMPRIMIR


%%

//  Reglas Gramaticales

INICIO:         INSTRUCCIONES { cout << "Final de ingenieria inversa" << endl; ii->iniciar($1);}  ;

INSTRUCCIONES:    INSTRUCCIONES TRESDIRECCIONES {
                                                    Nodo* nodo = new Nodo("INSTRUCCIONES");
                                                    nodo->AgregarHijo($1);
                                                    nodo->AgregarHijo($2);
                                                    $$ = nodo;
                                                  }
                | TRESDIRECCIONES {
                                    Nodo* nodo = new Nodo("INSTRUCCIONES");
                                    nodo->AgregarHijo($1);
                                    $$ = nodo;
                                  } ;

TRESDIRECCIONES:    INCLUDES {$$ = $1;}
                  | DECMETODOS {$$ = $1;}
                  | DECTEMPORALES {$$ = $1;}
                  | DECPUNTEROS {$$ = $1;}
                  | DECSTACK {$$ = $1;}
                  | DECHEAP {$$ = $1;} ;

DECTEMPORALES:    int_rsv TEMPORALES_LIST p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;};

TEMPORALES_LIST:        TEMPORALES_LIST coma id { Nodo* n = new Nodo("IGNORAR"); $$ = n;}
                      | id { Nodo* n = new Nodo("IGNORAR"); $$ = n;}

DECMETODOS:       DECMETODOS DECMETODO {
                                          Nodo* nodo = new Nodo("DECMETODOS");
                                          nodo->AgregarHijo($1);
                                          nodo->AgregarHijo($2);
                                          $$ = nodo;
                                        }
                | DECMETODO {
                              Nodo* nodo = new Nodo("DECMETODOS");
                              nodo->AgregarHijo($1);
                              $$ = $1;
                            } ;

DECMETODO:      void_rsv id par_a par_c p_coma {
                                                Nodo* nodo = new Nodo("IGNORAR");
                                                $$ = nodo;
                                              }
              | void_rsv id par_a par_c llave_a CUERPOMETODO llave_c {
                                                                      QString nombre = $2;
                                                                      ii->inversaMetodos(nombre);

                                                                      Nodo* nodo = new Nodo("DECMETODO");
                                                                      Nodo* id = new Nodo($2);
                                                                      nodo->AgregarHijo(id);
                                                                      nodo->AgregarHijo($6);
                                                                      $$ = nodo;
                                                                    }
              | int_rsv main_rsv par_a par_c llave_a CUERPOMETODO llave_c {
                                                                            ii->buscarPrincipal();

                                                                            Nodo* nodo = new Nodo("DECMAIN");
                                                                            nodo->AgregarHijo($6);
                                                                            $$ = nodo;
                                                                          } ;

DECPUNTEROS:    int_rsv ptr sig_igual numero p_coma  { Nodo* n = new Nodo("IGNORAR"); $$ = n;}
              | int_rsv ptrH sig_igual numero p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;};

DECSTACK:       long_rsv stack_rsv cor_a numero cor_c p_coma  { Nodo* n = new Nodo("IGNORAR"); $$ = n;};

DECHEAP:        long_rsv heap_rsv cor_a numero cor_c p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;} ;

INCLUDES:       numeral include_rsv iostream_rsv { Nodo* n = new Nodo("IGNORAR"); $$ = n;}
              | using_rsv namespace_rsv std_rsv p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;};

CUERPOMETODO:     CUERPOMETODO INSTRUCCIONESMETODO {
                                                    Nodo* nodo = new Nodo("CUERPOMETODO");
                                                    nodo->AgregarHijo($1);
                                                    nodo->AgregarHijo($2);
                                                    $$ = nodo;
                                                  }
                | INSTRUCCIONESMETODO { $$ = $1; };


INSTRUCCIONESMETODO:  OBTENERDESTACK { $$ = $1; }
                    | OBTENERDEHEAP { $$ = $1; }
                    | ASIGSTACK { $$ = $1; }
                    | ASIGHEAP { $$ = $1; }
                    | LABEL { $$ = $1; }
                    | SALTONOCOND { $$ = $1; }
                    | SALTOCOND { $$ = $1; }
                    | CAMBIOVIRTUAL { $$ = $1; }
                    | CAMBIODEAMBITO { $$ = $1; }
                    | REGRESODEAMBITO { $$ = $1; }
                    | TEMPASIG { $$ = $1; }
                    | TEMPOP { $$ = $1; }
                    | FUNCALL { $$ = $1; }
                    | RETURN { $$ = $1; }
                    | AUMENTARHEAP { $$ = $1; }
                    | IMPRIMIR { $$ = $1; }
                    | p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;} ;


OBTENERDESTACK:   id sig_igual stack_rsv cor_a id cor_c p_coma {
                                                              Nodo* nodo = new Nodo("OBTENERDESTACK");
                                                              Nodo* t1 = new Nodo($1);
                                                              Nodo* pos = new Nodo($5);
                                                              nodo->AgregarHijo(t1);
                                                              nodo->AgregarHijo(pos);
                                                              $$ = nodo;
                                                            } ;

OBTENERDEHEAP:    id sig_igual heap_rsv cor_a id cor_c p_coma {
                                                              Nodo* nodo = new Nodo("OBTENERDEHEAP");
                                                              Nodo* t1 = new Nodo($1);
                                                              Nodo* pos = new Nodo($5);
                                                              nodo->AgregarHijo(t1);
                                                              nodo->AgregarHijo(pos);
                                                              $$ = nodo;
                                                            } ;

ASIGSTACK:        stack_rsv cor_a id cor_c sig_igual id p_coma {
                                                                    Nodo* nodo = new Nodo("ASIGSTACK");
                                                                    Nodo* pos = new Nodo($3);
                                                                    Nodo* val = new Nodo($6);
                                                                    nodo->AgregarHijo(pos);
                                                                    nodo->AgregarHijo(val);
                                                                    $$ = nodo;
                                                                  };

ASIGHEAP:         heap_rsv cor_a id cor_c sig_igual id p_coma  {
                                                                    Nodo* nodo = new Nodo("ASIGHEAP");
                                                                    Nodo* pos = new Nodo($3);
                                                                    Nodo* val = new Nodo($6);
                                                                    nodo->AgregarHijo(pos);
                                                                    nodo->AgregarHijo(val);
                                                                    $$ = nodo;
                                                                  }
                | heap_rsv cor_a id cor_c sig_igual numero p_coma {
                                                                    Nodo* nodo = new Nodo("ASIGHEAP");
                                                                    Nodo* pos = new Nodo($3);
                                                                    Nodo* val = new Nodo($6);
                                                                    nodo->AgregarHijo(pos);
                                                                    nodo->AgregarHijo(val);
                                                                    $$ = nodo;
                                                                  } ;

LABEL:            id dos_p {
                            Nodo* nodo = new Nodo("ETIQ");
                            Nodo* eti = new Nodo($1);
                            nodo->AgregarHijo(eti);
                            $$ = nodo;
                          } ;
  
SALTONOCOND:      goto_rsv id p_coma {
                                      Nodo* nodo = new Nodo("SALTONOCOND");
                                      Nodo* l = new Nodo($2);
                                      nodo->AgregarHijo(l);
                                      $$ = nodo;
                                    } ;

SALTOCOND:        if_rsv par_a id OPREL id par_c goto_rsv id p_coma {
                                                                      Nodo* nodo = new Nodo("SALTOCOND");
                                                                      Nodo* if_n = new Nodo("if");
                                                                      Nodo* t1 = new Nodo($3);
                                                                      Nodo* t2 = new Nodo($5);
                                                                      Nodo* goto_n = new Nodo("goto");
                                                                      Nodo* l = new Nodo($8);
                                                                      nodo->AgregarHijo(if_n);
                                                                      nodo->AgregarHijo(t1);
                                                                      nodo->AgregarHijo($4);
                                                                      nodo->AgregarHijo(t2);
                                                                      nodo->AgregarHijo(goto_n);
                                                                      nodo->AgregarHijo(l);
                                                                      $$ = nodo;
                                                                    } ;

CAMBIOVIRTUAL:    id sig_igual ptr mas numero p_coma {
                                                      Nodo* nodo = new Nodo("CAMBIOVIRTUAL");
                                                      Nodo* id = new Nodo($1);
                                                      Nodo* num = new Nodo($5);
                                                      nodo->AgregarHijo(id);
                                                      nodo->AgregarHijo(num);
                                                      $$ = nodo;
                                                    } ;

CAMBIODEAMBITO:   ptr sig_igual ptr mas numero p_coma {
                                                        Nodo* nodo = new Nodo("CAMBIODEAMBITO");
                                                        Nodo* val = new Nodo($5);
                                                        nodo->AgregarHijo(val);
                                                        $$ = nodo;
                                                      } ;

REGRESODEAMBITO: ptr sig_igual ptr menos numero p_coma {
                                                        Nodo* nodo = new Nodo("REGRESODEAMBITO");
                                                        Nodo* val = new Nodo($5);
                                                        nodo->AgregarHijo(val);
                                                        $$ = nodo;
                                                      } ;

TEMPASIG:         id sig_igual ptrH p_coma  {
                                              Nodo* nodo = new Nodo("TEMPASIG");
                                              Nodo* t1 = new Nodo($1);
                                              Nodo* num = new Nodo($3);
                                              nodo->AgregarHijo(t1);
                                              nodo->AgregarHijo(num);
                                              $$ = nodo;
                                            } 
                | id sig_igual numero p_coma {
                                              Nodo* nodo = new Nodo("TEMPASIG");
                                              Nodo* t1 = new Nodo($1);
                                              Nodo* num = new Nodo($3);
                                              nodo->AgregarHijo(t1);
                                              nodo->AgregarHijo(num);
                                              $$ = nodo;
                                            } ;

TEMPOP:         id sig_igual id OP id p_coma  {
                                                    Nodo* nodo = new Nodo("TEMPOP");
                                                    Nodo* t1 = new Nodo($1);
                                                    Nodo* t2 = new Nodo($3);
                                                    Nodo* t3 = new Nodo($5);
                                                    nodo->AgregarHijo(t1);
                                                    nodo->AgregarHijo(t2);
                                                    nodo->AgregarHijo($4);
                                                    nodo->AgregarHijo(t3);
                                                    $$ = nodo;
                                                  }
              | id sig_igual id OP numero p_coma {
                                                    Nodo* nodo = new Nodo("TEMPOP");
                                                    Nodo* t1 = new Nodo($1);
                                                    Nodo* t2 = new Nodo($3);
                                                    Nodo* num = new Nodo($5);
                                                    nodo->AgregarHijo(t1);
                                                    nodo->AgregarHijo(t2);
                                                    nodo->AgregarHijo($4);
                                                    nodo->AgregarHijo(num);
                                                    $$ = nodo;
                                                  } ;

OP:         mas {
                  Nodo* nodo = new Nodo("OP");
                  Nodo* op = new Nodo($1);
                  nodo->AgregarHijo(op);
                  $$ = nodo;
                }
          | menos {
                  Nodo* nodo = new Nodo("OP");
                  Nodo* op = new Nodo($1);
                  nodo->AgregarHijo(op);
                  $$ = nodo;
                }
          | por {
                  Nodo* nodo = new Nodo("OP");
                  Nodo* op = new Nodo($1);
                  nodo->AgregarHijo(op);
                  $$ = nodo;
                }
          | divOp {
                  Nodo* nodo = new Nodo("OP");
                  Nodo* op = new Nodo($1);
                  nodo->AgregarHijo(op);
                  $$ = nodo;
                } ;

FUNCALL:    id par_a par_c p_coma {
                                    Nodo* nodo = new Nodo("FUNCALL");
                                    Nodo* val = new Nodo($1);
                                    nodo->AgregarHijo(val);
                                    $$ = nodo;
                                  } ;

RETURN:     return_rsv numero p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;} ;

OPREL:      menor {
                      Nodo* nodo = new Nodo("OPREL");
                      Nodo* val = new Nodo($1);
                      nodo->AgregarHijo(val);
                      $$ = nodo;
                    }
          | mayor {
                      Nodo* nodo = new Nodo("OPREL");
                      Nodo* val = new Nodo($1);
                      nodo->AgregarHijo(val);
                      $$ = nodo;
                    }
          | mayorigual {
                      Nodo* nodo = new Nodo("OPREL");
                      Nodo* val = new Nodo($1);
                      nodo->AgregarHijo(val);
                      $$ = nodo;
                    }
          | menorigual {
                      Nodo* nodo = new Nodo("OPREL");
                      Nodo* val = new Nodo($1);
                      nodo->AgregarHijo(val);
                      $$ = nodo;
                    }
          | noigual {
                      Nodo* nodo = new Nodo("OPREL");
                      Nodo* val = new Nodo($1);
                      nodo->AgregarHijo(val);
                      $$ = nodo;
                    }
          | esIgual {
                      Nodo* nodo = new Nodo("OPREL");
                      Nodo* val = new Nodo($1);
                      nodo->AgregarHijo(val);
                      $$ = nodo;
                    } ;

AUMENTARHEAP: ptrH sig_igual ptrH mas numero p_coma {
    Nodo* nodo = new Nodo("AUMENTARHEAP");
    Nodo* val = new Nodo($5);
    nodo->AgregarHijo(val);
    $$ = nodo;
} ;

IMPRIMIR:     cout_rsv doblemenor par_a char_rsv par_c id p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;}
            | cout_rsv doblemenor endl_rsv { Nodo* n = new Nodo("IGNORAR"); $$ = n;}
            | cout_rsv doblemenor par_a char_rsv par_c id doblemenor endl_rsv p_coma { Nodo* n = new Nodo("IGNORAR"); $$ = n;}
            | cout_rsv doblemenor id doblemenor endl_rsv p_coma  { Nodo* n = new Nodo("IGNORAR"); $$ = n;} ;

%%

