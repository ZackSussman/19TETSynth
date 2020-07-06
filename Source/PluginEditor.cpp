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
    
    info->addListener(this);
    modeOneButton.addListener(this);
    modeTwoButton.addListener(this);
    modeThreeButton.addListener(this);
    
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
    
    addAndMakeVisible(envelopeGraphic);
    envelopeGraphic.setSize(.6*1.5*getWidth()/4, getHeight()/6 + 20);
    envelopeGraphic.setTopLeftPosition(getWidth()/6 - 80, 5*getHeight()/6 - 80);
    
    
    addAndMakeVisible(attackTimeSlider);
    addAndMakeVisible(decayTimeSlider);
    addAndMakeVisible(releaseTimeSlider);
    addAndMakeVisible(sustainTimeSlider);
    addAndMakeVisible(attackTimeLabel);
    addAndMakeVisible(decayTimeLabel);
    addAndMakeVisible(releaseTimeLabel);
    addAndMakeVisible(sustainTimeLabel);
    
    addAndMakeVisible(attackAmpSlider);
    addAndMakeVisible(sustainAmpSlider);
    addAndMakeVisible(attackAmpLabel, -1);
    addAndMakeVisible(sustainAmpLabel, -1);
  
    attackTimeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    attackTimeSlider.setSize(getHeight()/7, getWidth()/20);
    attackTimeLabel.setText("at", dontSendNotification);
    attackTimeLabel.attachToComponent(&attackTimeSlider, true);
    attackTimeSlider.setTopLeftPosition(getWidth()/2 - 30 - sliderXShift, 12*getHeight()/20 + 50);
    attackTimeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    
    
    decayTimeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    decayTimeSlider.setSize(getHeight()/7, getWidth()/20);
    decayTimeLabel.setText("dt", dontSendNotification);
    decayTimeLabel.attachToComponent(&decayTimeSlider, true);
    decayTimeSlider.setTopLeftPosition(getWidth()/2 - 30 - sliderXShift, 13*getHeight()/20 + 50);
    decayTimeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    
    sustainTimeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    sustainTimeSlider.setSize(getHeight()/7, getWidth()/20);
    sustainTimeLabel.setText("st", dontSendNotification);
    sustainTimeLabel.attachToComponent(&sustainTimeSlider, true);
    sustainTimeSlider.setTopLeftPosition(getWidth()/2 - 30 - sliderXShift, 14*getHeight()/20 + 50);
    sustainTimeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    
    releaseTimeSlider.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    releaseTimeSlider.setSize(getHeight()/7, getWidth()/20);
    releaseTimeLabel.setText("rt", dontSendNotification);
    releaseTimeLabel.attachToComponent(&releaseTimeSlider, true);
    releaseTimeSlider.setTopLeftPosition(getWidth()/2 - 30 - sliderXShift, 15*getHeight()/20 + 50);
    releaseTimeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    
    
    
    attackAmpSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackAmpSlider.setSize(getWidth()/20, 2*getHeight()/9);
    attackAmpSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox , true, 0, 0);
    attackAmpSlider.setTopLeftPosition(getWidth()/2 + 50 - sliderXShift, 12*getHeight()/20 + 50);
    attackAmpLabel.setSize(getHeight()/20, getHeight()/20);
    attackAmpLabel.setTopLeftPosition(getWidth()/2 - sliderXShift + 50 + getWidth()/40 - 9, 12*getHeight()/20 + 50 + 2*getHeight()/9 - 10);
    attackAmpLabel.setText("a", dontSendNotification);
    
    
    sustainAmpSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainAmpSlider.setSize(getWidth()/20, 2*getHeight()/9);
    sustainAmpSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox , true, 0, 0);
    sustainAmpSlider.setTopLeftPosition(getWidth()/2 + 50 + 30 - sliderXShift, 12*getHeight()/20 + 50);
    sustainAmpLabel.setSize(getHeight()/20, getHeight()/20);
    sustainAmpLabel.setTopLeftPosition(30 + - sliderXShift + getWidth()/2 + 50 + getWidth()/40 - 9, 12*getHeight()/20 + 50 + 2*getHeight()/9 - 10);
    sustainAmpLabel.setText("s", dontSendNotification);
    
    attackTimeSlider.addListener(this);
    decayTimeSlider.addListener(this);
    sustainTimeSlider.addListener(this);
    releaseTimeSlider.addListener(this);
    
    attackAmpSlider.addListener(this);
    sustainAmpSlider.addListener(this);

    sustainAmpSlider.setRange(0, 1);
    attackAmpSlider.setRange(0, 1);
    
    attackTimeSlider.setValue(.2);
    decayTimeSlider.setValue(.2);
    sustainTimeSlider.setValue(3);
    releaseTimeSlider.setValue(.2);
    
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
    
    g.setColour(Colours::red);
    envelopeBorderPath.clear();
    envelopeBorderPath.startNewSubPath(getWidth()/6 - 80 - 20, getHeight()/6 + 20 + 5*getHeight()/6 - 80);
    envelopeBorderPath.lineTo(getWidth()/6 - 80 + .6*1.5*getWidth()/4 + 20, getHeight()/6 + 20 + 5*getHeight()/6 - 80);
    g.strokePath(envelopeBorderPath, PathStrokeType(4));
}

void _19tetsynthAudioProcessorEditor::buttonClicked(Button* button) {
    

    for (int i = 0; i < 19; i++) {
        info->notesOn[i] = 0;
    }
    if (&modeOneButton == button) {
        info->mode = info->SynthMode::left;
        keys.mode = keys.SynthMode::left;
    }
    else if (button == &modeTwoButton) {
        info->mode = info->SynthMode::right;
        keys.mode = keys.SynthMode::right;
    }
    else {
        info->mode = info->SynthMode::both;
        keys.mode = keys.SynthMode::both;
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

void _19tetsynthAudioProcessorEditor::sliderValueChanged(Slider* slider) {
   
    envelopeGraphic.updateValues(attackTimeSlider.getValue(), decayTimeSlider.getValue(), sustainTimeSlider.getValue(), releaseTimeSlider.getValue(), attackAmpSlider.getValue(), sustainAmpSlider.getValue());
    
    info->envelopeInfo.attackTime = attackSlider.getValue();
    info->envelopeInfo.decayTime = decaySlider.getValue();
    info->envelopeInfo.sustainTime = sustainSlider.getValue();
    info->envelopeInfo.releaseTime = releaseSlider.getValue();
    
    info->envelopeInfo.attackAmp = attackAmpSlider.getValue();
    info->envelopeInfo.sustainAmp = sustainAmpSlider.getValue();
    
    
    if (slider == &attackAmpSlider) {
        sustainAmpSlider.setRange(0, attackAmpSlider.getValue());
    }
    if (slider == &sustainAmpSlider) {
        attackAmpSlider.setRange(sustainAmpSlider.getValue(), 1);
        
    }
    
    
    
    
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
