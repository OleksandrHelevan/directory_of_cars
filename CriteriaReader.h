#ifndef DIRECTORY_OF_CARS_CRITERIAREADER_H
#define DIRECTORY_OF_CARS_CRITERIAREADER_H
#include "FileReader.h"

class CriteriaReader :public FileReader{
    string criteria_file;

public:
    explicit CriteriaReader(string &file){
        this->criteria_file = file;
    }
    ~CriteriaReader() override = default;

    void read_file() override {
        cout<<endl;
        cout<<"This is criteria for your choice:"<<endl;
        ifstream fin(criteria_file);
        std::unique_ptr<string> s = std::make_unique<string>(" ");
        try {
            if (!fin.is_open()) {
                throw std::runtime_error("Could not open the file: " + criteria_file);
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
#endif //DIRECTORY_OF_CARS_CRITERIAREADER_H
