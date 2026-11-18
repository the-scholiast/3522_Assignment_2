#include <vector>
#include "City.hpp"
using namespace std;
#pragma once

class Tour {
    vector<City*> cities;
    double fitness = 0;

public:
    Tour(vector<City*>); // Calculate fitness as well
    Tour();
    // Recalculate fitness and update cities order after shuffle or swap
    void shuffleCities(); // Use random to randomize the index order
    void swapCities(int index1, int index2);
    double calculateFitness();
    double getFitness() const;
    vector<City*> getCities() const;
    void printCities() const; // Print the route of the cities in order of index and then returning back to first city
    int getCitiesSize() const;
    City* getCityByIndex(int) const;
};