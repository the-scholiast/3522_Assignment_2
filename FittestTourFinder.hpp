class Population;
class GeneticAlgorithm;
#include <vector>
class City;
using namespace std;

class FittestTourFinder {
    vector<City> cities;
    Population* population;
    GeneticAlgorithm* algorithm;

    FittestTourFinder();

    void generateCities();
    void initializePop();
    void initializeAlgo();

public:
    static FittestTourFinder& getFittestTourFinder();
    ~FittestTourFinder();
    FittestTourFinder(const FittestTourFinder&) = delete;
    FittestTourFinder& operator=(const FittestTourFinder&) = delete;
    void execute();
};