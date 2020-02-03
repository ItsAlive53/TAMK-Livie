#include <iostream>
#include <fstream>

int main() {
    std::ifstream fRandom;
    int num, numCount = 0, sum = 0;

    fRandom.open("Random.txt");

    if (!fRandom) {
        std::cout << "Something went wrong in opening file" << std::endl;
        return 1;
    }

    while (fRandom >> num) {
        sum += num;
        numCount++;
    }

    fRandom.close();

    std::cout << "File has " << numCount << " numbers in it\n";
    std::cout << "Sum of the files numbers is " << sum << '\n';
    std::cout << "Average of files numbers is " << (double)sum / (double)numCount << std::endl;

    return 0;
}
