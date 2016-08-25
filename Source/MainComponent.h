/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public Component,
    private Slider::Listener,
    private ComboBox::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent() {}

    void paint (Graphics& g) override;
    void resized() override;

    virtual void sliderValueChanged (Slider* slider) override;
    virtual void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

private:
    //==============================================================================
    void updateText();

    OwnedArray<TextEditor> editors;
    Label heightLabel, scaleLabel, styleLabel, fontLabel;
    Slider heightSlider, scaleSlider;
    ComboBox styleBox, fontBox;
    TextEditor nameEt;
    TextEditor someContent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
