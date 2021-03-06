#ifndef SELFORGANIZINGMAP_H
#define SELFORGANIZINGMAP_H

#include <vector>
#include <utility>
#include <random>
#include <memory>
#include <algorithm>
#include <math.h>

using namespace std;

typedef pair<double, double> point;
typedef vector<point> cityMap;

enum DecayType
{
    STATIC,
    LINEAR,
    EXPONENTIAL,
};

class SelfOrganizingMap
{
private:
    static constexpr double LEARNING_RATE = 0.2;
    int RADIUS;

    // Algorithm methods
    int bestMatchingUnit(const point &city);
    int bestMatchingUnitSerialized(const point &city);
    std::vector<int> neighborhood(int bmu_index) const;
    void updateWeights(std::vector<int>& neighborhood_indexes, const point &city, int bmu_index);
    void calculateTourDistance();

    double euclideanNorm(const point &a, const point &b) const;
    double euclideanDistance(const point &a, const point &b) const;
    double euclideanDistanceScaled(const point &a, const point &b) const;

    double learningRate() const;
    double learningRateStatic() const;
    double learningRateLinear() const;
    double learningRateExponential() const;

    int radius() const;
    int radiusStatic() const;
    int radiusLinear() const;
    int radiusExponential() const;

    double influence(const point &node, const point &bmu) const;
    double influenceStatic() const;
    double influenceGaussian(const point &node, const point &bmu) const;

    random_device random_engine;

public:
    SelfOrganizingMap();

    void newCityInstance(const cityMap &data);
    void generateCircularCityMap(cityMap &cm, double radius, int len);
    void generateRandomCityMap(cityMap &cm, int len);

    void oneStep(const point& city);
    void oneEpoch();

    void makeTour();

    double x_scaling;
    double y_scaling;

    vector<int> tour_indexes;
    double tour_distance = 0.0;

    int epoch = 1;
    int epoch_radius;
    double epoch_learning_rate;

    int num_of_cities;
    int num_of_nodes;
    int num_of_iterations = 20;
    cityMap cities;
    cityMap nodes;

    DecayType decay_type = LINEAR;
    DecayType influence_type = EXPONENTIAL;
};





#endif // SELFORGANIZINGMAP_H
