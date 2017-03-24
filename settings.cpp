#include "settings.h"
#include "ui_settings.h"
#include "variablesglobs.h"

int testIndex(0);

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    if (testIndex == 0)
    {
        actualIndex = 0;
        testIndex++;
    }

    boxResolution = new QComboBox(this);
    boxResolution -> move(140, 120);
    boxResolution -> setMinimumSize(211, 22);
    boxResolution -> addItem("1280x720", 1);
    boxResolution -> addItem("1600x900", 2);
    boxResolution -> addItem("1920x1080", 3);
    boxResolution -> setCurrentIndex(actualIndex);
    boxResolution -> setEnabled(enableBox);

    fullscreenBox = new QCheckBox("Fullscreen", this);
    fullscreenBox -> move(450, 120);
    fullscreenBox -> setMinimumSize(70, 17);
    fullscreenBox -> setChecked(etatBox);

    QObject::connect(boxResolution, SIGNAL(currentIndexChanged(int)), this, SLOT(resolution()));
    QObject::connect(fullscreenBox, SIGNAL(stateChanged(int)), this, SLOT(fullscreen()));



}

Settings::~Settings()
{
    delete ui;
}

void Settings::resolution()
{
    int i;
    i = boxResolution->currentIndex();
    actualIndex = i;

    switch (i)
          {
             case 0:
                l = 1280;
                h = 720;
                break;

             case 1:
                l = 1600;
                h = 900;
                break;

             case 2:
                l = 1980;
                h = 1080;
                break;

             default:
                break;
          }

}

void Settings::fullscreen()
{

    if (fullscreenBox->checkState() == 2)
    {
        fullBox = 1;
        etatBox = true;
        boxResolution -> setDisabled(true);
        enableBox = false;
    }
    else if (fullscreenBox->checkState() == 0)
    {
        fullBox = 0;
        etatBox = false;
        boxResolution -> setEnabled(true);
        enableBox = true;
    }

}
