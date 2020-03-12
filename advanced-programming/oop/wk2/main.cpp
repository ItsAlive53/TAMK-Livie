#include <iostream>
#include <string>

#include "person.h"
#include "date.h"

void testFunction() {
    // Gets destroyed when function returns
    Person jkl = Person("Jkl", 24);
}

int main() {

    // Never gets destroyed unless delete is called
    Person* mno = new Person("Mno", 25);



    // Gets destroyed when program returns
    Person abc = Person("Abc", 21);

    std::cout << "Before if()\n";
    if (true) {
        // Gets destroyed when if-block ends
        Person def = Person("Def", 22);
    }
    std::cout << "After if()\n";

    std::cout << "Before for()\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "For loop i: " << i << '\n';
        // Gets destroyed when for-block ends, every iteration
        Person ghi = Person("Ghi", 23);
        std::cout << "For loop end\n";
    }
    std::cout << "After for()\n";

    std::cout << "Before function\n";
    testFunction();
    std::cout << "After function\n";

    // Necessary for objects created with new
    delete mno;

    std::cout << "End of program" << std::endl;
    return 0;
}
