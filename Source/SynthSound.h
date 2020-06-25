/*
  ==============================================================================

    SynthSound.h
    Created: 25 Jun 2020 11:13:56am
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public SynthesiserSound {
    
    bool appliesToNote (int midiNoteNumber) {
        return true;
    }
    
    bool appliesToChannel (int midiChannel) {
        return true;
    }

    
};
