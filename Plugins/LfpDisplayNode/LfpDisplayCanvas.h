/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2013 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef __LFPDISPLAYCANVAS_H_Alpha__
#define __LFPDISPLAYCANVAS_H_Alpha__

#include <VisualizerWindowHeaders.h>
#include "LfpDisplayNode.h"

#include <vector>
#include <array>

#define MAX_N_CHAN 2048
#define MAX_N_SAMP 5000
#define MAX_N_SAMP_PER_PIXEL 100

namespace LfpViewer {

class LfpDisplayNode;

class LfpTimescale;
!class LfpDisplay;
class LfpChannelDisplay;
class LfpChannelDisplayInfo;
class EventDisplayInterface;
class LfpViewport;
class LfpDisplayOptions;
class LfpBitmapPlotter;
class PerPixelBitmapPlotter;
class SupersampledBitmapPlotter;
class LfpChannelColourScheme;

    
    
#pragma mark - LfpDisplayCanvas -
//==============================================================================
/**

  Displays multiple channels of continuous data.

  @see LfpDisplayNode, LfpDisplayEditor

*/
    
class LfpDisplayCanvas : public Visualizer,
    public KeyListener
{
public:
    LfpDisplayCanvas(LfpDisplayNode* n);
    ~LfpDisplayCanvas();

    void beginAnimation();
    void endAnimation();

    void refreshState();
    void update();

    void setParameter(int, float);
    void setParameter(int, int, int, float) {}

    void paint(Graphics& g);

    void refresh();
    void resized();
    
    /** Resizes the LfpDisplay to the size required to fit all channels that are being
        drawn to the screen.
        
        @param respectViewportPosition  (optional) if true, viewport automatically
                                        scrolls to maintain view prior to resizing
     */
    void resizeToChannels(bool respectViewportPosition = false);

    void toggleOptionsDrawer(bool);

    int getChannelHeight();
    
    float channelOverlapFactor;

    float histogramParameterA;
    float histogramParameterB;

    /** Returns the number of both continuous and event channels tracked by the canvas */
    int getNumChannels();
    /** Returns the number of channels NOT hidden for display */
    int getNumChannelsVisible();
    bool getInputInvertedState();
    
    /** Returns a bool describing whether the spike raster functionality is enabled */
    bool getDisplaySpikeRasterizerState();
    
    bool getDrawMethodState();
    
    int getChannelSampleRate(int channel);
    
    /** Delegates a samplerate for drawing to the LfpDisplay referenced by this canvas */
    void setDrawableSampleRate(float samplerate);
    
    /** Returns the subprocessor index of the given channel */
    int getChannelSubprocessorIdx(int channel);
    
    /** Delegates a subprocessor for drawing to the LfpDisplay referenced by this
        this canvas */
    void setDrawableSubprocessor(uint32 sp);

    const float getXCoord(int chan, int samp);
    const float getYCoord(int chan, int samp);
    
    std::array<float, MAX_N_SAMP_PER_PIXEL> getSamplesPerPixel(int chan, int px);
    const int getSampleCountPerPixel(int px);
    
    const float getYCoordMin(int chan, int samp);
    const float getYCoordMean(int chan, int samp);
    const float getYCoordMax(int chan, int samp);

    float getMean(int chan);
    float getStd(int chan);

    Array<int> screenBufferIndex;
    Array<int> lastScreenBufferIndex;

    void saveVisualizerParameters(XmlElement* xml);
    void loadVisualizerParameters(XmlElement* xml);

    bool keyPressed(const KeyPress& key);
    bool keyPressed(const KeyPress& key, Component* orig);

    //void scrollBarMoved(ScrollBar *scrollBarThatHasMoved, double newRangeStart);

    bool fullredraw; // used to indicate that a full redraw is required. is set false after each full redraw, there is a similar switch for each display;
    static const int leftmargin = 50; // left margin for lfp plots (so the ch number text doesnt overlap)

    Array<bool> isChannelEnabled;
    
    bool  drawClipWarning; // optinally draw (subtle) warning if data is clipped in display
    bool  drawSaturationWarning; // optionally raise hell if the actual data is saturating
    
    int nChans;
    //int nChansVisible; // the number of channels NOT hidden for display

    float timebase;

    void redraw();

	DataChannel::DataChannelTypes selectedChannelType;

    ScopedPointer<LfpViewport> viewport;

private:
    
    float sampleRate;

    bool optionsDrawerIsOpen;
    
    float displayGain;
    float timeOffset;
    //int spread ; // vertical spacing between channels

	uint32 drawableSubprocessor;
	float displayedSampleRate;
    
    //float waves[MAX_N_CHAN][MAX_N_SAMP*2]; // we need an x and y point for each sample

    LfpDisplayNode* processor;
    std::shared_ptr<AudioSampleBuffer> displayBuffer; // sample wise data buffer for display
    ScopedPointer<AudioSampleBuffer> screenBuffer; // subsampled buffer- one int per pixel

    //'define 3 buffers for min mean and max for better plotting of spikes
    // not pretty, but 'AudioSampleBuffer works only for channels X samples
    ScopedPointer<AudioSampleBuffer> screenBufferMin; // like screenBuffer but holds min/mean/max values per pixel
    ScopedPointer<AudioSampleBuffer> screenBufferMean; // like screenBuffer but holds min/mean/max values per pixel
    ScopedPointer<AudioSampleBuffer> screenBufferMax; // like screenBuffer but holds min/mean/max values per pixel

    MidiBuffer* eventBuffer;

    ScopedPointer<LfpTimescale> timescale;
    ScopedPointer<LfpDisplay> lfpDisplay;
    
    ScopedPointer<LfpDisplayOptions> options;

    void refreshScreenBuffer();
    void updateScreenBuffer();

    Array<int> displayBufferIndex;
    int displayBufferSize;

    int scrollBarThickness;
    
    //float samplesPerPixel[MAX_N_SAMP][MAX_N_SAMP_PER_PIXEL];
    //float*** samplesPerPixel;

	void resizeSamplesPerPixelBuffer(int numChannels);
    std::vector<std::array<std::array<float, MAX_N_SAMP_PER_PIXEL>, MAX_N_SAMP>> samplesPerPixel;

    int sampleCountPerPixel[MAX_N_SAMP];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LfpDisplayCanvas);

};

    
    
   
};

#endif  // __LFPDISPLAYCANVAS_H_Alpha__
