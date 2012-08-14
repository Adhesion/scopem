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
	setRect( 0, 0, 512, 512 );

	bufferPos = 0;
	bufferSize = 1000;
	buffer = new float[ bufferSize ];
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
	gluLookAt( 0.0f, 0.0f, 0.5f,
				0.0f, 0.0f, -1.0f,
				0.0f, 1.0f, 0.0f );

	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glEnable( GL_LINE_SMOOTH );
	glLineWidth( 2.0f );
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

	// draw from -1.0f - 1.0f - total length 2.0f so x increment for each val
	// is 2/buffersize
	float xPos = -1.0f;
	float inc = 2.0f / (float)bufferSize;

	// draw axes
	glColor4f( 0.5f, 0.5f, 0.5f, 0.5f );
	glBegin( GL_LINES );
	glVertex3f( -1.0f, 0.0f, 0.0f );
	glVertex3f( 1.0f, 0.0f, 0.0f );
	glVertex3f( 0.0f, -1.0f, 0.0f );
	glVertex3f( 0.0f, 1.0f, 0.0f );
	glEnd();

	// draw buffer
	glColor4f( 0.2f, 0.3f, 0.9f, 0.95f );
	glBegin( GL_LINE_STRIP );
	// align with where the buffer was most recently written to so we don't
	// draw any discontinuities
	// bufferPos is newest data, so bufferPos+1 is oldest (draw old -> new)
	int pos = bufferPos + 1;
	for( int i = 0; i < bufferSize; i++ )
	{
		if ( pos == bufferSize )
		{
			pos = 0;
		}
		glVertex3f( xPos, buffer[ pos ], 0.0f );
		xPos += inc;
		pos++;
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
