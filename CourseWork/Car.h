#pragma once
#include <string>
#include <iostream>

class Car {
public:
    std::string brand;
    std::string color;
    double price;
    int power;

    Car(); // default
    Car(const std::string& brand, const std::string& color, double price, int power);
    Car(const Car& other); // copy ctor
    ~Car() = default;

    // Оператори порівняння для QVector
    bool operator==(const Car& other) const {
        return brand == other.brand && color == other.color &&
               price == other.price && power == other.power;
    }

    bool operator!=(const Car& other) const {
        return !(*this == other);
    }

    // file IO (declaration only)
    friend std::ostream& operator<<(std::ostream& out, const Car& c);
    friend std::istream& operator>>(std::istream& in, Car& c);
};
