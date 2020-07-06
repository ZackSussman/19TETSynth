/*
  ==============================================================================

    EnvelopeGraphic.h
    Created: 2 Jul 2020 10:04:26am
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class EnvelopeGraphic    : public Component
{
public:
    EnvelopeGraphic();
    ~EnvelopeGraphic();
    
    void paint (Graphics&) override;
    void resized() override;
    
    void updateValues(double aT,double dT,double sT,double rT,double aA,double sA);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeGraphic)
    double attackTime = .2;
    double decayTime = .2;
    double sustainTime = 5;
    double releaseTime = .2;
    


    double attackAmp = 1;
    double sustainAmp = .8;
    
    Path envelopePath;
};
