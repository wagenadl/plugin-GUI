#pragma mark - ShowHideOptionsButton -
//==============================================================================
/**
 
 Toggles view options drawer for LfpDisplayCanvas.
 
 */
class ShowHideOptionsButton : public Button
{
public:
    ShowHideOptionsButton(LfpDisplayOptions*);
    virtual ~ShowHideOptionsButton();
    void paintButton(Graphics& g, bool, bool);
    LfpDisplayOptions* options;
};
    
    
    
    
    
    
