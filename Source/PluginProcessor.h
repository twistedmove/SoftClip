/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

# define M_PI           3.14159265358979323846  /* pi */

//==============================================================================
/**
*/
class SoftClipAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SoftClipAudioProcessor();
    ~SoftClipAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	int SoftClipAudioProcessor::signum(float x);

	int _comboChoice;
	float _inputGain;
	AudioParameterFloat* gain;


	enum Types
	{
		_off = 0,
		_cubic,
		_arctan,
		_exponential
	};

	AudioProcessorValueTreeState& getTreeState();
private:
	ScopedPointer<AudioProcessorValueTreeState> state;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftClipAudioProcessor)
};


