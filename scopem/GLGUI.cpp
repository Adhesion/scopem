/*
 * GLGUI.cpp
 *
 * VST editor using VSTGL, for drawing the scope/spectrum.
 *
 * @author Andrew Ford
 */

#include "GLGUI.h"
#include "DrawTimer.h"

GLGUI::GLGUI( AudioEffect* effect )
	: VSTGLEditor( effect, Antialias4x )
{
	// 16ms interval ~= 60fps
	timer = new DrawTimer( 16, this );

	// have to set size early, presumably for GL context init
	setRect( 0, 0, 512, 384 );
}

GLGUI::~GLGUI()
{
	delete timer;
}

void GLGUI::guiClose()
{
	timer->stop();
}