#-------------------------------------------------
#
# Project created by QtCreator 2022-05-18T21:22:27
#
#-------------------------------------------------

QT       += core gui \
       multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    source/bullet.cpp \
    source/enemy.cpp \
    source/game.cpp \
    source/health.cpp \
    source/main.cpp \
    source/player.cpp \
    source/points.cpp \
    source/score.cpp

HEADERS += \
    headers/bullet.h \
    headers/enemy.h \
    headers/game.h \
    headers/health.h \
    headers/player.h \
    headers/points.h \
    headers/score.h

RESOURCES += \
    resource.qrc

DISTFILES += \
    mp3/background \
    mp3/eatsound.mp3 \
    mp3/shoot.mp3 \
    mp3/spawn.mp3 \
    png/backp.png \
    png/bullet.png \
    png/enemy.png \
    png/player.png
