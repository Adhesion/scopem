/*
 * DrawTimer.h
 *
 * Timer for redrawing the GL GUI.
 *
 * @author Andrew Ford
 */

#ifndef __DRAWTIMER_H
#define __DRAWTIMER_H

#include "VSTGL/VSTGLTimer.h"

class GLGUI;

class DrawTimer : public Timer
{
public:
	DrawTimer( int interval, GLGUI* p );
	void timerCallback();

private:
	GLGUI* parent;
};

#endif
