#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QWidget>

namespace Ui {
    class settingsDialog;
}

class settingsDialog : public QWidget
{
    Q_OBJECT

public:
    explicit settingsDialog(QWidget *parent = 0);
    ~settingsDialog();

private:
    Ui::settingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
