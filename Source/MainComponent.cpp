/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h" 

const String content (L"朝辞白帝彩云间，千里江陵一日还。两岸猿声啼不住，轻舟已过万重山。\n\n在几次被撂到路上的不快经历之后，陪伴我们整整11年的小拓终于被我无情地抛弃了：）换了一辆丰田的混动车（卡罗拉双擎）。这个车谈不上什么操控和运动，但是买菜基本够用了：）有点吃惊的并不是油耗和静音环保、油电协同的“黑科技”，而是Corolla这个神车进化到目前，虽然日系车的风格依然浓厚而根深蒂固，但行驶质感和整体感却多了一些德系车的味道。这点不错。\n\nThe quick brown fox jumps over the lazy dog, 9876543210. In the age of computers, this pangram is commonly used to display font samples and for testing computer keyboards. In cryptography, it is commonly used as a test vector for hash and encryption algorithms to verify their implementation, as well as to ensure alphabetic character set compatibility.");

//==============================================================================
MainContentComponent::MainContentComponent () :
                heightLabel (String (), L"大小"),
                scaleLabel (String (), L"缩放"),
                styleLabel (String (), L"样式"),
                fontLabel (String (), L"字体")
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

    fontBox.addItem ("Microsoft YaHei", 1);
    fontBox.addItem ("Microsoft YaHei Light", 2);
    fontBox.addItem ("Microsoft YaHei UI", 3);
    fontBox.addItem ("Microsoft YaHei UI Light", 4);
    fontBox.addItem ("Hiragino Sans GB W3", 5);
    fontBox.addItem ("PingFang SC", 6);
    fontBox.addItem ("Arial Unicode MS", 7);
    fontBox.addItem ("SimHei", 8);
    fontBox.addItem ("SimSun", 9);
    fontBox.addItem ("STFangsong", 10);
    fontBox.addItem ("STKaiti", 11);
    fontBox.addItem ("STSong", 12);
    fontBox.addItem ("STXihei", 13);
    fontBox.addItem ("STZhongsong", 14);
    fontBox.addItem ("DengXian", 15);
    fontBox.addItem ("FangSong", 16);
    fontBox.addItem ("FZLanTingHeiS-UL-GB", 17);
    fontBox.addItem ("FZYaoTi", 18);
    fontBox.addItem ("KaiTi", 19);
    fontBox.addItem ("LiSu", 20);
    fontBox.addItem ("Microsoft JhengHei", 21);
    fontBox.addItem ("Microsoft JhengHei UI", 22);
    fontBox.addItem ("NSimSun", 23);
    fontBox.addItem ("STCaiyun", 24);
    
    fontBox.setSelectedItemIndex (0);
    
    nameEt.setText (editors[0]->getFont().getTypefaceName());
    nameEt.setReadOnly (true);
    nameEt.setSelectAllWhenFocused (true);

    someContent.setFont (18.f);
    someContent.setReadOnly (true);
    someContent.setSelectAllWhenFocused (true);
    someContent.setMultiLine (true, true);
    someContent.setReturnKeyStartsNewLine (true);
    someContent.setText (L"汉字的显示效果。The quick brown fox jumps over the lazy dog, 9876543210. THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG'S BACK 1234567890 - In the age of computers, this pangram is commonly used to display font samples and for testing computer keyboards. In cryptography, it is commonly used as a test vector for hash and encryption algorithms to verify their implementation, as well as to ensure alphabetic character set compatibility.");

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

