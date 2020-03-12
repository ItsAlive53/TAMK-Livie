#include <iostream>
#include <string>

#include "person.h"
#include "date.h"

int main() {
    Person abc = Person("Abc", 21);

    abc.printInfo();

    Person people[10];

    return 0;
}
