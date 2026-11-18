#include "FittestTourFinder.hpp"
#include <string>
#include <cstdlib>
using namespace std;

FittestTourFinder::FittestTourFinder()
    : population(nullptr), algorithm(nullptr) {}

FittestTourFinder& FittestTourFinder::getFittestTourFinder() {
    static FittestTourFinder singleton;
    return singleton;
}

void FittestTourFinder::generateCities() {
    for (int i = 0; i < CITY_COUNT; i++) {
        string cityName = "City" + static_cast<char>('A' + i);
        int randomXCoordinate = rand() % 1001;
        int randomYCoordinate = rand() % 1001;

        cities.push_back(City(cityName, randomXCoordinate, randomYCoordinate));
    }
}

void FittestTourFinder::initializePop() {
    population = new Population(cities, Population::POPULATION_SIZE);
}

void FittestTourFinder::initializeAlgo() {
    algorithm = new GeneticAlgorithm(*population);
}

void FittestTourFinder::execute() {
    generateCities();
    initializePop();
    initializeAlgo();

    algorithm->executeAlgorithm();
}

FittestTourFinder::~FittestTourFinder() {
    delete algorithm;
    delete population;
}