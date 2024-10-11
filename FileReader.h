#ifndef DIRECTORY_OF_CARS_FILEREADER_H
#define DIRECTORY_OF_CARS_FILEREADER_H

#include <iostream>
#include <fstream>
#include <memory>
#include <exception>


using namespace std;

class FileReader{
public:
    FileReader()= default;
    virtual ~FileReader() = default;
    virtual void read_file() = 0;

};
#endif //DIRECTORY_OF_CARS_FILEREADER_H
