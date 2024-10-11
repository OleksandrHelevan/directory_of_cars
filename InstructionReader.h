#ifndef DIRECTORY_OF_CARS_INSTRUCTIONREADER_H
#define DIRECTORY_OF_CARS_INSTRUCTIONREADER_H

#include "FileReader.h"
class InstructionReader :public FileReader{
    string instruction;

public:
    explicit InstructionReader(string &file){
        this->instruction = file;
    };

    string get_instruction(){
        return instruction;
    }

    void set_instruction(string &instr){
        this->instruction = instr;
    }
    ~InstructionReader() override = default;

    void read_file() override {
        cout<<"Hello USER!!!"<<endl;
        cout<<"This is INSTRUCTION how to use this program"<<endl;
        ifstream fin(instruction);
        std::unique_ptr<string> s = std::make_unique<string>(" ");
        try {
            if (!fin.is_open()) {
                throw std::runtime_error("Could not open the file: " + instruction);
            }
            while (std::getline(fin, *s)) {
                std::cout << *s << endl;
            }
            fin.close();
            cout << endl << "This program was made by Oleksandr Helevan" << endl;
        } catch (const std::exception &e) {
            fin.close();
            std::cerr << e.what() << std::endl;
        }
    }
};


#endif //DIRECTORY_OF_CARS_INSTRUCTIONREADER_H
