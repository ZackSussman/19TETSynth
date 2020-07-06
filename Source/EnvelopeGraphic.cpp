/*
  ==============================================================================

    EnvelopeGraphic.cpp
    Created: 2 Jul 2020 10:04:26am
    Author:  Zack Sussman

  ==============================================================================
*/

#include <JuceHeader.h>
#include "EnvelopeGraphic.h"

//==============================================================================
EnvelopeGraphic::EnvelopeGraphic()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

EnvelopeGraphic::~EnvelopeGraphic()
{
}

void EnvelopeGraphic::paint (Graphics& g)
{
    g.setColour(Colours::limegreen);
    envelopePath.clear();
    envelopePath.startNewSubPath(0, getHeight());
    envelopePath.lineTo(getWidth()*(attackTime/(attackTime + decayTime + sustainTime + releaseTime)), getHeight()*(1-attackAmp));
    envelopePath.lineTo(getWidth()*((attackTime + decayTime)/(attackTime + decayTime + sustainTime + releaseTime)), getHeight()*(1-sustainAmp));
    envelopePath.lineTo(getWidth()*((attackTime + decayTime + sustainTime)/(attackTime + decayTime + sustainTime + releaseTime)), getHeight()*(1-sustainAmp));
    envelopePath.lineTo(getWidth(), getHeight());
    g.strokePath(envelopePath, PathStrokeType(2));


}

void EnvelopeGraphic::updateValues(double aT,double dT,double sT,double rT,double aA,double sA) {
    attackTime = aT;
    decayTime = dT;
    sustainTime = sT;
    decayTime = dT;
    
    attackAmp = aA;
    sustainAmp = sA;
    repaint();
}

void EnvelopeGraphic::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
