#pragma mark - LfpChannelDisplayInfo -
//==============================================================================
/**
    Displays meta data pertaining to an associated channel, such as channel number.
 
    The enableButton displays the channel number and toggles the drawing of the
    associated LfpChannelDisplay waveform on or off.
 */
class LfpChannelDisplayInfo : public LfpChannelDisplay,
    public Button::Listener
{
    friend class LfpDisplay;
public:
    LfpChannelDisplayInfo(LfpDisplayCanvas*, LfpDisplay*, LfpDisplayOptions*, int channelNumber);

    void paint(Graphics& g);

    void buttonClicked(Button* button);

    void resized();

    void setEnabledState(bool);
    void updateType();

    void updateXY(float, float);

    void setSingleChannelState(bool);
    
    /** Returns the sample rate associated with this channel */
    int getChannelSampleRate();
    /** Sets the sample rate associated with this channel */
    void setChannelSampleRate(int samplerate);
    
    int getSubprocessorIdx() { return subProcessorIdx; }
    
    void setSubprocessorIdx(int subProcessorIdx_) { subProcessorIdx = subProcessorIdx_; }
    
    /** Updates the parent LfpDisplay that the track vertical zoom should update */
    virtual void mouseDrag(const MouseEvent &event) override;
    
    /** Disengages the mouse drag to resize track height */
    virtual void mouseUp(const MouseEvent &event) override;
    
    

private:

    bool isSingleChannel;
    float x, y;
    
    int samplerate;
    int subProcessorIdx;
    
    ScopedPointer<UtilityButton> enableButton;
    
    bool channelTypeStringIsVisible;
    bool channelNumberHidden;
    
    void setEnabledButtonVisibility(bool shouldBeVisible);
    bool getEnabledButtonVisibility();

    void setChannelTypeStringVisibility(bool shouldBeVisible);
    bool getChannelTypeStringVisibility();
    
    void setChannelNumberIsHidden(bool shouldBeHidden);
    bool isChannelNumberHidden();
};

