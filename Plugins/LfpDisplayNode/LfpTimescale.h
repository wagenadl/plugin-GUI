#pragma mark - LfpTimeScale -
//==============================================================================
/**
 
    Displays the timescale of the LfpDisplayCanvas in the viewport.
 
 */
class LfpTimescale : public Component
{
public:
    LfpTimescale(LfpDisplayCanvas*, LfpDisplay*);
    ~LfpTimescale();

    void paint(Graphics& g);
    
    void resized();
    
    /** Handles the drag to zoom feature on the timescale. The display must
        be paused to zoom */
    void mouseDrag(const MouseEvent &e) override;
    
    void mouseUp(const MouseEvent &e) override;

    void setTimebase(float t);

private:

    LfpDisplayCanvas* canvas;
    LfpDisplay* lfpDisplay;

    float timebase;
    float labelIncrement;
    float numIncrements;

    Font font;

    StringArray labels;

};

