

#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioFilePlayerEditor::AudioFilePlayerEditor(AudioFilePlayerProcessor& p) :
    AudioProcessorEditor(&p),
    processor(p)
{
    thumbnail = new AudioThumbnailComp(processor.formatManager, processor.transportSource, processor.thumbnailCache, processor.currentlyLoadedFile);
    addAndMakeVisible(thumbnail);
    thumbnail->addChangeListener(this);

    addAndMakeVisible(startStopButton);
    startStopButton.setButtonText("Play/Stop");
    startStopButton.addListener(this);
    startStopButton.setColour(TextButton::buttonColourId, Colour(0xff79ed7f));

    setOpaque(true);

    setSize(512, 220);
}

AudioFilePlayerEditor::~AudioFilePlayerEditor()
{
    thumbnail->removeChangeListener(this);
}

void AudioFilePlayerEditor::paint(Graphics& g)
{
    g.fillAll(Colours::grey);
}

void AudioFilePlayerEditor::resized()
{
    Rectangle<int> r(getLocalBounds().reduced(4));

    Rectangle<int> controls(r.removeFromBottom(32));

    startStopButton.setBounds(controls);

    r.removeFromBottom(6);
    thumbnail->setBounds(r.removeFromBottom(180));
    r.removeFromBottom(6);
}

void AudioFilePlayerEditor::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == &startStopButton)
    {
        if (processor.transportSource.isPlaying())
        {
            processor.transportSource.stop();
        }
        else
        {
            processor.transportSource.setPosition(0);
            processor.transportSource.start();
        }
    }
}

void AudioFilePlayerEditor::changeListenerCallback(ChangeBroadcaster* source)
{
    if (source == thumbnail)
    {
        processor.loadFileIntoTransport(thumbnail->getLastDroppedFile());
        thumbnail->setFile(thumbnail->getLastDroppedFile());
    }
}

////==============================================================================
//AudioFilePlayerProcessorEditor::AudioFilePlayerProcessorEditor (AudioFilePlayerProcessor& p)
//    : AudioProcessorEditor (&p), processor (p), state (Stopped)
//{
//    // Make sure that before the constructor has finished, you've set the
//    // editor's size to whatever you need it to be.
//    setSize (400, 300);
//}
//
//AudioFilePlayerProcessorEditor::~AudioFilePlayerProcessorEditor()
//{
//}
//
////==============================================================================
//void AudioFilePlayerProcessorEditor::paint (Graphics& g)
//{
//    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
//
//    g.setColour (Colours::white);
//    g.setFont (15.0f);
//
//
//
//}
//
//void AudioFilePlayerProcessorEditor::resized()
//{
//    // This is generally where you'll want to lay out the positions of any
//    // subcomponents in your editor..
//
//    openButton.setBounds (10, 10, getWidth() - 20, 20);
//        playButton.setBounds (10, 40, getWidth() - 20, 20);
//        stopButton.setBounds (10, 70, getWidth() - 20, 20);
//
//}
