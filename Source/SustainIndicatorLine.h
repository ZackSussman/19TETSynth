/*
  ==============================================================================

    SustainIndicatorLine.h
    Created: 27 Jun 2020 6:34:53am
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SustainIndicatorLine    : public Component
{
public:
    SustainIndicatorLine();
    ~SustainIndicatorLine();
    
    Colour color = Colours::grey;
    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SustainIndicatorLine)
};
