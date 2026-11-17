#include <vector>
#include "Tour.hpp"
#pragma once
using namespace std;

class Population {
    static const int POPULATION_SIZE = 30;    

    vector<Tour> tours;

    void generateTours(vector<City>& cities, int popSize); // Use shuffle on cities to generate popSize number of tours

public:
    Population(vector<City>& cities, int popSize); // Use generateTours in here
    const vector<City>& getTours() const;
    const Tour& getBestFitness() const; // Find the tour with the lowest fitness
    void replaceTours(vector<Tour>& newTours);
    int getPopSize() const;
    const Tour& getRandomTour() const;
    void moveBestTourToFront(); // Move fittest tour to index[0] of tours
};