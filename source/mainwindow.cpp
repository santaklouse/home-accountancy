#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //configure menu->about
    ui->action_About->setStatusTip(tr("Info about program"));
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(about()));

    //configure menu->exit
    ui->action_Exit->setStatusTip(tr("Exit from program"));
    ui->action_Exit->setShortcut(tr("Ctrl+Q"));
    connect(ui->action_Exit, SIGNAL(triggered()), this, SLOT(close()));

    //configure status bar
    sb1 = new QLabel(statusBar());
    sb2 = new QLabel(statusBar());
    sb3 = new QLabel(statusBar());

    statusBar()->setSizeGripEnabled(false);
    statusBar()->addWidget(sb1, 2);
    statusBar()->addWidget(sb2, 1);
    statusBar()->addWidget(sb3, 1);

    sb1->setText(tr("Hello!"));

    setMouseTracking(true);

    //configure buttons
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(add_row()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveToFile()));
    connect(ui->getData, SIGNAL(clicked()), this, SLOT(loadFromFile()));

    QTableWidget *table = ui->tableWidget;

    table->setRowCount(10);
    table->setColumnCount(10);

    QString columnLabels = "", rowLabels = "";

    //generate labels
    for (int i = 0; i <= 10; i++)
    {
        columnLabels += "Column " + QString::number(i) + ",";
        rowLabels += "Row "  + QString::number(i) + ",";

    }
    //generate cells
    for (int r = 0; r <= 10; r++)
        for (int c = 0; c<=10; c++ )
        {
            QTableWidgetItem* item= new QTableWidgetItem("cell: " + QString::number(r) + ", " + QString::number(c));
            ui->tableWidget->setItem(r, c, item);
        }

    table->setHorizontalHeaderLabels(columnLabels.split(","));
    table->setVerticalHeaderLabels(rowLabels.split(","));

    //get column name (index: 0)
    //qDebug() << table->horizontalHeaderItem(0)->text();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_row()
{
    QString total_rows_count = QString::number(ui->tableWidget->rowCount());
    QString columnLabels = "", rowLabels = "";

    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    for (int i = 0; i <= ui->tableWidget->rowCount(); i++)
    {
        columnLabels += "Column " + QString::number(i) + ",";
        rowLabels += "Row "  + QString::number(i) + ",";
    }

    ui->tableWidget->setVerticalHeaderLabels(rowLabels.split(","));
}

void MainWindow::resizeEvent(QResizeEvent *event) {
     QSize sz = event->size();

     sb2->setText(
         QString( "(%1, %2)" ).arg( sz.width() ).arg( sz.height() ) );
 }

 void MainWindow::mouseMoveEvent(QMouseEvent *event) {
     QPoint pos = event->pos();
     sb3->setText(
         QString( "%1, %2" ).arg( pos.x() ).arg( pos.y() ) );
 }

 void MainWindow::about() {
     QMessageBox::information(
        this,
        tr("About"),
        tr("<h2>home-accountancy on Qt4</h2><p>ver. 0.0.1 alpha"));
 }

 bool MainWindow::askOnClose() {
     int r = QMessageBox::warning(
         this, tr("Confirm"),
         tr("Really want to exit?"),
         QMessageBox::Yes,
         QMessageBox::Escape | QMessageBox::No);
     return (r == QMessageBox::Yes);
 }

 void MainWindow::closeEvent(QCloseEvent *event) {
     if (askOnClose()) {
         event->accept();
     } else {
         event->ignore();
     }
 }

 void MainWindow::comingSoonDialog()
 {
     QMessageBox::about(
        this,
        tr("Coming soon"),
        tr("<h2>Coming soon"));
 }

 QString MainWindow::getJsonTable()
 {
    QString jsonEncoded = "{}";
    //getting data from table & serialize to JSON
    //must be here

    return jsonEncoded;
 }

void MainWindow::saveToFile()
{
    MainWindow::comingSoonDialog(); //temporary coming soon dialog
    QString fileName = "data/test.dbo";
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }

    QDataStream out(&file);
    out << MainWindow::getJsonTable();
}

 void MainWindow::loadFromFile()
 {
     MainWindow::comingSoonDialog(); //temporary coming soon dialog
     QString fileName = "data/test.dbo";
     if (fileName.isEmpty())
     {
         return;
     }
     else {
         QFile file(fileName);

         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::information(this, tr("Unable to open file"),
                                      file.errorString());
             return;
         }
         QDataStream in(&file);
     }
 }
