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

	void setParameter( VstInt32 index, float value );

	void updateRisePoint();

private:
	float* buffer;
	int bufferPos;
	int bufferSize;
	int risePoint;

	// amplitude scale for the scope
	float ampScale;
	// how many samples to display in the scope
	int window;

	DrawTimer* timer;
};

#endif
