#include "Car.h"
#include <sstream>
#include <algorithm>
#include <cctype>

Car::Car() : brand(""), color(""), price(0.0), power(0) {}
Car::Car(const std::string& brand_, const std::string& color_, double price_, int power_)
    : brand(brand_), color(color_), price(price_), power(power_) {}
Car::Car(const Car& other)
    : brand(other.brand), color(other.color), price(other.price), power(other.power) {}

static inline std::string trim(const std::string& s) {
    size_t a = 0, b = s.size();
    while (a < s.size() && std::isspace((unsigned char)s[a])) ++a;
    while (b > a && std::isspace((unsigned char)s[b-1])) --b;
    return s.substr(a, b-a);
}

std::ostream& operator<<(std::ostream& out, const Car& c) {
    // CSV line
    out << c.brand << "," << c.color << "," << c.price << "," << c.power << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, Car& c) {
    std::string line;
    if (!std::getline(in, line)) return in;
    if (line.empty()) return in;

    std::stringstream ss(line);
    std::string token;

    // Brand
    if (!std::getline(ss, token, ',')) return in;
    c.brand = trim(token);

    // Color
    if (!std::getline(ss, token, ',')) return in;
    c.color = trim(token);

    // Price
    if (!std::getline(ss, token, ',')) return in;
    try {
        c.price = std::stod(trim(token));
    } catch (...) {
        c.price = 0.0;
        return in;
    }

    // Power
    if (!std::getline(ss, token)) return in;
    try {
        c.power = std::stoi(trim(token));
    } catch(...) {
        c.power = 0;
    }

    return in;
}
