/********************************************************************************
** Form generated from reading UI file 'credits.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITS_H
#define UI_CREDITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Credits
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *Credits)
    {
        if (Credits->objectName().isEmpty())
            Credits->setObjectName(QStringLiteral("Credits"));
        Credits->resize(400, 300);
        label = new QLabel(Credits);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 12, 271, 41));
        label_2 = new QLabel(Credits);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 90, 261, 20));
        label_3 = new QLabel(Credits);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 130, 261, 20));
        label_4 = new QLabel(Credits);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 170, 261, 20));

        retranslateUi(Credits);

        QMetaObject::connectSlotsByName(Credits);
    } // setupUi

    void retranslateUi(QDialog *Credits)
    {
        Credits->setWindowTitle(QApplication::translate("Credits", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Credits", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic; color:#ff0000;\">Cr\303\251dits</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Credits", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Hugo Bollon</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Credits", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Simon Bernoud</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("Credits", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Gustave Lavorel</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Credits: public Ui_Credits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITS_H
