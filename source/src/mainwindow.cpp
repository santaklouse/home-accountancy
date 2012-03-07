#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "../headers/settingsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

//    DataBaseManager *dbman = new DataBaseManager();

    //configure menu->about
    ui->action_About->setStatusTip(tr("Info about program"));
    connect(ui->action_About, SIGNAL(triggered()), this, SLOT(about()));

    //configure menu->exit
    ui->action_Exit->setStatusTip(tr("Exit from program"));
    ui->action_Exit->setShortcut(tr("Ctrl+Q"));
    connect(ui->action_Exit, SIGNAL(triggered()), this, SLOT(close()));

    //configure menu->settings
    ui->action_Settings->setStatusTip(tr("Program settings"));
    connect(ui->action_Settings, SIGNAL(triggered()), this, SLOT(showSettings()));

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

    MainWindow::loadTable();

    //get column name (index: 0)
    //qDebug() << ui->tableWidget->horizontalHeaderItem(0)->text();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showSettings() {
    settingsDialog *dialog = new settingsDialog;
    dialog->setWindowFlags(Qt::Dialog
                           | Qt::CustomizeWindowHint
                           | Qt::WindowTitleHint
                           | Qt::WindowCloseButtonHint
                           | Qt::WindowSystemMenuHint
    );
    dialog->setFixedSize(dialog->width(), dialog->height());
    dialog->show();
}

void MainWindow::add_row() {
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
         MainWindow::saveToFile();
         event->accept();
     } else {
         event->ignore();
     }
 }

 void MainWindow::comingSoonDialog() {
     QMessageBox::about(
        this,
        tr("Coming soon"),
        tr("<h2>Coming soon"));
 }

 void MainWindow::loadTable() {
     QString fileName = QDir::toNativeSeparators("data/test.dbo");
     QFile file(fileName);

     if (!file.open(QIODevice::ReadOnly)) {
         QMessageBox::warning(this, tr("Unable to open file"),
                              file.errorString());
         return;
     }

     QTextStream stream(&file);
     QString fileContent = stream.readAll();
     if (fileContent.isEmpty())
         QMessageBox::warning(this, tr("empty DB"),
                              "DB file is empty");
     MainWindow::buildTable(fileContent);
 }

 void MainWindow::buildTable(QString jsonContent) {
    QTableWidget *table = ui->tableWidget;
    JsonReader reader;
    QVariantMap result;

    reader.parse(jsonContent);
    if(reader.errorString().isEmpty())
    {
        result = reader.result().toMap();
    }
    else
    {
        MainWindow::test_table();
        return;
    }
    //rows
    QVariant rows = result.find("rows").value();


    //set columns labels
    QString columnLabels = "";
    QString rowsLabels = "";
    QVariant columns = result.find("columns").value();
    int colCount = columns.toList().count();
    table->setColumnCount(colCount);

    /**
        1, Hide the header horizontalHeaderItem
        2, Display horizontalHeaderItem one first line 0
        3, make background from line 0 like horizontalHeaderItem grey..
        item->setData (Qt::BackgroundColorRole ,QColor("#grey"));

        4, insert flag editable item->setFlags ( Qt::ItemIsSelectable | Qt::ItemIsEnabled | editable );

        all other line row go + 1
    *
    * Use QTableWidget::horizontalHeader() and the signal from the QHeaderView.
    */

    foreach (QVariant label, columns.toList())
    {
        columnLabels += label.toString() + ",";
        table->setHorizontalHeaderLabels(columnLabels.split(","));
    }
    int rowsCount = rows.toList().count();

    int currentRow = 0;
    table->setRowCount(rowsCount);

    foreach (QVariant row, rows.toList()) {

        QString label = row.toMap().find("label").value().toString();
        rowsLabels += label + ",";
        QVariant cells = row.toMap().find("values").value();
        int currentCol = 0;
        foreach (QVariant cell, cells.toList()){
            QTableWidgetItem* item= new QTableWidgetItem(cell.toString());
            table->setItem(currentRow, currentCol, item);
            currentCol++;
        }
        currentRow++;
    }


    table->setVerticalHeaderLabels(rowsLabels.split(","));
 }

 void MainWindow::test_table() {
     QTableWidget *table = ui->tableWidget;

     table->setRowCount(1);
     table->setColumnCount(10);

     QString columnLabels = "", rowLabels = "";
     //generate labels
     for (int i = 0; i <= 10; i++)
     {
         columnLabels += "Column " + QString::number(i) + ",";
         rowLabels += "Row "  + QString::number(i) + ",";

     }
     //generate cells
     for (int r = 0; r <= 1; r++)
         for (int c = 0; c<=10; c++ )
         {
             QTableWidgetItem* item= new QTableWidgetItem("cell: " + QString::number(r) + ", " + QString::number(c));
             ui->tableWidget->setItem(r, c, item);
         }

     table->setHorizontalHeaderLabels(columnLabels.split(","));
     table->setVerticalHeaderLabels(rowLabels.split(","));
 }

 QString MainWindow::getJsonTable() {
    QString jsonEncoded = "{}";
    JsonWriter writer;
    QVariantMap table_map;
    QVariantList columns;
    QVariantList rows;
    QTableWidget *table = ui->tableWidget;


    for (int row = 0; row < table->rowCount(); row++)
    {
        QVariantList values;
        QVariantMap row_data;
        for (int column = 0; column < table->columnCount(); column++)
        {
            if (! table->item(row, column))
                values.insert(column, "");
            else
                values.insert(column, table->item(row, column)->text());

            if (columns.length() < table->columnCount() )
                columns.insert(columns.length(), table->horizontalHeaderItem(column)->text());
        }
        row_data.insert("values", values);
        row_data.insert("label", table->verticalHeaderItem(row)->text());

        rows.insert(row, row_data);
    }

    table_map.insert("columns", columns);
    table_map.insert("rows", rows);
    writer.stringify(table_map);
    return writer.result();
 }

void MainWindow::saveToFile() {
//    MainWindow::comingSoonDialog(); //temporary coming soon dialog
    QString fileName = "data/test.dbo";

    JsonWriter writer;
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(MainWindow::getJsonTable().toUtf8());
        return;
    }
    QMessageBox::warning(
       this,
       tr("Error"),
       tr("<h2>Error in save table"));
}

 void MainWindow::loadFromFile() {
     MainWindow::loadTable();
 }
