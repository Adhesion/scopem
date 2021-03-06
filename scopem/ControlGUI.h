/*
 * ControlGUI.h
 *
 * VST GUI editor with the main controls.
 *
 * @author Andrew Ford
 */

#ifndef __CONTROLGUI_H
#define __CONTROLGUI_H

#include "aeffguieditor.h"

// resource bitmap ids
enum
{
	backgroundID = 103,
	sliderBackgroundID,
	sliderHandleID
};

class ControlGUI : public AEffGUIEditor, public CControlListener
{
public:
	ControlGUI( AudioEffect* effect );
	~ControlGUI();

	bool open( void* ptr );
	void close();

	void setParameter( VstInt32 index, float value );
	void valueChanged( CDrawContext* context, CControl* control );

private:
	CBitmap* background;
	CBitmap* sliderBackground;
	CBitmap* sliderHandle;

	CVerticalSlider* amplitudeControl;
	CVerticalSlider* frequencyControl;
};

#endif
