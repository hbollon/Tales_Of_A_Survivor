/********************************************************************************
** Form generated from reading UI file 'highscores.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORES_H
#define UI_HIGHSCORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScores
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *HighScores)
    {
        if (HighScores->objectName().isEmpty())
            HighScores->setObjectName(QStringLiteral("HighScores"));
        HighScores->resize(400, 300);
        label = new QLabel(HighScores);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 10, 201, 41));
        label_2 = new QLabel(HighScores);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 31, 31));
        label_3 = new QLabel(HighScores);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 31, 31));
        label_4 = new QLabel(HighScores);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 150, 31, 31));
        label_5 = new QLabel(HighScores);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 190, 31, 31));

        retranslateUi(HighScores);

        QMetaObject::connectSlotsByName(HighScores);
    } // setupUi

    void retranslateUi(QWidget *HighScores)
    {
        HighScores->setWindowTitle(QApplication::translate("HighScores", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("HighScores", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-style:italic; color:#ff0000;\">HighScores</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("HighScores", "<html><head/><body><p align=\"center\">1:</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("HighScores", "<html><head/><body><p align=\"center\">2:</p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("HighScores", "<html><head/><body><p align=\"center\">3:</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("HighScores", "<html><head/><body><p align=\"center\">4:</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HighScores: public Ui_HighScores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORES_H
