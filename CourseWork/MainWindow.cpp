#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "EditDialog.h"
#include "OperationsWindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , editDialog(nullptr)
    , operationsWindow(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Менеджер автомобілів");

    // Налаштування таблиці
    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"Марка", "Колір", "Ціна ($)", "Потужність (к.с.)"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setAlternatingRowColors(true);

    // Налаштування пошуку
    ui->searchText->setPlaceholderText("🔍 Пошук за маркою або кольором...");

    // Стилізація кнопок
    QString buttonStyle = "QPushButton { "
                          "padding: 8px 16px; "
                          "border: 1px solid #ccc; "
                          "border-radius: 4px; "
                          "background-color: #f0f0f0; "
                          "min-width: 80px; "
                          "}"
                          "QPushButton:hover { "
                          "background-color: #e0e0e0; "
                          "}"
                          "QPushButton:pressed { "
                          "background-color: #d0d0d0; "
                          "}";

    ui->addButton->setStyleSheet(buttonStyle);
    ui->editButton->setStyleSheet(buttonStyle);
    ui->deleteButton->setStyleSheet(buttonStyle);
    ui->loadButton->setStyleSheet(buttonStyle);
    ui->saveButton->setStyleSheet(buttonStyle);
    ui->operationsButton->setStyleSheet(buttonStyle);

    showStatusMessage("Готово до роботи. Оберіть дію з меню вище.");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete editDialog;
    delete operationsWindow;
}

void MainWindow::updateTable()
{
    applyFilter(ui->searchText->text());
}

void MainWindow::applyFilter(const QString& filter)
{
    if (filter.isEmpty()) {
        filteredCars = cars;
    } else {
        filteredCars.clear();
        QString lowerFilter = filter.toLower();
        for (const auto& car : cars) {
            if (QString::fromStdString(car.brand).toLower().contains(lowerFilter) ||
                QString::fromStdString(car.color).toLower().contains(lowerFilter)) {
                filteredCars.append(car);
            }
        }
    }

    ui->tableWidget->setRowCount(filteredCars.size());

    for (int i = 0; i < filteredCars.size(); ++i) {
        const Car& car = filteredCars[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(car.brand)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(car.color)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(car.price, 'f', 2)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(car.power)));
    }

    // Оновлення статусу
    if (filteredCars.isEmpty()) {
        if (cars.isEmpty()) {
            showStatusMessage("Таблиця порожня. Додайте автомобілі або завантажте з файлу.");
        } else {
            showStatusMessage("Не знайдено автомобілів за запитом: " + filter);
        }
    } else {
        QString status = QString("Показано %1 з %2 автомобілів").arg(filteredCars.size()).arg(cars.size());
        if (!filter.isEmpty()) {
            status += " (фільтр: " + filter + ")";
        }
        showStatusMessage(status);
    }
}

void MainWindow::showStatusMessage(const QString& message, bool isError)
{
    QString styledMessage = message;
    if (isError) {
        styledMessage = "❌ " + message;
    }
    ui->statusbar->showMessage(styledMessage);
}

void MainWindow::loadFromFile(const QString& filePath)
{
    std::ifstream file(filePath.toStdString());
    if (!file.is_open()) {
        showStatusMessage("Помилка: не вдалося відкрити файл: " + filePath, true);
        QMessageBox::critical(this, "Помилка", "Не вдалося відкрити файл: " + filePath);
        return;
    }

    cars.clear();
    Car car;
    int loadedCount = 0;
    std::string line;

    // Читаємо файл рядок за рядком
    while (std::getline(file, line)) {
        if (line.empty()) continue; // Пропускаємо порожні рядки

        std::stringstream ss(line);
        if (ss >> car) {
            cars.append(car);
            loadedCount++;
        }
    }
    file.close();

    // Очищаємо фільтр при завантаженні
    ui->searchText->clear();
    updateTable();

    if (loadedCount > 0) {
        showStatusMessage("Успішно завантажено " + QString::number(loadedCount) + " автомобілів з файлу");
        QMessageBox::information(this, "Успіх",
                                 "Успішно завантажено " + QString::number(loadedCount) + " автомобілів з файлу.");
    } else {
        showStatusMessage("Файл завантажено, але не знайдено жодного запису", true);
        QMessageBox::warning(this, "Попередження",
                             "Файл завантажено, але не знайдено жодного запису або формат файлу невірний.\n"
                             "Переконайтеся, що файл містить дані у форматі: марка,колір,ціна,потужність\n"
                             "Кожен запис має бути в окремому рядку.");
    }
}

// Решта методів залишаються без змін...
void MainWindow::on_addButton_clicked()
{
    if (!editDialog) {
        editDialog = new EditDialog(this);
    }

    editDialog->setCarData(Car());
    if (editDialog->exec() == QDialog::Accepted) {
        Car newCar = editDialog->getCarData();
        cars.append(newCar);
        updateTable();

        showStatusMessage("Автомобіль успішно додано: " + QString::fromStdString(newCar.brand));
        QMessageBox::information(this, "Успіх",
                                 QString("Автомобіль успішно додано!\n%1 - %2 - %3 - %4")
                                     .arg(QString::fromStdString(newCar.brand))
                                     .arg(QString::fromStdString(newCar.color))
                                     .arg(newCar.price)
                                     .arg(newCar.power));
    }
}

void MainWindow::on_editButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0 || currentRow >= filteredCars.size()) {
        showStatusMessage("Помилка: будь ласка, виберіть автомобіль для редагування", true);
        return;
    }

    // Знаходимо оригінальний індекс у головному масиві
    Car selectedCar = filteredCars[currentRow];
    int originalIndex = -1;
    for (int i = 0; i < cars.size(); ++i) {
        if (cars[i] == selectedCar) {
            originalIndex = i;
            break;
        }
    }

    if (originalIndex == -1) {
        showStatusMessage("Помилка: не вдалося знайти обраний автомобіль", true);
        return;
    }

    if (!editDialog) {
        editDialog = new EditDialog(this);
    }

    Car originalCar = cars[originalIndex];
    editDialog->setCarData(originalCar);
    if (editDialog->exec() == QDialog::Accepted) {
        Car updatedCar = editDialog->getCarData();
        cars[originalIndex] = updatedCar;
        updateTable();

        showStatusMessage("Автомобіль успішно оновлено: " + QString::fromStdString(updatedCar.brand));
        QMessageBox::information(this, "Успіх",
                                 QString("Автомобіль успішно оновлено!\nБуло: %1 - %2 - %3 - %4\nСтало: %5 - %6 - %7 - %8")
                                     .arg(QString::fromStdString(originalCar.brand))
                                     .arg(QString::fromStdString(originalCar.color))
                                     .arg(originalCar.price)
                                     .arg(originalCar.power)
                                     .arg(QString::fromStdString(updatedCar.brand))
                                     .arg(QString::fromStdString(updatedCar.color))
                                     .arg(updatedCar.price)
                                     .arg(updatedCar.power));
    }
}

void MainWindow::on_deleteButton_clicked()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0 || currentRow >= filteredCars.size()) {
        showStatusMessage("Помилка: будь ласка, виберіть автомобіль для видалення", true);
        return;
    }

    Car carToDelete = filteredCars[currentRow];
    int originalIndex = -1;
    for (int i = 0; i < cars.size(); ++i) {
        if (cars[i] == carToDelete) {
            originalIndex = i;
            break;
        }
    }

    if (originalIndex == -1) {
        showStatusMessage("Помилка: не вдалося знайти обраний автомобіль", true);
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Підтвердження видалення",
                                                              QString("Ви впевнені, що хочете видалити цей автомобіль?\n%1 - %2 - %3 - %4")
                                                                  .arg(QString::fromStdString(carToDelete.brand))
                                                                  .arg(QString::fromStdString(carToDelete.color))
                                                                  .arg(carToDelete.price)
                                                                  .arg(carToDelete.power),
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        cars.removeAt(originalIndex);
        updateTable();
        showStatusMessage("Автомобіль успішно видалено");
        QMessageBox::information(this, "Успіх", "Автомобіль успішно видалено.");
    }
}

void MainWindow::on_loadButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Виберіть файл для завантаження",
                                                    "",
                                                    "Текстові файли (*.txt);;Файли даних (*.dat);;Всі файли (*)");

    if (!filePath.isEmpty()) {
        loadFromFile(filePath);
    } else {
        showStatusMessage("Завантаження скасовано");
    }
}

void MainWindow::on_saveButton_clicked()
{
    if (cars.isEmpty()) {
        showStatusMessage("Помилка: немає даних для збереження", true);
        QMessageBox::warning(this, "Попередження", "Немає даних для збереження. Додайте автомобілі перед збереженням.");
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Зберегти дані",
                                                    "",
                                                    "Текстові файли (*.txt);;Файли даних (*.dat);;Всі файли (*)");

    if (!filePath.isEmpty()) {
        std::ofstream file(filePath.toStdString());
        if (!file.is_open()) {
            showStatusMessage("Помилка: не вдалося створити файл", true);
            QMessageBox::critical(this, "Помилка", "Не вдалося створити файл: " + filePath);
            return;
        }

        for (const auto& car : cars) {
            file << car;
        }
        file.close();

        showStatusMessage("Дані успішно збережено у файл: " + filePath);
        QMessageBox::information(this, "Успіх",
                                 "Дані успішно збережено!\n" +
                                     QString::number(cars.size()) + " автомобілів збережено у файл: " + filePath);
    } else {
        showStatusMessage("Збереження скасовано");
    }
}

void MainWindow::on_operationsButton_clicked()
{
    if (cars.isEmpty()) {
        showStatusMessage("Помилка: немає даних для операцій", true);
        QMessageBox::warning(this, "Попередження",
                             "Немає даних для операцій. Додайте автомобілі або завантажте з файлу перед виконанням операцій.");
        return;
    }

    if (!operationsWindow) {
        operationsWindow = new OperationsWindow(this);
        connect(operationsWindow, &OperationsWindow::carsSorted, this, [this](const QVector<Car>& sortedCars) {
            this->cars = sortedCars;
            updateTable();
            showStatusMessage("Таблицю успішно відсортовано");
        });
    }

    operationsWindow->setCars(cars);
    operationsWindow->exec();
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    Q_UNUSED(item)
    on_editButton_clicked();
}

void MainWindow::on_searchText_textChanged(const QString &text)
{
    applyFilter(text);
}
