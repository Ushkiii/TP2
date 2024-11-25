#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void printSentencesWithoutCommas(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string sentence;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string word;
        sentence = "";

        while (ss >> word) {
            //Проверка на конец предложения (. ? !)
            if (word.back() == '.' || word.back() == '?' || word.back() == '!') {
                if (sentence.find(',') == std::string::npos) {
                    std::cout << sentence << word << std::endl;
                }
                sentence = "";
            } else {
                sentence += word + " ";
            }
        }
        //обработка последнего предложения без знака препинания в конце строки.
        if (!sentence.empty() && sentence.find(',') == std::string::npos)
        {
            std::cout << sentence << std::endl;
        }

    }
    inputFile.close();
}


int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    printSentencesWithoutCommas(filename);
    return 0;
}

