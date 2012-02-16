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

TRANSLATIONS += ./lang/untitled_ru.ts \
                ./lang/untitled_en.ts

SOURCES += main.cpp\
        mainwindow.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    settingsdialog.ui
