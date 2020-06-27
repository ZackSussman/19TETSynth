/*
  ==============================================================================

    ProcessorInfo.h
    Created: 26 Jun 2020 1:58:18pm
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once



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
    
    
    double getAttackTime() {
        return attackTime;
    }
    double getReleaseTime() {
        return releaseTime;
    }
    double getSustainTime() {
        return sustainTime;
    }
    double getDecayTime() {
        return decayTime;
    }
    
    double attackTime = 2;
    double decayTime = .1;
    double releaseTime = 2;
    double sustainTime = 30;
    
    SynthMode mode = left;
    
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

