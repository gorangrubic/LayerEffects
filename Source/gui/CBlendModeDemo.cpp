//------------------------------------------------------------------------------
/*
  LayerEffects for JUCE

  Official project location:
  https://github.com/vinniefalco/LayerEffects

  ------------------------------------------------------------------------------

  License: MIT License (http://www.opensource.org/licenses/mit-license.php)
  Copyright (c) 2012 by Vinnie Falco

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/
//------------------------------------------------------------------------------

CBlendModeDemo::CBlendModeDemo ()
{
  {
    CBlendModeResult* c = new CBlendModeResult;
    c->setBounds (4 + 256 + 4 + 256 + 4, 4, 256, 280);
    addAndMakeVisible (c);

    m_blendResult = c;
  }

  {
    CImageSource* c = new CImageSource (1);
    c->setBounds (4, 4, 256, 280);
    addAndMakeVisible (c);

    c->selectImage (1);
  }

  {
    CImageSource* c = new CImageSource (2);
    c->setBounds (4 + 256 + 4, 4, 256, 280);
    addAndMakeVisible (c);

    c->selectImage (2);
  }

  setSize (4 + 256 + 4 + 256 + 4 + 256 + 4, 4 + 280 + 4);
}

CBlendModeDemo::~CBlendModeDemo()
{
  m_blendResult = 0;

  deleteAllChildren();
}

void CBlendModeDemo::onImageSourceSelect (int id, Image image)
{
  m_blendResult->setSourceImage (id - 1, image);
}

void CBlendModeDemo::paint (Graphics& g)
{
}
