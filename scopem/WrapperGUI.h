/*
 * WrapperGUI.h
 *
 * MultiGUI wrapper class to contain GL & normal editors.
 *
 * @author Andrew Ford
 */

#ifndef __WRAPPERGUI_H
#define __WRAPPERGUI_H

#include "MultiGUI/MultiGUIEditor.h"
#include "GLGUI.h"
#include "ControlGUI.h"

class WrapperGUI : public MultiGUIEditor
{
public:
	WrapperGUI( AudioEffect* effect );
	~WrapperGUI();

	void setParameter( long index, float value );

	void addToBuffer( float in );

private:
	GLGUI* gl;
	ControlGUI* control;
};

#endif
