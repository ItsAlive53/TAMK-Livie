#include <iostream>
#include <map>

int main() {
    float weight, height;

    // <upper weight limit, price>
    std::map<float, std::string> indices;
    indices[20.7f] = "underweight";
    indices[26.4f] = "normal";
    indices[27.8f] = "slightly overweight";
    indices[31.1f] = "overweight";
    indices[100000.0f] = "very overweight";

    std::cout << "Enter weight (kg), then height (m): ";
    std::cin >> weight >> height;

    std::map<float, std::string>::iterator i = indices.begin();
    while (i != indices.end()) {
        float index = weight / (height*height);

        // first = key = upper limit
        // second = value = string
        if (index <= i->first) {
            std::cout << "According to your inputs, you're " << i->second << std::endl;

            return 0;
        }

        i++;
    }

    // reach here = over all limits
    std::cout << "Error in input." << std::endl;
    return 0;
}

