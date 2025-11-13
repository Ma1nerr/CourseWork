#pragma once

#include <QDialog>

namespace Ui {
class StartupDialog;
}

class StartupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartupDialog(QWidget *parent = nullptr);
    ~StartupDialog();

    QString getSelectedFilePath() const { return selectedFilePath; }

signals:
    void fileSelected(const QString& filePath);

private slots:
    void on_createButton_clicked();
    void on_loadButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::StartupDialog *ui;
    QString selectedFilePath;
};
