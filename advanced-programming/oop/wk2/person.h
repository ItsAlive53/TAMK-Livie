#pragma once

class Person {
public:
    Person();
    Person(std::string name);
    Person(std::string name, int age);

    ~Person();

    void setName(std::string name);
    void setAge(int age);

    std::string getName();
    int getAge();

    void printInfo();

private:
    std::string name;
    int age;

    void init(std::string name, int age);


};
