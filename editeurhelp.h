#ifndef EDITEURHELP_H
#define EDITEURHELP_H

#include <QDialog>

namespace Ui {
class editeurhelp;
}

class editeurhelp : public QDialog
{
    Q_OBJECT

public:
    explicit editeurhelp(QWidget *parent = 0);
    ~editeurhelp();

private:
    Ui::editeurhelp *ui;
};

#endif // EDITEURHELP_H
