#include "Car.h"
#include <sstream>
#include <algorithm>
#include <cctype>

Car::Car() : brand(""), color(""), price(0.0), power(0) {}

Car::Car(const std::string& brand_, const std::string& color_, double price_, int power_)
    : brand(brand_), color(color_), price(price_), power(power_) {
    validate();
}

Car::Car(const Car& other)
    : brand(other.brand), color(other.color), price(other.price), power(other.power) {}

void Car::validate() const {
    if (brand.empty()) {
        throw std::invalid_argument("Марка не може бути порожньою");
    }
    if (color.empty()) {
        throw std::invalid_argument("Колір не може бути порожнім");
    }
    if (price < 0) {
        throw std::invalid_argument("Ціна не може бути від'ємною");
    }
    if (power < 0) {
        throw std::invalid_argument("Потужність не може бути від'ємною");
    }
}

static inline std::string trim(const std::string& s) {
    size_t a = 0, b = s.size();
    while (a < s.size() && std::isspace((unsigned char)s[a])) ++a;
    while (b > a && std::isspace((unsigned char)s[b-1])) --b;
    return s.substr(a, b-a);
}

std::ostream& operator<<(std::ostream& out, const Car& c) {
    c.validate();
    out << c.brand << "," << c.color << "," << c.price << "," << c.power << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Car& c) {
    std::string line;
    if (!std::getline(in, line)) return in;
    if (line.empty()) return in;

    std::stringstream ss(line);
    std::string token;

    try {
        // Brand
        if (!std::getline(ss, token, ','))
            throw std::runtime_error("Недостатньо даних для марки");
        c.brand = trim(token);

        // Color
        if (!std::getline(ss, token, ','))
            throw std::runtime_error("Недостатньо даних для кольору");
        c.color = trim(token);

        // Price
        if (!std::getline(ss, token, ','))
            throw std::runtime_error("Недостатньо даних для ціни");
        c.price = std::stod(trim(token));

        // Power
        if (!std::getline(ss, token))
            throw std::runtime_error("Недостатньо даних для потужності");
        c.power = std::stoi(trim(token));

        c.validate();
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Помилка парсингу: ") + e.what());
    }

    return in;
}
