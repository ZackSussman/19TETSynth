/*
  ==============================================================================

    PianoKeys.h
    Created: 27 Jun 2020 6:57:25am
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PianoKeys    : public Component
{
public:
    enum SynthMode {left, right, both};
    PianoKeys();
    ~PianoKeys();
    int keyWidth = 40;
    int keyHeight = 140;
    void paint (Graphics&) override;
    void resized() override;
    bool notesOn[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int whiteKeyTransferIndex[7] = {0, 3, 6, 8, 11, 14, 17};
    int firstUpTransferIndex[5] = {1, 4, 9, 12, 15};
    int secondUpTransferIndex[7] = {2, 5, 7, 10, 13, 16, 18};
    

    
    
    
    
    void turnOnKey(int index);
    void turnOffKey(int index);
    void paintAgain();
    SynthMode mode = left;
    
    Colour colorLowSequenceLeft[7] = {Colours::white,Colours::white,Colours::white,Colours::white,Colours::white,Colours::white,Colours::white};
    Colour colorHighLeftSequencceLeft[5] = {Colours::black,Colours::black,Colours::black,Colours::black,Colours::black};
    Colour colorHighRightSequenceLeft[7] = {Colours::grey,Colours::grey,Colours::grey,Colours::grey,Colours::grey,Colours::grey,Colours::grey};
    
    Colour colorLowSequenceRight[7] = {Colours::white,Colours::white,Colours::grey,Colours::white,Colours::white,Colours::white,Colours::grey};
    Colour colorHighLeftSequenceRight[5] = {Colours::grey,Colours::grey,Colours::grey,Colours::grey,Colours::grey};
    Colour colorHighRightSequenceRight[7] = {Colours::black,Colours::black,Colours::white,Colours::black,Colours::black,Colours::black,Colours::white};
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PianoKeys)
};
