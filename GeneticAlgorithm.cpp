#include "GeneticAlgorithm.hpp"
#include <cstdlib>

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