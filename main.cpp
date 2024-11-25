#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Keeper.h"
#include "Worker.h"
using namespace std;

void task_2(const string& filename) {
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
    int choice;
A:
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. task 1" << endl;
        cout << "2. task 2" << endl;
        cout << "0. quit" << endl;
        cout << "> ";
        cin >> choice;
        switch (choice) {
        case 1: {
            Worker buffer;
            Keeper keeper;
            string filename = "task1.txt";
            while (true) {
                cout << "Menu task 1:"  << endl;
                cout << "1. Add object" << endl;
                cout << "2. Load "    	 << endl;
                cout << "3. Save"       << endl;
                cout << "4. Print all"  << endl;
                cout << "5. Search"     << endl;
                cout << "6. Remove item"<< endl;
                cout << "0. Back"       << endl;
                cout << "> ";
                cin >> choice;
                switch (choice) {
                case 1:
                    cin >> buffer;
                    keeper.Push(buffer);
                    break;

                case 2:
                    cout << "Enter load file: ";
                    cin >> filename;
                    keeper = keeper.Load(filename);
                    break;

                case 3:
                    cout << "Enter save file: ";
                    cin >> filename;
                    keeper.Save(filename);
                    break;
                    break;

                case 4:
                    keeper.Print();
                    break;

                case 5:
                    keeper.Search();
                    break;

                case 6:
                    keeper.Remove();
                    break;

                case 0:
                    goto A;

                default:
                    cout << "Choose correct option" << endl;

                    break;
                }
            }
        }
        case 2: {
            string filename = "";
            cout << "Enter file name: ";
            cin >> filename;
            task_2(filename);
            break;
        }

        case 0: {
            return 0;
        }

        default: {
            cout << "Choose correct option" << endl;
            break;
        }

        }

    }
}