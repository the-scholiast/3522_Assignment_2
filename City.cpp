#include "City.hpp"

City::City(string name, double x, double y): cityName(name), xCoordinate(x), yCoordinate(y) {}

string City::getCityName() const {
    return cityName;
}
double City::getX() const {
    return xCoordinate;
}
double City::getY() const {
    return yCoordinate;
}

