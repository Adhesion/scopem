/*
 * GLGUI.cpp
 *
 * VST editor using VSTGL, for drawing the scope/spectrum.
 *
 * @author Andrew Ford
 */

#include "GLGUI.h"
#include "DrawTimer.h"
#include "scopem.h"

GLGUI::GLGUI( AudioEffect* effect )
	: VSTGLEditor( effect, Antialias4x )
{
	// 16ms interval ~= 60fps
	timer = new DrawTimer( 16, this );

	// have to set size early, presumably for GL context init
	setRect( 0, 0, 512, 384 );

	bufferPos = 0;
	risePoint = 0;
	bufferSize = 10000;
	buffer = new float[ bufferSize ];

	ampScale = 1.0f;
	window = 700;
}

GLGUI::~GLGUI()
{
	delete timer;
}

void GLGUI::guiOpen()
{
	glViewport( 0, 0, getWidth(), getHeight() );

	// use frustum projection
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// depth 0.1 - 20 for now
	float width = (float)getWidth() / (float)getHeight();
	float height = 1.0f;
	glFrustum( -width, width, -height, height, 0.5, 1.5 );

	// default camera position
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	// note - args are camera, lookat, up
	gluLookAt( 0.0f, 0.0f, 0.75f,
				0.0f, 0.0f, -1.0f,
				0.0f, 1.0f, 0.0f );

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glEnable( GL_LINE_SMOOTH );
	glLineWidth( 1.5f );
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

	// start timer so we start drawing
	timer->start();
}

void GLGUI::guiClose()
{
	timer->stop();
}

void GLGUI::draw()
{
	glClear( GL_COLOR_BUFFER_BIT );

	// draw from 1.0f - -1.0f - total length 2.0f so x increment for each val
	// is 2/buffersize
	// drawing right to left from newest data for (window) samples
	float xPos = 1.0f;
	float inc = 2.0f / (float)window;

	// draw axes
	glColor4f( 0.7f, 0.7f, 0.7f, 0.25f );
	glBegin( GL_LINES );
	glVertex3f( -1.0f, 0.0f, 0.0f );
	glVertex3f( 1.0f, 0.0f, 0.0f );
	glVertex3f( 0.0f, -1.0f, 0.0f );
	glVertex3f( 0.0f, 1.0f, 0.0f );
	glEnd();

	// draw full scale (amplitude) boundary
	glColor4f( 0.5f, 0.5f, 0.5f, 0.15f );
	glBegin( GL_LINES );
	glVertex3f( -1.0f, ampScale, 0.0f );
	glVertex3f( 1.0f, ampScale, 0.0f );
	glVertex3f( -1.0f, ampScale * -1.0f, 0.0f );
	glVertex3f( 1.0f, ampScale * -1.0f, 0.0f );
	glEnd();

	// draw buffer (waveform)
	glColor4f( 0.2f, 0.3f, 0.9f, 0.95f );
	glBegin( GL_LINE_STRIP );
	// align with where the buffer was most recently written to so we don't
	// draw any discontinuities
	int pos = bufferPos;
	for( int i = 0; i < window; i++ )
	{
		if ( pos < 0 )
		{
			pos = bufferSize - 1;
		}
		glVertex3f( xPos, buffer[ pos ] * ampScale, 0.0f );
		xPos -= inc;
		pos--;
	}
	glEnd();
}

void GLGUI::addToBuffer( float in )
{
	bufferPos++;
	if ( bufferPos >= bufferSize )
	{
		bufferPos = 0;
	}
	buffer[ bufferPos ] = in;
}

void GLGUI::setParameter( VstInt32 index, float value )
{
	switch( index )
	{
	case amplitude:
		ampScale = value;
		printf( "GL setparam, ampscale now %f\n", ampScale );
		break;
	case frequency:
		// since we get the frequency & we want the period, flip it
		// (accounting for samplerate)
		window = (int)ceil( effect->getSampleRate() / value );
		printf( "GL setparam, window now %i (sr %f)\n", window, effect->getSampleRate() );
		break;
	}
}

void GLGUI::updateRisePoint()
{
	// find point where waveform "starts" (was 0, now rising)
	int lastPos = bufferPos == 0 ? bufferSize - 1 : bufferPos - 1;
	if ( abs( buffer[ lastPos ] ) < 0.001f &&
		buffer[ bufferPos ] > buffer[ lastPos ] )
	{
		risePoint = lastPos;
	}
}
