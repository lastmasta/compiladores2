%{

  #include "AssemblerScanner.h"
  #include <fstream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>
  #include <QString>
  using namespace std;

  extern int assemblerparserlex(void);
  extern char *assemblerparsertext;
  extern int assemblerparserlineno;
  extern int assemblerparsercolno;
  extern FILE *Mainin;
  ofstream salidanasm;
  void assemblerparsererror(char*s);


void assemblerparsererror(const char *s) {
cout << "Error SINTACTICO en la fila: " << assemblerparserlineno << " y columna: " << assemblerparsercolno<< ": "<<assemblerparsertext << endl;
}

void Iniciar(){
  salidanasm.open("assembler.asm");
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

INICIO:         {Iniciar();} INSTRUCCIONES { cout << "Final de la gramatica" << endl; salidanasm.close(); }  ;

INSTRUCCIONES:    INSTRUCCIONES TRESDIRECCIONES 
                | TRESDIRECCIONES;

TRESDIRECCIONES:    INCLUDES 
                  | DECMETODOS
                  | DECTEMPORALES
                  | DECPUNTEROS
                  | DECSTACK
                  | DECHEAP;

DECTEMPORALES:    int_rsv TEMPORALES_LIST p_coma;

TEMPORALES_LIST:        TEMPORALES_LIST coma id { salidanasm << "    " << $3 << " : resd 1" << endl; }
                      | id { salidanasm << "    " << $1 << " : resd 1" << endl; } ;

DECMETODOS:       DECMETODOS DECMETODO
                | { salidanasm << "section .text" << endl; } DECMETODO;

DECMETODO:      void_rsv id par_a par_c p_coma
              | void_rsv id par_a par_c llave_a { salidanasm << $2 << ":" << endl; 
                                                  salidanasm << "    pusha" << endl;
                                                   } 

                                                  CUERPOMETODO llave_c {
                                                                        salidanasm << "    popa" << endl;
                                                                        salidanasm << "    ret" << endl;
                                                                      }

              | int_rsv main_rsv par_a par_c llave_a {salidanasm << "global _start" << endl; salidanasm << "_start:" << endl;} CUERPOMETODO llave_c {
                                                                                                                                                  salidanasm << "    exit:" << endl;
                                                                                                                                                  salidanasm << "    mov eax, 1" << endl;
                                                                                                                                                  salidanasm << "    mov ebx, 0" << endl;
                                                                                                                                                  salidanasm << "    int 80h" << endl; 
                                                                                                                                                  } ;

DECPUNTEROS:    int_rsv ptr sig_igual numero p_coma { salidanasm << "section .data" << endl;
                                                      salidanasm << "    ptr: dw 0" << endl; }
              | int_rsv ptrH sig_igual numero p_coma {
                                                        salidanasm << "    ptrH: dw 0" << endl;  
                                                      };

DECSTACK:       long_rsv stack_rsv cor_a numero cor_c p_coma {
                                                              salidanasm << "section .bss" << endl; 
                                                              salidanasm << "    Stack: resd 10000" << endl;
                                                              } ;

DECHEAP:        long_rsv heap_rsv cor_a numero cor_c p_coma {
                                                              salidanasm << "    Heap: resd 10000" << endl;
                                                            } ;

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


OBTENERDESTACK:   id sig_igual stack_rsv cor_a id cor_c p_coma {
                                                                  salidanasm << "    mov ebx, [Stack]" << endl;
                                                                  salidanasm << "    mov eax, " << $5 << endl;
                                                                  salidanasm << "    mov ecx, [ebx + eax]" << endl;
                                                                  salidanasm << "    mov eax, ecx" << endl;
                                                                  salidanasm << "    mov ["<< $1 << "], eax" << endl;
                                                                  } ;

OBTENERDEHEAP:    id sig_igual heap_rsv cor_a id cor_c p_coma {
                                                                  salidanasm << "    mov ebx, [Heap]" << endl;
                                                                  salidanasm << "    mov eax, " << $5 << endl;
                                                                  salidanasm << "    mov ecx, [ebx + eax]" << endl;
                                                                  salidanasm << "    mov eax, ecx" << endl;
                                                                  salidanasm << "    mov ["<< $1 << "], eax" << endl;
                                                                  } ;

ASIGSTACK:        stack_rsv cor_a id cor_c sig_igual id p_coma {
                                                                salidanasm << "    mov ebx, [Stack]" << endl; 
                                                                salidanasm << "    mov eax, " << $3 << endl;
                                                                salidanasm << "    mov ecx, " << $6 << endl;
                                                                salidanasm << "    mov[ebx + eax], ecx" << endl; } ;

ASIGHEAP:         heap_rsv cor_a id cor_c sig_igual id p_coma {
                                                                salidanasm << "    mov ebx, [Heap]" << endl; 
                                                                salidanasm << "    mov eax, " << $3 << endl;
                                                                salidanasm << "    mov ecx, " << $6 << endl;
                                                                salidanasm << "    mov[ebx + eax], ecx" << endl; }
                | heap_rsv cor_a id cor_c sig_igual numero p_coma {
                                                                salidanasm << "    mov ebx, [Heap]" << endl; 
                                                                salidanasm << "    mov eax, " << $3 << endl;
                                                                salidanasm << "    mov ecx, " << $6 << endl;
                                                                salidanasm << "    mov[ebx + eax], ecx" << endl; };

LABEL:            id dos_p {salidanasm << "    " << $1 << ":" << endl;} ;

SALTONOCOND:      goto_rsv id p_coma {salidanasm << "    JMP " << $2 << endl; } ;

SALTOCOND:        if_rsv par_a id OPREL id par_c goto_rsv id p_coma {
                                                                        QString oprel = $4;
                                                                        salidanasm << "    mov eax, " << $3 << endl;
                                                                        salidanasm << "    mov ebx, " << $5 << endl;
                                                                        salidanasm << "    cmp eax, ebx" << endl;
                                                                        if(oprel == "==") {
                                                                          salidanasm << "    JE " << $8 << endl;
                                                                        } else if (oprel == "!="){
                                                                          salidanasm << "    JNE " << $8 << endl;
                                                                        } else if (oprel == ">"){
                                                                          salidanasm << "    JG " << $8 << endl;
                                                                        } else if (oprel == ">="){
                                                                          salidanasm << "    JGE " << $8 << endl;
                                                                        } else if (oprel == "<"){
                                                                          salidanasm << "    JL " << $8 << endl;
                                                                        } else if (oprel == "<="){
                                                                          salidanasm << "    JLE " << $8 << endl;
                                                                        }
                                                                    } ;

CAMBIOVIRTUAL:    id sig_igual ptr mas numero p_coma {
                                                      salidanasm << "    mov eax, ptr" << endl;
                                                      salidanasm << "    add eax, "<< $5 << endl;  
                                                      salidanasm << "    mov [" << $1 << "], eax" << endl;
                                                      } ;

CAMBIODEAMBITO:   ptr sig_igual ptr mas numero p_coma {
                                                      salidanasm << "    mov eax, ptr" << endl;
                                                      salidanasm << "    add eax, "<< $5 << endl;  
                                                      salidanasm << "    mov [ptr], eax" << endl;
                                                      };

REGRESODEAMBITO: ptr sig_igual ptr menos numero p_coma {
                                                      salidanasm << "    mov eax, ptr" << endl;
                                                      salidanasm << "    sub eax, "<< $5 << endl;  
                                                      salidanasm << "    mov [ptr], eax" << endl;
                                                      };

TEMPASIG:         id sig_igual ptrH p_coma {  salidanasm << "    mov eax, ptrH" << endl;
                                              salidanasm << "    mov [" << $1 << "], eax" << endl; } 
                | id sig_igual numero p_coma {salidanasm << "    mov eax, " << $3 << endl;
                                              salidanasm << "    mov [" << $1 << "], eax" << endl; } ;

TEMPOP:         id sig_igual id OP id p_coma {salidanasm << "    mov eax, " << $3 << endl;
                                              QString op = $4;
                                              if(op == "+") {
                                                salidanasm << "    add eax, " << $5 << endl;
                                              } else if(op=="-"){
                                                salidanasm << "    sub eax, " << $5 << endl;
                                              } else if(op=="*"){
                                                salidanasm << "    mul " << $5 << endl;
                                              } else if (op=="/"){
                                                salidanasm << "   div " << $5 << endl;
                                              }
                                              salidanasm << "    mov [" << $1 << "], eax" << endl;
                                              }
              | id sig_igual id OP numero p_coma {salidanasm << "    mov eax, " << $3 << endl;
                                              QString op = $4;
                                              if(op == "+") {
                                                salidanasm << "    add eax, " << $5 << endl;
                                              } else if(op=="-"){
                                                salidanasm << "    sub eax, " << $5 << endl;
                                              } else if(op=="*"){
                                                salidanasm << "    mul " << $5 << endl;
                                              } else if (op=="/"){
                                                salidanasm << "   div " << $5 << endl;
                                              }
                                              salidanasm << "    mov [" << $1 << "], eax" << endl;
                                              };

OP:         mas {$$ = $1;} | menos {$$ = $1;} | por {$$ = $1;} | divOp {$$ = $1;} ;

FUNCALL:    id par_a par_c p_coma {salidanasm << "    call " << $1 << endl;} ;

RETURN:     return_rsv numero p_coma;

OPREL:      menor {$$ = $1;} | mayor {$$ = $1;} | mayorigual {$$ = $1;} | menorigual {$$ = $1;} | noigual {$$ = $1;} | esIgual {$$ = $1;} ;

AUMENTARHEAP: ptrH sig_igual ptrH mas numero p_coma {
                                                      salidanasm << "    mov eax, ptrH" << endl;
                                                      salidanasm << "    add eax, " << $5 << endl;  
                                                      salidanasm << "    mov [ptrH], eax" << endl;
                                                      };

IMPRIMIR:     cout_rsv doblemenor par_a char_rsv par_c id p_coma
            | cout_rsv doblemenor endl_rsv
            | cout_rsv doblemenor par_a char_rsv par_c id doblemenor endl_rsv p_coma {  salidanasm << "    mov eax, 4" << endl;
                                                                                        salidanasm << "    mov ebx, 1" << endl;
                                                                                        salidanasm << "    mov ecx, " << $6 << endl;
                                                                                        salidanasm << "    mov edx, 100" << endl;
                                                                                        salidanasm << "    int 80h" << endl; 
                                                                                         }

            | cout_rsv doblemenor id doblemenor endl_rsv p_coma  {                      salidanasm << "    mov eax, 4" << endl;
                                                                                        salidanasm << "    mov ebx, 1" << endl;
                                                                                        salidanasm << "    mov ecx, " << $3 << endl; 
                                                                                        salidanasm << "    mov edx, 100" << endl;
                                                                                        salidanasm << "    int 80h" << endl; 
                                                                                         } ;

%%

