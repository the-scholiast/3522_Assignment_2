#include "City.hpp"
#include <cmath>

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

double City::calculateDistance(const City &other) const
{
    double distance;
    distance = sqrt((xCoordinate - other.xCoordinate) * (xCoordinate - other.xCoordinate) + (yCoordinate - other.yCoordinate) * (yCoordinate - other.yCoordinate));
    return distance;
}
