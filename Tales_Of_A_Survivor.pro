#-------------------------------------------------
#
# Project created by QtCreator 2017-03-02T21:58:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tales_Of_A_Survivor
TEMPLATE = app
CONFIG += console
QT += core gui multimedia

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    highscores.cpp \
    credits.cpp \
    render_window.cpp \
    settings.cpp \
    variablesglobs.cpp \
    sprites.cpp \
    define.cpp \
    personnage.cpp

HEADERS  += mainwindow.h \
    highscores.h \
    credits.h \
    render_window.h \
    settings.h \
    variablesglobs.h \
    sprites.h \
    define.h \
    personnage.h

FORMS    += mainwindow.ui \
    highscores.ui \
    credits.ui \
    settings.ui

win32:CONFIG(release, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-graphics- -lsfml-main- -lsfml-system- -lsfml-window-
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/SFML/lib/ -lsfml-graphics-d -lsfml-main-d -lsfml-system-d -lsfml-window-d

INCLUDEPATH += C:/SFML/include
DEPENDPATH += C:/SFML/include

RESOURCES += \
    ressourcesqtdesign.qrc
