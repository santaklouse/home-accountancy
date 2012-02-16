#include "settingsdialog.h"
#include "ui_settingsdialog.h"

settingsDialog::settingsDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
    connect(ui->saveSettings, SIGNAL(accepted()), this, SLOT(close()));
    connect(ui->saveSettings, SIGNAL(rejected()), this, SLOT(close()));
}

settingsDialog::~settingsDialog()
{
    delete ui;
}
