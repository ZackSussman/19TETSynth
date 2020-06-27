/*
  ==============================================================================

    PianoKeys.cpp
    Created: 27 Jun 2020 6:57:25am
    Author:  Zack Sussman

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PianoKeys.h" 

//==============================================================================
PianoKeys::PianoKeys()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

PianoKeys::~PianoKeys()
{
}

void PianoKeys::paintAgain() {
    repaint();
}

void PianoKeys::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    int totalXAdjust = 80;
    int totalYAdjust = 40;
    
    for (int i = -1; i < 8; i++) {
        g.setColour(normalKeysColor);
        
        if (notesOn[whiteKeyTransferIndex[i]] && i != 7) {
            g.setColour(Colours::red);
        }
        
        if (i == 7 || i == -1) {
            g.setColour(Colours::limegreen);
        }
        
        
        g.fillRect(i*keyWidth + getWidth()/4 + totalXAdjust, getHeight()/4 - totalYAdjust, keyWidth, keyHeight);
        g.setColour(Colours::black);
        g.drawRect(i*keyWidth + getWidth()/4 + totalXAdjust, getHeight()/4 - totalYAdjust, keyWidth, keyHeight);
    }
    

    for (int i = 0; i < 6; i++) {
        if (i >= 2 ) {
            g.setColour(firstUpColor);
            if (notesOn[firstUpTransferIndex[i-1]]) {
                g.setColour(Colours::red);
            }
        }
        else {
            g.setColour(firstUpColor);
            if (notesOn[firstUpTransferIndex[i]]) {
                g.setColour(Colours::red);
            }
        }
        if (i != 2) {
            g.fillRect(i*keyWidth + keyWidth/3 + getWidth()/4 + totalXAdjust, getHeight()/4 - totalYAdjust, keyWidth/2, 3*keyHeight/5);
            g.setColour(Colours::black);
            g.drawRect(i*keyWidth + keyWidth/3 + getWidth()/4 + totalXAdjust, getHeight()/4 - totalYAdjust, keyWidth/2, 3*keyHeight/5);
        }

    }
    
    int xShift = 7;
    int yShift = 3;
    for (int i = 0; i < 7; i++) {
        if (i != 2 && i != 6) {
            g.setColour(secondUpColor);
            if (notesOn[secondUpTransferIndex[i]]) {
                g.setColour(Colours::red);
            }
            g.fillRect(i*keyWidth + 2*keyWidth/3 + getWidth()/4 + xShift + totalXAdjust,getHeight()/4 - yShift - totalYAdjust, keyWidth/2,3*keyHeight/5 - yShift);
            g.setColour(Colours::black);
            g.drawRect(i*keyWidth + 2*keyWidth/3 + getWidth()/4 + xShift + totalXAdjust,getHeight()/4 - yShift - totalYAdjust, keyWidth/2,3*keyHeight/5 - yShift);
        }
        else {
            g.setColour(secondUpColor);
            if (notesOn[secondUpTransferIndex[i]]) {
                g.setColour(Colours::red);
            }
            g.fillRect(i*keyWidth + keyWidth/2 + getWidth()/4 + xShift + totalXAdjust, getHeight()/4 - yShift - totalYAdjust, keyWidth/2,3*keyHeight/5 - yShift);
            g.setColour(Colours::black);
            g.drawRect(i*keyWidth + keyWidth/2 + getWidth()/4 + xShift + totalXAdjust, getHeight()/4 - yShift - totalYAdjust, keyWidth/2,3*keyHeight/5 - yShift);
        }
        
    }
    
}

void PianoKeys::turnOnKey(int index) {
    notesOn[index] = true;
}
void PianoKeys::turnOffKey(int index) {
    notesOn[index] = false;
}

void PianoKeys::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
