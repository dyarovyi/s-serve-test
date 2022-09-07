#include <iostream>
#include <vector>

class Interpolator {
public:
    std::vector<std::pair<double, double>> data;

    Interpolator(const std::vector<std::pair<double, double>> &new_data);

    std::vector<std::pair<double, double>> &get_data();

    virtual void interpolate(int intervals) = 0;
    double f(double x);
};

class LinearInterpolator : public Interpolator {
public:
    LinearInterpolator(const std::vector<std::pair<double, double>> &new_data);
    void interpolate(int intervals);
    double f(double x);
};

class HermiteInterpolator : public Interpolator {
public:
    HermiteInterpolator(const std::vector<std::pair<double, double>> &new_data);
    void interpolate(int intervals);
    double f(double x);
};