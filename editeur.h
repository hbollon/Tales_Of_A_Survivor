#ifndef EDITEUR_H
#define EDITEUR_H

#include <QString>
#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QTextEdit>
#include <QFileDialog>

namespace Ui {
class Editeur;
}

class Editeur : public QDialog
{
    Q_OBJECT

public:
    explicit Editeur(QWidget *parent = 0);
    ~Editeur();

private:
    Ui::Editeur *ui;
    QPushButton *pushHelp;
    QPushButton *pushSave;
    QPushButton *pushCancel;
    QPushButton *pushEdit;
    QPushButton *pushOpen;
    QLineEdit *lineName;
    QLineEdit *lineMusic;
    QLineEdit *lineBkg;
    QRadioButton *radioCustom1;
    QRadioButton *radioCustom2;
    QRadioButton *radioCustom3;
    QRadioButton *radioCustom4;
    QCheckBox *checkPrefab;
    QCheckBox *checkMusic;
    QCheckBox *checkBkg;
    QFileDialog *mapBrowser;
    QTextEdit *mapEdit;

    QString urlMap;
    QString nameMap;

private slots:
    void help();
    void cancel();
    void edit();
    void save();
    void openFile();
    void openMap();
    void prefab();
    void customMusic();
    void customBkg();


};

#endif // EDITEUR_H
