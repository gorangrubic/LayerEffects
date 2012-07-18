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

#include "AppConfig.h"

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable: 4100) // unreferenced formal parameter
#endif

#include "modules/juce_core/juce_core.h"
#include "modules/juce_gui_basics/juce_gui_basics.h"

#include "modules/vf_core/vf_core.h"
#include "modules/vf_gui/vf_gui.h"

using namespace juce;

#include "gui/CBlendModeResult.h"
#include "gui/CImageSource.h"

#include "gui/CBlendModeDemo.h"
#include "gui/CTextDemo.h"

#include "gui/MainPanel.h"
#include "gui/MainWindow.h"
#include "gui/MainApp.h"

//----------

#include "gui/CBlendModeResult.cpp"
#include "gui/CImageSource.cpp"

#include "gui/CBlendModeDemo.cpp"
#include "gui/CTextDemo.cpp"

#include "gui/MainApp.cpp"
#include "gui/MainPanel.cpp"
#include "gui/MainWindow.cpp"

#ifdef _MSC_VER
#pragma warning (pop)
#endif
