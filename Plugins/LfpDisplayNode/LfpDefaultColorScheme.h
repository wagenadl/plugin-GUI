    
    
#pragma mark - LfpDefaultColourScheme -
class LfpDefaultColourScheme : public LfpChannelColourScheme
{
public:
    LfpDefaultColourScheme(LfpDisplay*, LfpDisplayCanvas*);
    virtual ~LfpDefaultColourScheme() {}
    
    void paint(Graphics &g) override;
    void resized() override;
    
    virtual const Colour getColourForIndex(int index) const override;
    
private:
    static Array<Colour> colourList;
};
    
