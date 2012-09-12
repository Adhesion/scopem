scopem
======

GL-based oscilloscope (wavelet-based spectrum analysis coming soon).

Usage
=====

Put the .dll in your host's VST directory - should show up as a proper audio
effect in any host that supports VST 2.4.

Left slider is amplitude scaling - moving the amplitude slider will change the
vertical zoom of the waveform. The horizontal lines at the top and bottom,
which represent -1.0 and 1.0 (ie, will clip if the waveform crosses those) will
move proportionally.

Right slider is frequency, from 20Hz to 5000Hz.

License
=======

Copyright (c) 2012 Andrew Ford

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

Misc
====

VST is a trademark of Steinberg Media Technologies GmbH.
