#ifndef LEVEL_H
#define LEVEL_H

#include <QDialog>
#include <QRadioButton>
#include "variablesglobs.h"

namespace Ui {
class Level;
}

class Level : public QDialog
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = 0);
    ~Level();

private:
    Ui::Level *ui;
    QRadioButton *Level1;
    QRadioButton *Level2;
    QRadioButton *Level3;
    QRadioButton *Level4;
    QRadioButton *radioLoadCustom1;
    QRadioButton *radioLoadCustom2;
    QRadioButton *radioLoadCustom3;
    QRadioButton *radioLoadCustom4;


private slots:
    void setLevel1();
    void setLevel2();
    void setLevel3();
    void setLevel4();

};

#endif // LEVEL_H
