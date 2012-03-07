#-------------------------------------------------
#
# Project created by QtCreator 2012-02-12T14:57:53
#
#-------------------------------------------------

QT       += core gui

#----------------------------
# include JSON library
#----------------------------
#JsonReader reader;
#    reader.parse(jsonString);
#    QVariant v = reader.result();

#    JsonWriter writer;
#    writer.stringify(v);
#    QString json = writer.result();
#----------------------------

include(./3rd_party/qtjsonsettings/qtjsonsettings.pri)

#----------------------------

TARGET = test_project
TEMPLATE = app

unix{
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ./bin/
    UI_DIR = ./obj/
}

INCLUDEPATH += $$PWD/headers/
DEPENDPATH += $$PWD/headers/

TRANSLATIONS += ./lang/untitled_ru.ts \
                ./lang/untitled_en.ts

SOURCES += ./src/main.cpp\
        ./src/mainwindow.cpp \
    ./src/settingsdialog.cpp \
    src/databasemanager.cpp

HEADERS  += ./headers/mainwindow.h \
    ./headers/settingsdialog.h \
    headers/databasemanager.h

FORMS    += ./ui/mainwindow.ui \
    ./ui/settingsdialog.ui \
