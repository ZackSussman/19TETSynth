/*
  ==============================================================================

    SustainIndicatorLine.cpp
    Created: 27 Jun 2020 6:34:53am
    Author:  Zack Sussman

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SustainIndicatorLine.h"

//==============================================================================
SustainIndicatorLine::SustainIndicatorLine()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

SustainIndicatorLine::~SustainIndicatorLine()
{
}

void SustainIndicatorLine::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    g.setColour(color);
    g.drawLine(getWidth()/10 + getWidth()/5 - 14, 17*getHeight()/20 - getHeight()/30, getWidth()/10 + getWidth()/5 - 14, 17*getHeight()/20 - getHeight()/23, 1);
    
}

void SustainIndicatorLine::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
