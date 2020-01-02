/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

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


//#include "../JuceLibraryCode/JuceHeader.h"
//#include "PluginProcessor.h"
//
////==============================================================================
///**
//*/
//class AudioFilePlayerProcessorEditor  : public AudioProcessorEditor
//{
//public:
//    AudioFilePlayerProcessorEditor (AudioFilePlayerProcessor&);
//    ~AudioFilePlayerProcessorEditor();
//
//    //==============================================================================
//    void paint (Graphics&) override;
//    void resized() override;
//
//private:
//    // This reference is provided as a quick way for your editor to
//    // access the processor object that created it.
//    AudioFilePlayerProcessor& processor;
//
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioFilePlayerProcessorEditor)
//
//    //==========================================================================
//
//    TextButton openButton;
//    TextButton playButton;
//    TextButton stopButton;
//
//    enum TransportState
//     {
//         Stopped,
//         Starting,
//         Playing,
//         Pausing,
//         Paused,
//         Stopping
//     };
//
//    AudioFormatManager formatManager;
//    ScopedPointer<AudioFormatReaderSource> readerSource;
//    AudioTransportSource transportSource;
//    TransportState state;
//
//     void changeState (TransportState newState)
//     {
//         if (state != newState)
//         {
//             state = newState;
//
//             switch (state)
//             {
//                 case Stopped:
//                     playButton.setButtonText ("Play");
//                     stopButton.setButtonText ("Stop");
//                     stopButton.setEnabled (false);
//                     transportSource.setPosition (0.0);
//                     break;
//
//                 case Starting:
//                     transportSource.start();
//                     break;
//
//                 case Playing:
//                     playButton.setButtonText ("Pause");
//                     stopButton.setButtonText ("Stop");
//                     stopButton.setEnabled (true);
//                     break;
//
//                 case Pausing:
//                     transportSource.stop();
//                     break;
//
//                 case Paused:
//                     playButton.setButtonText ("Resume");
//                     stopButton.setButtonText ("Return to Zero");
//                     break;
//
//                 case Stopping:
//                     transportSource.stop();
//                     break;
//             }
//         }
//     }
//};
