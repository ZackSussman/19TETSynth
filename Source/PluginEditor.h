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
#include "PianoKeys.h"
#include "EnvelopeGraphic.h"

//==============================================================================
/**
*/
class _19tetsynthAudioProcessorEditor  : public AudioProcessorEditor, public ProcessorInfo::Listener, public Button::Listener, public Slider::Listener

{
public:
    _19tetsynthAudioProcessorEditor (_19tetsynthAudioProcessor&);
    ~_19tetsynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    ProcessorInfo* info;
    void buttonClicked(Button* button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    _19tetsynthAudioProcessor& processor;
    
    int sliderXShift = 35;
    
    Path adsrOutline;
    
    Path modesOutline;
    
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
    
    EnvelopeGraphic envelopeGraphic;
    
    Path envelopeBorderPath;
    
    Slider attackTimeSlider;
    Label attackTimeLabel;
    
    Slider decayTimeSlider;
    Label decayTimeLabel;
    
    Slider sustainTimeSlider;
    Label sustainTimeLabel;
    
    Slider releaseTimeSlider;
    Label releaseTimeLabel;
    
    
    Slider attackAmpSlider;
    Label attackAmpLabel;
    
    Slider sustainAmpSlider;
    Label sustainAmpLabel;
    
    
    void noteOn() ;
    void noteOff();
    
    void sliderValueChanged(Slider* slider) override;
    
    PianoKeys keys;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (_19tetsynthAudioProcessorEditor)
};
