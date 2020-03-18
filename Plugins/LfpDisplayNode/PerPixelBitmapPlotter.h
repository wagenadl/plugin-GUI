
    
    
#pragma mark - PerPixelBitmapPlotter -
//==============================================================================
/**
    Abstraction of the per-pixel plotting method.
 */
class PerPixelBitmapPlotter : public LfpBitmapPlotter
{
public:
    PerPixelBitmapPlotter(LfpDisplay * lfpDisplay);
    virtual ~PerPixelBitmapPlotter() {}
    
    /** Plots one subsample of data from a single channel to the bitmap provided */
    virtual void plot(Image::BitmapData &bitmapData, LfpBitmapPlotterInfo &plotterInfo) override;
};
    
    
