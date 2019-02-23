/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SoftClipAudioProcessorEditor::SoftClipAudioProcessorEditor (SoftClipAudioProcessor& p)
    : AudioProcessorEditor(p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    comboBox.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox.get());
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("Select algorithm"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Off"), 1);
    comboBox->addItem (TRANS("Cubic"), 2);
    comboBox->addItem (TRANS("Arctan"), 3);
    comboBox->addItem (TRANS("Exponential"), 4);
    comboBox->addListener (this);

    comboBox->setBounds (32, 40, 150, 24);

    sliderInputGain.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderInputGain.get());
    sliderInputGain->setRange (1, 10, 0.01);
    sliderInputGain->setSliderStyle (Slider::LinearHorizontal);
    sliderInputGain->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    sliderInputGain->addListener (this);

    sliderInputGain->setBounds (32, 80, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	inputGainAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getTreeState(), "inputGain", *sliderInputGain);
    //[/Constructor]
}

SoftClipAudioProcessorEditor::~SoftClipAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	inputGainAttachment = nullptr;
    //[/Destructor_pre]

    comboBox = nullptr;
    sliderInputGain = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SoftClipAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SoftClipAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SoftClipAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox.get())
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
		processor._comboChoice = comboBox->getSelectedItemIndex();
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void SoftClipAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderInputGain.get())
    {
        //[UserSliderCode_sliderInputGain] -- add your slider handling code here..
		processor._inputGain = sliderInputGain->getValue();
        //[/UserSliderCode_sliderInputGain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SoftClipAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="SoftClipAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <COMBOBOX name="new combo box" id="8c772b09981f372" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="32 40 150 24" editable="0"
            layout="33" items="Off&#10;Cubic&#10;Arctan&#10;Exponential"
            textWhenNonSelected="Select algorithm" textWhenNoItems="(no choices)"/>
  <SLIDER name="new slider" id="3a039714caf2084d" memberName="sliderInputGain"
          virtualName="" explicitFocusOrder="0" pos="32 80 150 24" min="1.0"
          max="10.0" int="0.01000000000000000021" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
