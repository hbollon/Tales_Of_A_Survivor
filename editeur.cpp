#include "editeur.h"
#include "ui_editeur.h"

Editeur::Editeur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editeur)
{
    ui->setupUi(this);

    pushEdit = new QPushButton("Edit", this);
    pushEdit -> move(20, 430);
    pushEdit -> setMinimumSize(91, 23);

    pushHelp = new QPushButton("Help", this);
    pushHelp -> move(20, 530);
    pushHelp -> setMinimumSize(91, 23);

    pushSave = new QPushButton("Save", this);
    pushSave -> move(570, 530);
    pushSave -> setMinimumSize(91, 23);

    pushCancel = new QPushButton("Cancel", this);
    pushCancel -> move(680, 530);
    pushCancel -> setMinimumSize(91, 23);

    pushOpen = new QPushButton("Open Existing file", this);
    pushOpen -> move(300, 128);
    pushOpen -> setMinimumSize(140, 23);

    lineName = new QLineEdit(this);
    lineName -> move(20, 130);
    lineName -> setMinimumSize(241, 20);

    lineMusic = new QLineEdit(this);
    lineMusic -> move(150, 360);
    lineMusic -> setMinimumSize(241, 20);
    lineMusic -> setDisabled(true);

    lineBkg = new QLineEdit(this);
    lineBkg -> move(150, 330);
    lineBkg -> setMinimumSize(241, 20);
    lineBkg -> setDisabled(true);

    checkPrefab = new QCheckBox("Prefab ground",this);
    checkPrefab -> move(20, 300);
    checkPrefab -> setMinimumSize(101, 17);

    checkBkg = new QCheckBox("Custom background" ,this);
    checkBkg -> move(20, 330);
    checkBkg -> setMinimumSize(101, 17);

    checkMusic = new QCheckBox("Custom music",this);
    checkMusic -> move(20, 360);
    checkMusic -> setMinimumSize(101, 17);

    radioCustom1 = new QRadioButton("Custom1", this);
    radioCustom1 -> move(20, 220);
    radioCustom1 -> setMinimumSize(82, 17);

    radioCustom2 = new QRadioButton("Custom2", this);
    radioCustom2 -> move(130, 220);
    radioCustom2 -> setMinimumSize(82, 17);

    radioCustom3 = new QRadioButton("Custom3", this);
    radioCustom3 -> move(240, 220);
    radioCustom3 -> setMinimumSize(82, 17);

    radioCustom4 = new QRadioButton("Custom4", this);
    radioCustom4 -> move(350, 220);
    radioCustom4 -> setMinimumSize(82, 17);

    QObject::connect(pushEdit, SIGNAL(pressed()), this, SLOT(edit()));
    QObject::connect(pushHelp, SIGNAL(pressed()), this, SLOT(help()));
    QObject::connect(pushSave, SIGNAL(pressed()), this, SLOT(save()));
    QObject::connect(pushCancel, SIGNAL(pressed()), this, SLOT(cancel()));
    QObject::connect(pushOpen, SIGNAL(pressed()), this, SLOT(openFile()));
    QObject::connect(checkPrefab, SIGNAL(stateChanged(int)), this, SLOT(prefab()));
    QObject::connect(checkBkg, SIGNAL(stateChanged(int)), this, SLOT(customBkg()));
    QObject::connect(checkMusic, SIGNAL(stateChanged(int)), this, SLOT(customMusic()));


}

Editeur::~Editeur()
{
    delete ui;
}

void Editeur::openFile()
{
    mapBrowser = new QFileDialog(this);
    mapBrowser -> show();

    QObject::connect(mapBrowser, SIGNAL(accepted()), this, SLOT(openMap()));

}

void Editeur::openMap()
{
    mapBrowser -> getOpenFileUrl(this, urlMap);
    mapBrowser -> getOpenFileName(this, nameMap);
    lineName -> setText(nameMap);
}

void Editeur::edit()
{
    mapEdit = new QTextEdit(this);
    mapEdit -> show();
}

void Editeur::save()
{

}

void Editeur::help()
{

}

void Editeur::cancel()
{

}

void Editeur::prefab()
{

}

void Editeur::customBkg()
{

}

void Editeur::customMusic()
{

}
