#include <string>
using namespace std;
#pragma once

class City {
    string cityName;
    double xCoordinate;
    double yCoordinate;

public:
    City(string name, double x, double y);
    string getCityName() const;
    double getX() const;
    double getY() const;
    // Distance between this city vs the other city. Check the slides for formula.
    double calculateDistance(const City& other) const;
};