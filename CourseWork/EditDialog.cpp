#include "EditDialog.h"
#include "ui_EditDialog.h"
#include <QMessageBox>

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
    QString brand = ui->brandEdit->text().trimmed();
    QString color = ui->colorEdit->text().trimmed();
    bool priceOk, powerOk;
    double price = ui->priceEdit->text().toDouble(&priceOk);
    int power = ui->powerEdit->text().toInt(&powerOk);

    // Валідація даних
    if (brand.isEmpty()) {
        QMessageBox::warning(this, "Помилка введення", "Будь ласка, введіть марку автомобіля.");
        ui->brandEdit->setFocus();
        return;
    }

    if (color.isEmpty()) {
        QMessageBox::warning(this, "Помилка введення", "Будь ласка, введіть колір автомобіля.");
        ui->colorEdit->setFocus();
        return;
    }

    if (!priceOk || price < 0) {
        QMessageBox::warning(this, "Помилка введення", "Будь ласка, введіть коректну ціну (додатнє число).");
        ui->priceEdit->setFocus();
        ui->priceEdit->selectAll();
        return;
    }

    if (!powerOk || power < 0) {
        QMessageBox::warning(this, "Помилка введення", "Будь ласка, введіть коректну потужність (додатнє ціле число).");
        ui->powerEdit->setFocus();
        ui->powerEdit->selectAll();
        return;
    }

    currentCar.brand = brand.toStdString();
    currentCar.color = color.toStdString();
    currentCar.price = price;
    currentCar.power = power;

    accept();
}

void EditDialog::on_cancelButton_clicked()
{
    reject();
}
