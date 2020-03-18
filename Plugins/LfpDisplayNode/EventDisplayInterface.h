    
    
#pragma mark - EventDisplayInterface -
//==============================================================================
/**
    Interface class for Event Display channels.
 */
class EventDisplayInterface : public Component,
    public Button::Listener
{
public:
    EventDisplayInterface(LfpDisplay*, LfpDisplayCanvas*, int chNum);
    ~EventDisplayInterface();

    void paint(Graphics& g);

    void buttonClicked(Button* button);

    void checkEnabledState();

    bool isEnabled;

private:

    int channelNumber;

    LfpDisplay* display;
    LfpDisplayCanvas* canvas;

    ScopedPointer<UtilityButton> chButton;

};
