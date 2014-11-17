#ifndef SALIDAINVERSA_H
#define SALIDAINVERSA_H

#include <QWidget>

namespace Ui {
class SalidaInversa;
}

class SalidaInversa : public QWidget
{
    Q_OBJECT

public:
    explicit SalidaInversa(QWidget *parent = 0);
    ~SalidaInversa();

    void setTexto(QString texto);

private:
    Ui::SalidaInversa *ui;
};

#endif // SALIDAINVERSA_H
