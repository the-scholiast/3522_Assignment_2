class Population;
class GeneticAlgorithm;
#include <vector>
class City;
using namespace std;

class FittestTourFinder {
    static const int CITY_COUNT = 20;
    static const int MIN_COORDINATE = 0;
    static const int MAX_COORDINATE = 1000;

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