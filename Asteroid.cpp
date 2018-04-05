#include "Asteroid.h"

std::string Asteroid::toString() const {
    std::stringstream tmp;
    tmp << id << ": " << date << ", " << weight << ", " << distance;

    return tmp.str();
}

std::ostream& operator<<(std::ostream& out, const Asteroid& asteroid) {
    out << asteroid.toString();
    return out;
}
