
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioThumbnailComp.h"

//==============================================================================
/**

This is a JUCE framework audio plugin that can be added to the audio plugin host, 
based on the one created by another user here:

https://github.com/jonathonracz/AudioFilePlayerPlugin

That version wouldn't compile on Projucer 5.4.5. This version does, though I do
not vouch for the code quality - I just did what seemed necessary to get it 
working :)

*/
class AudioFilePlayerProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AudioFilePlayerProcessor();
    ~AudioFilePlayerProcessor();

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
//    bool isMidiEffect() const override {return false;};
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

    AudioTransportSource transportSource;
    AudioFormatManager formatManager;
    File currentlyLoadedFile;
    AudioThumbnailCache thumbnailCache;

    void loadFileIntoTransport(const File& audioFile);
    
private:
    
    //==============================================================================
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
    TimeSliceThread readAheadThread;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioFilePlayerProcessor)
};
