#-------------------------------------------------
#
# Project created by QtCreator 2014-09-26T13:28:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MainParser.cpp \
    MainScanner.cpp \
    nodo.cpp \
    generadordecodigo.cpp \
    graficadorast.cpp \
    simbolo.cpp \
    tablasimbolos.cpp \
    errores.cpp \
    AssemblerParser.cpp \
    AssemblerScanner.cpp \
    InversaParser.cpp \
    InversaScanner.cpp \
    ingenieriainversa.cpp

HEADERS  += mainwindow.h \
    MainScanner.h \
    MainParser.h \
    nodo.h \
    MainScanner.l \
    generadordecodigo.h \
    graficadorast.h \
    simbolo.h \
    tablasimbolos.h \
    errores.h \
    GlobalGenerador.h \
    AssemblerScanner.l \
    AssemblerParser.h \
    AssemblerScanner.h \
    InversaParser.h \
    InversaScanner.h \
    InversaScanner.l \
    ingenieriainversa.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    MainParser.y \
    ../archivo_prueba.txt \
    AssemblerParser.y \
    InversaParser.y
