#include <iostream>
#include <vector>
#include <cmath>

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
    std::vector<double> x;
    HermiteInterpolator(const std::vector<std::pair<double, double>> &new_data, std::vector<double> &new_x);
    void interpolate(int intervals);
    double f(double x, double x0, double x1, double y0, double dy0, double y1, double dy1);
};