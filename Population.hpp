#include <vector>
#include "Tour.hpp"
#pragma once
using namespace std;

class Population { 
    vector<Tour> tours;

    void generateTours(vector<City>& cities, int popSize); // Use shuffle on cities to generate popSize number of tours

public:
    static const int POPULATION_SIZE = 30;  
    
    Population(vector<City>& cities, int popSize); // Use generateTours in here
    const vector<Tour>& getTours() const;
    const Tour& getBestFitness() const; // Find the tour with the lowest fitness
    void replaceTours(vector<Tour>& newTours);
    int getPopSize() const;
    const Tour& getRandomTour() const;
    void moveBestTourToFront(); // Move fittest tour to index[0] of tours
};