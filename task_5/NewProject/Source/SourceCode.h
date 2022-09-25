/*
  ==============================================================================

    SourceCode.h
    Created: 8 Sep 2022 10:51:25am
    Author:  dyaro

  ==============================================================================
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Interpolator {
public:
    std::vector<std::pair<double, double>> data;

    Interpolator(const std::vector<std::pair<double, double>>& new_data);

    std::vector<std::pair<double, double>>& get_data();
    virtual void interpolate(int intervals) = 0;
    double f(double x);
};

class LinearInterpolator : public Interpolator {
public:
    LinearInterpolator(const std::vector<std::pair<double, double>>& new_data);
    void interpolate(int intervals);
    double f(double x);
};

class HermiteInterpolator : public Interpolator {
public:
    std::vector<double> derivatives;
    HermiteInterpolator(const std::vector<std::pair<double, double>> &new_data, std::vector<double> &derivatives);
    void interpolate(int intervals);
    double f(double x, double x0, double x1, double y0, double dy0, double y1, double dy1);
};
