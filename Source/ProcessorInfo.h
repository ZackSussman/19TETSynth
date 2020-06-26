/*
  ==============================================================================

    ProcessorInfo.h
    Created: 26 Jun 2020 1:58:18pm
    Author:  Zack Sussman

  ==============================================================================
*/

#pragma once

struct ProcessorInfo {
    
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
    
    
};
