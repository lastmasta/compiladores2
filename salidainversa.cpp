#include "salidainversa.h"
#include "ui_salidainversa.h"

SalidaInversa::SalidaInversa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalidaInversa)
{
    ui->setupUi(this);
}

SalidaInversa::~SalidaInversa()
{
    delete ui;
}

void SalidaInversa::setTexto(QString texto)
{
    this->ui->inversaText->append(texto);
}
