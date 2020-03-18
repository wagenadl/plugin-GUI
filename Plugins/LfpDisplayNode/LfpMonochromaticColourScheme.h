    
    
#pragma mark - LfpMonochromaticColourScheme -
enum ColourPattern
{
    DOWN = 0,
    UP,
    DOWN_UP,
    UP_DOWN
};
    
class LfpMonochromaticColourScheme : public LfpChannelColourScheme,
    public ComboBox::Listener,
    public Slider::Listener
{
public:
    LfpMonochromaticColourScheme(LfpDisplay*, LfpDisplayCanvas*);
    virtual ~LfpMonochromaticColourScheme() {}
    
    void paint(Graphics &g) override;
    void resized() override;
    
    virtual bool hasConfigurableElements() override { return true; };
    
    void sliderValueChanged(Slider* sl);
    void comboBoxChanged(ComboBox *cb);
    
    /** Catches mouseUp to determine whether the base hue has changed. */
    void mouseUp(const MouseEvent &e) override;
    
    void setBaseHue(Colour base);
    const Colour getBaseHue() const;
    
    void setColourPattern(ColourPattern newPattern) { colourPattern = newPattern; }
    ColourPattern getColourPattern() { return colourPattern; }
    
    void setNumColourSeriesSteps(int numSteps);
    int getNumColourSeriesSteps();
    
    virtual const Colour getColourForIndex(int index) const override;
    
protected:
    bool isBlackAndWhite; // Not used yet
    Colour baseHue;
    Colour swatchHue;
    Array<Colour> colourList;
    
    ColourPattern colourPattern;
    
    ScopedPointer<Label> numChannelsLabel;
    ScopedPointer<ComboBox> numChannelsSelection;
    ScopedPointer<Label> baseHueLabel;
    ScopedPointer<Slider> baseHueSlider;
    ScopedPointer<Label> colourPatternLabel;
    ScopedPointer<ComboBox> colourPatternSelection;
    
    Rectangle<int> colourSwatchRect;
    
    virtual void calculateColourSeriesFromBaseHue();
};
