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
    this->ui->tresText->setText("");
    this->ui->nasmText->setText("");
    this->ui->erroresText->setText(">> Analizando código de alto nivel...");
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
              errores += "!¡ "+line+'\n';
           }
           inputFile.close();
        }

        if(errores!=""){
            this->ui->erroresText->setText(errores);
        } else {
            this->ui->erroresText->append(">> Generando código de tres direcciones...");
            this->ui->erroresText->append(">> Generando código ensamblador...");

            QString codigo3D = "";

            QFile tresdirFile("3D.cpp");
            if(tresdirFile.open(QIODevice::ReadOnly)){
                QTextStream in(&tresdirFile);
                while (!in.atEnd() ){
                    QString line = in.readLine();
                    codigo3D += line;
                    this->ui->tresText->append(line);
                }
            }

            analizarCodigo3D(codigo3D.toStdString());

            QFile nasmFile("assembler.asm");
            if(nasmFile.open(QIODevice::ReadOnly)){
                QTextStream in(&nasmFile);
                while(!in.atEnd() ){
                    QString line = in.readLine();
                    this->ui->nasmText->append(line);
                }
            }
        }




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


}

void MainWindow::on_ejecutar_btn_clicked()
{
    system("g++ 3D.cpp -o salida");
    system("xfce4-terminal --hold -e ./salida");
}
