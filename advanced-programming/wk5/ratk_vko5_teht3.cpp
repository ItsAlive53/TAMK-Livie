#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile;
    std::string name, desc;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter short description: ";
    std::getline(std::cin, desc);

    outFile.open("index.html");

    outFile << "<!doctype html>\n"
            << "<html lang=\"en\">\n"
            << "<head>\n"
            << "\t<title>PLACEHOLDER_TEXT</title>\n"
            << "\t<meta charset=\"UTF-8\">\n"
            << "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
            << "\t<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css\">\n"
            << "</head>\n"
            << "\n"
            << "<body class=\"bg-secondary\">\n"
            << "\t<div class=\"container-fluid text-light\">\n"
            << "\t\t<div class=\"row mt-3\">\n"
            << "\t\t\t<div class=\"col\">\n"
            << "\t\t\t\t<h1 id=\"name\">" << name << "</h1>\n"
            << "\t\t\t</div>\n"
            << "\t\t</div>\n"
            << "\t\t<div class=\"row\">\n"
            << "\t\t\t<div class=\"col-1\"></div>\n"
            << "\t\t\t<div class=\"col\">\n"
            << "\t\t\t\t<p id=\"description\">" << desc << "</p>\n"
            << "\t\t\t</div>\n"
            << "\t\t</div>\n"
            << "\t</div>\n"
            << "</body>\n"
            << "</html>\n";

    outFile.close();
    std::cout << "File writted (index.html)" << std::endl;

    return 0;
}
