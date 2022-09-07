#include "task_5.hpp"

Interpolator::Interpolator(const std::vector<std::pair<double, double>> &new_data) : data(new_data) {
    std::sort(data.begin(), data.end());
}

std::vector<std::pair<double, double>> &Interpolator::get_data() {
    return data;
}

LinearInterpolator::LinearInterpolator(const std::vector<std::pair<double, double>> &new_data) : Interpolator(new_data) {}

double LinearInterpolator::f(double x) {
    /* Check if given X is less than X int data */
    auto lessThan = [](const std::pair<double, double>& point, double x) {
        return point.first < x;
    };

    /* Find first element that is lower than X */
    auto iter = std::lower_bound(data.begin(), data.end(), x, lessThan);

    /* Check if X is greater than the greatest in data */
    if (iter == data.end())
        return (data.end() - 1)->second;

    /* Check if X is lower than the lowest in data */
    if (iter == data.begin() && x <= data.begin()->first)
        return data.begin()->second;

    double x0 = (iter - 1)->first;
    double y0 = (iter - 1)->second;
    double x1 = iter->first;
    double y1 = iter->second;

    double dx = x1 - x0;
    double dy = y1 - y0;

    return y0 + ((x - x0)/ dx) * dy;
}

HermiteInterpolator::HermiteInterpolator(const std::vector<std::pair<double, double>> &new_data) : Interpolator(new_data) {}

double HermiteInterpolator::f(double x) {
    return 0;
}

/* For chosen number of intervals function finds values for each interval */
void LinearInterpolator::interpolate(int intervals) {
    std::vector<std::pair<double, double>> result;
    for (auto iter = data.begin(); iter != data.end() - 1; iter++) {
        double step = ((iter + 1)->first - iter->first) / intervals;
        for (double x = iter->first; x != (iter + 1)->first; x += step) {
            double y = f(x);
            result.push_back(std::pair<double, double>(x, y));
        }
    }
    result.push_back(std::pair<double, double>((data.end() - 1)->first, (data.end() - 1)->second));

    data.clear();
    data.insert(data.end(), result.begin(), result.end());
}

/* For chosen number of intervals function finds values for each interval */
void HermiteInterpolator::interpolate(int intervals) {
    
}