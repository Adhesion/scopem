/*
 * DrawTimer.cpp
 *
 * Timer for redrawing the GL GUI.
 *
 * @author Andrew Ford
 */

#include "DrawTimer.h"
#include "GLGUI.h"

DrawTimer::DrawTimer( int interval, GLGUI* p )
	: Timer( interval ), parent( p )
{

}

void DrawTimer::timerCallback()
{
	parent->refreshGraphics();
}
