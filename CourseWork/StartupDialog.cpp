#include "StartupDialog.h"
#include "ui_StartupDialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <stdexcept>

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
    try {
        QString filePath = QFileDialog::getOpenFileName(this,
                                                        "Виберіть файл для завантаження",
                                                        "",
                                                        "Текстові файли (*.txt);;Файли даних (*.dat);;CSV файли (*.csv);;Всі файли (*)");

        if (!filePath.isEmpty()) {
            QFileInfo fileInfo(filePath);
            QString extension = fileInfo.suffix().toLower();

            if (extension != "txt" && extension != "dat" && extension != "csv") {
                throw std::invalid_argument("Непідтримуваний тип файлу. Оберіть файл з розширенням .txt, .dat або .csv");
            }

            selectedFilePath = filePath;
            emit fileSelected(filePath);
            accept();
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка вибору файлу", e.what());
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
