/*
  ==============================================================================

    Envelope.h
    Created: 25 Jun 2020 4:40:06pm
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once


enum whichStageOfPlayBack {attack, decay, sustain, release, off};

class Envelope {

public:
    double attackTime = .1;
    double relativeAttackLevel = 1;
    
    double decayTime = .05;
    double relativeDecayLevel = .8;

    double sustainTime = 1;
    
    double releaseTime = .1;
    double relativeReleaseLevel = 0;
    
    double time = 0;
    whichStageOfPlayBack stage = off;

public:
    
    Envelope() {};
    
    Envelope(double attack, double attackLevel, double decay, double decayLevel, double sustain, double release, double releaseLevel) {
        attackTime = attack;
        relativeAttackLevel = attackLevel;
        
        decayTime = decay;
        relativeDecayLevel = decayLevel;
        
        sustainTime = sustain;
        
        releaseTime = release;
        relativeReleaseLevel = releaseLevel;
        
    }
    
    double preform(double input){
        if (stage == attack) {
            return input*relativeAttackLevel*(time/attackTime);
        }
        else if (stage == decay) {
            return input*relativeAttackLevel - (relativeAttackLevel - relativeDecayLevel)*input*((time - attackTime)/(decayTime)) ;
        }
        else if (stage == sustain) {
            return input*relativeDecayLevel;
        }
        else if (stage == release) {
            return input*relativeDecayLevel - (relativeDecayLevel - relativeReleaseLevel)*input*((time - decayTime - attackTime - sustainTime)/(releaseTime)) ;
        }
        else {
            return 0;
        }
        
    }
    
    void beginningOfNote() {
        time = 0;
        
    }
    
    void update() {
        time += .01;
        if (time <= attackTime) {
            stage = attack;
        }
        else if (time <= attackTime + decayTime) {
            stage = decay;
        }
        else if (time <= attackTime + decayTime + sustainTime) {
            stage = sustain;
        }
        else if (time <= attackTime + decayTime + sustainTime + releaseTime) {
            stage = release;
        }
        else {
            stage = off;
        }
    }
    
    
};
