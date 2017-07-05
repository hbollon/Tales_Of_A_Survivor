#include "level.h"
#include "ui_level.h"

Level::Level(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);

    Level1 = new QRadioButton("Level 1", this);
    Level1 -> move(40, 100);

    Level2 = new QRadioButton("Level 2", this);
    Level2 -> move(190, 100);

    Level3 = new QRadioButton("Level 3", this);
    Level3 -> move(340, 100);

    Level4 = new QRadioButton("Level 4", this);
    Level4 -> move(490, 100);

    radioLoadCustom1 = new QRadioButton("Custom Level 1", this);
    radioLoadCustom1 -> move(40, 400);

    radioLoadCustom2 = new QRadioButton("Custom Level 2", this);
    radioLoadCustom2 -> move(190, 400);

    radioLoadCustom3 = new QRadioButton("Custom Level 3", this);
    radioLoadCustom3 -> move(340, 400);

    radioLoadCustom4 = new QRadioButton("Custom Level 4", this);
    radioLoadCustom4 -> move(490, 400);

    switch (levelSelected)
    {
        case 1:
        Level1->setChecked(true);
        break;

        case 2:
        Level2->setChecked(true);
        break;

        case 3:
        Level3->setChecked(true);
        break;

        case 4:
        Level4->setChecked(true);
        break;

        default:
        break;
    }

    QObject::connect(Level1, SIGNAL(toggled(bool)), this, SLOT(setLevel1()));
    QObject::connect(Level2, SIGNAL(toggled(bool)), this, SLOT(setLevel2()));
    QObject::connect(Level3, SIGNAL(toggled(bool)), this, SLOT(setLevel3()));
    QObject::connect(Level4, SIGNAL(toggled(bool)), this, SLOT(setLevel4()));

}

Level::~Level()
{
    delete ui;
}

void Level::setLevel1()
{
    levelSelected = 1;
    mapSelected = "MapLevel1.txt";
}

void Level::setLevel2()
{
    levelSelected = 2;
    mapSelected = "MapLevel2.txt";
}

void Level::setLevel3()
{
    levelSelected = 3;
    mapSelected = "MapLevel3.txt";
}

void Level::setLevel4()
{
    levelSelected = 4;
    mapSelected = "MapLevel4.txt";
}
