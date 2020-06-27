/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ProcessorInfo.h"
#include "SustainIndicatorLine.h"

//==============================================================================
/**
*/
class _19tetsynthAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener

{
public:
    _19tetsynthAudioProcessorEditor (_19tetsynthAudioProcessor&);
    ~_19tetsynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    ProcessorInfo* info;
    void sliderValueChanged(Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _19tetsynthAudioProcessor& processor;
    

    Path adsrOutline;
    
    SustainIndicatorLine sustainCutoff;
    
    Slider attackSlider;
    Label attackLabel;
    
    Slider decaySlider;
    Label decayLabel;
    
    Slider sustainSlider;
    Label sustainLabel;
    
    Slider releaseSlider;
    Label releaseLabel;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_19tetsynthAudioProcessorEditor)
};
