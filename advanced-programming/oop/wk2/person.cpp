#include <iostream>
#include <string>

#include "person.h"

Person::Person() {
    std::cout << "Ctor-> Person()\n";

    this->init("default", -1);
}

Person::Person(std::string name) {
    std::cout << "Ctor-> Person(std::string)\n";

    this->init(name, -1);
}

Person::Person(std::string name, int age) {
    std::cout << "Ctor-> Person(std::string, int)\n";

    this->init(name, age);
}

Person::~Person() {
    std::cout << "Dtor-> ~Person()-> (" << this->name << ", " << this->age << ")\n";
}

void Person::init(std::string name, int age) {
    this->name = name;
    this->age = age;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

std::string Person::getName() {
    return this->name;
}

int Person::getAge() {
    return this->age;
}

void Person::printInfo() {
    std::cout << "Name: " << this->name << '\n';
    std::cout << "Age: " << this->age << '\n';
}
