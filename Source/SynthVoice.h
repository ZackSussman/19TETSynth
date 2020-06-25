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
#include "PluginProcessor.h"
#include "Envelope.h"

class SynthVoice : public SynthesiserVoice {

public:
    
    bool canPlaySound (SynthesiserSound* sound) {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        level = velocity;
        frequency = convertMidiNumberToFrequencyModeOne(midiNoteNumber);
        envelope->beginningOfNote();
    }
    
    void stopNote (float velocity, bool allowTailOff) {
        level = 0;
        clearCurrentNote();
    }
    
    void pitchWheelMoved (int newPitchWheelValue) {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue) {
        
    }
    
    void renderNextBlock (AudioBuffer<float>& outputBuffer,int startSample,int numSamples) {
        
        double sampleRate = getSampleRate();
        
        for (int sample = 0; sample < numSamples; ++sample) {
            double signal = envelope->preform(level*(double)sinf(frequency*2*M_PI*(sampleNumber/sampleRate)));
            for (int channel = 0; channel  < outputBuffer.getNumChannels(); ++channel) {
                outputBuffer.addSample(channel, startSample, signal);
                //outputBuffer.addSample(channel, startSample, signal);
            }
            sampleNumber++;
            ++startSample;
            envelope->update();
        }
        
    }
    
private:
    double level = 0.5;
    double frequency = 440;
    int sampleNumber = 0;
    Envelope* envelope = new Envelope(.1, 1, .1, .8, 10, .1, 0);
    

    
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
