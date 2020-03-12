#include <iostream>
#include <string>

#include "person.h"

Person::Person() {
    this->init("default", -1);
}

Person::Person(std::string name) {
    this->init(name, -1);
}

Person::Person(std::string name, int age) {
    this->init(name, age);
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
