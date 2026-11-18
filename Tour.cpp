#include "Tour.hpp"
#include <utility>
#include <algorithm>
#include <random>
#include <iostream>


double Tour::calculateFitness(){
    double totalDistance = 0;
    for (size_t i = 0; i < cities.size(); i++) {
        size_t next = (i + 1) % cities.size();
        totalDistance += cities[i]->calculateDistance(*cities[next]);
    }
    fitness = totalDistance;
    return fitness;
}

Tour::Tour(vector<City *> c) : cities(c)
{
    calculateFitness();
}

double Tour::getFitness() const{
    return fitness;
}

void Tour::swapCities(int index1, int index2){
    std::swap(cities[index1], cities[index2]);
    calculateFitness();
}

void Tour::shuffleCities(){
    static std::mt19937 rng(std::random_device{}());
    std::shuffle(cities.begin(), cities.end(), rng);
    calculateFitness();
}

vector<City *> Tour::getCities() const{
    return cities;
}

void Tour::printCities() const{
    cout << "(";
    for (size_t i = 0; i < cities.size(); i++)
    {
        cout << cities[i]->getCityName() << "->";
    }
    cout << cities[0]->getCityName();
    cout << ")" << endl;
}

const int Tour::getCitiesSize() const {
    return cities.size();
}

City* Tour::getCityByIndex(int index) const {
    return cities[index];
}