#include "InFile.h"

void InFile::init() {
    file.open(fileName.c_str());
    if (file.fail()) {
        status = ABNORM;
        throw FileNotFoundException;
    }
}

void InFile::read() {
    std::string tmp;
    std::stringstream line;

    getline(file, tmp);
    if (file.fail()) {
        status = ABNORM;
        return;
    }

    status = NORM;
    line << tmp;
    std::string id;
    std::string date;
    int weight;
    int distance;

    line >> id >> date >> weight >> distance;
    setCurrent(id, date, weight, distance);
}
