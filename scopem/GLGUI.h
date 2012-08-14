/*
 * GLGUI.h
 *
 * VST editor using VSTGL, for drawing the scope/spectrum.
 *
 * @author Andrew Ford
 */

#ifndef __GLGUI_H
#define __GLGUI_H

#include "VSTGL/VSTGLEditor.h"

class DrawTimer;

class GLGUI : public VSTGLEditor
{
public:
	GLGUI( AudioEffect* effect );
	~GLGUI();

	void guiOpen();
	void guiClose();

	void draw();

	void addToBuffer( float in );

private:
	float* buffer;
	int bufferPos;
	int bufferSize;
	DrawTimer* timer;
};

#endif
