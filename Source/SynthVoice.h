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
#include "ProcessorInfo.h"

class SynthVoice : public SynthesiserVoice {

public:

    SynthVoice(ProcessorInfo* passedInfo){
        info = passedInfo;
    }
    
    SynthVoice(){
        
    }
    
    bool canPlaySound (SynthesiserSound* sound) {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
 
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        int note;
        
        if (info->mode == info->SynthMode::left) {
            note = convertMidiNumberToNineteenNumberModeOne(midiNoteNumber);
        }
        else if (info->mode == info->SynthMode::right) {
            note = convertMidiNumberToNineteenNumberModeTwo(midiNoteNumber);
        }
        else {
            note = convertMidiNumberToNineteenNumberModeOne(midiNoteNumber);
        }
        info->notesOn[note] = true;
        lastNoteNumber = note;
        level = velocity;
        if (info->mode == info->SynthMode::left) {
            frequency = convertMidiNumberToFrequencyModeOne(midiNoteNumber);
        }
        else if (info->mode == info->SynthMode::right) {
            frequency = convertMidiNumberToFrequencyModeTwo(midiNoteNumber);
        }
        else {
            frequency = 440*pow(2, ((midiNoteNumber-69)*1.0)/19);
        }
        info->notifyListenersNoteOn();
    }
    
    void stopNote (float velocity, bool allowTailOff) {
        clearCurrentNote();
        info->notesOn[lastNoteNumber] = false;
        info->notifyListenersNoteOff();
        level = 0;
    }
    
    void pitchWheelMoved (int newPitchWheelValue) {
        
    }
    
    void controllerMoved (int controllerNumber, int newControllerValue) {
        
    }
    
    void renderNextBlock (AudioBuffer<float>& outputBuffer,int startSample,int numSamples) {
        
        double sampleRate = getSampleRate();
        
        for (int sample = 0; sample < numSamples; ++sample) {
            
            //double signal = level*info->sinApprox(frequency*2*M_PI*((1.0*sampleNumber)/sampleRate));
            double signal = level*sin(frequency*2*M_PI*((1.0*sampleNumber)/sampleRate));
            if (signal > 1) {
                signal = signal/abs(signal);
            }
            for (int channel = 0; channel  < outputBuffer.getNumChannels(); ++channel) {
                outputBuffer.addSample(channel, startSample, signal);
                //outputBuffer.addSample(channel, startSample, signal);
            }
            if (sampleNumber*1.0/sampleRate == 1) {
                sampleNumber = -1;
            }
            sampleNumber++;
            ++startSample;
        }
    }
    
public:
    ProcessorInfo* info;
    
    
private:
    double level = 0;
    double frequency = 440;
    int sampleNumber = 0;
    int lastNoteNumber = 0;
    
    
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
    
    double convertMidiNumberToFrequencyModeTwo(int midiNumber) {
        int steps[12] = {2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 2, 1};
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
    
    
    int convertMidiNumberToNineteenNumberModeOne(int midiNumber) {
        int twelveNumber = midiNumber%12;
        int lookUp[12] = {0, 1, 3, 4, 6, 8, 9, 11, 12, 14, 15, 17};
        return lookUp[twelveNumber];
    }
    
    int convertMidiNumberToNineteenNumberModeTwo(int midiNumber) {
        int twelveNumber = midiNumber%12;
        int lookUp[12] = {0, 2, 3, 5, 7, 8, 10, 11, 13, 14, 16, 18};
        return lookUp[twelveNumber];
    }
    
    
};
