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
    double fixyTime = 0;
    double lastSignal;
    bool noteReleased;
    double decayTime = .05;
    double relativeDecayLevel = .8;
    
    bool mustEndSoundSmoothlyAndPromptly = false;

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
    
    void endVelope() {
        time = attackTime + sustainTime + releaseTime;
        stage = release;
    }
    
    double preform(double input, bool isKeyDown){
        
        
        
        if (isKeyDown && sustainTime > 98.6) {
            time = attackTime + releaseTime;
            stage = sustain;
        }
        
        if (stage == attack) {
            lastSignal = input*relativeAttackLevel*(time/attackTime);
            return input*relativeAttackLevel*(time/attackTime);
        }
        else if (stage == decay) {
            lastSignal = input*relativeAttackLevel - (relativeAttackLevel - relativeDecayLevel)*input*((time - attackTime)/(decayTime)) ;
            return input*relativeAttackLevel - (relativeAttackLevel - relativeDecayLevel)*input*((time - attackTime)/(decayTime)) ;
        }
        else if (stage == sustain) {
            lastSignal = input*relativeDecayLevel;
            return input*relativeDecayLevel;
        }
        else if (stage == release) {
            lastSignal = input*relativeDecayLevel - (relativeDecayLevel - relativeReleaseLevel)*input*((time - decayTime - attackTime -sustainTime)/(releaseTime)) ;
            return input*relativeDecayLevel - (relativeDecayLevel - relativeReleaseLevel)*input*((time - decayTime - attackTime - sustainTime)/(releaseTime)) ;
        }
        else {
            return 0;
        }
        
      
    }
    
    void beginningOfNote() {
        time = 0;
    }
    
    void changeAttackTime(double newTime) {
        attackTime = newTime;
    }
    void changeDecayTime(double newTime) {
        decayTime = newTime;
    }
    void changeSustainTime(double newTime) {
        sustainTime = newTime;
    }
    void changeReleaseTime(double newTime) {
        releaseTime = newTime;
    }
    void changeAttackLevel(double newLevel) {
        relativeAttackLevel = newLevel;
    }
    void changeDecayLevel(double newLevel) {
        relativeDecayLevel = newLevel;
    }
    void changeReleaseLevel(double newLevel) {
        relativeReleaseLevel = newLevel;
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
