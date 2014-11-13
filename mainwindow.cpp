#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>

extern int assemblerparserparse();
extern int mainparserparse();
extern FILE *mainparserin;
extern FILE *assemblerparserin;

void guardarCodigo(string texto)
{
    ofstream fichero;
    fichero.open("codigofuente.txt",ofstream::out|ofstream::trunc);
    fichero << texto;
    fichero.close();
}

int  analizarCodigoFuente(string cadena)
{

    if(true){
        guardarCodigo(cadena);
        mainparserin=fopen("codigofuente.txt","rt");
        mainparserparse();
    }
}

int analizarCodigo3D(string cadena){
    guardarCodigo(cadena);
    assemblerparserin=fopen("codigofuente.txt","rt");
    assemblerparserparse();
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_compilarBtn_clicked()
{
    cout<<"analizando...."<<endl;
    QString codigo = this->ui->sourceArea->toPlainText();
    analizarCodigoFuente(codigo.toStdString());

    QString errores = "";
    QFile inputFile("errores.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           QTextStream in(&inputFile);
           while ( !in.atEnd() )
           {
              QString line = in.readLine();
              errores += line+'\n';
           }
           inputFile.close();
        }

        this->ui->erroresText->setText(errores);
}

void MainWindow::on_compilarBtn_2_clicked()
{
    QTextBrowser* browser = new QTextBrowser();

    browser->setFixedSize(750,500);
    browser->setSource(*new QUrl("tabla.html"));
    browser->setWindowTitle("Tabla de Simbolos");
    browser->show();
}

void MainWindow::on_compilar3d_btn_clicked()
{
    cout<<"analizando codigo de tres direcciones..."<<endl;
    QString codigo = this->ui->sourceArea->toPlainText();
    analizarCodigo3D(codigo.toStdString());

}
