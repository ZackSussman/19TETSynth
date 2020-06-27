/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <iostream>
//==============================================================================
_19tetsynthAudioProcessorEditor::_19tetsynthAudioProcessorEditor (_19tetsynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    
    processor.fixMyInfo(&info);
    setSize (1000, 600);
    
    addAndMakeVisible(sustainCutoff, 0);
    sustainCutoff.setBounds(getLocalBounds());
    
    addAndMakeVisible(decaySlider, 1);
    addAndMakeVisible(sustainSlider, 1);
    addAndMakeVisible(releaseSlider, 1);
    addAndMakeVisible(attackSlider, 1);
    addAndMakeVisible(decayLabel);
    addAndMakeVisible(sustainLabel);
    addAndMakeVisible(releaseLabel);
    addAndMakeVisible(attackLabel);
    attackSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    attackSlider.setRange(0.1, 100, .1);
    attackSlider.setSize(getWidth()/5, getHeight()/20);
    attackSlider.setTopLeftPosition(2*getWidth()/20, 14*getHeight()/20);
    attackLabel.setText("attack", dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, true);
    attackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, getWidth()/20, getHeight()/20);
    attackSlider.addListener(this);
    

    decaySlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    decaySlider.setRange(0.1, 100, .1);
    decaySlider.setSize(getWidth()/5, getHeight()/20);
    decaySlider.setTopLeftPosition(2*getWidth()/20, 15*getHeight()/20);
    decayLabel.setText("decay", dontSendNotification);
    decayLabel.attachToComponent(&decaySlider, true);
    decaySlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, getWidth()/20, getHeight()/20);
    decaySlider.addListener(this);

    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    sustainSlider.setRange(0.1, 100, .1);
    sustainSlider.setSize(getWidth()/5, getHeight()/20);
    sustainSlider.setTopLeftPosition(2*getWidth()/20, 16*getHeight()/20);
    sustainLabel.setText("sustain", dontSendNotification);
    sustainLabel.attachToComponent(&sustainSlider, true);
    sustainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, getWidth()/20, getHeight()/20);
    sustainSlider.addListener(this);

    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    releaseSlider.setRange(0.1, 100, .1);
    releaseSlider.setSize(getWidth()/5, getHeight()/20);
    releaseSlider.setTopLeftPosition(2*getWidth()/20, 17*getHeight()/20);
    releaseLabel.setText("release", dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, true);
    releaseSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, getWidth()/20, getHeight()/20);
    releaseSlider.addListener(this);
    
    attackSlider.setValue(2);
    releaseSlider.setValue(2);
    decaySlider.setValue(.1);
    sustainSlider.setValue(20);
    

}

_19tetsynthAudioProcessorEditor::~_19tetsynthAudioProcessorEditor()
{
}

//==============================================================================
void _19tetsynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::limegreen);
    g.setFont (15.0f);
    
    int xAdjust = 5;
    int upperYAdjust = 20;
    int lowerYAdjust = 18;
    
    adsrOutline.clear();
    adsrOutline.startNewSubPath(getWidth()/20 - xAdjust, 13*getHeight()/20 + upperYAdjust);
    adsrOutline.lineTo(2*getWidth()/20 + getWidth()/5 - xAdjust, 13*getHeight()/20 + upperYAdjust);
    adsrOutline.lineTo(2*getWidth()/20 + getWidth()/5 - xAdjust, 19*getHeight()/20 - lowerYAdjust);
    adsrOutline.lineTo(getWidth()/20 - xAdjust, 19*getHeight()/20 - lowerYAdjust);
    adsrOutline.closeSubPath();
    g.strokePath(adsrOutline, PathStrokeType(3));
    

    
}

void _19tetsynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void _19tetsynthAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    
    if (slider == &attackSlider) {
        info->attackTime = slider->getValue();
    }
    else if (slider == &decaySlider) {
        info->decayTime = slider->getValue();
    }
    else if (slider == &sustainSlider) {
        info->sustainTime = slider->getValue();
        if (slider->getValue() > 98.6) {
            sustainCutoff.color = Colours::limegreen;
        }
        else {
            sustainCutoff.color = Colours::grey;
        }
    }
    else {
        info->releaseTime = slider->getValue();
    }
    
}
