#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Car {
public:
    std::string brand;
    std::string color;
    double price;
    int power;

    Car();
    Car(const std::string& brand, const std::string& color, double price, int power);
    Car(const Car& other);
    ~Car() = default;

    void validate() const;

    bool operator==(const Car& other) const {
        return brand == other.brand && color == other.color &&
               price == other.price && power == other.power;
    }

    bool operator!=(const Car& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& out, const Car& c);
    friend std::istream& operator>>(std::istream& in, Car& c);
};
