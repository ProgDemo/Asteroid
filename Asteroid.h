#ifndef ASTEROID_H_INCLUDED
#define ASTEROID_H_INCLUDED

#include<vector>
#include<ostream>
#include<sstream>

class Asteroid {

    private:
        std::string id;
        std::string date;
        int weight;
        int distance;

    public:
        Asteroid(std::string id = "", std::string date = "0000.00.00", int weight = 0, int distance = 0):
            id(id), date(date), weight(weight), distance(distance) {}

        void setId(const std::string& id) { this->id = id; }
        void setDate(const std::string& date) { this->date = date;}
        void setWeight(const int& weight) { this->weight = weight; }
        void setDistance(const int& distance) {this->distance = distance; }

        std::string getId() { return id; }
        std::string getDate() {return date; }
        int getWeight() { return weight; }
        int getDistance() { return distance; }

        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& out, const Asteroid& asteroid);


};

#endif // ASTEROID_H_INCLUDED
