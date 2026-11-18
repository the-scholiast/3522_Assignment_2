#include "Population.hpp"
#include <utility>
#include <random>

void Population::generateTours(vector<City> &cities, int popSize)
{
    vector<City*> citiesAddress;
    for (size_t i = 0; i < cities.size(); i++)
    {
        citiesAddress.push_back(&cities[i]);
    }
    for (int i = 0; i < popSize; i++)
    {
        Tour tour(citiesAddress);
        tour.shuffleCities();
        tours.push_back(tour);
    }
}

Population::Population(vector<City> &cities, int popSize){
    generateTours(cities, popSize);
}

int Population::getPopSize() const {
    return tours.size();
}

const vector<Tour> &Population::getTours() const
{
    return tours;
}

size_t Population::getBestIndex() const
{
    size_t smallestFitness = 0;
    for (size_t i = 1; i < tours.size(); i++)
    {
        if (tours[smallestFitness].getFitness() > tours[i].getFitness())
        {
            smallestFitness = i;
        }
    }
    return smallestFitness;
}

const Tour &Population::getBestFitness() const // Find the tour with the lowest fitness
{
    return tours[getBestIndex()];
}

void Population::moveBestTourToFront(){
    std::swap(tours[0], tours[getBestIndex()]);
}

void Population::replaceTours(vector<Tour> &newTours){
    tours = newTours;
}
const Tour& Population::getRandomTour() const{
    static std::mt19937 rng(std::random_device{}()); //generate seed
    std::uniform_int_distribution<size_t> dist(0, tours.size() -1); //get the random index
    return tours[dist(rng)];
}
