#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include "variablesglobs.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    Ui::Settings *ui;
    QComboBox *boxResolution;
    QCheckBox *fullscreenBox;



private slots:
    void resolution();
    void fullscreen();

};

#endif // SETTINGS_H
