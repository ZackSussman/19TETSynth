/*
  ==============================================================================

    ProcessorInfo.h
    Created: 26 Jun 2020 1:58:18pm
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once
#include <cmath>

class EnvelopeInfo {

public:
    EnvelopeInfo() {
        attackTime = .2;
        decayTime = .2;
        sustainTime = 20;
        releaseTime = .2;
        
        attackAmp = 1;
        sustainAmp = .8;
    }
    
    double attackTime;
    double decayTime;
    double sustainTime;
    double releaseTime;
    
    double attackAmp;
    double sustainAmp;
};


class ProcessorInfo {

public:
    enum SynthMode {left, right, both};
    
    class Listener {
    
    public:
        virtual ~Listener() = default;
        
        virtual void noteOn() = 0;
        virtual void noteOff() = 0;
        
    };
    
    
    ProcessorInfo(){}

    SynthMode mode = left;
    
    EnvelopeInfo envelopeInfo;
    
    bool notesOn[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    void addListener(Listener* listener) {
        listeners.push_back(listener);
    }
    
    void removeListener(Listener* listener) {
      listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
    }
    
    void notifyListenersNoteOn() {
        for (Listener* listener: listeners) {
            listener->noteOn();
        }
    }
    void notifyListenersNoteOff() {
        for (Listener* listener: listeners) {
            listener->noteOff();
        }
    }
    
    
    

private:
    std::vector<Listener*> listeners;
};

