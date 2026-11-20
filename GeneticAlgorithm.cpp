#include "GeneticAlgorithm.hpp"
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(Population& pop)
    : population(pop), baseTour(pop.getBestFitness()), bestTour(pop.getBestFitness()), iteration(0) {}

const Tour& GeneticAlgorithm::randomBestTour() const {
    const Tour* fittestTour = &population.getRandomTour();

    for (int i = 1; i < RANDOM_SIZE; i++) {
        const Tour& randomTour = population.getRandomTour();
        if (randomTour.getFitness() < fittestTour->getFitness()) {
            fittestTour = &randomTour;
        }
    }

    return *fittestTour;
}

void GeneticAlgorithm::mutate(Tour& tour) {
    int citiesSize = tour.getCitiesSize();

    for (int i = 0; i < citiesSize - 1; i++) {
        double mutateProb = static_cast<double>(rand()) / RAND_MAX;
        if (mutateProb < MUTATION_RATE) {
            tour.swapCities(i, i + 1);
        }
    }
}

Tour GeneticAlgorithm::crossover(const Tour& tour1, const Tour& tour2) {
    int citiesSize = tour1.getCitiesSize();
    int randomIndex = rand() % citiesSize;
    vector<City*> tempCities;

    for (int i = 0; i <= randomIndex; i++) {
        tempCities.push_back(tour1.getCityByIndex(i));
    }

    for (int i = 0; i < citiesSize; i++) {
        City* tempCity = tour2.getCityByIndex(i);
        if (find(tempCities.begin(), tempCities.end(), tempCity) == tempCities.end()) {
            tempCities.push_back(tempCity);
        }
    }

    return Tour(tempCities);
}

void GeneticAlgorithm::createNewPopulation() {
    population.moveBestTourToFront();
    vector<Tour> tempTours;
    // Preserve best Tour
    tempTours.push_back(bestTour);

    // Fill temp tours with crossover tours
    while (tempTours.size() < population.getPopSize()) {
        const Tour* tour1 = &randomBestTour();
        const Tour* tour2 = &randomBestTour();

        while (tour1->getCities() == tour2->getCities()) {
            tour2 = &randomBestTour();
        }

        Tour crossoverTour = crossover(*tour1, *tour2);
        tempTours.push_back(crossoverTour);
    }

    // Mutate all non-best tours
    for (int i = 1; i < tempTours.size(); i++) {
        double mutateProb = static_cast<double>(rand()) / RAND_MAX;
        if (mutateProb < MUTATION_PERCENT) {
            mutate(tempTours[i]);
        }
    }

    population.replaceTours(tempTours);
}

bool GeneticAlgorithm::evaluateNewPopulation() {
    const Tour& currentBestTour = population.getBestFitness();

    if (currentBestTour.getFitness() < bestTour.getFitness()) {
        bestTour = currentBestTour;
        return true;
    }

    return false;
}

bool GeneticAlgorithm::metTarget() const {
    double newRatio = static_cast<double>(baseTour.getFitness()) / bestTour.getFitness();

    return newRatio >= TARGET_RATIO;
}

void GeneticAlgorithm::printProgress(bool newEliteFound) const {
    cout << "Iteration: " << iteration << endl;

    double improvementRatio = static_cast<double>(baseTour.getFitness()) / bestTour.getFitness();
    
    if (newEliteFound) {
        cout << "NEW ELETE FOUND" << endl;
        cout << "Distance: " << bestTour.getFitness() << endl;
    } else {
        cout << "Elite distance: " << bestTour.getFitness() << endl;
        const Tour& bestNonEliteTour = population.getBestNonElite();
        cout << "Best non-elite distance: " << bestNonEliteTour.getFitness() << endl;
    }

    cout << "Improvement over base: " << improvementRatio << endl;
    cout << endl;
}

void GeneticAlgorithm::printResults() const {
    cout << "--- FINISHED ALGORITHM ---" << endl;
    cout << "Total iterations: " << iteration << endl;
    cout << "Original Elite:" << endl;
    cout << "Distance: " << baseTour.getFitness() << endl;
    baseTour.printCities();

    cout << "\nBest elite:" << endl;
    cout << "Distance: " << bestTour.getFitness() << endl;
    bestTour.printCities();
    cout << endl;

    if (metTarget()) {
        cout << "Improvement factor reached!" << endl;
    } else {
        cout << "Improvment factor not reached." << endl;
    }

    double improvementRatio = static_cast<double>(baseTour.getFitness()) / bestTour.getFitness();
    cout << "Improvement factor: " << improvementRatio << endl;
}

void GeneticAlgorithm::executeAlgorithm() {
    cout << "Original Elite:" << endl;
    cout << "Distance: " << baseTour.getFitness() << endl;
    baseTour.printCities();

    cout << "\n--- STARTING ALGORITHM ---" << endl;

    while (!metTarget() && iteration < MAX_ITERATIONS) {
        createNewPopulation();
        bool newEliteFound = evaluateNewPopulation();
        population.moveBestTourToFront();
        printProgress(newEliteFound);
        iteration++;
    }

    printResults();
}