#include "task_5.cpp"

void present(std::vector<std::pair<double, double>> data) {
    for (auto iter = data.begin(); iter != data.end(); iter++) {
        std::cout << "( " << iter->first << " : " << iter->second << " )" << std::endl;
    }
}

int main() {
    std::vector<std::pair<double, double>> data = {
        std::pair<double, double>(1.0, 4.0),
        std::pair<double, double>(2.0, 1.0),
        std::pair<double, double>(3.0, 0.0),
        std::pair<double, double>(4.0, 1.0),
        std::pair<double, double>(5.0, 4.0)
    };

    LinearInterpolator *LI = new LinearInterpolator(data);
    LI->interpolate(4);

    present(LI->get_data());

    return 0;
}