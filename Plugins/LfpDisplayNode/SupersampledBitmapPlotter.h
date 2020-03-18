    
#pragma mark - SupersampledBitmapPlotter -
//==============================================================================
/**
 Abstraction of the supersampled line-based plotting method.
 */
class SupersampledBitmapPlotter : public LfpBitmapPlotter
{
public:
    SupersampledBitmapPlotter(LfpDisplay * lfpDisplay);
    virtual ~SupersampledBitmapPlotter() {}
    
    /** Plots one subsample of data from a single channel to the bitmap provided */
    virtual void plot(Image::BitmapData &bitmapData, LfpBitmapPlotterInfo &plotterInfo) override;
};
