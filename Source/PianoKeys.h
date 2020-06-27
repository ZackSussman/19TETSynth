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
    PianoKeys();
    ~PianoKeys();
    Colour normalKeysColor = Colours::white;
    Colour firstUpColor = Colours::black;
    Colour secondUpColor = Colours::grey;
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
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PianoKeys)
};
