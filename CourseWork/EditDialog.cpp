#include "EditDialog.h"
#include "ui_EditDialog.h"
#include <QMessageBox>
#include <stdexcept>

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    setWindowTitle("Редагування автомобіля");
    setFixedSize(400, 300);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::setCarData(const Car& car)
{
    currentCar = car;
    ui->brandEdit->setText(QString::fromStdString(car.brand));
    ui->colorEdit->setText(QString::fromStdString(car.color));
    ui->priceEdit->setText(QString::number(car.price));
    ui->powerEdit->setText(QString::number(car.power));
}

Car EditDialog::getCarData() const
{
    return currentCar;
}

void EditDialog::on_okButton_clicked()
{
    try {
        QString brand = ui->brandEdit->text().trimmed();
        QString color = ui->colorEdit->text().trimmed();

        if (brand.isEmpty()) {
            throw std::invalid_argument("Будь ласка, введіть марку автомобіля.");
        }
        if (color.isEmpty()) {
            throw std::invalid_argument("Будь ласка, введіть колір автомобіля.");
        }

        // Перевірка числових значень з використанням try-catch
        bool priceOk, powerOk;
        double price = ui->priceEdit->text().toDouble(&priceOk);
        int power = ui->powerEdit->text().toInt(&powerOk);

        if (!priceOk) {
            throw std::invalid_argument("Некоректний формат ціни. Введіть число.");
        }
        if (!powerOk) {
            throw std::invalid_argument("Некоректний формат потужності. Введіть ціле число.");
        }
        if (price < 0) {
            throw std::invalid_argument("Ціна не може бути від'ємною.");
        }
        if (power < 0) {
            throw std::invalid_argument("Потужність не може бути від'ємною.");
        }

        currentCar.brand = brand.toStdString();
        currentCar.color = color.toStdString();
        currentCar.price = price;
        currentCar.power = power;

        // Валідація об'єкта Car
        currentCar.validate();

        accept();

    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Помилка введення", e.what());

        // Фокус на поле з помилкою
        if (ui->brandEdit->text().trimmed().isEmpty()) {
            ui->brandEdit->setFocus();
        } else if (ui->colorEdit->text().trimmed().isEmpty()) {
            ui->colorEdit->setFocus();
        } else {
            ui->priceEdit->setFocus();
            ui->priceEdit->selectAll();
        }
    }
}

void EditDialog::on_cancelButton_clicked()
{
    reject();
}
