%{

  #include "MainScanner.h"
  #include "generadordecodigo.h"
  #include "GlobalGenerador.h"
  #include "graficadorast.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>
  #include "nodo.h"
  using namespace std;

  extern int mainparserlex(void);
  extern char *mainparsertext;
  extern int mainparserlineno;
  extern int mainparsercolno;
  extern FILE *Mainin;
  void mainparsererror(char*s);

void inicializar() {

}


void mainparsererror(const char *s) {
cout << "Error SINTACTICO en la fila: " << mainparserlineno << " y columna: " << mainparsercolno<< ": "<<mainparsertext << endl;
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

%token <st> par_a
%token <st> par_c
%token <st> llave_a
%token <st> llave_c
%token <st> sig_igual
%token <st> p_coma
%token <st> dos_p
%token <st> punto
%token <st> comillas
%token <st> coma
%token <st> id
%token <st> numero
%token <st> string_token
%token <st> caracter_token

%token <st> clase_rsv
%token <st> extiende_rsv
%token <st> paratodos_rsv
%token <st> protegido_rsv
%token <st> privado_rsv
%token <st> dolar
%token <st> traer_rsv
%token <st> decattr_rsv
%token <st> entero_rsv
%token <st> bool_rsv
%token <st> caracter_rsv
%token <st> cadena_rsv
%token <st> def_rsv
%token <st> ninguno_rsv
%token <st> retornar_rsv
%token <st> ref_rsv
%token <st> si_cumple_rsv
%token <st> sino_intente
%token <st> sino_cumple_rsv
%token <st> repetir_mientras_rsv
%token <st> detener_rsv
%token <st> decarr_rsv
%token <st> true_rsv
%token <st> false_rsv
%token <st> imprimir_rsv
%token <st> instanciar_rsv
%token <st> este_rsv


%token <st> esigual
%token <st> noigual
%token <st> mayor
%token <st> menor
%token <st> mayorigual
%token <st> menorigual
%token <st> esnulo
%token <st> orOp
%token <st> andOp
%token <st> notOp
%token <st> mas
%token <st> menos
%token <st> por
%token <st> divOp
%token <st> potencia
%token <st> numeralnumeral
%token <st> masmas
%token <st> menosmenos
%token <st> porpor

//Más baja precendencia

%left orOp
%left andOp
%left notOp
%left esigual noigual mayor menor mayorigual menorigual
%left esnulo
%left mas menos
%left por divOp
%right potencia


//Más alta precedencia

%type <nodo> IMPORT
%type <nodo> IMPORT_LIST
%type <nodo> CLASE_LIST
%type <nodo> CLASE
%type <nodo> TIPO_ACCESO
%type <nodo> EXTIENDE
%type <nodo> CUERPO_CLASE
%type <nodo> SENTENCIAS_CLASE
%type <nodo> DECATR
%type <nodo> TIPO
%type <nodo> DECMETODO
%type <nodo> PARAMLIST
%type <nodo> PARAM
%type <nodo> INSTRUCCIONES
%type <nodo> SENTENCIAS
%type <nodo> DECVAR
%type <nodo> EXPRESION
%type <nodo> EXPLOG
%type <nodo> EXPMAT
%type <nodo> EXP
%type <nodo> IF
%type <nodo> ELSEIF
%type <nodo> ELSEIFLIST
%type <nodo> CICLO
%type <nodo> DETENER
%type <nodo> OPSIMP
%type <nodo> DECARRATR
%type <nodo> DECARRVAR
%type <nodo> DIMLIST
%type <nodo> DIM
%type <nodo> BOOL
%type <nodo> ASIGNACION
%type <nodo> INICIAR_ARR
%type <nodo> ASIGLIST
%type <nodo> LISTA_ASIG_ARR
%type <nodo> ARR_ACCESO
%type <nodo> ASIG_ARR
%type <nodo> VAR_ASIG
/*%type <nodo> CONCATENACION*/
%type <nodo> IMPRIMIR
%type <nodo> FUNCALL
%type <nodo> INSTANCIAR
%type <nodo> PARAMS
%type <nodo> VALOR
%type <nodo> ACCESOATRIBUTO
%type <nodo> MODIFATRIBUTO
%type <nodo> ACCESOMETODO
%type <nodo> RETORNO
%type <nodo> ELSE

%%

//  Reglas Gramaticales



INICIO:         CLASE_LIST {
                        Nodo* nodo = new Nodo("INICIO");
                        nodo->AgregarHijo($1);
                        GraficadorAST* ga = new GraficadorAST();
                        ga->Graficar(nodo);
                        gdc.AgregarAbol(nodo);
                      }
              | IMPORT_LIST CLASE_LIST {
                                    Nodo* nodo = new Nodo("INICIO");
                                    nodo->AgregarHijo($1);
                                    nodo->AgregarHijo($2);
                                    GraficadorAST* ga = new GraficadorAST();
                                    ga->Graficar(nodo);
                                    gdc.AgregarAbol(nodo);
                                  };
CLASE_LIST:     CLASE_LIST CLASE {
                            Nodo* nodo = new Nodo("CLASE_LIST");
                            nodo->AgregarHijo($1);
                            nodo->AgregarHijo($2);
                            $$ = nodo;
                            }

            |   CLASE {
                        Nodo* nodo = new Nodo("CLASE_LIST");
                        nodo->AgregarHijo($1);
                        $$ = nodo;
                      };
;

CLASE:          TIPO_ACCESO clase_rsv id dolar CUERPO_CLASE dolar  {
                                                                              Nodo* nodo = new Nodo("CLASE");
                                                                              nodo->AgregarHijo($1);

                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString($3));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo($5);
                                                                              $$ = nodo;
                                                                            }

              | TIPO_ACCESO clase_rsv id EXTIENDE dolar CUERPO_CLASE dolar {
                                                                              Nodo* nodo = new Nodo("CLASE");
                                                                              nodo->AgregarHijo($1);
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString($3));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo($4);
                                                                              nodo->AgregarHijo($6);
                                                                              $$ = nodo;
                                                                            };

TIPO_ACCESO:      paratodos_rsv {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString($1));
                                nodo->AgregarHijo(val);
                                $$ = nodo;
                              }
                | protegido_rsv {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString($1));
                                nodo->AgregarHijo(val);
                                $$ = nodo;
                              }
                | privado_rsv {
                                Nodo* nodo = new Nodo("TIPO_ACCESO");
                                Nodo* val = new Nodo(QString::fromStdString($1));
                                nodo->AgregarHijo(val);
                                $$ = nodo;
                              };

EXTIENDE:         extiende_rsv id {
                                    Nodo* nodo = new Nodo("EXTIENDE");
                                    Nodo* id = new Nodo("ID");
                                    Nodo* n = new Nodo(QString::fromStdString($2));
                                    id->AgregarHijo(n);
                                    nodo->AgregarHijo(id);
                                    $$ = nodo;
                                  };

IMPORT_LIST:    IMPORT_LIST IMPORT {
                          Nodo* nodo = new Nodo("IMPORT_LIST");
                          nodo->AgregarHijo($1);
                          nodo->AgregarHijo($2);
                          $$ = nodo;
                        }
              | IMPORT {
                          Nodo* nodo = new Nodo("IMPORT_LIST");
                          nodo->AgregarHijo($1);
                          $$ = nodo;
                        };

IMPORT:         traer_rsv string_token {
                                          Nodo* nodo = new Nodo("IMPORT");
                                          Nodo* val = new Nodo(QString::fromStdString($2));
                                          nodo->AgregarHijo(val);
                                          $$ = nodo;
                                        };

CUERPO_CLASE:   CUERPO_CLASE SENTENCIAS_CLASE {
                                  Nodo* nodo = new Nodo("CUERPO_CLASE");
                                  nodo->AgregarHijo($1);
                                  nodo->AgregarHijo($2);
                                  $$ = nodo;
                                }
              | SENTENCIAS_CLASE {
                                  Nodo* nodo = new Nodo("CUERPO_CLASE");
                                  nodo->AgregarHijo($1);
                                  $$ = nodo;
                                };

SENTENCIAS_CLASE: DECATR p_coma {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo($1);
                                    $$ = nodo;
                                  }
                | DECMETODO {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo($1);
                                    $$ = nodo;
                                  }
                | DECARRATR p_coma {
                                    Nodo* nodo = new Nodo("SENTENCIAS_CLASE");
                                    nodo->AgregarHijo($1);
                                    $$ = nodo;
                                  };


DECATR:   decattr_rsv TIPO_ACCESO id TIPO {
                                                                  Nodo* nodo = new Nodo("DECATR");
                                                                  nodo->AgregarHijo($2);
                                                                  Nodo* id = new Nodo("ID");
                                                                  Nodo* n = new Nodo(QString::fromStdString($3));
                                                                  id->AgregarHijo(n);
                                                                  nodo->AgregarHijo(id);
                                                                  nodo->AgregarHijo($4);
                                                                  $$ = nodo;
                                                                }
        | decattr_rsv TIPO_ACCESO id TIPO sig_igual ASIGNACION {
                                                                  Nodo* nodo = new Nodo("DECATR");
                                                                  nodo->AgregarHijo($2);
                                                                  Nodo* id = new Nodo("ID");
                                                                  Nodo* n = new Nodo(QString::fromStdString($3));
                                                                  id->AgregarHijo(n);
                                                                  nodo->AgregarHijo(id);
                                                                  nodo->AgregarHijo($4);
                                                                  nodo->AgregarHijo($6);
                                                                  $$ = nodo;
                                                                };

DECARRATR:    decarr_rsv TIPO_ACCESO id TIPO DIMLIST {
                                                                              Nodo* nodo = new Nodo("DECARRATR");
                                                                              nodo->AgregarHijo($2);
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString($3));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo($4);
                                                                              nodo->AgregarHijo($5);
                                                                              $$ = nodo;
                                                                            }
            | decarr_rsv TIPO_ACCESO id TIPO DIMLIST sig_igual INICIAR_ARR {
                                                                              Nodo* nodo = new Nodo("DECARRATR");
                                                                              nodo->AgregarHijo($2);
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString($3));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo($4);
                                                                              nodo->AgregarHijo($5);
                                                                              nodo->AgregarHijo($7);
                                                                              $$ = nodo;
                                                                            };

DIMLIST:    DIMLIST DIM {
                          Nodo* nodo = new Nodo("DIMLIST");
                          nodo->AgregarHijo($1);
                          nodo->AgregarHijo($2);
                          $$ = nodo;
                        }
          | DIM {
                  Nodo* nodo = new Nodo("DIMLIST");
                  nodo->AgregarHijo($1);
                  $$ = nodo;
                };

DIM:        llave_a EXPMAT llave_c {
                                    Nodo* nodo = new Nodo("DIM");
                                    nodo->AgregarHijo($2);
                                    $$ = nodo;
                                    };

TIPO: entero_rsv {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString($1));
            nodo->AgregarHijo(val);
            $$ = nodo;
          }
    | cadena_rsv {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString($1));
            nodo->AgregarHijo(val);
            $$ = nodo;
          }
    | caracter_rsv {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString($1));
            nodo->AgregarHijo(val);
            $$ = nodo;
          }
    | bool_rsv {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString($1));
            nodo->AgregarHijo(val);
            $$ = nodo;
          }
    | ninguno_rsv {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString($1));
            nodo->AgregarHijo(val);
            $$ = nodo;
          }
    | id {
            Nodo* nodo = new Nodo("TIPO");
            Nodo* val = new Nodo(QString::fromStdString($1));
            nodo->AgregarHijo(val);
            $$ = nodo;
          };

BOOL:   true_rsv {
                  Nodo* nodo = new Nodo("BOOL");
                  Nodo* val = new Nodo("true");
                  nodo->AgregarHijo(val);
                  $$ = nodo;
                }
      | false_rsv {
                  Nodo* nodo = new Nodo("BOOL");
                  Nodo* val = new Nodo("false");
                  nodo->AgregarHijo(val);
                  $$ = nodo;
                }
                  ;

DECMETODO: def_rsv TIPO_ACCESO id TIPO par_a PARAMLIST par_c dolar INSTRUCCIONES dolar {
                                                                                          Nodo* nodo = new Nodo("DECMETODO");
                                                                                          nodo->AgregarHijo($2);
                                                                                          Nodo* id = new Nodo("ID");
                                                                                          Nodo* n = new Nodo(QString::fromStdString($3));
                                                                                          id->AgregarHijo(n);
                                                                                          nodo->AgregarHijo(id);
                                                                                          nodo->AgregarHijo($4);
                                                                                          nodo->AgregarHijo($6);
                                                                                          nodo->AgregarHijo($9);
                                                                                          $$ = nodo;
                                                                                        }
        | def_rsv id TIPO par_a PARAMLIST par_c dolar INSTRUCCIONES dolar {
                                                                              Nodo* nodo = new Nodo("DECMETODO");
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString($2));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo($3);
                                                                              nodo->AgregarHijo($5);
                                                                              nodo->AgregarHijo($8);
                                                                              $$ = nodo;
                                                                          }
        | def_rsv TIPO_ACCESO id TIPO par_a par_c dolar INSTRUCCIONES dolar {
                                                                              Nodo* nodo = new Nodo("DECMETODO");
                                                                              nodo->AgregarHijo($2);
                                                                              Nodo* id = new Nodo("ID");
                                                                              Nodo* n = new Nodo(QString::fromStdString($3));
                                                                              id->AgregarHijo(n);
                                                                              nodo->AgregarHijo(id);
                                                                              nodo->AgregarHijo($4);
                                                                              nodo->AgregarHijo($8);
                                                                              $$ = nodo;
                                                                            }
        | def_rsv id TIPO par_a par_c dolar INSTRUCCIONES dolar {
                                                                  Nodo* nodo = new Nodo("DECMETODO");
                                                                  Nodo* id = new Nodo("ID");
                                                                  Nodo* n = new Nodo(QString::fromStdString($2));
                                                                  id->AgregarHijo(n);
                                                                  nodo->AgregarHijo(id);
                                                                  nodo->AgregarHijo($3);
                                                                  nodo->AgregarHijo($7);
                                                                  $$ = nodo;
                                                                };


PARAMLIST:  PARAMLIST coma PARAM {
                                    Nodo* nodo = new Nodo("PARAMLIST");
                                    nodo->AgregarHijo($1);
                                    nodo->AgregarHijo($3);
                                    $$ = nodo;
                                  }
          | PARAM {
                    Nodo* nodo = new Nodo("PARAMLIST");
                    nodo->AgregarHijo($1);
                    $$ = nodo;
          };

PARAM:    id TIPO {
                    Nodo* nodo = new Nodo("PARAM");
                    Nodo* id = new Nodo("ID");
                    Nodo* n = new Nodo(QString::fromStdString($1));
                    id->AgregarHijo(n);
                    nodo->AgregarHijo(id);
                    nodo->AgregarHijo($2);
                    $$ = nodo;
                  }
        | ref_rsv id TIPO {
                            Nodo* nodo = new Nodo("REFPARAM");
                            Nodo* ref = new Nodo("ref");
                            Nodo* id = new Nodo("ID");
                            Nodo* n = new Nodo(QString::fromStdString($2));
                            id->AgregarHijo(n);
                            nodo->AgregarHijo(ref);
                            nodo->AgregarHijo(id);
                            nodo->AgregarHijo($3);
                            $$ = nodo;
                          };


INSTRUCCIONES:  INSTRUCCIONES SENTENCIAS {
                                          Nodo* nodo = new Nodo("INSTRUCCIONES");
                                          nodo->AgregarHijo($1);
                                          nodo->AgregarHijo($2);
                                          $$ = nodo;
                            }
              | SENTENCIAS  {
                            Nodo* nodo = new Nodo("INSTRUCCIONES");
                            nodo->AgregarHijo($1);
                            $$ = nodo;
                            };

SENTENCIAS:   DECVAR p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | RETORNO p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | IF {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | CICLO {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | DETENER p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | OPSIMP p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | DECARRVAR p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | ASIG_ARR p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | VAR_ASIG p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }
            | FUNCALL p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    }

            | MODIFATRIBUTO p_coma {
                                      Nodo* nodo = new Nodo("SENTENCIAS");
                                      nodo->AgregarHijo($1);
                                      $$ = nodo;
                                    };

DECVAR: id TIPO {
                  Nodo* nodo = new Nodo("DECVAR");
                  Nodo* id = new Nodo("ID");
                  Nodo* n = new Nodo(QString::fromStdString($1));
                  id->AgregarHijo(n);
                  nodo->AgregarHijo(id);
                  nodo->AgregarHijo($2);
                  $$ = nodo;
                }

        | id TIPO sig_igual ASIGNACION {
                                          Nodo* nodo = new Nodo("DECVAR");
                                          Nodo* id = new Nodo("ID");
                                          Nodo* n = new Nodo(QString::fromStdString($1));
                                          id->AgregarHijo(n);
                                          nodo->AgregarHijo(id);
                                          nodo->AgregarHijo($2);
                                          nodo->AgregarHijo($4);
                                          $$ = nodo;
                                        };

RETORNO: retornar_rsv EXPLOG {
                                  Nodo* nodo = new Nodo("RETORNO");
                                  nodo->AgregarHijo($2);
                                  $$ = nodo;
                                };

    EXPLOG: EXPLOG orOp EXPLOG {
                    Nodo* nodo = new Nodo("EXPLOG");
                    Nodo* op = new Nodo(QString::fromStdString($2));
                    nodo->AgregarHijo($1);
                    nodo->AgregarHijo(op);
                    nodo->AgregarHijo($3);
                    $$ = nodo;
            }
            | EXPLOG andOp EXPLOG {
                    Nodo* nodo = new Nodo("EXPLOG");
                    Nodo* op = new Nodo(QString::fromStdString($2));
                    nodo->AgregarHijo($1);
                    nodo->AgregarHijo(op);
                    nodo->AgregarHijo($3);
                    $$ = nodo;
            }
            | notOp EXPLOG {
                Nodo* nodo = new Nodo("EXPLOG");
                Nodo* op = new Nodo(QString::fromStdString($1));
                nodo->AgregarHijo(op);
                nodo->AgregarHijo($2);
                $$ = nodo;
            }

            | EXPRESION {$$ = $1;};

EXPRESION:  EXPRESION esigual EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPRESION noigual EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPRESION mayor EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPRESION menor EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPRESION mayorigual EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPRESION menorigual EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPRESION esnulo EXPRESION {
                                        Nodo* nodo = new Nodo("EXPRESION");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPMAT {$$ = $1;};

EXPMAT:       EXPMAT mas EXPMAT {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPMAT menos EXPMAT {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPMAT por EXPMAT {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPMAT divOp EXPMAT {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXPMAT potencia EXPMAT {
                                        Nodo* nodo = new Nodo("EXPMAT");
                                        Nodo* op = new Nodo(QString::fromStdString($2));
                                        nodo->AgregarHijo($1);
                                        nodo->AgregarHijo(op);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      }
            | EXP {$$ = $1;};

EXP:          par_a EXPLOG par_c {$$ = $2;}
            | id {
                      Nodo* nodo = new Nodo("ID");
                      Nodo* id = new Nodo(QString::fromStdString($1));
                      nodo->AgregarHijo(id);
                      $$ = nodo;
                    }
            | numero {
                      Nodo* nodo = new Nodo("NUM");
                      Nodo* num = new Nodo(QString::fromStdString($1));
                      nodo->AgregarHijo(num);
                      $$ = nodo;
                    }
            | OPSIMP {$$ = $1;}
            | BOOL {$$ = $1;}
            | ARR_ACCESO {$$ = $1;};

IF:           si_cumple_rsv par_a EXPLOG par_c dolar INSTRUCCIONES dolar {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo($3);
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo($6);
                                                                                                                                  $$ = nodo;
                                                                                                                                  }
            | si_cumple_rsv par_a EXPLOG par_c dolar INSTRUCCIONES dolar ELSE  {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo($3);
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo($6);
                                                                                                                                  nodo->AgregarHijo($8);
                                                                                                                                  $$ = nodo;
                                                                                                                                  }
            | si_cumple_rsv par_a EXPLOG par_c dolar INSTRUCCIONES dolar ELSEIFLIST ELSE {
                                                                                                                                  Nodo* nodo = new Nodo("IF");
                                                                                                                                  Nodo* cond = new Nodo("COND");
                                                                                                                                  cond->AgregarHijo($3);
                                                                                                                                  nodo->AgregarHijo(cond);
                                                                                                                                  nodo->AgregarHijo($6);
                                                                                                                                  nodo->AgregarHijo($8);
                                                                                                                                  nodo->AgregarHijo($9);
                                                                                                                                  $$ = nodo;
                                                                                                                                  };

ELSE: sino_cumple_rsv dolar INSTRUCCIONES dolar {
                                                        Nodo* nodo = new Nodo("ELSE");
                                                        nodo->AgregarHijo($3);
                                                        $$ = nodo;
                                                    };

ELSEIFLIST:   ELSEIFLIST ELSEIF {
                                  Nodo* nodo = new Nodo("ELSEIFLIST");
                                  nodo->AgregarHijo($1);
                                  nodo->AgregarHijo($2);
                                  $$ = nodo;
                      }
            | ELSEIF {
                      Nodo* nodo = new Nodo("ELSEIFLIST");
                      nodo->AgregarHijo($1);
                      $$ = nodo;
                      };

ELSEIF:       sino_intente par_a EXPLOG par_c dolar INSTRUCCIONES dolar {
                                                                              Nodo* nodo = new Nodo("ELSEIF");
                                                                              Nodo* cond = new Nodo("COND");
                                                                              cond->AgregarHijo($3);
                                                                              nodo->AgregarHijo(cond);
                                                                              nodo->AgregarHijo($6);
                                                                              $$ = nodo;
                                                                            };

DETENER:      detener_rsv {Nodo* nodo = new Nodo("DETENER");
                            $$ = nodo;
                          };


CICLO:        repetir_mientras_rsv par_a EXPLOG par_c dolar INSTRUCCIONES dolar {
                                                                                      Nodo* nodo = new Nodo("CICLO");
                                                                                      Nodo* cond = new Nodo("COND");
                                                                                      cond->AgregarHijo($3);
                                                                                      nodo->AgregarHijo(cond);
                                                                                      nodo->AgregarHijo($6);
                                                                                      $$ = nodo;
                                                                                    };

OPSIMP:       id masmas                     {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString($1));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | id menosmenos                 {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString($1));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | id porpor                     {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString($1));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | id numeralnumeral             {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              Nodo* id = new Nodo("ID");
                                              Nodo* n = new Nodo(QString::fromStdString($1));
                                              id->AgregarHijo(n);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(id);
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | ACCESOATRIBUTO masmas         {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo($1);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | ACCESOATRIBUTO menosmenos       {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo($1);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | ACCESOATRIBUTO porpor         {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo($1);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            }
            | ACCESOATRIBUTO numeralnumeral {
                                              Nodo* nodo = new Nodo("OPSIMP");
                                              nodo->AgregarHijo($1);
                                              Nodo* op = new Nodo(QString::fromStdString($2));
                                              nodo->AgregarHijo(op);
                                              $$ = nodo;
                                            };

DECARRVAR:    id TIPO DIMLIST {
                                Nodo* nodo = new Nodo("DECARRVAR");
                                Nodo* id = new Nodo("ID");
                                Nodo* n = new Nodo(QString::fromStdString($1));
                                id->AgregarHijo(n);
                                nodo->AgregarHijo(id);
                                nodo->AgregarHijo($2);
                                nodo->AgregarHijo($3);
                                $$ = nodo;
                              }
            | id TIPO DIMLIST sig_igual INICIAR_ARR {
                                                      Nodo* nodo = new Nodo("DECARRVAR");
                                                      Nodo* id = new Nodo("ID");
                                                      Nodo* n = new Nodo(QString::fromStdString($1));
                                                      id->AgregarHijo(n);
                                                      nodo->AgregarHijo(id);
                                                      nodo->AgregarHijo($2);
                                                      nodo->AgregarHijo($3);
                                                      nodo->AgregarHijo($5);
                                                      $$ = nodo;
                                                    };

ASIGNACION:   VALOR {
                      Nodo* nodo = new Nodo("ASIGNACION");
                      nodo->AgregarHijo($1);
                      $$ = nodo;
                    }
              | INSTANCIAR  {
              Nodo* nodo = new Nodo("ASIGNACION");
              nodo->AgregarHijo($1);
              $$ = nodo;
            }
            /*| CONCATENACION*/;

VALOR:  string_token {
                        Nodo* nodo = new Nodo("VALOR");
                        Nodo* n1 = new Nodo("CADENA");
                        Nodo* n1h = new Nodo(QString::fromStdString($1));
                        n1->AgregarHijo(n1h);
                        nodo->AgregarHijo(n1);
                        $$ = nodo;
                        }
      | caracter_token {
                        Nodo* nodo = new Nodo("VALOR");
                        Nodo* n1 = new Nodo("CHAR");
                        Nodo* n1h = new Nodo(QString::fromStdString($1));
                        n1->AgregarHijo(n1h);
                        nodo->AgregarHijo(n1);
                        $$ = nodo;
                        }
      | EXPLOG {
                    Nodo* nodo = new Nodo("VALOR");
                    nodo->AgregarHijo($1);
                    $$ = nodo;
                  }
      | ACCESOATRIBUTO {
                        Nodo* nodo = new Nodo("VALOR");
                        nodo->AgregarHijo($1);
                        $$ = nodo;
                      }
      | FUNCALL {
                  Nodo* nodo = new Nodo("VALOR");
                  nodo->AgregarHijo($1);
                  $$ = nodo;
                }
      /*| CONCATENACION*/;

INICIAR_ARR : llave_a LISTA_ASIG_ARR llave_c {
                                              Nodo* nodo = new Nodo("INICIAR_ARR");
                                              nodo->AgregarHijo($2);
                                              $$ = nodo;
                                            }
                | llave_a ASIGLIST llave_c {
                                              Nodo* nodo = new Nodo("INICIAR_ARR");
                                              nodo->AgregarHijo($2);
                                              $$ = nodo;
                                            };

LISTA_ASIG_ARR:   LISTA_ASIG_ARR coma INICIAR_ARR {
                                                    Nodo* nodo = new Nodo("LISTA_ASIG_ARR");
                                                    nodo->AgregarHijo($1);
                                                    nodo->AgregarHijo($3);
                                                    $$ = nodo;
                                                  }
                | INICIAR_ARR {
                                Nodo* nodo = new Nodo("LISTA_ASIG_ARR");
                                nodo->AgregarHijo($1);
                                $$ = nodo;
                              };

ASIGLIST:       ASIGLIST coma ASIGNACION {
                                            Nodo* nodo = new Nodo("ASIGLIST");
                                            nodo->AgregarHijo($1);
                                            nodo->AgregarHijo($3);
                                            $$ = nodo;
                                          }
              | ASIGNACION {
                              Nodo* nodo = new Nodo("ASIGLIST");
                              nodo->AgregarHijo($1);
                              $$ = nodo;
                            };

ARR_ACCESO:     id DIMLIST {
                              Nodo* nodo = new Nodo("ARR_ACCESO");
                              Nodo* n1 = new Nodo(QString::fromStdString($1));
                              nodo->AgregarHijo(n1);
                              nodo->AgregarHijo($2);
                              $$ = nodo;
                            };

ASIG_ARR:     ARR_ACCESO sig_igual ASIGNACION {
                                                Nodo* nodo = new Nodo("ASIG_ARR");
                                                nodo->AgregarHijo($1);
                                                nodo->AgregarHijo($3);
                                                $$ = nodo;
                                              };

VAR_ASIG:     id sig_igual ASIGNACION {
                                        Nodo* nodo = new Nodo("VAR_ASIG");
                                        Nodo* n1 = new Nodo(QString::fromStdString($1));
                                        nodo->AgregarHijo(n1);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      };

/*CONCATENACION:    CONCATENACION mas VALOR
                | VALOR;*/

FUNCALL:        IMPRIMIR {
                          Nodo* nodo = new Nodo("FUNCALL");
                          nodo->AgregarHijo($1);
                          $$ = nodo;
                            }
              | ACCESOMETODO {
                              Nodo* nodo = new Nodo("FUNCALL");
                              nodo->AgregarHijo($1);
                              $$ = nodo;
                            }
              | id par_a par_c {
                                Nodo* nodo = new Nodo("FUNCALL");
                                Nodo* n1 = new Nodo(QString::fromStdString($1));
                                nodo->AgregarHijo(n1);
                                $$ = nodo;
                              }
              | id par_a PARAMS par_c {
                                        Nodo* nodo = new Nodo("FUNCALL");
                                        Nodo* n1 = new Nodo(QString::fromStdString($1));
                                        nodo->AgregarHijo(n1);
                                        nodo->AgregarHijo($3);
                                        $$ = nodo;
                                      };

IMPRIMIR:       imprimir_rsv par_a VALOR par_c {
                                                  Nodo* nodo = new Nodo("IMPRIMIR");
                                                  nodo->AgregarHijo($3);
                                                  $$ = nodo;
                                              }
              /*| imprimir_rsv par_a CONCATENACION par_c*/;

INSTANCIAR:     instanciar_rsv id par_a PARAMS par_c {
                                                            Nodo* nodo = new Nodo("INSTANCIAR");
                                                            Nodo* constructor = new Nodo(QString::fromStdString($2));
                                                            nodo->AgregarHijo(constructor);
                                                            nodo->AgregarHijo($4);
                                                            $$ = nodo;
                                                      }

              | instanciar_rsv id par_a par_c {
                                                                Nodo* nodo = new Nodo("INSTANCIAR");
                                                                Nodo* constructor = new Nodo(QString::fromStdString($2));
                                                                nodo->AgregarHijo(constructor);
                                                                $$ = nodo;
                                                              };

PARAMS:     PARAMS coma VALOR {
                                Nodo* nodo = new Nodo("PARAMS");
                                nodo->AgregarHijo($1);
                                nodo->AgregarHijo($3);
                                $$ = nodo;
                              }
          /*| PARAMS coma CONCATENACION*/
          | VALOR {
                    Nodo* nodo = new Nodo("PARAMS");
                    nodo->AgregarHijo($1);
                    $$ = nodo;
                  }
          /*| CONCATENACION*/;

ACCESOATRIBUTO: id punto id   {
                                Nodo* nodo = new Nodo("ACCESOATRIBUTO");
                                Nodo* n1 = new Nodo(QString::fromStdString($1));
                                Nodo* n2 = new Nodo(QString::fromStdString($3));
                                nodo->AgregarHijo(n1);
                                nodo->AgregarHijo(n2);
                                $$ = nodo;
                              }
              | este_rsv punto id {
                                Nodo* nodo = new Nodo("ACCESOATRIBUTO");
                                Nodo* n1 = new Nodo("este");
                                Nodo* n2 = new Nodo(QString::fromStdString($3));
                                nodo->AgregarHijo(n1);
                                nodo->AgregarHijo(n2);
                                $$ = nodo;
                              };

MODIFATRIBUTO:  ACCESOATRIBUTO sig_igual ASIGNACION {
                                                      Nodo* nodo = new Nodo("MODIFATRIBUTO");
                                                      nodo->AgregarHijo($1);
                                                      nodo->AgregarHijo($3);
                                                      $$=nodo;
                                                    };

ACCESOMETODO:   id punto id par_a par_c {
                                         Nodo* nodo = new Nodo("ACCESOMETODO");
                                         Nodo* n1 = new Nodo(QString::fromStdString($1));
                                         Nodo* n2 = new Nodo(QString::fromStdString($3));
                                         nodo->AgregarHijo(n1);
                                         nodo->AgregarHijo(n2);
                                         $$ = nodo;
                                         }

              | este_rsv punto id par_a par_c {
                                                Nodo* nodo = new Nodo("ACCESOMETODO");
                                                Nodo* n1 = new Nodo("este");
                                                Nodo* n2 = new Nodo(QString::fromStdString($3));
                                                nodo->AgregarHijo(n1);
                                                nodo->AgregarHijo(n2);
                                                $$ = nodo;
                                              }

              | id punto id par_a PARAMS par_c {
                                                Nodo* nodo = new Nodo("ACCESOMETODO");
                                                Nodo* n1 = new Nodo(QString::fromStdString($1));
                                                Nodo* n2 = new Nodo(QString::fromStdString($3));
                                                nodo->AgregarHijo(n1);
                                                nodo->AgregarHijo(n2);
                                                nodo->AgregarHijo($5);
                                                $$ = nodo;
                                              }
              | este_rsv punto id par_a PARAMS par_c {
                                                    Nodo* nodo = new Nodo("ACCESOMETODO");
                                                    Nodo* n1 = new Nodo("este");
                                                    Nodo* n2 = new Nodo(QString::fromStdString($3));
                                                    nodo->AgregarHijo(n1);
                                                    nodo->AgregarHijo(n2);
                                                    nodo->AgregarHijo($5);
                                                    $$ = nodo;
                                              };




%%

