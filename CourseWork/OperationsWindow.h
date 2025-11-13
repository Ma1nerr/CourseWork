#pragma once

#include <QDialog>
#include <QVector>
#include <QTableWidgetItem>
#include "Car.h"

namespace Ui {
class OperationsWindow;
}

class OperationsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OperationsWindow(QWidget *parent = nullptr);
    ~OperationsWindow();

    void setCars(const QVector<Car>& carsList);

signals:
    void carsSorted(const QVector<Car>& sortedCars);

private slots:
    void on_sortColorAscButton_clicked();
    void on_sortColorDescButton_clicked();
    void on_sortPriceAscButton_clicked();
    void on_sortPriceDescButton_clicked();
    void on_sortPowerAscButton_clicked();
    void on_sortPowerDescButton_clicked();
    void on_findBrandButton_clicked();
    void on_samePriceDiffColorButton_clicked();
    void on_priceRangeButton_clicked();
    void on_brandColorQueriesButton_clicked();
    void on_colorMinMaxButton_clicked();
    void on_closeButton_clicked();
    void on_clearResultsButton_clicked();

private:
    Ui::OperationsWindow *ui;
    QVector<Car> cars;

    QString carToString(const Car& car);
    void mergeSort(QVector<Car>& arr, std::function<bool(const Car&, const Car&)> comp);
    void merge(QVector<Car>& left, QVector<Car>& right, QVector<Car>& result, std::function<bool(const Car&, const Car&)> comp);
    void showResult(const QString& title, const QString& content);
};
