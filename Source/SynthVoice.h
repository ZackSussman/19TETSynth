/*
  ==============================================================================

    SynthVoice.h
    Created: 25 Jun 2020 11:14:04am
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <cmath>
#include "SynthSound.h"

class SynthVoice : public SynthesiserVoice {

public:
    
    bool canPlaySound (SynthesiserSound* sound) {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition) {
        frequency = convertMidiNumberToFrequencyModeOne(midiNoteNumber);
    }
    
    void stopNote (float velocity, bool allowTailOff) {
        clearCurrentNote();
    }
    
    void pitchWheelMoved (int newPitchWheelValue) {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue) {
        
    }
    
    void renderNextBlock (AudioBuffer<float>& outputBuffer,int startSample,int numSamples) {
        
    }
    
private:
    double level;
    double frequency;
    
    double convertMidiNumberToFrequencyModeOne(int midiNumber) {
        int steps[12] = {1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2};
        int relativeToAPitch = midiNumber - 69;
        int cycle = (relativeToAPitch) % 12;
        int numerator = 0;
        
        if (relativeToAPitch >= 0) {
            for (int i = 0; i < cycle; i++) {
                numerator += steps[i];
            }
            numerator += ((midiNumber - 9)/12 - 5)*19 ;
        }
        else {
            for (int i = 0; i < abs(cycle); i++) {
                numerator -= steps[11 - i];
            }
            numerator -= (5 - ceil(1.0*(midiNumber - 9)/(1.0*12)))*19 ;
        }
        
        return 440*(pow(2.0, numerator*1.0/19.0));
    }
    
};
