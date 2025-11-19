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
#include <stdexcept>

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

bool MainWindow::isValidFileExtension(const QString& filePath) {
    QFileInfo fileInfo(filePath);
    QString extension = fileInfo.suffix().toLower();
    return (extension == "txt" || extension == "dat" || extension == "csv");
}

void MainWindow::validateFileForReading(const QString& filePath) {
    if (!isValidFileExtension(filePath)) {
        throw std::invalid_argument("Непідтримуваний тип файлу. Дозволені формати: .txt, .dat, .csv");
    }

    QFile file(filePath);
    if (!file.exists()) {
        throw std::runtime_error("Файл не існує: " + filePath.toStdString());
    }

    if (file.size() == 0) {
        throw std::runtime_error("Файл порожній: " + filePath.toStdString());
    }
}

void MainWindow::validateFileForWriting(const QString& filePath) {
    if (!isValidFileExtension(filePath)) {
        throw std::invalid_argument("Непідтримуваний тип файлу. Дозволені формати: .txt, .dat, .csv");
    }

    QFileInfo fileInfo(filePath);
    if (fileInfo.exists() && !fileInfo.isWritable()) {
        throw std::runtime_error("Немає прав запису у файл: " + filePath.toStdString());
    }
}

void MainWindow::loadFromFile(const QString& filePath) {
    try {
        validateFileForReading(filePath);

        std::ifstream file(filePath.toStdString());
        if (!file.is_open()) {
            throw std::runtime_error("Не вдалося відкрити файл для читання");
        }

        cars.clear();
        Car car;
        int loadedCount = 0;
        int lineNumber = 0;
        std::string line;

        while (std::getline(file, line)) {
            lineNumber++;
            if (line.empty()) continue;

            try {
                std::stringstream ss(line);
                if (ss >> car) {
                    cars.append(car);
                    loadedCount++;
                }
            } catch (const std::exception& e) {
                showStatusMessage(QString("Помилка у рядку %1: %2").arg(lineNumber).arg(e.what()), true);
            }
        }
        file.close();

        ui->searchText->clear();
        updateTable();

        if (loadedCount > 0) {
            showStatusMessage("Успішно завантажено " + QString::number(loadedCount) + " автомобілів з файлу");
            QMessageBox::information(this, "Успіх",
                                     "Успішно завантажено " + QString::number(loadedCount) + " автомобілів з файлу.");
        } else {
            throw std::runtime_error("Не знайдено жодного коректного запису у файлі");
        }
    } catch (const std::exception& e) {
        showStatusMessage("Помилка завантаження: " + QString(e.what()), true);
        QMessageBox::critical(this, "Помилка завантаження",
                              QString("Не вдалося завантажити файл:\n%1").arg(e.what()));
    }
}

void MainWindow::on_addButton_clicked() {
    try {
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
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка додавання", QString("Помилка при додаванні авто: %1").arg(e.what()));
    }
}

void MainWindow::on_editButton_clicked() {
    try {
        int currentRow = ui->tableWidget->currentRow();
        if (currentRow < 0 || currentRow >= filteredCars.size()) {
            throw std::runtime_error("Будь ласка, виберіть автомобіль для редагування");
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
            throw std::runtime_error("Не вдалося знайти обраний автомобіль");
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
    } catch (const std::exception& e) {
        showStatusMessage("Помилка редагування: " + QString(e.what()), true);
        QMessageBox::critical(this, "Помилка редагування", e.what());
    }
}

void MainWindow::on_deleteButton_clicked() {
    try {
        int currentRow = ui->tableWidget->currentRow();
        if (currentRow < 0 || currentRow >= filteredCars.size()) {
            throw std::runtime_error("Будь ласка, виберіть автомобіль для видалення");
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
            throw std::runtime_error("Не вдалося знайти обраний автомобіль");
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
    } catch (const std::exception& e) {
        showStatusMessage("Помилка видалення: " + QString(e.what()), true);
        QMessageBox::critical(this, "Помилка видалення", e.what());
    }
}

void MainWindow::on_loadButton_clicked() {
    try {
        QString filePath = QFileDialog::getOpenFileName(this,
                                                        "Виберіть файл для завантаження",
                                                        "",
                                                        "Текстові файли (*.txt);;Файли даних (*.dat);;CSV файли (*.csv);;Всі файли (*)");

        if (!filePath.isEmpty()) {
            loadFromFile(filePath);
        } else {
            showStatusMessage("Завантаження скасовано");
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка", QString("Помилка вибору файлу: %1").arg(e.what()));
    }
}

void MainWindow::on_saveButton_clicked() {
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для збереження");
        }

        QString filePath = QFileDialog::getSaveFileName(this,
                                                        "Зберегти дані",
                                                        "",
                                                        "Текстові файли (*.txt);;Файли даних (*.dat);;CSV файли (*.csv);;Всі файли (*)");

        if (!filePath.isEmpty()) {
            validateFileForWriting(filePath);

            std::ofstream file(filePath.toStdString());
            if (!file.is_open()) {
                throw std::runtime_error("Не вдалося створити файл для запису");
            }

            int savedCount = 0;
            for (const auto& car : cars) {
                try {
                    file << car;
                    savedCount++;
                } catch (const std::exception& e) {
                    showStatusMessage("Помилка збереження автомобіля: " + QString(e.what()), true);
                }
            }
            file.close();

            if (savedCount > 0) {
                showStatusMessage("Успішно збережено " + QString::number(savedCount) + " автомобілів у файл");
                QMessageBox::information(this, "Успіх",
                                         "Дані успішно збережено!\n" +
                                             QString::number(savedCount) + " автомобілів збережено у файл: " + filePath);
            } else {
                throw std::runtime_error("Не вдалося зберегти жодного автомобіля");
            }
        } else {
            showStatusMessage("Збереження скасовано");
        }
    } catch (const std::exception& e) {
        showStatusMessage("Помилка збереження: " + QString(e.what()), true);
        QMessageBox::critical(this, "Помилка збереження",
                              QString("Не вдалося зберегти файл:\n%1").arg(e.what()));
    }
}

void MainWindow::on_operationsButton_clicked() {
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для операцій");
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
    } catch (const std::exception& e) {
        showStatusMessage("Помилка операцій: " + QString(e.what()), true);
        QMessageBox::critical(this, "Помилка операцій", e.what());
    }
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item) {
    Q_UNUSED(item)
    on_editButton_clicked();
}

void MainWindow::on_searchText_textChanged(const QString &text) {
    applyFilter(text);
}
