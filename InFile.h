#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED

#include<sstream>
#include<fstream>
#include<vector>
#include "Asteroid.h"

class InFile {

    private:
        enum Status {NORM, ABNORM};
        std::string fileName;
        std::ifstream file;
        Asteroid current;
        Status status;
        void read();
        void setCurrent(const std::string& id, const std::string& date, const int& weight, const int& distance) {
            current.setId(id);
            current.setDate(date);
            current.setWeight(weight);
            current.setDistance(distance);
        }

    public:
        enum InFileExceptions {FileNotFoundException, EmptyFileException};
        InFile(const std::string& fileName): fileName(fileName) {}
        void init();
        void first() {
            read();
            if (end()) {
                throw EmptyFileException;
            }
        }
        void next() {read(); }
        Asteroid getCurrent() const { return current; }
        bool end() const {return status == ABNORM; }

};

#endif // INFILE_H_INCLUDED
