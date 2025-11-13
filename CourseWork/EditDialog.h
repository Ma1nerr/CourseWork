#pragma once

#include <QDialog>
#include <QTableWidgetItem>
#include "Car.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

    void setCarData(const Car& car);
    Car getCarData() const;

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::EditDialog *ui;
    Car currentCar;
};
