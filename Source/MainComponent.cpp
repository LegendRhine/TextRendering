/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

const String content (L"���ǰ׵۲��Ƽ䣬ǧ�ｭ��һ�ջ�������Գ���䲻ס�������ѹ�����ɽ��\n\n�ڼ��α��̵�·�ϵĲ��쾭��֮�������������11���С�����ڱ�������������ˣ�������һ������Ļ춯����������˫�棩�������̸����ʲô�ٿغ��˶���������˻��������ˣ����е�Ծ��Ĳ������ͺĺ;����������͵�Эͬ�ġ��ڿƼ���������Corolla����񳵽�����Ŀǰ����Ȼ��ϵ���ķ����ȻŨ�������ٹ̣�����ʻ�ʸк������ȴ����һЩ��ϵ����ζ������㲻��\n\nThe quick brown fox jumps over the lazy dog, 9876543210. In the age of computers, this pangram is commonly used to display font samples and for testing computer keyboards. In cryptography, it is commonly used as a test vector for hash and encryption algorithms to verify their implementation, as well as to ensure alphabetic character set compatibility.");

//==============================================================================
MainContentComponent::MainContentComponent () :
                heightLabel (String (), L"��С"),
                scaleLabel (String (), L"����"),
                styleLabel (String (), L"��ʽ"),
                fontLabel (String (), L"����")
{
    // text editors...
    for (int i = 4; --i >= 0; )
    {
        TextEditor* e = new TextEditor ();
        e->setMultiLine (true, true);
        e->setReturnKeyStartsNewLine (true);

        addAndMakeVisible (e);
        editors.add (e);
    }

    editors[0]->setColour (TextEditor::backgroundColourId, Colours::white);
    editors[0]->setColour (TextEditor::textColourId, Colours::black);

    editors[1]->setColour (TextEditor::backgroundColourId, Colours::lightgrey);
    editors[1]->setColour (TextEditor::textColourId, Colours::black);

    editors[2]->setColour (TextEditor::backgroundColourId, Colours::grey);
    editors[2]->setColour (TextEditor::textColourId, Colours::white);

    editors[3]->setColour (TextEditor::backgroundColourId, Colours::black);
    editors[3]->setColour (TextEditor::textColourId, Colours::white);

    for (int i = 4; --i >= 0; )
    {
        editors[i]->setFont (18.f);
        editors[i]->setText (content, false);
    }

    //...
    addAndMakeVisible (heightSlider);
    addAndMakeVisible (heightLabel);
    addAndMakeVisible (scaleLabel);
    addAndMakeVisible (fontLabel);
    addAndMakeVisible (scaleSlider);
    addAndMakeVisible (styleBox);
    addAndMakeVisible (fontBox);
    addAndMakeVisible (nameEt);
    addAndMakeVisible (someContent);

    heightLabel.attachToComponent (&heightSlider, true);
    scaleLabel.attachToComponent (&scaleSlider, true);
    styleLabel.attachToComponent (&styleBox, true);
    fontLabel.attachToComponent (&fontBox, true);

    heightSlider.addListener (this);
    scaleSlider.addListener (this);
    styleBox.addListener (this);
    fontBox.addListener (this);

    heightSlider.setRange (12.0, 50.0, 0.1);
    heightSlider.setValue (18.0);
    heightSlider.setDoubleClickReturnValue (true, 18.0);
    heightSlider.setTextBoxStyle (Slider::TextBoxLeft, false, 60, 25);

    scaleSlider.setRange (0.5, 2.0, 0.01);
    scaleSlider.setValue (1.0);
    scaleSlider.setDoubleClickReturnValue (true, 1.0);
    scaleSlider.setTextBoxStyle (Slider::TextBoxLeft, false, 60, 25);

    //..
    const StringArray newStyles (editors[0]->getFont().getAvailableStyles ());
    styleBox.clear ();
    styleBox.addItemList (newStyles, 1);
    styleBox.setSelectedItemIndex (0);

    fontBox.addItem ("Microsoft YaHei Light", 1);
    fontBox.addItem ("Microsoft YaHei UI", 2);
    fontBox.addItem ("Hiragino Sans GB W3", 3);
    fontBox.addItem ("PingFang SC", 4);
    fontBox.addItem ("SimHei", 5);
    fontBox.addItem ("SimSun", 6);
    fontBox.addItem ("STFangsong", 7);
    fontBox.addItem ("STKaiti", 8);
    fontBox.addItem ("STSong", 9);
    fontBox.addItem ("STXihei", 10);
    fontBox.addItem ("STZhongsong", 11);
    fontBox.addItem ("Arial Unicode MS", 12);
    fontBox.addItem ("DengXian", 13);
    fontBox.addItem ("FangSong", 14);
    fontBox.addItem ("FZLanTingHeiS-UL-GB", 15);
    fontBox.addItem ("FZYaoTi", 16);
    fontBox.addItem ("KaiTi", 17);
    fontBox.addItem ("LiSu", 18);
    fontBox.addItem ("Microsoft JhengHei", 19);
    fontBox.addItem ("Microsoft JhengHei UI", 20);
    fontBox.addItem ("NSimSun", 21);
    fontBox.addItem ("STCaiyun", 22);
    fontBox.addItem ("Microsoft YaHei", 23);
    fontBox.addItem ("Microsoft YaHei UI Light", 24);
    
    fontBox.setSelectedItemIndex (0);
    
    nameEt.setText (editors[0]->getFont().getTypefaceName());
    nameEt.setReadOnly (true);
    nameEt.setSelectAllWhenFocused (true);

    someContent.setFont (18.f);
    someContent.setReadOnly (true);
    someContent.setSelectAllWhenFocused (true);
    someContent.setMultiLine (true, true);
    someContent.setReturnKeyStartsNewLine (true);
    someContent.setText ("The quick brown fox jumps over the lazy dog, 9876543210. THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG'S BACK 1234567890 - In the age of computers, this pangram is commonly used to display font samples and for testing computer keyboards. In cryptography, it is commonly used as a test vector for hash and encryption algorithms to verify their implementation, as well as to ensure alphabetic character set compatibility.");

    setSize (1000, 600);
}

//=================================================================================================
void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::lightgrey);

    g.setColour (Colours::black);
    g.drawHorizontalLine (getHeight () - 30, 5.f, getWidth () - 5.f);
}

//=========================================================================
void MainContentComponent::resized ()
{
    const int width = getWidth () / 4;

    for (int i = 4; --i >= 0; )
        editors[i]->setBounds (i * width, 0, getWidth () / 4, getHeight () - 110);

    someContent.setBounds (0, editors[0]->getBottom () + 2, getWidth (), 80);

    heightSlider.setBounds (60, getHeight () - 27, 200, 25);
    scaleSlider.setBounds (heightSlider.getRight() + 40, getHeight () - 27, 200, 25);
    styleBox.setBounds (scaleSlider.getRight () + 40, getHeight () - 26, 80, 22);
    fontBox.setBounds (styleBox.getRight () + 40, getHeight () - 26, 150, 22);
    nameEt.setBounds (fontBox.getRight () + 20, getHeight () - 26, 150, 22);
}

//=================================================================================================
void MainContentComponent::sliderValueChanged (Slider* /*slider*/)
{
    updateText ();
}

//=================================================================================================
void MainContentComponent::comboBoxChanged (ComboBox* cb)
{
    if (cb == &fontBox)
    {
        Font f (fontBox.getText(), (float) heightSlider.getValue(), Font::plain);
        const StringArray newStyles (f.getAvailableStyles());
        
        styleBox.clear ();
        styleBox.addItemList (newStyles, 1);
        styleBox.setSelectedItemIndex (0);
    }

    updateText ();
    nameEt.setText (editors[0]->getFont().getTypefaceName ());
}

//=================================================================================================
void MainContentComponent::updateText ()
{
    Font f = Font (fontBox.getText(), styleBox.getText(), (float) heightSlider.getValue())
        .withHorizontalScale ((float) scaleSlider.getValue());

    for (int i = 4; --i >= 0; )
    {
        editors[i]->setFont (f);
        editors[i]->applyFontToAllText (f);
    }
}

