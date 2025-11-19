#include "OperationsWindow.h"
#include "ui_OperationsWindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <functional>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>

OperationsWindow::OperationsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperationsWindow)
{
    ui->setupUi(this);
    setWindowTitle("Операції з автомобілями");
    setMinimumSize(800, 600);

    // Стилізація кнопок
    QString buttonStyle = "QPushButton { "
                          "padding: 8px 16px; "
                          "border: 1px solid #ccc; "
                          "border-radius: 4px; "
                          "background-color: #f0f0f0; "
                          "min-width: 120px; "
                          "}"
                          "QPushButton:hover { "
                          "background-color: #e0e0e0; "
                          "}"
                          "QPushButton:pressed { "
                          "background-color: #d0d0d0; "
                          "}";

    // Застосовуємо стиль до всіх кнопок
    QList<QPushButton*> buttons = findChildren<QPushButton*>();
    for (QPushButton* button : buttons) {
        button->setStyleSheet(buttonStyle);
    }
}

OperationsWindow::~OperationsWindow()
{
    delete ui;
}

void OperationsWindow::setCars(const QVector<Car>& carsList)
{
    cars = carsList;
    ui->resultsText->clear();
    showResult("Інформація", "Завантажено " + QString::number(cars.size()) + " автомобілів для операцій.");
}

QString OperationsWindow::carToString(const Car& car)
{
    return QString::fromStdString(car.brand) + " | " +
           QString::fromStdString(car.color) + " | " +
           QString::number(car.price, 'f', 2) + " | " +
           QString::number(car.power);
}

void OperationsWindow::merge(QVector<Car>& left, QVector<Car>& right, QVector<Car>& result, std::function<bool(const Car&, const Car&)> comp)
{
    result.clear();
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (comp(left[i], right[j])) {
            result.append(left[i++]);
        } else {
            result.append(right[j++]);
        }
    }

    while (i < left.size()) result.append(left[i++]);
    while (j < right.size()) result.append(right[j++]);
}

void OperationsWindow::mergeSort(QVector<Car>& arr, std::function<bool(const Car&, const Car&)> comp)
{
    if (arr.size() <= 1) return;

    int mid = arr.size() / 2;
    QVector<Car> left, right, result;

    for (int i = 0; i < mid; i++) left.append(arr[i]);
    for (int i = mid; i < arr.size(); i++) right.append(arr[i]);

    mergeSort(left, comp);
    mergeSort(right, comp);
    merge(left, right, result, comp);

    arr = result;
}

void OperationsWindow::showResult(const QString& title, const QString& content)
{
    ui->resultsText->appendPlainText("=== " + title + " ===");
    ui->resultsText->appendPlainText(content);
    ui->resultsText->appendPlainText("");
}

void OperationsWindow::on_sortColorAscButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для сортування. Додайте автомобілі або завантажте з файлу.");
        }

        QVector<Car> sorted = cars;
        mergeSort(sorted, [](const Car& a, const Car& b) {
            QString colorA = QString::fromStdString(a.color).toLower();
            QString colorB = QString::fromStdString(b.color).toLower();
            if (colorA == colorB) return a.brand < b.brand;
            return colorA < colorB;
        });

        showResult("Сортування за кольором (А-Я)", "Таблицю відсортовано за кольором у зростаючому порядку.");
        emit carsSorted(sorted);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка сортування", QString("Не вдалося відсортувати дані:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_sortColorDescButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для сортування. Додайте автомобілі або завантажте з файлу.");
        }

        QVector<Car> sorted = cars;
        mergeSort(sorted, [](const Car& a, const Car& b) {
            QString colorA = QString::fromStdString(a.color).toLower();
            QString colorB = QString::fromStdString(b.color).toLower();
            if (colorA == colorB) return a.brand > b.brand;
            return colorA > colorB;
        });

        showResult("Сортування за кольором (Я-А)", "Таблицю відсортовано за кольором у спадному порядку.");
        emit carsSorted(sorted);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка сортування", QString("Не вдалося відсортувати дані:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_sortPriceAscButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для сортування. Додайте автомобілі або завантажте з файлу.");
        }

        QVector<Car> sorted = cars;
        mergeSort(sorted, [](const Car& a, const Car& b) {
            if (a.price == b.price) return a.brand < b.brand;
            return a.price < b.price;
        });

        showResult("Сортування за ціною (зростання)", "Таблицю відсортовано за ціною у зростаючому порядку.");
        emit carsSorted(sorted);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка сортування", QString("Не вдалося відсортувати дані:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_sortPriceDescButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для сортування. Додайте автомобілі або завантажте з файлу.");
        }

        QVector<Car> sorted = cars;
        mergeSort(sorted, [](const Car& a, const Car& b) {
            if (a.price == b.price) return a.brand > b.brand;
            return a.price > b.price;
        });

        showResult("Сортування за ціною (спадання)", "Таблицю відсортовано за ціною у спадному порядку.");
        emit carsSorted(sorted);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка сортування", QString("Не вдалося відсортувати дані:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_sortPowerAscButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для сортування. Додайте автомобілі або завантажте з файлу.");
        }

        QVector<Car> sorted = cars;
        mergeSort(sorted, [](const Car& a, const Car& b) {
            if (a.power == b.power) return a.brand < b.brand;
            return a.power < b.power;
        });

        showResult("Сортування за потужністю (зростання)", "Таблицю відсортовано за потужністю у зростаючому порядку.");
        emit carsSorted(sorted);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка сортування", QString("Не вдалося відсортувати дані:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_sortPowerDescButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для сортування. Додайте автомобілі або завантажте з файлу.");
        }

        QVector<Car> sorted = cars;
        mergeSort(sorted, [](const Car& a, const Car& b) {
            if (a.power == b.power) return a.brand > b.brand;
            return a.power > b.power;
        });

        showResult("Сортування за потужністю (спадання)", "Таблицю відсортовано за потужністю у спадному порядку.");
        emit carsSorted(sorted);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка сортування", QString("Не вдалося відсортувати дані:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_findBrandButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для пошуку. Додайте автомобілі або завантажте з файлу.");
        }

        bool ok;
        QString brand = QInputDialog::getText(this, "Пошук за маркою",
                                              "Введіть назву марки:",
                                              QLineEdit::Normal, "", &ok);
        if (!ok) {
            showResult("Пошук скасовано", "Операцію пошуку скасовано користувачем.");
            return;
        }

        if (brand.isEmpty()) {
            throw std::invalid_argument("Назва марки не може бути порожньою.");
        }

        QVector<Car> brandCars;
        for (const auto& car : cars) {
            if (QString::fromStdString(car.brand).compare(brand, Qt::CaseInsensitive) == 0) {
                brandCars.append(car);
            }
        }

        if (brandCars.isEmpty()) {
            showResult("Результати пошуку", "Не знайдено автомобілів марки: " + brand);
            return;
        }

        QVector<Car> resultCars;

        // Знаходимо мінімальні значення ціни та потужності
        double minPrice = brandCars[0].price;
        int minPower = brandCars[0].power;

        for (const auto& car : brandCars) {
            if (car.price < minPrice) minPrice = car.price;
            if (car.power < minPower) minPower = car.power;
        }

        // Знаходимо всі автомобілі, які мають одночасно мінімальну ціну та мінімальну потужність
        for (const auto& car : brandCars) {
            if (car.price == minPrice && car.power == minPower) {
                resultCars.append(car);
            }
        }

        QString result = "Результати пошуку для марки: " + brand + "\n";
        result += "Знайдено автомобілів марки: " + QString::number(brandCars.size()) + "\n";
        result += "Мінімальна ціна: " + QString::number(minPrice, 'f', 2) + "\n";
        result += "Мінімальна потужність: " + QString::number(minPower) + "\n\n";

        if (resultCars.isEmpty()) {
            result += "Не знайдено автомобілів, які мають одночасно мінімальну ціну та мінімальну потужність.";
        } else {
            result += "Автомобілі з одночасно мінімальною ціною та мінімальною потужністю (" +
                      QString::number(resultCars.size()) + " шт.):\n";
            for (const auto& car : resultCars) {
                result += "  • " + carToString(car) + "\n";
            }
        }

        showResult("Пошук за маркою", result);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка пошуку", QString("Не вдалося виконати пошук:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_samePriceDiffColorButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для аналізу. Додайте автомобілі або завантажте з файлу.");
        }

        // Групуємо за маркою та ціною, збираємо кольори
        std::map<std::string, std::map<double, std::set<std::string>>> brandPriceColors;

        for (const auto& car : cars) {
            brandPriceColors[car.brand][car.price].insert(car.color);
        }

        QString result;
        bool found = false;

        // Шукаємо марки, де для однієї ціни є різні кольори
        for (const auto& [brand, priceColors] : brandPriceColors) {
            bool brandHasSamePriceDiffColors = false;
            QString brandResult = "Марка: " + QString::fromStdString(brand) + "\n";

            for (const auto& [price, colors] : priceColors) {
                if (colors.size() >= 2) {
                    brandHasSamePriceDiffColors = true;
                    brandResult += "  Ціна: " + QString::number(price, 'f', 2) + " - Кольори: ";
                    bool first = true;
                    for (const auto& color : colors) {
                        if (!first) brandResult += ", ";
                        brandResult += QString::fromStdString(color);
                        first = false;
                    }
                    brandResult += "\n";
                }
            }

            if (brandHasSamePriceDiffColors) {
                found = true;
                result += brandResult + "\n";
            }
        }

        if (!found) {
            showResult("Аналіз цін", "Не знайдено марок з однаковою ціною та різними кольорами.");
        } else {
            showResult("Марки з однаковою ціною та різними кольорами", result);
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка аналізу", QString("Не вдалося виконати аналіз:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_priceRangeButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для аналізу. Додайте автомобілі або завантажте з файлу.");
        }

        bool ok1, ok2;
        double minPrice = QInputDialog::getDouble(this, "Діапазон цін",
                                                  "Мінімальна ціна:", 0, 0, 1000000, 2, &ok1);
        double maxPrice = QInputDialog::getDouble(this, "Діапазон цін",
                                                  "Максимальна ціна:", 10000, minPrice, 1000000, 2, &ok2);

        if (!ok1 || !ok2) {
            showResult("Діапазон цін", "Введення діапазону скасовано користувачем.");
            return;
        }

        if (minPrice < 0 || maxPrice < 0) {
            throw std::invalid_argument("Ціна не може бути від'ємною.");
        }

        if (minPrice > maxPrice) {
            throw std::invalid_argument("Мінімальна ціна не може бути більшою за максимальну.");
        }

        std::set<std::string> brandsInRange;
        QVector<Car> carsInRange;

        for (const auto& car : cars) {
            if (car.price >= minPrice && car.price <= maxPrice) {
                brandsInRange.insert(car.brand);
                carsInRange.append(car);
            }
        }

        QString result = "Діапазон цін: " + QString::number(minPrice, 'f', 2) + " - " + QString::number(maxPrice, 'f', 2) + "\n";
        result += "Знайдено автомобілів: " + QString::number(carsInRange.size()) + "\n";
        result += "Унікальних марок: " + QString::number(brandsInRange.size()) + "\n\n";

        if (brandsInRange.empty()) {
            result += "Не знайдено марок у вказаному діапазоні цін.";
        } else {
            result += "Марки в діапазоні:\n";
            for (const auto& brand : brandsInRange) {
                result += "• " + QString::fromStdString(brand) + "\n";
            }
        }

        showResult("Бренди в діапазоні цін", result);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка аналізу", QString("Не вдалося виконати аналіз діапазону цін:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_brandColorQueriesButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для аналізу. Додайте автомобілі або завантажте з файлу.");
        }

        std::map<std::string, QVector<Car>> carsByBrand;
        for (const auto& car : cars) {
            carsByBrand[car.brand].append(car);
        }

        QString result;
        int brandsWithRed = 0;
        int brandsWithBlack = 0;

        for (const auto& [brand, brandCars] : carsByBrand) {
            result += "🏷️ " + QString::fromStdString(brand) + ":\n";

            Car mostPowerfulRed;
            bool foundRed = false;
            for (const auto& car : brandCars) {
                QString color = QString::fromStdString(car.color).toLower();
                if (color == "red" || color == "червоний" || color == "червонний" || color.contains("червон")) {
                    if (!foundRed || car.power > mostPowerfulRed.power) {
                        mostPowerfulRed = car;
                        foundRed = true;
                    }
                }
            }

            if (foundRed) {
                result += "  🔴 Найпотужніший червоний: " + carToString(mostPowerfulRed) + "\n";
                brandsWithRed++;
            } else {
                result += "  🔴 Червоних автомобілів не знайдено\n";
            }

            Car cheapestBlack;
            bool foundBlack = false;
            for (const auto& car : brandCars) {
                QString color = QString::fromStdString(car.color).toLower();
                if (color == "black" || color == "чорний" || color.contains("чорн")) {
                    if (!foundBlack || car.price < cheapestBlack.price) {
                        cheapestBlack = car;
                        foundBlack = true;
                    }
                }
            }

            if (foundBlack) {
                result += "  ⚫ Найдешевший чорний: " + carToString(cheapestBlack) + "\n";
                brandsWithBlack++;
            } else {
                result += "  ⚫ Чорних автомобілів не знайдено\n";
            }

            result += "\n";
        }

        QString summary = "Загальна статистика:\n";
        summary += "• Проаналізовано марок: " + QString::number(carsByBrand.size()) + "\n";
        summary += "• Марки з червоними авто: " + QString::number(brandsWithRed) + "\n";
        summary += "• Марки з чорними авто: " + QString::number(brandsWithBlack) + "\n\n";

        showResult("Аналіз за марками", summary + result);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка аналізу", QString("Не вдалося виконати аналіз за марками:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_colorMinMaxButton_clicked()
{
    try {
        if (cars.isEmpty()) {
            throw std::runtime_error("Немає даних для аналізу. Додайте автомобілі або завантажте з файлу.");
        }

        std::map<std::string, std::pair<double, double>> colorStats; // color -> {minPrice, maxPrice}

        for (const auto& car : cars) {
            auto& stats = colorStats[car.color];
            if (stats.first == 0 || car.price < stats.first) stats.first = car.price;
            if (car.price > stats.second) stats.second = car.price;
        }

        if (colorStats.empty()) {
            throw std::runtime_error("Не вдалося зібрати статистику за кольорами.");
        }

        QString result = "Статистика цін за кольорами:\n\n";

        for (const auto& [color, prices] : colorStats) {
            result += "🎨 " + QString::fromStdString(color) + ":\n";
            result += "   📉 Мінімальна ціна: " + QString::number(prices.first, 'f', 2) + "\n";
            result += "   📈 Максимальна ціна: " + QString::number(prices.second, 'f', 2) + "\n";
            result += "   📊 Різниця: " + QString::number(prices.second - prices.first, 'f', 2) + "\n\n";
        }

        showResult("Ціни за кольорами", result);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка аналізу", QString("Не вдалося виконати аналіз цін за кольорами:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_clearResultsButton_clicked()
{
    try {
        ui->resultsText->clear();
        showResult("Інформація", "Результати очищено. Готово до нових операцій.");
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка", QString("Не вдалося очистити результати:\n%1").arg(e.what()));
    }
}

void OperationsWindow::on_closeButton_clicked()
{
    try {
        accept();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка", QString("Не вдалося закрити вікно:\n%1").arg(e.what()));
        reject();
    }
}
