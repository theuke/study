#include <iostream>
#include <string>
#define print(s) std::cout << s << std::endl;
using String = std::string; // typedef std::string String; // I don't want to using namespace std - I only want to cherry-pick this one definition.

class Car {
    public:
        String brand;
        String model;
        int year;

        Car(const char* brand, const char* model, int _year) {
            (*this).brand = brand; // using this
            this->model = model; // using this with arrow operator, same as pointer dereferencing above, looks cleaner
            year = _year; // without this, could have been in an initialization list....
        };
};

int main() {
    Car carObj1("hidy", "ho", 1776);
    print(carObj1.year);
}