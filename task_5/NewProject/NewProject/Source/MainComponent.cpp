#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::orange);


    std::vector<std::pair<double, double>> data_for_linear = {
        std::pair<double, double>(1.0, 4.0),
        std::pair<double, double>(2.0, 1.0),
        std::pair<double, double>(3.0, 0.0),
        std::pair<double, double>(4.0, 1.0),
        std::pair<double, double>(5.0, 4.0)
    };

    LinearInterpolator* LI = new LinearInterpolator(data_for_linear);
    LI->interpolate(4);

    std::cout << "LINEAR INTERPOLATION" << std::endl;

    std::vector<juce::Line<float>> liner_linear;
    for (auto iter = LI->data.begin(); iter != LI->data.end() - 1; iter++) {
        juce::Point<float> a(iter->first * 50, iter->second * 50);
        juce::Point<float> b((iter + 1)->first * 50, (iter + 1)->second * 50);
        liner_linear.push_back(juce::Line<float>(a, b));
        g.drawRoundedRectangle(a.getX(), a.getY(), 5, 5, 5, 5);
        g.drawRoundedRectangle(b.getX(), b.getY(), 5, 5, 5, 5);
    }

    for (auto iter = liner_linear.begin(); iter != liner_linear.end(); iter++) {
        g.drawLine(*iter, 2.0f);
    }

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


    int i = 0;
    std::vector<juce::Line<float>> lines_hermite;
    for (auto iter = HI->data.begin(); iter != HI->data.end() - 1; iter++) {
        juce::Point<float> a(iter->first * 200 + 200, iter->second * 200);
        juce::Point<float> b((iter + 1)->first * 200 + 200, (iter + 1)->second * 200);
        lines_hermite.push_back(juce::Line<float>(a, b));
        g.drawRoundedRectangle(a.getX(), a.getY(), 5, 5, 5, 5);
        g.drawRoundedRectangle(b.getX(), b.getY(), 5, 5, 5, 5);
    }

    for (auto iter = lines_hermite.begin(); iter != lines_hermite.end(); iter++) {
        g.drawLine(*iter, 2.0f);
    }
    
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
