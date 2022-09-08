#include "SourceCode.h"

Interpolator::Interpolator(const std::vector<std::pair<double, double>> &new_data) : data(new_data) {
    std::sort(data.begin(), data.end());
}

std::vector<std::pair<double, double>> &Interpolator::get_data() {
    return data;
}

/* ---------- */

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

/* ---------- */

HermiteInterpolator::HermiteInterpolator(const std::vector<std::pair<double, double>> &new_data, std::vector<double> &new_x) : Interpolator(new_data), x(new_x) {}

double HermiteInterpolator::f(double x, double x0, double x1, double y0, double dy0, double y1, double dy1) {
    double lval = ((1 - (2 * (x - x0) / (x0 - x1))) * y0 + (x - x0) * dy0) * pow(((x - x1) / (x0 - x1)), 2);
    double rval = ((1 - (2 * (x - x1) / (x1 - x0))) * y1 + (x - x0) * dy1) * pow(((x - x0) / (x1 - x0)), 2);
    
    return lval + rval;
}

/* For chosen number of intervals function finds values for each interval */
void HermiteInterpolator::interpolate(int intervals) {
    std::vector<std::pair<double, double>> data_result;
    std::vector<double> x_result;

    for (int i = 0; i < x.size() - 1; i++) {
        double step = (x[i + 1] - x[i]) / intervals;

        for (double z = x[i]; z != x[i + 1]; z += step) {
            double x0 = x[i];
            double x1 = x[i + 1];
            double y0 = data[i].first;
            double dy0 = data[i].second;
            double y1 = data[i + 1].first;
            double dy1 = data[i + 1].second;

            double y = f(z, x0, x1, y0, dy0, y1, dy1);

            if (z == x[i]) {
                data_result.push_back(std::pair<double, double>(y0, dy0));
            } else {
                data_result.push_back(std::pair<double, double>(y, (dy1 + dy0) / 2));
            }
            x_result.push_back(z);
        }
    }

    data_result.push_back(std::pair<double, double>((data.end() - 1)->first, (data.end() - 1)->second));
    x_result.push_back(*(x.end() - 1));

    data.clear();
    x.clear();
    data.insert(data.end(), data_result.begin(), data_result.end());
    x.insert(x.end(), x_result.begin(), x_result.end());

    std::reverse(data.begin(), data.end());
}