    
    
#pragma mark - LfpChannelColourScheme -
/**
 Interface for a color scheme object
 */
class LfpChannelColourScheme : public Component
{
public:
    LfpChannelColourScheme(int numColourChannels_, LfpDisplay* display, LfpDisplayCanvas* canvas)
    : lfpDisplay(display)
    , canvas(canvas)
    , numColourChannels(numColourChannels_)
    { }
    
    virtual ~LfpChannelColourScheme() {}
    
    void paint(Graphics &g) override {}
    void resized() override {}
    
    virtual const Colour getColourForIndex(int index) const = 0;
    
    /** Returns true if a color scheme has configurable UI elements that
        must be drawn to the options drawer. Subclasses should override this
        if they have drawable elements in the options drawer. */
    virtual bool hasConfigurableElements() { return false; }
    
    void setColourGrouping(int grouping);
    int getColourGrouping();
    
protected:
    LfpDisplay * lfpDisplay;
    LfpDisplayCanvas * canvas;
    
    int numColourChannels;
    static int colourGrouping;
};
    
