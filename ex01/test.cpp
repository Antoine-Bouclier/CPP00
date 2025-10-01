#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string input = "1234";

    if (!input.empty() && 
        std::find_if(input.begin(), input.end(),
                     [](unsigned char c) { return !std::isdigit(c); }) == input.end()) 
    {
        std::cout << "La chaîne est uniquement numérique." << std::endl;
    } else {
        std::cout << "La chaîne contient des caractères non numériques." << std::endl;
    }
}
