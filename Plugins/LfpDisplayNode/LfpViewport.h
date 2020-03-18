    
#pragma mark - LfpViewport -
//==============================================================================
/**
    Encapsulates the logic for the LfpDisplayCanvas's viewable area and user inter-
    action (scrolling) when drawn in the environment.
 
    Not much is overridden here, it uses mostly JUCE's Viewport functionality
    by inheriting Viewport but stores a reference to the LfpDisplayCanvas.
 
    @see Viewport, LfpDisplayCanvas
 */
class LfpViewport : public Viewport
{
public:
    LfpViewport(LfpDisplayCanvas* canvas);
    void visibleAreaChanged(const Rectangle<int>& newVisibleArea);

private:
    LfpDisplayCanvas* canvas;
};

