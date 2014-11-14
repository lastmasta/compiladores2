#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "generadordecodigo.h"
#include "MainParser.h"
#include "AssemblerParser.h"
#include "InversaParser.h"
#include "tablasimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_compilarBtn_clicked();

    void on_compilarBtn_2_clicked();

    void on_compilar3d_btn_clicked();

    void on_ejecutar_btn_clicked();

    void on_compilarBtn_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
