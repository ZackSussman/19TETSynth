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
#include "PianoKeys.h"

//==============================================================================
/**
*/
class _19tetsynthAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener, public ProcessorInfo::Listener, public Button::Listener

{
public:
    _19tetsynthAudioProcessorEditor (_19tetsynthAudioProcessor&);
    ~_19tetsynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    ProcessorInfo* info;
    void sliderValueChanged(Slider* slider) override;
    void buttonClicked(Button* button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _19tetsynthAudioProcessor& processor;
    

    Path adsrOutline;
    
    Path modesOutline;
    
    SustainIndicatorLine sustainCutoff;
    
    Slider attackSlider;
    Label attackLabel;
    
    Slider decaySlider;
    Label decayLabel;
    
    Slider sustainSlider;
    Label sustainLabel;
    
    Slider releaseSlider;
    Label releaseLabel;
    
    TextButton modeOneButton;
    TextButton modeTwoButton;
    TextButton modeThreeButton;
    
    void noteOn();
    void noteOff();
    
    
    PianoKeys keys;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_19tetsynthAudioProcessorEditor)
};
