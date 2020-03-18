    
#pragma mark - LfpGradientColourScheme
    
class LfpGradientColourScheme : public LfpMonochromaticColourScheme
{
public:
    
    LfpGradientColourScheme(LfpDisplay*, LfpDisplayCanvas*);
    
    void paint(Graphics &) override;
    void resized() override;
    
    void sliderValueChanged(Slider *sl) override;
    void mouseUp(const MouseEvent &e) override;
    
    void setLerpToHue(Colour c);
    Colour getLerpToHue();
    
private:
    Colour baseHueB;
    Colour swatchHueB;
    Rectangle<int> colourSwatchRectB;
    
    ScopedPointer<Label> baseHueLabelB;
    ScopedPointer<Slider> baseHueSliderB;
    
    void calculateColourSeriesFromBaseHue() override;
};
    
