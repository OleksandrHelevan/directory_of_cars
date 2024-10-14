#ifndef DIRECTORY_OF_CARS_FILEREADER_H
#define DIRECTORY_OF_CARS_FILEREADER_H

#include <iostream>
#include <fstream>
#include <memory>
#include <exception>

using namespace std;

class FileReader {
public:
    FileReader() = default;

    virtual ~FileReader() = default;

    static void read_file(string &file) {
        ifstream fin(file);
        std::unique_ptr<string> s = std::make_unique<string>(" ");
        try {
            if (!fin.is_open()) {
                throw std::runtime_error("Could not open the file: " + file);
            }
            while (std::getline(fin, *s)) {
                std::cout << *s << endl;
            }
            fin.close();
        } catch (const std::exception &e) {
            fin.close();
            std::cerr << e.what() << std::endl;
        }
    }

};

#endif //DIRECTORY_OF_CARS_FILEREADER_H
