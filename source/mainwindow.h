#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "3rd_party/qtjsonsettings/json.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void about();
    void add_row();
    void saveToFile();
    void loadFromFile();
    void showSettings();

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void closeEvent(QCloseEvent *event);

private:
    QString getJsonTable();
    void comingSoonDialog();
    void loadTable();
    void buildTable(QString jsonContent);
    void test_table();
    Ui::MainWindow *ui;
    QAction *aboutAction;
    QAction *exitAction;
    QMenu *fileMenu;
    QLabel *sb1;
    QLabel *sb2;
    QLabel *sb3;
    bool askOnClose();
};

#endif // MAINWINDOW_H
