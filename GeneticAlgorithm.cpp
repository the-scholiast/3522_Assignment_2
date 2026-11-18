#include "GeneticAlgorithm.hpp"
#include <cstdlib>
#include <algorithm>
using namespace std;

GeneticAlgorithm::GeneticAlgorithm(Population& pop)
    : population(pop), baseTour(pop.getBestFitness()), bestTour(pop.getBestFitness()) {
        iteration = 0;
    }

const Tour& GeneticAlgorithm::randomBestTour() const {
    const Tour* fittestTour = &population.getRandomTour();

    for (int i = 1; i < RANDOM_SIZE; i++) {
        const Tour& randomTour = population.getRandomTour();
        if (randomTour.getFitness() > fittestTour->getFitness()) {
            fittestTour = &randomTour;
        }
    }

    return *fittestTour;
}

void GeneticAlgorithm::mutate(Tour& tour) {
    int citiesSize = tour.getCitiesSize();

    for (int i = 0; i < citiesSize - 2; i++) {
        double mutateProb = static_cast<double>(rand() / RAND_MAX);
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

    for (int i = randomIndex + 1; i < citiesSize; i++) {
        City* tempCity = tour2.getCityByIndex(i);
        if (find(tempCities.begin(), tempCities.end(), tempCity) == tempCities.end()) {
            tempCities.push_back(tempCity);
        }
    }

    return Tour(tempCities);
}

