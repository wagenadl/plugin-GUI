    
#pragma mark - LfpBitmapPlotter -
//==============================================================================
/**
    Interface class for different plotting methods.
 */
class LfpBitmapPlotter
{
public:
    LfpBitmapPlotter(LfpDisplay * lfpDisplay)
        : display(lfpDisplay)
    {}
    virtual ~LfpBitmapPlotter() {}
    
    /** Plots one subsample of data from a single channel to the bitmap provided */
    virtual void plot(Image::BitmapData &bitmapData, LfpBitmapPlotterInfo &plotterInfo) = 0;
    
protected:
    LfpDisplay * display;
};
