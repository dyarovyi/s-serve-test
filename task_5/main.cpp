#include "task_5.cpp"

void present(std::vector<std::pair<double, double>> data) {
    for (auto iter = data.begin(); iter != data.end(); iter++) {
        std::cout << "( " << iter->first << " : " << iter->second << " )" << std::endl;
    }
}

void present(std::vector<std::pair<double, double>> data, std::vector<double> derivatives) {
    int i = 0;
    for (auto iter = data.begin(); iter != data.end(); iter++) {
        std::cout << "( " << iter->first << " : " << iter->second << " : " << derivatives[i] << " )" << std::endl;
        i++;
    }
}

int main() {
    std::vector<std::pair<double, double>> data_for_linear = {
        std::pair<double, double>(1.0, 4.0),
        std::pair<double, double>(2.0, 1.0),
        std::pair<double, double>(3.0, 0.0),
        std::pair<double, double>(4.0, 1.0),
        std::pair<double, double>(5.0, 4.0)
    };   

    LinearInterpolator *LI = new LinearInterpolator(data_for_linear);
    LI->interpolate(4);

    std::cout << "LINEAR INTERPOLATION" << std::endl;
    present(LI->get_data());

    /* ---------- */

    /* In each std::pair<double, double>: [0] = y(x), [1] = dy(x) */ 
    std::vector<std::pair<double, double>> data_for_hermite = {
        std::pair<double, double>(1.0, 4.0),
        std::pair<double, double>(2.0, 1.0),
        std::pair<double, double>(3.0, 0.0),
        std::pair<double, double>(4.0, 1.0),
        std::pair<double, double>(5.0, 4.0)
    };  

    /* Each double = x[i] */
    std::vector<double> derivatives_for_hermite = { 2.0, 4.0, 6.0, 8.0, 10.0 };

    HermiteInterpolator *HI = new HermiteInterpolator(data_for_hermite, derivatives_for_hermite);
    HI->interpolate(4);

    std::cout << "HEMITE INTERPOLATION" << std::endl;
    present(HI->get_data(), HI->derivatives);

    return 0;
}