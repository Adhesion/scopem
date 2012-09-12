scopem
======

GL-based oscilloscope (wavelet-based spectrum analysis coming soon).

Build Requirements
==================

- Visual Studio 2010 (express should work)
- VST 2.4 SDK
- ndcvst (http://github.com/Adhesion/ndcvst, originally by Niall Moody http://www.niallmoody.com/ndcplugs/index.htm with some bugfixes by myself)
- zlib (1.2.7 works)
- OpenGL libs (should come with a standard driver install)

You'll need to build zlib first - on Windows the makefile that uses nmake (Makefile.msc in win32/) should work. In the makefile, you'll probably want to change the runtime library command line option (in CFLAGS) for zlib to match the one in the scopem project (multi-threaded debug (-MTd) for debug, multi-threaded (-MT) for release - ie static build and not dynamic build), otherwise the linker will complain.

Make sure to change the VC++ include and additional library directories (in project properties) to the top-level directory for the VST SDK, zlib etc. on your machine. Build result will be a standalone .dll in the build directory (either Debug/ or Release/ depending on which you have selected).

Usage
=====

See docs/scopem-readme.txt for usage information.

License
=======

Copyright (c) 2012 Andrew Ford

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Misc
====

VST is a trademark of Steinberg Media Technologies GmbH.
