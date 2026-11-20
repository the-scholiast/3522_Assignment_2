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
        string cityName = string("City") + static_cast<char>('A' + i);
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
    // generateCities();
    generateFixedCities();
    initializePop();
    initializeAlgo();

    algorithm->executeAlgorithm();
}

FittestTourFinder::~FittestTourFinder() {
    delete algorithm;
    delete population;
}

void FittestTourFinder::generateFixedCities() {
    const int coordinates[CITY_COUNT][2] = {
        {900, 500}, {892, 578}, {870, 653}, {833, 722},
        {783, 783}, {722, 833}, {653, 870}, {578, 892},
        {500, 900}, {422, 892}, {347, 870}, {278, 833},
        {217, 783}, {167, 722}, {130, 653}, {108, 578},
        {100, 500}, {108, 422}, {130, 347}, {167, 278},
        {217, 217}, {278, 167}, {347, 130}, {422, 108},
        {500, 100}, {578, 108}, {653, 130}, {722, 167},
        {783, 217}, {833, 278}, {870, 347}, {892, 422}
    };

    for (int i = 0; i < CITY_COUNT; i++) {
        string cityName = string("City") + to_string(i + 1);


        cities.push_back(City(cityName, coordinates[i][0], coordinates[i][1]));
    }
}