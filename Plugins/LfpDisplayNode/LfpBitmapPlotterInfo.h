    
    
#pragma mark - LfpBitmapPlotterInfo -
//==============================================================================
/**
    Information struct for plotting method encapsulation classes.
 */
struct LfpBitmapPlotterInfo
{
    int channelID;
    int samp;
    int to;
    int from;
    int x;
    int y;
    int height;
    int width;
    float channelHeightFloat;
    std::array<float, MAX_N_SAMP_PER_PIXEL> samplesPerPixel;
    int sampleCountPerPixel;
    float range;
    int samplerange;
    float histogramParameterA;
    Colour lineColour;
    Colour lineColourBright;
    Colour lineColourDark;
};

    
