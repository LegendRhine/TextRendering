/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "JuceHeader.h"
#include "MainComponent.h"

class RenderingLookAndFeel : public LookAndFeel_V3
{
public:
    RenderingLookAndFeel ()
    {
        setDefaultSansSerifTypefaceName ("Microsoft YaHei Light");
    }    
};
//==============================================================================
class TextRenderingApplication : public JUCEApplication
{
public:
    //==============================================================================
    TextRenderingApplication () {}

    const String getApplicationName () override { return ProjectInfo::projectName; }
    const String getApplicationVersion () override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed () override { return true; }

    //==============================================================================
    void initialise (const String& /*commandLine*/) override
    {
        laf = new RenderingLookAndFeel ();
        LookAndFeel::setDefaultLookAndFeel (laf);

        mainWindow = new MainWindow (getApplicationName ());
    }

    void shutdown () override { mainWindow = nullptr; }
    void systemRequestedQuit () override { quit (); }
    void anotherInstanceStarted (const String& /*commandLine*/) override { }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainContentComponent class.
    */
    class MainWindow : public DocumentWindow
    {
    public:
        MainWindow (String name) : DocumentWindow (name,
            Colours::lightgrey,
            DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar (true);
            setContentOwned (new MainContentComponent (), true);
            setResizable (true, false);

            centreWithSize (getWidth (), getHeight ());
            setVisible (true);
        }

        void closeButtonPressed () override
        {
            JUCEApplication::getInstance ()->systemRequestedQuit ();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    ScopedPointer<MainWindow> mainWindow;
    ScopedPointer<RenderingLookAndFeel> laf;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (TextRenderingApplication)
