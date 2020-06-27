/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
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
    
    info->addListener(this);
    modeOneButton.addListener(this);
    modeTwoButton.addListener(this);
    modeThreeButton.addListener(this);
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
    
    addAndMakeVisible(keys, 0);
    keys.setBounds(getLocalBounds());
    
    addAndMakeVisible(modeOneButton);
    addAndMakeVisible(modeTwoButton);
    addAndMakeVisible(modeThreeButton);
    
    modeOneButton.setSize(getWidth()/8, (-38 + 6*getHeight()/20)/3);
    modeTwoButton.setSize(getWidth()/8, (-38 + 6*getHeight()/20)/3);
    modeThreeButton.setSize(getWidth()/8, (-38 + 6*getHeight()/20)/3);
    
    modeOneButton.setButtonText("flat mode");
    modeTwoButton.setButtonText("sharp mode");
    modeThreeButton.setButtonText("all mode");
    
    modeOneButton.setTopLeftPosition(5*getWidth()/7 + 20, 13*getHeight()/20 + 20);
    modeTwoButton.setTopLeftPosition(5*getWidth()/7 + 20, 13*getHeight()/20 + +20 + (-38 + 6*getHeight()/20)/3);
    modeThreeButton.setTopLeftPosition(5*getWidth()/7 + 20, 13*getHeight()/20 +  + 20 + 2*(-38 + 6*getHeight()/20)/3);
    
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
    
    
    modesOutline.clear();
    modesOutline.startNewSubPath(5*getWidth()/7 + 20, 13*getHeight()/20 + 20);
    modesOutline.lineTo(getWidth()/8 + 5*getWidth()/7 + 20, 13*getHeight()/20 + 20);
    modesOutline.lineTo(getWidth()/8 + 5*getWidth()/7 + 20, 13*getHeight()/20 +  + 20 + 2*(-38 + 6*getHeight()/20)/3 + (-38 + 6*getHeight()/20)/3);
    modesOutline.lineTo(5*getWidth()/7 + 20, 13*getHeight()/20 +  + 20 + 2*(-38 + 6*getHeight()/20)/3 + (-38 + 6*getHeight()/20)/3);
    modesOutline.closeSubPath();
    g.strokePath(modesOutline, PathStrokeType(3));
    
    for (int index = 0; index < 19; index++) {
        keys.notesOn[index] = info->notesOn[index];
    }
    
}

void _19tetsynthAudioProcessorEditor::buttonClicked(Button* button) {
    if (&modeOneButton == button) {
        info->mode = info->SynthMode::left;
    }
    else if (button == &modeTwoButton) {
        info->mode = info->SynthMode::right;
    }
    else {
        info->mode = info->SynthMode::both;
    }
    MessageManager::getInstance()->callAsync([this](){
        keys.paintAgain();
    });
}

void _19tetsynthAudioProcessorEditor::noteOn() {
    MessageManager::getInstance()->callAsync([this](){
        keys.paintAgain();
    });
}

void _19tetsynthAudioProcessorEditor::noteOff() {
    MessageManager::getInstance()->callAsync([this](){
        keys.paintAgain();
    });
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
            sustainCutoff.color = Colours::lightgreen;
        }
        else {
            sustainCutoff.color = Colours::black;
        }
    }
    else {
        info->releaseTime = slider->getValue();
    }
    
}
