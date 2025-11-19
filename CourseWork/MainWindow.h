#pragma once

#include <QMainWindow>
#include <QVector>
#include <QTableWidgetItem>
#include <QFileInfo>
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

    // Нові методи для перевірки файлів
    bool isValidFileExtension(const QString& filePath);
    void validateFileForReading(const QString& filePath);
    void validateFileForWriting(const QString& filePath);
};
