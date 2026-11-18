#include "Population.hpp"
#pragma once
using namespace std;

class GeneticAlgorithm {
    static const int RANDOM_SIZE = 5;
    static const double MUTATION_RATE = 0.15;
    static const double TARGET_RATIO = 1.2;
    static const int MAX_ITERATIONS = 1000;

    Population& population;
    Tour baseTour;
    Tour bestTour;
    int iteration;

public:
    GeneticAlgorithm(Population& pop);
    void executeAlgorithm(); // Runs the entire flow and iterations
    const Tour& randomBestTour() const; // Compare 5 random tours and return the fittest
    Tour crossover(const Tour& tour1, const Tour& tour2);
    void mutate(Tour& tour);
    void createNewPopulation();
    bool evaluateNewPopulation(); // Checks if the new pop contains a better Tour
    bool metTarget() const; // Checks it the new best tour has reached the target of 1.2 (baseTour/bestTour)
    void printProgress(bool) const; // Prints current iteration, base and best fittness, and improvment ratio of new pop
    void printResults() const; // Prints initial and best tour and fittness, # of iterations, improvement ratio, if target reached,  
};