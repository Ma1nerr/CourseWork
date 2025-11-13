#pragma once

#include <QMainWindow>
#include <QVector>
#include <QTableWidgetItem>
#include "Car.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class EditDialog;
class OperationsWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Зробити метод public, щоб можна було викликати з main.cpp
    void loadFromFile(const QString& filePath);

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_operationsButton_clicked();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_searchText_textChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    QVector<Car> cars;
    QVector<Car> filteredCars;
    EditDialog *editDialog;
    OperationsWindow *operationsWindow;

    void updateTable();
    void applyFilter(const QString& filter);
    void showStatusMessage(const QString& message, bool isError = false);
};
