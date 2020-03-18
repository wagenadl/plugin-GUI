    
    
#pragma mark - LfpChannelDisplay -
//==============================================================================
/**
    Displays the information pertaining to a single data channel.
 */
class LfpChannelDisplay : public Component
{
public:
    LfpChannelDisplay(LfpDisplayCanvas*, LfpDisplay*, LfpDisplayOptions*, int channelNumber);
    ~LfpChannelDisplay();

    void resized();
    
    void paint(Graphics& g);
    
    void pxPaint(); // like paint, but just populate lfpChannelBitmap
                    // needs to avoid a paint(Graphics& g) mechanism here becauswe we need to clear the screen in the lfpDisplay repaint(),
                    // because otherwise we cant deal with the channel overlap (need to clear a vertical section first, _then_ all channels are dawn, so cant do it per channel)
                

    void select();
    void deselect();

    bool getSelected();

    void setName(String);

    void setColour(Colour c);

    void setChannelHeight(int);
    int getChannelHeight();

    void setChannelOverlap(int);
    int getChannelOverlap();
    
    /** Return the assigned channel number */
    int getChannelNumber();
    
    /** Return the assigned channel name */
    String getName();

    /** Returns the assigned channel number for this display, relative
        to the subset of channels being drawn to the canvas */
    int getDrawableChannelNumber();
    
    /** Set the channel number of this channel relative to the subset of
        channels being drawn to the canvas */
    void setDrawableChannelNumber(int channelId);

    void setRange(float range);
    int getRange();

    void setInputInverted(bool);
    void setCanBeInverted(bool);

    void setDrawMethod(bool);

    PopupMenu getOptions();
    void changeParameter(const int id);

    void setEnabledState(bool);
    bool getEnabledState()
    {
        return isEnabled;
    }
    
    /** Set the isHidden flag, indicates whether this channel display
        should render to screen or not */
    void setHidden(bool);
    
    /** Return a bool flag describing whether this channel display is
        hidden from the canvas */
    bool getHidden() {
        return isHidden;
    }

	DataChannel::DataChannelTypes getType();
    void updateType();

    bool fullredraw; // used to indicate that a full redraw is required. is set false after each full redraw

protected:

    
    LfpDisplayCanvas* canvas;
    LfpDisplay* display;
    LfpDisplayOptions* options;

    bool isSelected;
    bool isHidden;

    int chan;
    int drawableChan;

    String name;

    Font channelFont;

    Colour lineColour;

    int channelOverlap;
    int channelHeight;
    float channelHeightFloat;

    float range;

    bool isEnabled;
    bool inputInverted;
    bool canBeInverted;
    bool drawMethod;

	DataChannel::DataChannelTypes type;
    String typeStr;
    
    

};
   
