#include "StartupDialog.h"
#include "ui_StartupDialog.h"
#include <QFileDialog>
#include <QMessageBox>

StartupDialog::StartupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartupDialog),
    selectedFilePath("")
{
    ui->setupUi(this);
    setWindowTitle("Менеджер автомобілів - Початок роботи");
    setFixedSize(400, 200);
}

StartupDialog::~StartupDialog()
{
    delete ui;
}

void StartupDialog::on_createButton_clicked()
{
    selectedFilePath = "";
    accept();
}

void StartupDialog::on_loadButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Виберіть файл для завантаження",
                                                    "",
                                                    "Текстові файли (*.txt);;Файли даних (*.dat);;Всі файли (*)");

    if (!filePath.isEmpty()) {
        selectedFilePath = filePath;
        emit fileSelected(filePath);
        accept();
    }
}

void StartupDialog::on_cancelButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                                              "Підтвердження виходу",
                                                              "Ви впевнені, що хочете вийти з програми?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        reject();
    }
}
