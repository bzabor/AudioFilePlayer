

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class AudioFilePlayerEditor :
    public AudioProcessorEditor,
    private Button::Listener,
    private ChangeListener
{
public:
    AudioFilePlayerEditor(AudioFilePlayerProcessor&);
    ~AudioFilePlayerEditor();

    void paint(Graphics&) override;
    void resized() override;

private:
    AudioFilePlayerProcessor& processor;

    ScopedPointer<AudioThumbnailComp> thumbnail;

    TextButton startStopButton;

    void buttonClicked(Button* buttonThatWasClicked) override;

    void changeListenerCallback(ChangeBroadcaster* source) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioFilePlayerEditor)
};


