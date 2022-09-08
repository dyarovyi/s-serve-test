#include "MainComponent.h"
#include "SourceCode.cpp"

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
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
    
    std::vector<std::pair<double, double>> data_for_linear = {
        std::pair<double, double>(1.0, 4.0),
        std::pair<double, double>(2.0, 1.0),
        std::pair<double, double>(3.0, 0.0),
        std::pair<double, double>(4.0, 1.0),
        std::pair<double, double>(5.0, 4.0)
    };   

    LinearInterpolator *LI = new LinearInterpolator(data_for_linear);
    LI->interpolate(4);
    
    for (auto iter = data_for_linear.begin(); iter != data_for_linear.end(); iter++) {
        std::cout << "( " << iter->first << " : " << iter->second << " )" << std::endl;
    }

    /* ---------- */

    /* In each std::pair<double, double>: [0] = y(x), [1] = dy(x) */ 
    std::vector<std::pair<double, double>> data_for_hermite = {
        std::pair<double, double>(0.6200860, -0.5220232),
        std::pair<double, double>(0.4554022, -0.5698959),
        std::pair<double, double>(0.2818186, -0.5811571)
    };  

    /* Each double = x[i] */
    std::vector<double> x_for_hermite = { 1.3, 1.6, 1.9 };

    HermiteInterpolator *HI = new HermiteInterpolator(data_for_hermite, x_for_hermite);
    HI->interpolate(2);
    
    int i = 0;
    for (auto iter = data_for_hermite.begin(); iter != data_for_hermite.end(); iter++) {
        std::cout << "( " << x_for_hermite[i] << " : " << iter->first << " : " << iter->second << " )" << std::endl;
        i++;
    }
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
